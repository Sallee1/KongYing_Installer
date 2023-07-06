#include "pch.h"
#include "uninstall_widget.h"
#include "uninstall_thread.h"

namespace tianli {
  uninstall_widget::uninstall_widget(QWidget* parent)
  {
    init();
    afterInit();
    ui->stackedWidget_2->setCurrentIndex(2);
    //修改说明文字
    timeLineLabelList[0]->findChild<QLabel*>("label_Title")->setText(QString("清理注册表"));
    timeLineLabelList[1]->findChild<QLabel*>("label_Title")->setText(QString("删除快捷方式"));
    timeLineLabelList[2]->findChild<QLabel*>("label_Title")->setText(QString("删除程序"));
    timeLineLabelList[3]->findChild<QLabel*>("label_Title")->setText(QString("删除用户数据"));
  }

  uninstall_widget::~uninstall_widget()
  {
    delete thread;
  }

  void uninstall_widget::init()
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
    thread = new Uninstall_thread();     //重写的卸载线程

    //卸载的说明文件
    ui->label_Uninstall_ReadMe->setHidden(true);
  }

  void uninstall_widget::connectSignal()
  {
    tianli_widget_super::connectSignal();
    previewButton->disconnect();
    startProgramButton->disconnect();

    fastButton->disconnect();
    connect(this->fastButton, &QPushButton::clicked, this, &uninstall_widget::pushButton_Fast);

    thread->disconnect(this, &tianli_widget_super::setInstallConfig, thread, &Thread_super::setInstallConfig);
    connect(this, &uninstall_widget::setUninstallConfig, dynamic_cast<Uninstall_thread*>(this->thread), &Uninstall_thread::setUnnstallConfig);

    connect(this->removeUserDataCheckBox, &QCheckBox::toggled, ui->label_Uninstall_ReadMe, &QLabel::setVisible);
  }

  void uninstall_widget::pushButton_Fast()
  {
    string installPath = "";

    bool isSuccess = tianliUtils::getRegValue_REG_SZ(
      HKEY_LOCAL_MACHINE,
      std::format("SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Uninstall\\{0}", config::reginfo.displayName),
      "InstallLocation",
      installPath);

    if (!isSuccess)
    {
      activedWidget->setCurrentIndex(3);
      errorInfoLabel->setText("尝试获取安装路径失败，请手动删除文件");
    }
    else
    {
      tianli::config::reginfo.InstallLocation = installPath;
    }

    this->activedWidget->setCurrentIndex(1);
    this->beginProcess();
  }

  void uninstall_widget::afterClose()
  {
    if (activedWidget->currentIndex() == 3)  //卸载失败
    {
      tianliUtils::cleanUninstallReg();
    }
    if (activedWidget->currentIndex() == 2)   //卸载成功
    {
      //删除残留文件
      QFile removeSelfBat(QString::fromStdString(std::format("{0}\\removeSelf.bat", tianli::config::reginfo.InstallLocation)));
      removeSelfBat.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate);
      {
        QTextStream qOut(&removeSelfBat);
        qOut << QString::fromStdString(bat::removeSelf);
      }
      removeSelfBat.close();

      QProcess process;
      process.startDetached("cmd.exe", QStringList() << "/c" << QString::fromStdString(std::format("{0}\\removeSelf.bat", tianli::config::reginfo.InstallLocation)));
      return;
    }
  }

  void uninstall_widget::beginProcess()
  {
    ui->pushButton_UI_Close->setHidden(true);

    emit this->setUninstallConfig(this->removeUserDataCheckBox->isChecked());
    thread->start();

  }
}