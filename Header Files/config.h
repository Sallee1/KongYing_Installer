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
    wstring displayIcon=L"map.exe";
    wstring uninstallString=L"Uninstall.exe";
    DWORD estimatedSize = 342016;
  } RegInfo;

  typedef struct InstallInfo{
    wstring installPath;
    bool desktopShortcut;
    bool startmenuShortcut;

    wstring exePath = L"map.exe";
    //放置用来覆盖安装检测的文件名(夹)，同时检测到文件存在则采取覆盖安装策略
    std::vector<wstring> existFileName = { L"map.exe" ,L"UnityCrashHandler64.exe",L"UnityPlayer.dll"};    
  } InstallInfo;

public:
  static RegInfo reginfo;
  static InstallInfo installInfo;
};


config::RegInfo config::reginfo;
config::InstallInfo config::installInfo;