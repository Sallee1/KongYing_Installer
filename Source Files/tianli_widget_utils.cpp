#include "pch.h"
#include "tianli_widget_utils.h"
#include "tianli_widget.h"

namespace fs = std::filesystem;

bool tianliWidgetUtils::checkPathIsAvilable(QString pathStr, QString& outPathStr)
{
  if (pathStr == "")return false;
  fs::path folderPath = pathStr.toStdWString();
  //�ļ��в����ڣ�·����Ч
  if (!fs::exists(folderPath))
  {
    outPathStr = pathStr;
    return true;
  }
  //�ļ���Ϊ�գ����趨Ϊ��Ч·��
  if (fs::directory_iterator(folderPath) == fs::directory_iterator())
  {
    outPathStr = pathStr;
    return true;
  }
  //���򣬷ŵ����ļ��в���⣬���·�������ҷǿգ�����Ч
  outPathStr = pathStr + "/KongYingMap";
  folderPath = outPathStr.toStdWString();
  if (fs::exists(folderPath) && fs::directory_iterator(folderPath) != fs::directory_iterator())
  {
    return false;
  }
  return true;
}

void tianliWidgetUtils:: setFont(const QString& fontPath, QWidget* widget, bool isBold) {
  // ���������ļ�
  int id = QFontDatabase::addApplicationFont(fontPath);
  if (id != -1) {
    // ��ȡ�������
    QString family = QFontDatabase::applicationFontFamilies(id).at(0);
    // ��������
    QFont font(family);
    if (isBold)
      font.setBold(true);
    widget->setFont(font);
  }
}