#include "pch.h"
#include "installThread.h"
#include "config.h"

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
      this->totalSize += fs::file_size(inPath) / 1024;
      emit this->processPercent(min(this->totalSize / static_cast<float>(config::reginfo.estimatedSize), 1) * 100);
      fs::remove(outPath);  //�Է���һ����ɾ�ٸ���
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


//�ڶ�����д��ע���
inline void InstallThread::writeReg()
{
  HKEY key;
  config::reginfo.InstallLocation = this->installPathStr.toStdWString();
   //���� HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall �µ�����
  if (RegCreateKeyEx(HKEY_LOCAL_MACHINE, std::format(L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Uninstall\\{0}", config::reginfo.displayName).c_str(),
    0, NULL, REG_OPTION_NON_VOLATILE, KEY_ALL_ACCESS, NULL, &key, NULL) == ERROR_SUCCESS)
    this->createUninstallInfoReg(key);
}

inline void InstallThread::createUninstallInfoReg(HKEY& key) {

  {
    // ���ֵ
    RegSetValueEx(key, L"DisplayName", 0, REG_SZ, (BYTE*)config::reginfo.displayName.c_str(), config::reginfo.displayName.length() * 2 + 2);
    msleep(100); emit this->processPercent(14);
    RegSetValueEx(key, L"DisplayVersion", 0, REG_SZ, (BYTE*)config::reginfo.displayVersion.c_str(), config::reginfo.displayVersion.length() * 2 + 2);
    msleep(100); emit this->processPercent(28);
    RegSetValueEx(key, L"UninstallString", 0, REG_SZ, (BYTE*)config::reginfo.uninstallString.c_str(), config::reginfo.uninstallString.length() * 2 + 2);
    msleep(100); emit this->processPercent(42);
    RegSetValueEx(key, L"Publisher", 0, REG_SZ, (BYTE*)config::reginfo.publisher.c_str(), config::reginfo.publisher.length() * 2 + 2);
    msleep(100); emit this->processPercent(57);
    RegSetValueEx(key, L"InstallLocation", 0, REG_SZ, (BYTE*)config::reginfo.InstallLocation.c_str(), config::reginfo.InstallLocation.length() * 2 + 2);
    msleep(100); emit this->processPercent(72);
    RegSetValueEx(key, L"DisplayIcon", 0, REG_SZ, (BYTE*)config::reginfo.displayIcon.c_str(), config::reginfo.displayIcon.length() * 2 + 2);
    msleep(100); emit this->processPercent(86);
    RegSetValueEx(key, L"EstimatedSize", 0, REG_DWORD, (BYTE*)config::reginfo.estimatedSize, sizeof(DWORD));
    msleep(100); emit this->processPercent(100);
    RegCloseKey(key);
  }
}

//��������������ʼ�˵��������ݷ�ʽ
inline void InstallThread::addShortCut()
{
  //�ļ�·��
  QString exePath = this->installPathStr + "\\" + QString::fromStdWString(config::installInfo.exePath);
  QString uninstallExePath = this->installPathStr + "\\" + QString::fromStdWString(config::reginfo.uninstallString);
  QString desktopShortcutPath = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation) + "\\" + QString::fromStdWString(config::installInfo.desktopShortcut_name);

  QString startMenuFolderPath = QStandardPaths::writableLocation(QStandardPaths::ApplicationsLocation) + "\\" + QString::fromStdWString(config::installInfo.startmenuShortcut_foldername);
  QString startMenuShortcutPath = startMenuFolderPath + "\\" + QString::fromStdWString(config::installInfo.startmenuShortcut_progarmName);
  QString startMenuUninstallShortcutPath = startMenuFolderPath +"\\" + QString::fromStdWString(config::installInfo.startmenuShortcut_uninstallName);

  //���������ݷ�ʽ
  if (this->desktopShortcut)
    createShortCut(exePath, desktopShortcutPath);
  msleep(100); emit this->processPercent(25);
  // ������ʼ�˵��ļ��У�����ж���򵼵Ŀ�ݷ�ʽ
  if (this->startMenuShortcut)
  {
    if (!fs::exists(startMenuShortcutPath.toStdWString()))
      fs::create_directory(startMenuFolderPath.toStdWString());
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

  // ����IShellLink����
  IShellLink* pShellLink = NULL;
  hres = CoCreateInstance(CLSID_ShellLink, NULL, CLSCTX_INPROC_SERVER, IID_IShellLinkW, (LPVOID*)&pShellLink);

  // ���ÿ�ݷ�ʽ·��������
  pShellLink->SetPath(exePath.toStdWString().c_str());

  // ����IPersistFile����
  IPersistFile* pPersistFile = NULL;
  hres = pShellLink->QueryInterface(IID_IPersistFile, (LPVOID*)&pPersistFile);

  // �����ݷ�ʽ
  hres = pPersistFile->Save(lnkPath.toStdWString().c_str(), TRUE);

  // �ͷŶ���
  pPersistFile->Release();
  pShellLink->Release();
  CoUninitialize();
}

//���Ĳ������ղ����ļ�
inline void InstallThread::cleanCache()
{
  std::error_code ec;
  uintmax_t removed_count = 0;
  fs::_Remove_all_dir(L"./package",ec,removed_count);
}

inline void InstallThread::run()
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
    //this->cleanCache();
    msleep(500);

    emit this->installFinish(true);
  }
  catch (std::exception e)
  {
    emit this->throwError(QString::fromLocal8Bit(e.what()));
  }
}