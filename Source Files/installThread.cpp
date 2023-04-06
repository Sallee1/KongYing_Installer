#include "pch.h"
#include "installThread.h"
#include "config.h"

inline void InstallThread::copyFiles()
{
  fs::path installPath = installPathStr.toStdString();
  fs::path sourcePath = "./package";
  copyTrees(sourcePath, installPath);
}

inline void InstallThread::copyTrees(fs::path inPath, fs::path outPath)
{
  if (fs::is_regular_file(inPath))
  {
    this->totalSize += fs::file_size(inPath) / 1024;
    emit this->processPercent(min(this->totalSize / static_cast<float>(tianli::config::reginfo.estimatedSize), 1) * 100);
    fs::remove(outPath);  //以防万一，先删再复制
    fs::copy_file(inPath, outPath, fs::copy_options::overwrite_existing);
  }
  else
  {
    if (!fs::exists(outPath))
      fs::create_directories(outPath);
    bool inPathIsExist = fs::exists(inPath);
    for (fs::directory_entry entry : fs::directory_iterator(inPath))
    {
      fs::path inSubPath = entry.path();
      fs::path outSubPath = std::format("{0}\\{1}", outPath.string(), entry.path().filename().string());
      copyTrees(inSubPath, outSubPath);
    }
  }
}


//第二步，写入注册表
inline void InstallThread::writeReg()
{
  HKEY key;
  tianli::config::reginfo.InstallLocation = this->installPathStr.toStdString();
  //创建 HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall 下的子项
  if (RegCreateKeyEx(HKEY_LOCAL_MACHINE, std::format("SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Uninstall\\{0}", tianli::config::reginfo.displayName).c_str(),
    0, NULL, REG_OPTION_NON_VOLATILE, KEY_ALL_ACCESS, NULL, &key, NULL) == ERROR_SUCCESS)
    this->createUninstallInfoReg(key);
}

inline void InstallThread::createUninstallInfoReg(HKEY& key) {

  {
    // 添加值
    RegSetValueEx(key, "DisplayName", 0, REG_SZ, (BYTE*)tianli::config::reginfo.displayName.c_str(), tianli::config::reginfo.displayName.length() * 2 + 2);
    msleep(100); emit this->processPercent(12);
    RegSetValueEx(key, "DisplayVersion", 0, REG_SZ, (BYTE*)tianli::config::reginfo.displayVersion.c_str(), tianli::config::reginfo.displayVersion.length() * 2 + 2);
    msleep(100); emit this->processPercent(25);
    std::string uninstallerLocation = std::format("{0}\\{1}", this->installPathStr.toStdString(), tianli::config::reginfo.uninstallString);
    RegSetValueEx(key, "UninstallString", 0, REG_SZ, (BYTE*)uninstallerLocation.c_str(), uninstallerLocation.length() * 2 + 2);
    msleep(100); emit this->processPercent(38);
    RegSetValueEx(key, "Publisher", 0, REG_SZ, (BYTE*)tianli::config::reginfo.publisher.c_str(), tianli::config::reginfo.publisher.length() * 2 + 2);
    msleep(100); emit this->processPercent(50);
    RegSetValueEx(key, "InstallLocation", 0, REG_SZ, (BYTE*)tianli::config::reginfo.InstallLocation.c_str(), tianli::config::reginfo.InstallLocation.length() * 2 + 2);
    msleep(100); emit this->processPercent(63);
    RegSetValueEx(key, "UserDataLocation", 0, REG_SZ, (BYTE*)tianli::config::reginfo.UserDataLocation.c_str(), tianli::config::reginfo.UserDataLocation.length() * 2 + 2);
    msleep(100); emit this->processPercent(75);
    std::string DisplayIcon = std::format("{0}\\{1}", this->installPathStr.toStdString(), tianli::config::reginfo.displayIcon);
    msleep(100); emit this->processPercent(88);
    RegSetValueEx(key, "EstimatedSize", 0, REG_DWORD, (BYTE*)&tianli::config::reginfo.estimatedSize, sizeof(DWORD));
    msleep(100); emit this->processPercent(100);
    RegCloseKey(key);
  }
}

//第三步，创建开始菜单和桌面快捷方式
inline void InstallThread::addShortCut()
{
  //文件路径
  QString exePath = this->installPathStr + "\\" + QString::fromStdString(tianli::config::installInfo.exePath);
  QString uninstallExePath = this->installPathStr + "\\" + QString::fromStdString(tianli::config::reginfo.uninstallString);
  QString desktopShortcutPath = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation) + "\\" + QString::fromStdString(tianli::config::installInfo.desktopShortcut_name);

  QString startMenuFolderPath = QStandardPaths::writableLocation(QStandardPaths::ApplicationsLocation) + "\\" + QString::fromStdString(tianli::config::installInfo.startmenuShortcut_foldername);
  QString startMenuShortcutPath = startMenuFolderPath + "\\" + QString::fromStdString(tianli::config::installInfo.startmenuShortcut_progarmName);
  QString startMenuUninstallShortcutPath = startMenuFolderPath + "\\" + QString::fromStdString(tianli::config::installInfo.startmenuShortcut_uninstallName);

  //创建桌面快捷方式
  if (this->desktopShortcut)
    createShortCut(exePath, desktopShortcutPath);
  msleep(100); emit this->processPercent(25);
  // 创建开始菜单文件夹，包含卸载向导的快捷方式
  if (this->startMenuShortcut)
  {
    if (!fs::exists(startMenuShortcutPath.toStdString()))
      fs::create_directory(startMenuFolderPath.toStdString());
    msleep(100); emit this->processPercent(50);
    createShortCut(exePath, startMenuShortcutPath);
    msleep(100);  emit this->processPercent(75);
    createShortCut(uninstallExePath, startMenuUninstallShortcutPath);
  }
  msleep(100); emit this->processPercent(100);
}

void InstallThread::createShortCut(QString exePath, QString lnkPath)
{
  HRESULT hres;
  CoInitialize(NULL);

  // 创建IShellLink对象
  IShellLink* pShellLink = NULL;
  hres = CoCreateInstance(CLSID_ShellLink, NULL, CLSCTX_INPROC_SERVER, IID_IShellLinkW, (LPVOID*)&pShellLink);

  // 设置快捷方式路径和名称
  pShellLink->SetPath(exePath.toStdString().c_str());

  // 创建IPersistFile对象
  IPersistFile* pPersistFile = NULL;
  hres = pShellLink->QueryInterface(IID_IPersistFile, (LPVOID*)&pPersistFile);

  // 保存快捷方式
  hres = pPersistFile->Save(lnkPath.toStdWString().c_str(), TRUE);

  // 释放对象
  pPersistFile->Release();
  pShellLink->Release();
  CoUninitialize();
}

//第四步，回收残留文件
inline void InstallThread::cleanCache()
{
  std::error_code ec;
  uintmax_t removed_count = 0;
  //fs::_Remove_all_dir("./package",ec,removed_count); //能用
  msleep(100); emit this->processPercent(75);

  //创建一个bat，用来将安装卸载二合一向导复制到安装目录
  //自己无法复制自己！！！只能在执行后用bat复制
  fs::path installerLocation = QDir::toNativeSeparators(QCoreApplication::applicationFilePath()).toStdString().c_str();
  fs::path uninstallerLocation = std::format("{0}\\{1}", this->installPathStr.toStdString(), tianli::config::reginfo.uninstallString);
  QFile cloneBat("cloneInstaller.bat");
  cloneBat.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate);
  {
    QTextStream qOut(&cloneBat);
    qOut << QString::fromStdString("TIMEOUT /T 3") << endl;
    qOut << QString::fromStdString(std::format("move \"{0}\" \"{1}\"", installerLocation.string(), uninstallerLocation.string())) << endl;
  }
  cloneBat.close();
  msleep(100); emit this->processPercent(100);
}

void InstallThread::run()
{
  try {
    emit this->processChange(InstallThread::ProcessType::MOVE_FILES);
    emit this->processPercent(0);
    this->copyFiles(); msleep(500);

    emit this->processChange(InstallThread::ProcessType::WRITE_REG);
    emit this->processPercent(0);
    this->writeReg(); msleep(500);

    emit this->processChange(InstallThread::ProcessType::ADD_SHORTCUT);
    emit this->processPercent(0);
    this->addShortCut(); msleep(500);

    emit this->processChange(InstallThread::ProcessType::CLEAN_CACHE);
    emit this->processPercent(0);
    this->cleanCache(); msleep(500);

    emit this->processFinish(true);
  }
  catch (std::exception e)
  {
    emit this->throwError(QString::fromLocal8Bit(e.what()));
  }
}