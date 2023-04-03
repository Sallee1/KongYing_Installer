#pragma once
#include <pch.h>

namespace fs = std::filesystem;
using std::wstring;

class InstallThread :public QThread
{
  Q_OBJECT
public:
  InstallThread(QThread* parent = nullptr);
public slots:
  void setInstallConfig(QString installPathStr, bool desktopShortcut, bool startMenuShortcut)
  {
    this->installPathStr = installPathStr;
    this->desktopShortcut = desktopShortcut;
    this->startMenuShortcut = startMenuShortcut;
  }

public:
  enum ProcessType {
    MOVE_FILES, WRITE_REG, ADD_SHORTCUT, CLEAN_CACHE
  };

private:
  //��һ�����ƶ��ļ�
  void copyFiles();
  void copyTrees(fs::path inPath, fs::path outPath);
  //�ڶ�����д��ע���
  void writeReg();
  void createUninstallInfoReg(HKEY &key);
  //��������������ʼ�˵��������ݷ�ʽ
  void addShortCut();
  void createShortCut(QString exePath, QString lnkPath);
  //���Ĳ������ղ����ļ�
  void cleanCache();
signals:
  void processChange(int step);
  void processPercent(int percent);
  void installFinish(bool isSuccess);
  void throwError(QString error);

private:
  void run() override;

private:
  QString installPathStr;
  bool desktopShortcut;
  bool startMenuShortcut;
};

