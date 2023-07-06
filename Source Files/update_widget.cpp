//
// Created by Sallee on 2023/4/4.
//

#include "pch.h"
#include "install_widget.h"
#include "tianli_utils.h"
#include "config.h"
#include "update_widget.h"

namespace tianli {
  tianli::update_widget::update_widget(QWidget* parent)
  {
    init();
    afterInit();
    ui->stackedWidget_2->setCurrentIndex(1);
    //读取注册表，获取安装路径
  }

  update_widget::~update_widget()
  {
    delete thread;
  }

  void update_widget::init()
  {
    activedWidget = ui->stackedWidget_update;
    fastButton = ui->pushButton_FastUpdate;
    customButton = ui->pushButton_CustomizeUpdate;
    customStackedWidget = ui->stackedWidget_UpdataCustom;
    previewButton = ui->pushButton_preview;
    pathLineEdit = ui->lineEdit_installPath;
    desktopCheckBox = ui->checkBox_desktopShortcutUpdate;
    startmenuCheckBox = ui->checkBox_startMenuShortCutUpdate;
    removeUserDataCheckBox = ui->checkBox_removeUserData;
    cancelButton = ui->pushButton_update_Cancel;
    startProgramButton = ui->pushButton_Finished_Run_Update;
    finishExitButton = ui->pushButton_Finished_Exit_Update;
    errorExitButton = ui->pushButton_Fail_Close_Updaye;
    errorInfoLabel = ui->label_err_info_Update;
    thread = new InstallThread();     //可以沿用安装线程
  }

  void update_widget::afterInit()
  {
    tianli::tianli_widget_super::afterInit();

    //检查快捷方式是否存在
    if (fs::exists(std::format("{0}\\{1}", std::string(QDir::toNativeSeparators(QStandardPaths::writableLocation(QStandardPaths::DesktopLocation)).toLocal8Bit()), tianli::config::installInfo.desktopShortcut_name)))
    {
      desktopCheckBox->setChecked(true);
      desktopCheckBox->setEnabled(false);
    }
    else
    {
      desktopCheckBox->setChecked(false);
    }

    std::string path = std::format("{0}\\{1}\\{2}", std::string(QDir::toNativeSeparators(QStandardPaths::writableLocation(QStandardPaths::ApplicationsLocation)).toLocal8Bit()), tianli::config::installInfo.startmenuShortcut_foldername, tianli::config::installInfo.startmenuShortcut_programName);
    if (fs::exists(std::format("{0}\\{1}\\{2}", std::string(QDir::toNativeSeparators(QStandardPaths::writableLocation(QStandardPaths::ApplicationsLocation)).toLocal8Bit()), tianli::config::installInfo.startmenuShortcut_foldername, tianli::config::installInfo.startmenuShortcut_programName)))
    {
      startmenuCheckBox->setChecked(true);
      startmenuCheckBox->setEnabled(false);
    }
    else
    {
      desktopCheckBox->setChecked(false);
    }
    //设置帮助信息
    ui->gridLayout_externLink->setParent(this->activedWidget->widget(2));
  }

  void update_widget::connectSignal()
  {
    tianli_widget_super::connectSignal();
    previewButton->disconnect();    
    
    fastButton->disconnect();
    connect(this->fastButton, &QPushButton::clicked, this, &update_widget::pushButton_Fast);

    connect(customButton, &QPushButton::clicked, [=]() {
      ui->label_FastUpdate_Documentation->setText(QString("使用自定义方案"));
      });
  }

  void update_widget::pushButton_Fast()      //重写快速安装按钮，从注册表读取路径，并取消路径校验
  { 
    string installPath = "";

    bool isSuccess = tianliUtils::getRegValue_REG_SZ(
      HKEY_LOCAL_MACHINE,
      std::format("SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Uninstall\\{0}", tianli::config::reginfo.displayName),
      "InstallLocation",
      installPath);

    if (!isSuccess)
    {
      activedWidget->setCurrentIndex(3);
      errorInfoLabel->setText("尝试获取安装路径失败，请尝试重新安装。");
    }

    this->pathLineEdit->setText(QString::fromStdString(installPath));
    this->activedWidget->setCurrentIndex(1);
    this->beginProcess();
  }

} // tianli