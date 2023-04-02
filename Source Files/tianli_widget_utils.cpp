#include "pch.h"
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
  //否则，放到子文件夹并检测，如果路径存在且非空，则无效
  outPathStr = pathStr + "/KongYingMap";
  folderPath = outPathStr.toStdWString();
  if (fs::exists(folderPath) && fs::directory_iterator(folderPath) != fs::directory_iterator())
  {
    return false;
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