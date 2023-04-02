#pragma once
using std::wstring;
namespace fs = std::filesystem;

static class config
{
public:
  typedef struct{
    wstring displayName;
    wstring displayVersion;
    wstring publisher;
    wstring displayIcon;
    wstring uninstallString;
  } RegInfo;

  typedef struct {
    wstring formName;
    wstring title;
  } InstallerGlobal;

  typedef struct {
    wstring subTitle;
    wstring defaultPath;
    bool desktopShortcut;
    bool startmenuShortcut;
    wstring tip;
    wstring tipLink;
  } InstallerPage1;

  typedef struct {
    wstring subTitle;
  }InstallerPage2;

  typedef struct {
    wstring subTitle;
    wstring tip;
    wstring tipLink;
    wstring startExe;
    wstring snsIcon1;
    wstring snsLink1;
    wstring snsIcon2;
    wstring snsLink2;
  }InstallerPage3;

  typedef struct {
    wstring subTitle;
    wstring tip;
    wstring tipLink;
  }InstallerPage4;

public:
  RegInfo reginfo;
  InstallerGlobal installerGlobal;
  InstallerPage1 installerPage1;
  InstallerPage2 installerPage2;
  InstallerPage3 installerPage3;
  InstallerPage4 installerPage4;

public:
  config(fs::path);
};