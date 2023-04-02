#include "pch.h"
#include "installThread.h"

InstallThread::InstallThread(QThread* parent) :
  installPathStr(QString::fromLocal8Bit("C:/Program Files/KongYingMap")), desktopShortcut(true), startMenuShortcut(true) {}
;

inline void InstallThread::copyFiles()
{
  fs::path installPath = installPathStr.toStdWString();
  fs::path sourcePath = L"./package";
  copyTrees(sourcePath, installPath);
}

inline void InstallThread::copyTrees(fs::path inPath, fs::path outPath)
{
  if (fs::is_regular_file(inPath))
  {
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
      fs::path outSubPath = std::format("{0}/{1}", outPath.string(), entry.path().filename().string());
      copyTrees(inSubPath, outSubPath);
    }
  }
}


//第二步，写入注册表
inline void InstallThread::writeReg()
{
  HKEY key;
  InstallThread::UninstallInfo uninstallInfo(
    L"空荧酒馆原神地图",                                                           // 软件名称
    this->installPathStr.toStdWString() + L"\\map.exe",                         // 图标
    L"1.0.0",                                                                   // 版本
    std::format(L"{0}\\uninstall.exe", this->installPathStr.toStdWString()),    // 卸载命令
    L"空荧酒馆",                                                                  // 发布者
    this->installPathStr.toStdWString(),                                        // 安装路径
    1024                                                                        // 预估大小
  );
  // 创建 HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall 下的子项
  if (RegCreateKeyEx(HKEY_LOCAL_MACHINE, std::format(L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Uninstall\\{0}", uninstallInfo.DisplayName).c_str(),
    0, NULL, REG_OPTION_NON_VOLATILE, KEY_ALL_ACCESS, NULL, &key, NULL) == ERROR_SUCCESS)
    this->createUninstallInfoReg(key, uninstallInfo);
}

inline void InstallThread::createUninstallInfoReg(HKEY& key, struct InstallThread::UninstallInfo uninstallInfo) {

  {
    // 添加值
    RegSetValueEx(key, L"DisplayName", 0, REG_SZ, (BYTE*)uninstallInfo.DisplayName.c_str(), uninstallInfo.DisplayName.length() * 2 + 2);
    msleep(550); emit this->processPercent(14);
    RegSetValueEx(key, L"DisplayVersion", 0, REG_SZ, (BYTE*)uninstallInfo.DisplayVersion.c_str(), uninstallInfo.DisplayVersion.length() * 2 + 2);
    msleep(550); emit this->processPercent(28);
    RegSetValueEx(key, L"UninstallString", 0, REG_SZ, (BYTE*)uninstallInfo.UninstallString.c_str(), uninstallInfo.UninstallString.length() * 2 + 2);
    msleep(550); emit this->processPercent(42);
    RegSetValueEx(key, L"Publisher", 0, REG_SZ, (BYTE*)uninstallInfo.Publisher.c_str(), uninstallInfo.Publisher.length() * 2 + 2);
    msleep(550); emit this->processPercent(57);
    RegSetValueEx(key, L"InstallLocation", 0, REG_SZ, (BYTE*)uninstallInfo.InstallLocation.c_str(), uninstallInfo.InstallLocation.length() * 2 + 2);
    msleep(550); emit this->processPercent(72);
    RegSetValueEx(key, L"DisplayIcon", 0, REG_SZ, (BYTE*)uninstallInfo.DisplayIcon.c_str(), uninstallInfo.DisplayIcon.length() * 2 + 2);
    msleep(550); emit this->processPercent(86);
    RegSetValueEx(key, L"EstimatedSize", 0, REG_DWORD, (BYTE*)uninstallInfo.EstimateSize, sizeof(DWORD));
    msleep(550); emit this->processPercent(100);
    RegCloseKey(key);
  }
}

//第三步，创建开始菜单和桌面快捷方式
inline void InstallThread::addShortCut()
{
  //文件路径
  QString exePath = this->installPathStr + QString::fromLocal8Bit("\\map.exe");
  QString uninstallExePath = this->installPathStr + QString::fromLocal8Bit("\\uninstall.exe");
  QString desktopShortcutPath = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation) + QString::fromLocal8Bit("\\空荧酒馆原神地图.lnk");

  QString startMenuFolderPath = QStandardPaths::writableLocation(QStandardPaths::ApplicationsLocation) + QString::fromLocal8Bit("\\空荧酒馆原神地图");
  QString startMenuShortcutPath = startMenuFolderPath + QString::fromLocal8Bit("\\启动地图.lnk");
  QString startMenuUninstallShortcutPath = startMenuFolderPath + QString::fromLocal8Bit("\\卸载.lnk");

  //创建桌面快捷方式
  if (this->desktopShortcut)
    createShortCut(exePath, desktopShortcutPath);
  msleep(550); emit this->processPercent(25);
  // 创建开始菜单文件夹，包含卸载向导的快捷方式
  if (this->startMenuShortcut)
  {
    if (!fs::exists(startMenuShortcutPath.toStdWString()))
      fs::create_directory(startMenuFolderPath.toStdWString());
    msleep(550); emit this->processPercent(50);
    createShortCut(exePath, startMenuShortcutPath);
    msleep(550);  emit this->processPercent(75);
    createShortCut(uninstallExePath, startMenuUninstallShortcutPath);
  }    
  msleep(550); emit this->processPercent(100);
}

void InstallThread::createShortCut(QString exePath, QString lnkPath)
{
  HRESULT hres;
  CoInitialize(NULL);

  // 创建IShellLink对象
  IShellLink* pShellLink = NULL;
  hres = CoCreateInstance(CLSID_ShellLink, NULL, CLSCTX_INPROC_SERVER, IID_IShellLinkW, (LPVOID*)&pShellLink);

  // 设置快捷方式路径和名称
  pShellLink->SetPath(exePath.toStdWString().c_str());

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
  fs::_Remove_all_dir(L"./package",ec,removed_count);
}

inline void InstallThread::run()
{
  emit this->processChange(InstallThread::ProcessType::MOVE_FILES);
  emit this->processPercent(0);
  this->copyFiles();msleep(500);

  emit this->processChange(InstallThread::ProcessType::WRITE_REG);
  emit this->processPercent(0);
  this->writeReg(); msleep(500);

  emit this->processChange(InstallThread::ProcessType::ADD_SHORTCUT);
  emit this->processPercent(0);
  this->addShortCut(); msleep(500);

  emit this->processChange(InstallThread::ProcessType::CLEAN_CACHE);
  emit this->processPercent(0);
  //this->cleanCache();
  msleep(500);

  emit this->installFinish(true);
}