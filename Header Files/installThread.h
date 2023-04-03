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
  //第一步，移动文件
  void copyFiles();
  void copyTrees(fs::path inPath, fs::path outPath);
  //第二步，写入注册表
  void writeReg();
  void createUninstallInfoReg(HKEY &key);
  //第三步，创建开始菜单和桌面快捷方式
  void addShortCut();
  void createShortCut(QString exePath, QString lnkPath);
  //第四步，回收残留文件
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

