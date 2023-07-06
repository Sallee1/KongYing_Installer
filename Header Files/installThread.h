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
  //第一步，移动文件
  void copyFiles();
  void copyTrees(fs::path inPath, fs::path outPath);
  //第二步，写入注册表
  void writeReg();
  void createUninstallInfoReg(HKEY& key);
  //第三步，创建开始菜单和桌面快捷方式
  void addShortCut();
  void createShortCut(std::string exePath, std::string lnkPath);
  //第四步，回收残留文件
  void cleanCache();

private:
  void run() Q_DECL_OVERRIDE;
};

