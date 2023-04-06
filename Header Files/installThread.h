#pragma once
#include <pch.h>
#include "thread_super.h"

namespace fs = std::filesystem;
using std::string;

class InstallThread :public Thread_super
{
  Q_OBJECT

public:
  enum ProcessType {
    MOVE_FILES, WRITE_REG, ADD_SHORTCUT, CLEAN_CACHE
  };

private:
  uintmax_t totalSize = 0;
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

private:
  void run() Q_DECL_OVERRIDE;
};

