#include "pch.h"
#include "config.h"
#include "tianli_widget_utils.h"

namespace fs = std::filesystem;

namespace tianliUtils {
  bool checkPathIsAvilable(QString pathStr, QString& outPathStr)
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
    for (std::wstring fileName : tianli::config::installInfo.existFileName)
    {
      if (!fs::exists(std::format(L"{0}\\{1}", pathStr.toStdWString(), fileName)))
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
    outPathStr = pathStr + "\\KongYingMap";
    folderPath = outPathStr.toStdWString();
    if (fs::exists(folderPath) && fs::directory_iterator(folderPath) != fs::directory_iterator())
    {
      for (std::wstring fileName : tianli::config::installInfo.existFileName)
      {
        if (!fs::exists(std::format(L"{0}\\{1}", folderPath.wstring(), fileName)))
        {
          return false;
        }
      }
      return true;
    }
    return true;
  }

  void setFont(const QString& fontPath, QWidget* widget, bool isBold) {
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

  void cleanUninstallReg()
  {
    HKEY hKey;
    RegOpenKeyEx(HKEY_LOCAL_MACHINE, std::format(L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Uninstall\\{0}", tianli::config::reginfo.displayName).c_str(), 0, KEY_ALL_ACCESS, &hKey);
    RegDeleteTree(hKey, NULL);
    RegCloseKey(hKey);
    RegDeleteKey(HKEY_LOCAL_MACHINE, std::format(L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Uninstall\\{0}", tianli::config::reginfo.displayName).c_str());
  }

  bool getRegValue_REG_SZ(HKEY root,std::wstring Item, std::wstring Key, std::wstring& ret, int maxLength)
  {
    HKEY hKey;
    long lRes = RegOpenKeyEx(root, Item.c_str(), 0, KEY_READ, &hKey);
    if (lRes != ERROR_SUCCESS)
    {
      RegCloseKey(hKey);
      return false;
    }
    wchar_t* lpData = new wchar_t[maxLength];
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

  bool getRegValue_DWORD(HKEY root, std::wstring Item, std::wstring Key, int& ret)
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

  wstring envPath2AbsolutePath(std::wstring envPath)
  {
    wchar_t expanded_path[4096]; 

    DWORD result = ExpandEnvironmentStrings(envPath.c_str(), expanded_path, MAX_PATH);
    if (result == 0) throw std::exception("ExpandEnvironmentStrings:路径中包含不合法的环境变量");
    
    return std::wstring(expanded_path);
  }
};