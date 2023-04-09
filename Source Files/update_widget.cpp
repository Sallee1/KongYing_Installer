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
    //��ȡע�����ȡ��װ·��
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
    thread = new InstallThread();     //�������ð�װ�߳�

    //����ݷ�ʽ�Ƿ����
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
    if (fs::exists(std::format("{0}\\{1}\\{2}",std::string(QDir::toNativeSeparators(QStandardPaths::writableLocation(QStandardPaths::ApplicationsLocation)).toLocal8Bit()), tianli::config::installInfo.startmenuShortcut_foldername, tianli::config::installInfo.startmenuShortcut_programName)))
    {
      startmenuCheckBox->setChecked(true);
      startmenuCheckBox->setEnabled(false);
    }
    else
    {
      desktopCheckBox->setChecked(false);
    }
  }

  void update_widget::connectSignal()
  {
    tianli_widget_super::connectSignal();
    previewButton->disconnect();    
    
    fastButton->disconnect();
    connect(this->fastButton, &QPushButton::clicked, this, &update_widget::pushButton_Fast);
  }

  void update_widget::pushButton_Fast()      //��д���ٰ�װ��ť����ע����ȡ·������ȡ��·��У��
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
      errorInfoLabel->setText("���Ի�ȡ��װ·��ʧ�ܣ��볢�����°�װ��");
    }

    this->pathLineEdit->setText(QString::fromLocal8Bit(installPath.c_str()));
    this->activedWidget->setCurrentIndex(1);
    this->beginProcess();
  }

} // tianli