#pragma
#include "pch.h"
#include "install_widget.h"
#include "update_widget.h"
#include "tianli_utils.h"
#include "uninstall_widget.h"
#include "QApplication"
#include "QDir"

int print(std::vector<std::string>& arg) {
  for (auto& i : arg) {
    std::cout << i << std::endl;
  }
  return 0;
}

int main_window(int argc, char* argv[]) {
  //将参数转换为单字节
  QApplication a(argc, argv);
  
  // 设置字体
  QFont font(QString::fromLocal8Bit("Microsoft YaHei UI"));
  a.setFont(font);

  tianli::Install_widget w;
  //tianli::update_widget w;
  //tianli::uninstall_widget w;


  w.show();

  return a.exec();
}

int main_quiet_install(int argc, char* argv[]) {
  std::vector<std::string> args;
  for (int i = 0; i < argc; ++i) {
    args.push_back(argv[i]);
  }
  return print(args);
}

int main_help() {
  std::vector<std::string> arg = {
          "Usage: ",
          "  -h, --help                 --展开帮助列表",
          "  -v, --version              --显示版本号",
          "  -w, --window               --启动安装器，智能判断类型", 
          "  -wi, --window --install    --启动安装器，安装模式",
          "  -wu, --window --upgrade    --启动安装器，升级模式",
          "  -wr, --window --remove     --启动安装器，卸载模式"
          "  -q, --quiet                --退出"
  };
  print(arg);
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
  if (arg == "-w" || arg == "--window") {
    return main_window(argc, argv);
  }
  if (arg == "-q" || arg == "--quiet") {
    return main_quiet_install(argc, argv);
  }
  return 0;

}