#include "pch.h"
#include "config.h"
#include "tianli_widget_utils.h"
#include "tianli_widget.h"

namespace fs = std::filesystem;

bool tianliWidgetUtils::checkPathIsAvilable(QString pathStr, QString& outPathStr)
{
  if (pathStr == "")return false;
  fs::path folderPath = pathStr.toStdWString();
  //文件夹不存在，路径有效
  if (!fs::exists(folderPath))
  {
    outPathStr = pathStr;
    return true;
  }
  //文件夹为空，则设定为有效路径
  if (fs::directory_iterator(folderPath) == fs::directory_iterator())
  {
    outPathStr = pathStr;
    return true;
  }
  //非空，覆盖安装检测
  bool isOverWrite = true;
  for (std::wstring fileName : config::installInfo.existFileName)
  {
    if (!fs::exists(std::format(L"{0}/{1}", pathStr.toStdWString(), fileName)))
    {
      isOverWrite = false;
      break;
    }
  }
  if (isOverWrite)
  {
    outPathStr = pathStr;
    return true;
  }

  //否则，放到子文件夹并检测，如果路径存在，并且非空，并且没有通过覆盖检测，则无效
  outPathStr = pathStr + "/KongYingMap";
  folderPath = outPathStr.toStdWString();
  if (fs::exists(folderPath) && fs::directory_iterator(folderPath) != fs::directory_iterator())
  {
    for (std::wstring fileName : config::installInfo.existFileName)
    {
      if (!fs::exists(std::format(L"{0}/{1}", folderPath.wstring(), fileName)))
      {
        return false;
      }
    }
    return true;
  }
  return true;
}

void tianliWidgetUtils:: setFont(const QString& fontPath, QWidget* widget, bool isBold) {
  // 加载字体文件
  int id = QFontDatabase::addApplicationFont(fontPath);
  if (id != -1) {
    // 获取字体家族
    QString family = QFontDatabase::applicationFontFamilies(id).at(0);
    // 设置字体
    QFont font(family);
    if (isBold)
      font.setBold(true);
    widget->setFont(font);
  }
}

void tianliWidgetUtils:: cleanUninstallReg()
{
  HKEY hKey;
  RegOpenKeyEx(HKEY_LOCAL_MACHINE, std::format(L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Uninstall\\{0}", config::reginfo.displayName).c_str(), 0, KEY_ALL_ACCESS, &hKey);
  RegDeleteTree(hKey, NULL);
  RegCloseKey(hKey);
  RegDeleteKey(HKEY_LOCAL_MACHINE, std::format(L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Uninstall\\{0}", config::reginfo.displayName).c_str());
}