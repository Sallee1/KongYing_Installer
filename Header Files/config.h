#pragma once
using std::string;
namespace fs = std::filesystem;

namespace tianli {
  class config
  {
  public:
    typedef struct RegInfo {
      string displayName = "空荧酒馆原神地图";
      string displayVersion = "Beta3.5";
      string publisher = "空荧酒馆";
      string displayIcon = "Map.exe";
      string uninstallString = "Uninstall.exe";
      string InstallLocation = "";        //自动配置，留空
      string UserDataLocation = "%APPDATA%\\..\\LocalLow\\空荧酒馆";    //用户数据存储的位置
      DWORD estimatedSize = 342016;         //预估大小，影响到控制面板中显示的程序大小以及安装过程的进度条
    } RegInfo;

    typedef struct InstallInfo {
      string defaultInstallPath = "C:\\Program Files\\KongYingMap";

      bool desktopShortcut = true;
      string desktopShortcut_name = "空荧酒馆原神地图.lnk";
      bool startmenuShortcut = true;
      string startmenuShortcut_foldername = "空荧酒馆原神地图";
      string startmenuShortcut_progarmName = "启动地图.lnk";
      string startmenuShortcut_uninstallName = "卸载.lnk";

      string exePath = "Map.exe";
      //放置用来覆盖安装检测的文件名(夹)，同时检测到文件存在则采取覆盖安装策略（不创建子文件夹）
      std::vector<string> existFileName = { "Map.exe" ,"UnityCrashHandler64.exe","UnityPlayer.dll" };
    } InstallInfo;

  public:
    static RegInfo reginfo;
    static InstallInfo installInfo;
  };
}

inline tianli::config::RegInfo tianli::config::reginfo;
inline tianli::config::InstallInfo tianli::config::installInfo;