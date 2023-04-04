#pragma once
#include <pch.h>

namespace tianliWidgetUtils {
  bool checkPathIsAvilable(QString pathStr, QString& outPathStr);
  void setFont(const QString& fontPath, QWidget* widget, bool isBold = false);
  void cleanUninstallReg();
}