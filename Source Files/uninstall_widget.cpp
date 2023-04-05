#include "pch.h"
#include "uninstall_widget.h"
#include "uninstall_thread.h"

tianli::uninstall_widget::uninstall_widget(QWidget* parent)
{
  init();
  afterInit();
  ui->stackedWidget_2->setCurrentIndex(2);
  //��ȡע�����ȡ��װ·��
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
}

void tianli::uninstall_widget::connectSignal()
{
  tianli_widget_super::connectSignal();
  previewButton->disconnect();
  startProgramButton->disconnect();

  fastButton->disconnect();
  connect(this->fastButton, &QPushButton::clicked, this, &uninstall_widget::pushButton_Fast);
}

void tianli::uninstall_widget::pushButton_Fast()
{
  wstring installPath = L"";

  bool isSuccess = tianliWidgetUtils::getRegValue_REG_SZ(
    HKEY_LOCAL_MACHINE,
    std::format(L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Uninstall\\{0}", tianli::config::reginfo.displayName),
    L"InstallLocation",
    installPath);

  if (!isSuccess)
  {
    activedWidget->setCurrentIndex(3);
    errorInfoLabel->setText("���Ի�ȡ��װ·��ʧ�ܣ����ֶ�ɾ���ļ�");
  }

  this->pathLineEdit->setText(QString::fromStdWString(installPath));
  this->activedWidget->setCurrentIndex(1);
  this->beginProcess();
}
