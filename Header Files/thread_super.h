#pragma once
#include <pch.h> 

class Thread_super :public QThread
{
  Q_OBJECT
public:
  Thread_super(QThread* parent = nullptr);

public slots:
  void setInstallConfig(QString installPathStr, bool desktopShortcut, bool startMenuShortcut)
  {
    this->installPathStr = std::wstring(installPathStr.toStdWString());
    this->desktopShortcut = desktopShortcut;
    this->startMenuShortcut = startMenuShortcut;
  }

signals:
  void processChange(int step);
  void processPercent(int percent);
  void processFinish(bool isSuccess);
  void throwError(QString error);

protected:
  uintmax_t totalSize = 0;  //用来计算进度条
  std::wstring installPathStr;
  bool desktopShortcut;
  bool startMenuShortcut;

  virtual void run() Q_DECL_OVERRIDE {};
};

