#pragma once
#include <string>
#include <filesystem>

namespace fs = std::filesystem;

namespace tianli {
  class config
  {
  public:
    typedef struct RegInfo {
      std::wstring displayName = L"空荧酒馆原神地图";
      std::wstring displayVersion = L"Beta3.5";
      std::wstring publisher = L"空荧酒馆";
      std::wstring displayIcon = L"Map.exe";
      std::wstring uninstallString = L"Uninstall.exe";
      std::wstring InstallLocation = L"";        //自动配置，留空
      std::wstring UserDataLocation = L"%APPDATA%\\..\\LocalLow\\空荧酒馆";    //用户数据存储的位置

      std::wstring URLInfoAbout = L"https://yuanshen.site/docs/";
      std::wstring HelpLink = L"https://support.qq.com/products/321980/faqs/94938";
      std::wstring URLUpdateInfo = L"https://support.qq.com/products/321980/blog/505884";
      DWORD estimatedSize = 342016;         //预估大小，影响到控制面板中显示的程序大小以及安装过程的进度条
    } RegInfo;

    typedef struct InstallInfo {
      std::wstring defaultInstallPath = L"C:\\Program Files\\KongYingMap";

      bool desktopShortcut = true;
      std::wstring desktopShortcut_name = L"空荧酒馆原神地图.lnk";
      bool startmenuShortcut = true;
      std::wstring startmenuShortcut_foldername = L"空荧酒馆原神地图";
      std::wstring startmenuShortcut_programName = L"启动地图.lnk";
      std::wstring startmenuShortcut_uninstallName = L"卸载.lnk";

      std::wstring exePath = L"Map.exe";
      //放置用来覆盖安装检测的文件名(夹)，同时检测到文件存在则采取覆盖安装策略（不创建子文件夹）
      std::vector<std::wstring> existFileName = { L"Map.exe" ,L"UnityCrashHandler64.exe",L"UnityPlayer.dll" };
    } InstallInfo;

  public:
    static RegInfo reginfo;
    static InstallInfo installInfo;
    //从json文件读取配置
  public:
    static QJsonParseError readconfigFromJson(fs::path path)
    {
      QFile jsonFile(QString::fromStdWString(path.wstring()));
      QJsonDocument jsonDoc;
      jsonFile.open(QFile::ReadOnly | QFile::Text);
      {
        QTextStream in(&jsonFile);
        QString QJsonStr = in.readAll();
        QJsonParseError err;
        jsonDoc = QJsonDocument::fromJson(QJsonStr.toUtf8(), &err);
        if (err.error != QJsonParseError::NoError)
        {
          return err;
        }
      }
      jsonFile.close();

      QJsonObject super_obj = jsonDoc.object();
      QJsonObject regInfo_obj = super_obj.value(L"RegInfo").toObject();
      QJsonObject InstallerGlobal_obj = super_obj.value(L"InstallerGlobal").toObject();

      tianli::config::reginfo.displayName = std::wstring(regInfo_obj.value(L"displayName").toString().toStdWString());
      tianli::config::reginfo.displayVersion = std::wstring(regInfo_obj.value(L"displayVersion").toString().toStdWString());
      tianli::config::reginfo.publisher = std::wstring(regInfo_obj.value(L"publisher").toString().toStdWString());
      tianli::config::reginfo.displayIcon = std::wstring(regInfo_obj.value(L"displayIcon").toString().toStdWString());
      tianli::config::reginfo.uninstallString = std::wstring(regInfo_obj.value(L"uninstallString").toString().toStdWString());
      tianli::config::reginfo.UserDataLocation = std::wstring(regInfo_obj.value(L"UserDataLocation").toString().toStdWString());
      tianli::config::reginfo.displayIcon = std::wstring(regInfo_obj.value(L"displayIcon").toString().toStdWString());
      tianli::config::reginfo.URLInfoAbout = std::wstring(regInfo_obj.value(L"URLInfoAbout").toString().toStdWString());
      tianli::config::reginfo.HelpLink = std::wstring(regInfo_obj.value(L"HelpLink").toString().toStdWString());
      tianli::config::reginfo.URLUpdateInfo = std::wstring(regInfo_obj.value(L"URLUpdateInfo").toString().toStdWString());
      tianli::config::reginfo.estimatedSize = regInfo_obj.value(L"estimatedSize").toInt();

      tianli::config::installInfo.defaultInstallPath = std::wstring(InstallerGlobal_obj.value(L"defaultInstallPath").toString().toStdWString());
      tianli::config::installInfo.desktopShortcut = InstallerGlobal_obj.value(L"desktopShortcut").toBool();
      tianli::config::installInfo.desktopShortcut_name = std::wstring(InstallerGlobal_obj.value(L"desktopShortcut_name").toString().toStdWString());
      tianli::config::installInfo.startmenuShortcut = InstallerGlobal_obj.value(L"startmenuShortcut").toBool(); ;
      tianli::config::installInfo.startmenuShortcut_foldername = std::wstring(InstallerGlobal_obj.value(L"startmenuShortcut_foldername").toString().toStdWString());
      tianli::config::installInfo.startmenuShortcut_programName = std::wstring(InstallerGlobal_obj.value(L"startmenuShortcut_programName").toString().toStdWString());
      tianli::config::installInfo.startmenuShortcut_uninstallName = std::wstring(InstallerGlobal_obj.value(L"startmenuShortcut_uninstallName").toString().toStdWString());
      tianli::config::installInfo.exePath = std::wstring(InstallerGlobal_obj.value(L"exePath").toString().toStdWString());

      QJsonArray existFileName_array = InstallerGlobal_obj.value(L"existFileName").toArray();
      tianli::config::installInfo.existFileName = std::vector<std::wstring>();
      for (auto it : existFileName_array)
      {
        tianli::config::installInfo.existFileName.emplace_back(std::wstring(it.toString().toStdWString()));
      }
      return QJsonParseError();
    }
  };


  namespace bat {
    inline std::wstring removeSelf =
      LR"(@echo off
setlocal enableextensions
set "folder=%~dp0"
timeout /t 10
cd /d "%SystemDrive%\"
rd /s /q "%folder%"
del %0)";
  };
}

inline tianli::config::RegInfo tianli::config::reginfo;
inline tianli::config::InstallInfo tianli::config::installInfo;