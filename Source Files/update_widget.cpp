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

  void update_widget::connectSignal()
  {
    tianli_widget_super::connectSignal();
    previewButton->disconnect();    
    
    fastButton->disconnect();
    connect(this->fastButton, &QPushButton::clicked, this, &update_widget::pushButton_Fast);
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

    this->pathLineEdit->setText(QString::fromLocal8Bit(installPath.c_str()));
    this->activedWidget->setCurrentIndex(1);
    this->beginProcess();
  }

  void update_widget::afterClose()
  {
    if (activedWidget->currentIndex() == 3)  //安装失败
    {

    }
    else
    {
      QProcess process;
      process.startDetached("cmd.exe", QStringList() << "/c" << "cloneInstaller.bat");
    }
    //只有安装器在Temp目录，才允许自我删除，以避免误删
    fs::path pt1 = fs::absolute(fs::path(".."));
    fs::path pt2 = tianliUtils::envPath2AbsolutePath("%TEMP%");
    if (fs::equivalent(fs::path("..\\"), tianliUtils::envPath2AbsolutePath("%TEMP%")))
    {
      QFile removeSelfBat("removeSelf.bat");
      removeSelfBat.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate);
      {
        QTextStream qOut(&removeSelfBat);
        qOut << QString::fromLocal8Bit(tianli::bat::removeSelf.c_str());
      }
      removeSelfBat.close();

      QProcess process;
      process.startDetached("cmd.exe", QStringList() << "/c" << "removeSelf.bat");
      return;
    }
  }

} // tianli