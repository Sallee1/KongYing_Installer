//
// Created by Sallee on 2023/4/4.
//

#include "pch.h"
#include "install_widget.h"
#include "tianli_widget_utils.h"
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
  }

  void update_widget::connectSignal()
  {
    tianli_widget_super::connectSignal();
    fastButton->disconnect();
    connect(this->fastButton, &QPushButton::clicked, this, &update_widget::pushButton_Fast);
  }

  void update_widget::pushButton_Fast()
  {
    wstring installPath = L"";

    bool isSuccess = tianliWidgetUtils::getRegValue_REG_SZ(
      HKEY_LOCAL_MACHINE,
      std::format(L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Uninstall\\{0}", config::reginfo.displayName),
      L"InstallLocation",
      installPath);

    if (!isSuccess)
    {
      activedWidget->setCurrentIndex(3);
      errorInfoLabel->setText("���Ի�ȡ��װ·��ʧ�ܣ��볢�����°�װ��");
    }

    this->pathLineEdit->setText(QString::fromStdWString(installPath));
    this->activedWidget->setCurrentIndex(1);
    this->beginProcess();
  }
  //��д���ٰ�װ��ť����ע����ȡ·������ȡ��·��У��
} // tianli