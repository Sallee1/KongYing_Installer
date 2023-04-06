#include "pch.h"
#include "uninstall_widget.h"
#include "uninstall_thread.h"

tianli::uninstall_widget::uninstall_widget(QWidget* parent)
{
  init();
  afterInit();
  ui->stackedWidget_2->setCurrentIndex(2);
  //�޸�˵������
  timeLineLabelList[0]->findChild<QLabel*>("label_Title")->setText(QString::fromLocal8Bit("����ע���"));
  timeLineLabelList[1]->findChild<QLabel*>("label_Title")->setText(QString::fromLocal8Bit("ɾ����ݷ�ʽ"));
  timeLineLabelList[2]->findChild<QLabel*>("label_Title")->setText(QString::fromLocal8Bit("ɾ������"));
  timeLineLabelList[3]->findChild<QLabel*>("label_Title")->setText(QString::fromLocal8Bit("ɾ���û�����"));
}

tianli::uninstall_widget::~uninstall_widget()
{
  delete thread;
}

void tianli::uninstall_widget::init()
{
  activedWidget = ui->stackedWidget_uninstall;
  fastButton = ui->pushButton_FastUninstall;
  customButton = ui->pushButton_CustomizeInstall;
  customStackedWidget = ui->stackedWidget_UpdataCustom;
  previewButton = ui->pushButton_preview;
  pathLineEdit = ui->lineEdit_installPath;
  desktopCheckBox = ui->checkBox_desktopShortcut;
  startmenuCheckBox = ui->checkBox_startMenuShortCut;
  removeUserDataCheckBox = ui->checkBox_removeUserData;
  cancelButton = ui->pushButton_Uninstall_Cancel;
  startProgramButton = ui->pushButton_Finished_Run;
  finishExitButton = ui->pushButton_Finished_Exit_Uninstall;
  errorExitButton = ui->pushButton_Fail_Close_Uninstall;
  errorInfoLabel = ui->label_err_info_Uninstall;
  thread = new Uninstall_thread();     //��д��ж���߳�
  
  //ж�ص�˵���ļ�
  ui->label_Uninstall_ReadMe->setHidden(true);
}

void tianli::uninstall_widget::connectSignal()
{
  tianli_widget_super::connectSignal();
  previewButton->disconnect();
  startProgramButton->disconnect();

  fastButton->disconnect();
  connect(this->fastButton, &QPushButton::clicked, this, &uninstall_widget::pushButton_Fast);

  thread->disconnect(this,&tianli_widget_super::setInstallConfig,thread,&Thread_super::setInstallConfig);
  connect(this, &uninstall_widget::setUninstallConfig, dynamic_cast<Uninstall_thread*>(this->thread), &Uninstall_thread::setUnnstallConfig);

  connect(this->removeUserDataCheckBox, &QCheckBox::toggled, ui->label_Uninstall_ReadMe, &QLabel::setVisible);
}

void tianli::uninstall_widget::pushButton_Fast()
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
    errorInfoLabel->setText("���Ի�ȡ��װ·��ʧ�ܣ����ֶ�ɾ���ļ�");
  }

  this->activedWidget->setCurrentIndex(1);
  this->beginProcess();
}

void tianli::uninstall_widget::beginProcess()
{
  ui->pushButton_UI_Close->setHidden(true);

  emit this->setUninstallConfig(this->removeUserDataCheckBox->isChecked());
  thread->start();

}
