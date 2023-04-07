#include "pch.h"
#include "config.h"
#include "tianli_utils.h"

namespace fs = std::filesystem;

namespace tianliUtils {
  bool checkPathIsAvilable(QString pathStr, QString& outPathStr)
  {
    if (pathStr == "")return false;
    fs::path folderPath = std::string(pathStr.toLocal8Bit());
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
    for (std::string fileName : tianli::config::installInfo.existFileName)
    {
      if (!fs::exists(std::format("{0}\\{1}", std::string(pathStr.toLocal8Bit()), fileName)))
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
    outPathStr = pathStr + "\\KongYingMap";
    folderPath = std::string(outPathStr.toLocal8Bit());
    if (fs::exists(folderPath) && fs::directory_iterator(folderPath) != fs::directory_iterator())
    {
      for (std::string fileName : tianli::config::installInfo.existFileName)
      {
        if (!fs::exists(std::format("{0}\\{1}", folderPath.string(), fileName)))
        {
          return false;
        }
      }
      return true;
    }
    return true;
  }

  void setFont(const QString& fontPath, QWidget* widget, bool isBold) {
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

  void cleanUninstallReg()
  {
    HKEY hKey;
    RegOpenKeyEx(HKEY_LOCAL_MACHINE, std::format("SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Uninstall\\{0}", tianli::config::reginfo.displayName).c_str(), 0, KEY_ALL_ACCESS, &hKey);
    RegDeleteTree(hKey, NULL);
    RegCloseKey(hKey);
    RegDeleteKey(HKEY_LOCAL_MACHINE, std::format("SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Uninstall\\{0}", tianli::config::reginfo.displayName).c_str());
  }

  bool getRegValue_REG_SZ(HKEY root,std::string Item, std::string Key, std::string& ret, int maxLength)
  {
    HKEY hKey;
    long lRes = RegOpenKeyEx(root, Item.c_str(), 0, KEY_READ, &hKey);
    if (lRes != ERROR_SUCCESS)
    {
      RegCloseKey(hKey);
      return false;
    }
    char* lpData = new char[maxLength];
    DWORD dwType = REG_SZ;
    DWORD dwSize = maxLength;

    lRes = RegGetValue(hKey, NULL, Key.c_str(), RRF_RT_REG_SZ, &dwType, lpData, &dwSize);
    if (lRes != ERROR_SUCCESS)
    {
      RegCloseKey(hKey);
      delete[] lpData;
      return false;
    }

    ret = lpData;
    delete[] lpData;
    RegCloseKey(hKey);
    return true;
  }

  bool getRegValue_DWORD(HKEY root, std::string Item, std::string Key, int& ret)
  {
    HKEY hKey;
    long lRes = RegOpenKeyEx(root, Item.c_str(), 0, KEY_READ, &hKey);
    if (lRes != ERROR_SUCCESS)
    {
      RegCloseKey(hKey);
      return false;
    }
    DWORD lpData;
    DWORD dwType = REG_DWORD;
    DWORD dwSize = sizeof(DWORD);

    lRes = RegGetValue(hKey, NULL, Key.c_str(), RRF_RT_REG_DWORD, &dwType, &lpData, &dwSize);
    if (lRes != ERROR_SUCCESS)
    {
      RegCloseKey(hKey);
      return false;
    }

    ret = lpData;
    RegCloseKey(hKey);
    return true;
  }

  std::string envPath2AbsolutePath(std::string envPath)
  {
    char expanded_path[4096]; 

    DWORD result = ExpandEnvironmentStrings(envPath.c_str(), expanded_path, MAX_PATH);
    if (result == 0) throw std::exception("ExpandEnvironmentStrings:·���а������Ϸ��Ļ�������");
    
    return std::string(expanded_path);
  }
};