#pragma once
#include <pch.h> 

namespace tianliUtils {
  bool checkPathIsAvilable(QString pathStr, QString& outPathStr);
  void setFont(const QString& fontPath, QWidget* widget, bool isBold = false);

  void cleanUninstallReg();
  bool getRegValue_REG_SZ(HKEY root, std::string Item, std::string Key, std::string& ret, int maxLength = 4096);
  bool getRegValue_DWORD(HKEY root, std::string Item, std::string Key, int& ret);
  std::string envPath2AbsolutePath(std::string envPath);
}