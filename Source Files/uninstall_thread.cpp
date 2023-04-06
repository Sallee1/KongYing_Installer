#include "pch.h"
#include "uninstall_thread.h"
#include "tianli_widget_utils.h"
#include "config.h"

void Uninstall_thread::readReg()
{
  bool isSuccess;
  std::wstring installPath;
  std::wstring userDataPath;
  isSuccess=tianliUtils::getRegValue_REG_SZ(HKEY_LOCAL_MACHINE,
    std::format(L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Uninstall\\{0}", tianli::config::reginfo.displayName),
    L"InstallLocation",
    installPath);
  if (!isSuccess) throw std::exception("readReg: ��ȡInstallLocationʧ�ܣ�ע����Ϣ�����Ѿ���");

  isSuccess = tianliUtils::getRegValue_REG_SZ(HKEY_LOCAL_MACHINE,
    std::format(L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Uninstall\\{0}", tianli::config::reginfo.displayName),
    L"UserDataLocation",
    userDataPath);
  if (!isSuccess) throw std::exception("readReg: ��ȡUserDataLocationʧ�ܣ�ע����Ϣ�����Ѿ���");

  int EstimatedSize;
  isSuccess = tianliUtils::getRegValue_DWORD(HKEY_LOCAL_MACHINE,
    std::format(L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Uninstall\\{0}", tianli::config::reginfo.displayName),
    L"EstimatedSize",
    EstimatedSize);
  if (!isSuccess) throw std::exception("readReg: ��ȡEstimatedSizeʧ�ܣ�ע����Ϣ�����Ѿ���");

  tianli::config::reginfo.InstallLocation = installPath;
  tianli::config::reginfo.UserDataLocation = userDataPath;
  tianli::config::reginfo.uninstallString = QDir::toNativeSeparators(QCoreApplication::applicationFilePath()).toStdWString();
  
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

  //ɾ�������ݷ�ʽ
  if (fs::exists(desktopShortcutPath.toStdWString()))
    fs::remove(desktopShortcutPath.toStdWString());
  msleep(100); emit this->processPercent(25);

  //ɾ����ʼ�˵���ݷ�ʽ
  std::error_code ec;
  uintmax_t removed_count = 0;
  if (fs::exists(startMenuFolderPath.toStdWString()))
    fs::_Remove_all_dir(startMenuFolderPath.toStdWString(),ec,removed_count);
  msleep(100); emit this->processPercent(100);
}

void Uninstall_thread::removeProgram()
{
  fs::path installPath = tianli::config::reginfo.InstallLocation;
  removeTree(installPath);
}



void Uninstall_thread::removeTree(fs::path rmPath)
{
  if (fs::is_regular_file(rmPath))
  {
    if (rmPath == fs::path(tianli::config::reginfo.uninstallString))
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
  wstring absoluteUserPath = tianliUtils::envPath2AbsolutePath(tianli::config::reginfo.UserDataLocation);

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
    emit this->throwError(QString::fromLocal8Bit(e.what()));
  }
}