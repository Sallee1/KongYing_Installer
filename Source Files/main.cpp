#pragma
#include "pch.h"
#include "install_widget.h"
#include "update_widget.h"
#include "tianli_utils.h"
#include "uninstall_widget.h"
#include <QDesktopServices>


int print(std::vector<std::string>& arg) {
  for (auto& i : arg) {
    std::cout << i << std::endl;
  }
  return 0;
}

tianli::tianli_widget_super* getInstanceWidget();

int main_window(int argc, char* argv[]) {
  QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
  QGuiApplication::setHighDpiScaleFactorRoundingPolicy(Qt::HighDpiScaleFactorRoundingPolicy::PassThrough);

  QApplication a(argc, argv);

  QFont font(QString("Microsoft YaHei UI"));
  font.setPointSize(9);
  a.setFont(font);

  tianli::tianli_widget_super* w;

  std::vector<string> args;
  for (int i = 0; i < argc; i++)
    args.emplace_back(std::string(argv[i]));

  //智能模式
  if (argc == 1 || (argc == 2 && args[1] == "--window") || args[1] == "-w")
    w = getInstanceWidget();
  //安装模式
  else if ((argc == 3 && args[1] == "--window" && args[2] == "--install") || (argc == 2 && args[1] == "-wi"))
    w = new tianli::Install_widget;
  //升级模式
  else if ((argc == 3 && args[1] == "--window" && args[2] == "--upgrade") || (argc == 2 && args[1] == "-wu"))
    w = new tianli::update_widget;
  //卸载模式
  else if ((argc == 3 && args[1] == "--window" && args[2] == "--remove") || (argc == 2 && args[1] == "-wr"))
    w = new tianli::uninstall_widget;

  //w = new tianli::uninstall_widget;
  //读取配置文件
  std::string typeId = typeid(*w).name();
  if (typeId != "class tianli::uninstall_widget") {
    QJsonParseError err = tianli::config::readconfigFromJson("installer.json");
    if (err.error != QJsonParseError::NoError)
    {
      QMessageBox::critical(nullptr, QString::fromStdString("配置文件错误"),
        QString::fromStdString(std::format("installer.json存在问题，无法继续安装流程，报错信息如下：\n{0}", std::string(err.errorString().toLocal8Bit()))));
      return -1;
    }
  }

  w->show();

  int code = a.exec();
  delete w;
  return code;
}

tianli::tianli_widget_super* getInstanceWidget()
{
  string installPath;
  bool isSuccess = tianliUtils::getRegValue_REG_SZ(HKEY_LOCAL_MACHINE,
    std::format("SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Uninstall\\{0}", tianli::config::reginfo.displayName),
    "InstallLocation",
    installPath);
  if (isSuccess)    //检测成功，判断是否在安装文件夹内
  {
    if (!fs::exists(installPath))
      return new tianli::update_widget;     //安装文件夹不存在，尝试修复
    if (fs::equivalent(std::string(QDir::toNativeSeparators(QCoreApplication::applicationDirPath()).toLocal8Bit()), installPath))
    {
      return new tianli::uninstall_widget;
    }
    return new tianli::update_widget;
  }
  else return new tianli::Install_widget;     //检测失败，默认安装
}

int main_quiet_install(int argc, char* argv[]) {
  std::vector<std::string> args;
  for (int i = 0; i < argc; ++i) {
    args.push_back(argv[i]);
  }
  return print(args);
}

int main_help() {
  QLocale systemLocale = QLocale::system(); // 获取系统默认的本地化设置
  QString systemLocaleName = systemLocale.name(); // 获取本地化设置的名称

  std::vector<std::string> arg;


  if (systemLocaleName == "zh_CN") {    //显示中文帮助
    arg = {
    "Usage: ",
    "  -h, --help                 --展开帮助列表",
    "  -v, --version              --显示版本号",
    "  -w, --window               --启动安装器，智能判断类型",
    "  -wi, --window --install    --启动安装器，安装模式",
    "  -wu, --window --upgrade    --启动安装器，升级模式",
    "  -wr, --window --remove     --启动安装器，卸载模式"
    "  -q, --quiet                --退出"
    };
  }
  else {      //非中文，显示英语帮助
    arg = {
    "Usage:",
    "  -h, --help                 --display this help list",
    "  -v, --version              --display version number",
    "  -w, --window               --start installer in automatic mode",
    "  -wi, --window --install    --start installer in install mode",
    "  -wu, --window --upgrade    --start installer in upgrade mode",
    "  -wr, --window --remove     --start installer in remove mode",
    "  -q, --quiet                --quit"
    };

  }

  // print out the list
  for (const auto& s : arg) {
    std::cout << s << "\n";
  }

  // return 1 to indicate success
  return 1;
}

int main_version() {
  std::vector<std::string> arg = {
    tianli::config::reginfo.displayVersion
  };
  print(arg);
  return 1;
}

int main(int argc, char* argv[])
{
  if (argc == 1) {
    return main_window(argc, argv);
  }
  std::string arg = argv[1];
  if (arg == "-h" || arg == "--help") {
    return main_help();
  }
  if (arg == "-v" || arg == "--version") {
    return main_version();
  }
  if (arg == "-w" || arg == "-wi" || arg == "-wu" || arg == "-wr" || arg == "--window") {
    return main_window(argc, argv);
  }
  if (arg == "-q" || arg == "--quiet") {
    return main_quiet_install(argc, argv);
  }
  else
  {
    fprintf(stderr, "WRONG PARAMETERS!");
    return main_help();
  }

  return 0;

}