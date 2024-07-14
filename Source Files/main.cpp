#pragma
#include "pch.h"
#include "install_widget.h"
#include "update_widget.h"
#include "tianli_utils.h"
#include "uninstall_widget.h"
#include <QDesktopServices>


int print(std::vector<std::wstring>& arg) {
  for (auto& i : arg) {
    std::wcout << i << std::endl;
  }
  return 0;
}

tianli::tianli_widget_super* getInstanceWidget();

int main_window(int argc, char* argv[]) {
  QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
  QGuiApplication::setHighDpiScaleFactorRoundingPolicy(Qt::HighDpiScaleFactorRoundingPolicy::PassThrough);

  QApplication a(argc, argv);

  QFont font(QString::fromStdWString(L"Microsoft YaHei UI"));
  font.setPointSize(9);
  a.setFont(font);

  tianli::tianli_widget_super* w;

  std::vector<std::wstring> args;
  for (int i = 0; i < argc; i++)
    args.emplace_back(std::wstring(QString::fromLocal8Bit(argv[i]).toStdWString()));

  //智能模式
  if (argc == 1 || (argc == 2 && args[1] == L"--window") || args[1] == L"-w")
    w = getInstanceWidget();
  //安装模式
  else if ((argc == 3 && args[1] == L"--window" && args[2] == L"--install") || (argc == 2 && args[1] == L"-wi"))
    w = new tianli::Install_widget;
  //升级模式
  else if ((argc == 3 && args[1] == L"--window" && args[2] == L"--upgrade") || (argc == 2 && args[1] == L"-wu"))
    w = new tianli::update_widget;
  //卸载模式
  else if ((argc == 3 && args[1] == L"--window" && args[2] == L"--remove") || (argc == 2 && args[1] == L"-wr"))
    w = new tianli::uninstall_widget;

  //w = new tianli::uninstall_widget;
  //读取配置文件
  std::wstring typeId = QString::fromLocal8Bit(typeid(*w).name()).toStdWString();
  if (typeId != L"class tianli::uninstall_widget") {
    QJsonParseError err = tianli::config::readconfigFromJson(L"installer.json");
    if (err.error != QJsonParseError::NoError)
    {
      QMessageBox::critical(nullptr, QString::fromStdWString(L"配置文件错误"),
        QString::fromStdWString(std::format(L"installer.json存在问题，无法继续安装流程，报错信息如下：\n{0}", std::wstring(err.errorString().toStdWString()))));
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
  std::wstring installPath;
  bool isSuccess = tianliUtils::getRegValue_REG_SZ(HKEY_LOCAL_MACHINE,
    std::format(L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Uninstall\\{0}", tianli::config::reginfo.displayName),
    L"InstallLocation",
    installPath);
  if (isSuccess)    //检测成功，判断是否在安装文件夹内
  {
    if (!fs::exists(installPath))
      return new tianli::update_widget;     //安装文件夹不存在，尝试修复
    if (fs::equivalent(std::wstring(QDir::toNativeSeparators(QCoreApplication::applicationDirPath()).toStdWString()), installPath))
    {
      return new tianli::uninstall_widget;
    }
    return new tianli::update_widget;
  }
  else return new tianli::Install_widget;     //检测失败，默认安装
}

int main_quiet_install(int argc, char* argv[]) {
  std::vector<std::wstring> args;
  for (int i = 0; i < argc; ++i) {
    args.push_back(QString::fromLocal8Bit(argv[i]).toStdWString());
  }
  return print(args);
}

int main_help() {
  QLocale systemLocale = QLocale::system(); // 获取系统默认的本地化设置
  QString systemLocaleName = systemLocale.name(); // 获取本地化设置的名称

  std::vector<std::wstring> arg;


  if (systemLocaleName == L"zh_CN") {    //显示中文帮助
    arg = {
    L"Usage: ",
    L"  -h, --help                 --展开帮助列表",
    L"  -v, --version              --显示版本号",
    L"  -w, --window               --启动安装器，智能判断类型",
    L"  -wi, --window --install    --启动安装器，安装模式",
    L"  -wu, --window --upgrade    --启动安装器，升级模式",
    L"  -wr, --window --remove     --启动安装器，卸载模式"
    L"  -q, --quiet                --退出"
    };
  }
  else {      //非中文，显示英语帮助
    arg = {
    L"Usage:",
    L"  -h, --help                 --display this help list",
    L"  -v, --version              --display version number",
    L"  -w, --window               --start installer in automatic mode",
    L"  -wi, --window --install    --start installer in install mode",
    L"  -wu, --window --upgrade    --start installer in upgrade mode",
    L"  -wr, --window --remove     --start installer in remove mode",
    L"  -q, --quiet                --quit"
    };

  }

  // print out the list
  for (const auto& s : arg) {
    std::wcout << s << L"\n";
  }

  // return 1 to indicate success
  return 1;
}

int main_version() {
  std::vector<std::wstring> arg = {
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
  std::wstring arg = QString::fromLocal8Bit(argv[1]).toStdWString();
  if (arg == L"-h" || arg == L"--help") {
    return main_help();
  }
  if (arg == L"-v" || arg == L"--version") {
    return main_version();
  }
  if (arg == L"-w" || arg == L"-wi" || arg == L"-wu" || arg == L"-wr" || arg == L"--window") {
    return main_window(argc, argv);
  }
  if (arg == L"-q" || arg == L"--quiet") {
    return main_quiet_install(argc, argv);
  }
  else
  {
    fprintf(stderr, "WRONG PARAMETERS!");
    return main_help();
  }

  return 0;

}