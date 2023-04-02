#pragma once
using std::wstring;
namespace fs = std::filesystem;

class config
{
public:
  typedef struct RegInfo {
    wstring displayName=L"空荧酒馆原神地图";
    wstring displayVersion=L"Beta3.5";
    wstring publisher=L"空荧酒馆";
    wstring displayIcon=L"Map.exe";
    wstring uninstallString=L"Uninstall.exe";
    wstring InstallLocation = L"";        //自动配置，留空
    DWORD estimatedSize = 342016;
  } RegInfo;

  typedef struct InstallInfo{
    wstring defaultInstallPath = L"C:\\Program Files\\KongYingMap";

    bool desktopShortcut = true;
    wstring desktopShortcut_name = L"空荧酒馆原神地图.lnk";
    bool startmenuShortcut = true;
    wstring startmenuShortcut_foldname = L"空荧酒馆原神地图";
    wstring startmenuShortcut_progarmName = L"启动地图.lnk";
    wstring startmenuShortcut_uninstallName = L"卸载.lnk";

    wstring exePath = L"Map.exe";
    //放置用来覆盖安装检测的文件名(夹)，同时检测到文件存在则采取覆盖安装策略
    std::vector<wstring> existFileName = { L"Map.exe" ,L"UnityCrashHandler64.exe",L"UnityPlayer.dll"};    
  } InstallInfo;

public:
  static RegInfo reginfo;
  static InstallInfo installInfo;
};


inline config::RegInfo config::reginfo;
inline config::InstallInfo config::installInfo;