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
  //���㲽����ȡע���
  void readReg();
  //��һ�������ע���
  void eraserReg();
  //�ڶ�����ɾ����ݷ�ʽ
  void removeShortcut();
  //��������ɾ���ļ�
  void removeProgram();
  void removeTree(fs::path path);

  //���Ĳ���ɾ���û�����
  void removeUserData();

private:
  void run() Q_DECL_OVERRIDE;
};
