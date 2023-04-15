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

      string URLInfoAbout = "https://yuanshen.site/docs/";
      string HelpLink = "https://support.qq.com/products/321980/faqs/94938";
      string URLUpdateInfo = "https://support.qq.com/products/321980/blog/505884";
      DWORD estimatedSize = 342016;         //预估大小，影响到控制面板中显示的程序大小以及安装过程的进度条
    } RegInfo;

    typedef struct InstallInfo {
      string defaultInstallPath = "C:\\Program Files\\KongYingMap";

      bool desktopShortcut = true;
      string desktopShortcut_name = "空荧酒馆原神地图.lnk";
      bool startmenuShortcut = true;
      string startmenuShortcut_foldername = "空荧酒馆原神地图";
      string startmenuShortcut_programName = "启动地图.lnk";
      string startmenuShortcut_uninstallName = "卸载.lnk";

      string exePath = "Map.exe";
      //放置用来覆盖安装检测的文件名(夹)，同时检测到文件存在则采取覆盖安装策略（不创建子文件夹）
      std::vector<string> existFileName = { "Map.exe" ,"UnityCrashHandler64.exe","UnityPlayer.dll" };
    } InstallInfo;

  public:
    static RegInfo reginfo;
    static InstallInfo installInfo;
    //从json文件读取配置
  public:
    static QJsonParseError readconfigFromJson(fs::path path)
    {
      QFile jsonFile(QString::fromLocal8Bit(path.string().c_str()));
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
      QJsonObject regInfo_obj = super_obj.value("RegInfo").toObject();
      QJsonObject InstallerGlobal_obj = super_obj.value("InstallerGlobal").toObject();

      tianli::config::reginfo.displayName = std::string(regInfo_obj.value("displayName").toString().toLocal8Bit());
      tianli::config::reginfo.displayVersion = std::string(regInfo_obj.value("displayVersion").toString().toLocal8Bit());
      tianli::config::reginfo.publisher = std::string(regInfo_obj.value("publisher").toString().toLocal8Bit());
      tianli::config::reginfo.displayIcon = std::string(regInfo_obj.value("displayIcon").toString().toLocal8Bit());
      tianli::config::reginfo.uninstallString = std::string(regInfo_obj.value("uninstallString").toString().toLocal8Bit());
      tianli::config::reginfo.UserDataLocation = std::string(regInfo_obj.value("UserDataLocation").toString().toLocal8Bit());
      tianli::config::reginfo.displayIcon = std::string(regInfo_obj.value("displayIcon").toString().toLocal8Bit());
      tianli::config::reginfo.URLInfoAbout = std::string(regInfo_obj.value("URLInfoAbout").toString().toLocal8Bit());
      tianli::config::reginfo.HelpLink = std::string(regInfo_obj.value("HelpLink").toString().toLocal8Bit());
      tianli::config::reginfo.URLUpdateInfo = std::string(regInfo_obj.value("URLUpdateInfo").toString().toLocal8Bit());
      tianli::config::reginfo.estimatedSize = regInfo_obj.value("estimatedSize").toInt();

      tianli::config::installInfo.defaultInstallPath = std::string(InstallerGlobal_obj.value("defaultInstallPath").toString().toLocal8Bit());
      tianli::config::installInfo.desktopShortcut = InstallerGlobal_obj.value("desktopShortcut").toBool();
      tianli::config::installInfo.desktopShortcut_name = std::string(InstallerGlobal_obj.value("desktopShortcut_name").toString().toLocal8Bit());
      tianli::config::installInfo.startmenuShortcut = InstallerGlobal_obj.value("startmenuShortcut").toBool(); ;
      tianli::config::installInfo.startmenuShortcut_foldername = std::string(InstallerGlobal_obj.value("startmenuShortcut_foldername").toString().toLocal8Bit());
      tianli::config::installInfo.startmenuShortcut_programName = std::string(InstallerGlobal_obj.value("startmenuShortcut_programName").toString().toLocal8Bit());
      tianli::config::installInfo.startmenuShortcut_uninstallName = std::string(InstallerGlobal_obj.value("startmenuShortcut_uninstallName").toString().toLocal8Bit());
      tianli::config::installInfo.exePath = std::string(InstallerGlobal_obj.value("exePath").toString().toLocal8Bit());

      QJsonArray existFileName_array = InstallerGlobal_obj.value("existFileName").toArray();
      tianli::config::installInfo.existFileName = std::vector<std::string>();
      for (auto it : existFileName_array)
      {
        tianli::config::installInfo.existFileName.emplace_back(std::string(it.toString().toLocal8Bit()));
      }
      return QJsonParseError();
    }
  };


  namespace bat {
    inline std::string removeSelf =
      R"(@echo off
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