#include "pch.h"
#include "uninstall_thread.h"
#include "tianli_utils.h"
#include "config.h"

void Uninstall_thread::readReg()
{
  bool isSuccess;
  std::wstring installPath;
  std::wstring userDataPath;
  isSuccess = tianliUtils::getRegValue_REG_SZ(HKEY_LOCAL_MACHINE,
    std::format(L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Uninstall\\{0}", tianli::config::reginfo.displayName),
    L"InstallLocation",
    installPath);
  if (!isSuccess) throw std::exception("readReg: 读取InstallLocation失败，注册信息可能已经损坏");

  isSuccess = tianliUtils::getRegValue_REG_SZ(HKEY_LOCAL_MACHINE,
    std::format(L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Uninstall\\{0}", tianli::config::reginfo.displayName),
    L"UserDataLocation",
    userDataPath);
  if (!isSuccess) throw std::exception("readReg: 读取UserDataLocation失败，注册信息可能已经损坏");

  int EstimatedSize;
  isSuccess = tianliUtils::getRegValue_DWORD(HKEY_LOCAL_MACHINE,
    std::format(L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Uninstall\\{0}", tianli::config::reginfo.displayName),
    L"EstimatedSize",
    EstimatedSize);
  if (!isSuccess) throw std::exception("readReg: 读取EstimatedSize失败，注册信息可能已经损坏");

  tianli::config::reginfo.InstallLocation = installPath;
  tianli::config::reginfo.UserDataLocation = userDataPath;
  tianli::config::reginfo.uninstallString = std::wstring(QDir::toNativeSeparators(QCoreApplication::applicationFilePath()).toStdWString());

}

void Uninstall_thread::eraserReg()
{
  tianliUtils::cleanUninstallReg();
  msleep(100); emit this->processPercent(100);
}

void Uninstall_thread::removeShortcut()
{
  QString desktopShortcutPath = QDir::toNativeSeparators(QStandardPaths::writableLocation(QStandardPaths::DesktopLocation) + "\\" + QString::fromStdWString(tianli::config::installInfo.desktopShortcut_name));
  QString startMenuFolderPath = QDir::toNativeSeparators(QStandardPaths::writableLocation(QStandardPaths::ApplicationsLocation) + "\\" + QString::fromStdWString(tianli::config::installInfo.startmenuShortcut_foldername));

  //删除桌面快捷方式
  if (fs::exists(std::wstring(desktopShortcutPath.toStdWString())))
    fs::remove(std::wstring(desktopShortcutPath.toStdWString()));
  msleep(100); emit this->processPercent(25);

  //删除开始菜单快捷方式
  std::error_code ec;
  uintmax_t removed_count = 0;
  if (fs::exists(std::wstring(startMenuFolderPath.toStdWString())))
    fs::_Remove_all_dir(std::wstring(startMenuFolderPath.toStdWString()), ec, removed_count);
  msleep(100); emit this->processPercent(100);
}

void Uninstall_thread::removeProgram()
{
  fs::path installPath = tianli::config::reginfo.InstallLocation;
  for (fs::directory_entry entry : fs::directory_iterator(tianli::config::reginfo.InstallLocation))
  {
    fs::path inSubPath = entry.path();
    removeTree(inSubPath);
  }
}



void Uninstall_thread::removeTree(fs::path rmPath)
{
  if (fs::is_regular_file(rmPath))
  {
    if (rmPath == fs::path(tianli::config::reginfo.uninstallString))    //排除自己以免删除失败
      return;
    this->totalSize += fs::file_size(rmPath) / 1024;
    emit this->processPercent(min(this->totalSize / static_cast<float>(tianli::config::reginfo.estimatedSize), 1) * 100);
    fs::remove(rmPath);
  }
  else
  {
    bool inPathIsExist = fs::exists(rmPath);
    for (fs::directory_entry entry : fs::directory_iterator(rmPath))
    {
      fs::path inSubPath = entry.path();
      removeTree(inSubPath);
    }
    fs::remove(rmPath);
  }
}


void Uninstall_thread::removeUserData()
{
  std::wstring absoluteUserPath = tianliUtils::envPath2AbsolutePath(tianli::config::reginfo.UserDataLocation);

  std::error_code ec;
  uintmax_t removed_count = 0;
  if (fs::exists(absoluteUserPath))
    fs::_Remove_all_dir(absoluteUserPath, ec, removed_count);
  msleep(100); emit this->processPercent(100);
}

void Uninstall_thread::run()
{
  try {
    this->readReg();

    emit this->processChange(Uninstall_thread::ProcessType::ERASER_REG);
    emit this->processPercent(0);
    this->eraserReg(); msleep(500);

    emit this->processChange(Uninstall_thread::ProcessType::REMOVE_SHORTCUT);
    emit this->processPercent(0);
    this->removeShortcut(); msleep(500);

    emit this->processChange(Uninstall_thread::ProcessType::REMOVE_FILES);
    emit this->processPercent(0);
    this->removeProgram(); msleep(500);

    emit this->processChange(Uninstall_thread::ProcessType::REMOVE_DATA);
    emit this->processPercent(0);
    if (userData)
    {
      this->removeUserData(); msleep(500);
    }
    emit this->processFinish(true);
  }
  catch (std::exception e)
  {
    emit this->throwError(QString(e.what()));
  }
}