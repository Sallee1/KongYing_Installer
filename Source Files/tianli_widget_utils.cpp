#include "pch.h"
#include "config.h"
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
  //�ǿգ����ǰ�װ���
  bool isOverWrite = true;
  for (std::wstring fileName : config::installInfo.existFileName)
  {
    if (fs::exists(std::format(L"{0}/{1}", pathStr.toStdWString(), fileName)))
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

  //���򣬷ŵ����ļ��в���⣬���·�����ڣ����ҷǿգ�����û��ͨ�����Ǽ�⣬����Ч
  outPathStr = pathStr + "/KongYingMap";
  folderPath = outPathStr.toStdWString();
  if (fs::exists(folderPath) && fs::directory_iterator(folderPath) != fs::directory_iterator())
  {
    for (std::wstring fileName : config::installInfo.existFileName)
    {
      if (fs::exists(std::format(L"{0}/{1}", folderPath.wstring(), fileName)))
      {
        return false;
      }
    }
    return true;
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