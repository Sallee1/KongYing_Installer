#pragma once
#include "thread_super.h"
#include "pch.h"

namespace fs = std::filesystem;

class Uninstall_thread :public Thread_super {
public:
  enum ProcessType {
    ERASER_REG, REMOVE_SHORTCUT,REMOVE_FILES,REMOVE_DATA
  };

private:
  uintmax_t totalSize = 0;
  //第零步，读取注册表
  void readReg();
  //第一步，清空注册表
  void eraserReg();
  //第二步，删除快捷方式
  void removeShortcut();
  //第三步，删除文件
  void removeProgram();
  void removeTree(fs::path path);

  //第四步，删除用户数据
  void removeUserData();

private:
  void run() Q_DECL_OVERRIDE;
};
