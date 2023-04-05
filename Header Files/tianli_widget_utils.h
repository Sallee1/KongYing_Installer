#pragma once
#include <pch.h>

namespace tianliWidgetUtils {
  bool checkPathIsAvilable(QString pathStr, QString& outPathStr);
  void setFont(const QString& fontPath, QWidget* widget, bool isBold = false);

  void cleanUninstallReg();
  bool getRegValue_REG_SZ(HKEY root, std::wstring Item, std::wstring Key, std::wstring& ret, int maxLength = 4096);
  bool getRegValue_DWORD(HKEY root, std::wstring Item, std::wstring Key, int& ret);
}