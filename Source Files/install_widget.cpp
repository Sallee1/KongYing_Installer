//
// Created by Sallee on 2023/4/4.
//

#include "pch.h"
#include "install_widget.h"
#include "tianli_utils.h"
#include "config.h"

namespace tianli {
  Install_widget::Install_widget(QWidget* parent) : tianli_widget_super(parent) {
    init();
    afterInit();    
    ui->stackedWidget_2->setCurrentIndex(0);

  }
  void Install_widget::init()
  {
    activedWidget = ui->stackedWidget_install;
    fastButton = ui->pushButton_FastInstall;
    customButton = ui->pushButton_CustomizeInstall;
    customStackedWidget = ui->stackedWidget_InstallCustom;
    previewButton = ui->pushButton_preview;
    pathLineEdit = ui->lineEdit_installPath;
    desktopCheckBox = ui->checkBox_desktopShortcut;
    startmenuCheckBox = ui->checkBox_startMenuShortCut;
    removeUserDataCheckBox = ui->checkBox_removeUserData;
    cancelButton = ui->pushButton_installing_Cancel;
    startProgramButton = ui->pushButton_Finished_Run;
    finishExitButton = ui->pushButton_Finished_Exit;
    errorExitButton = ui->pushButton_Fail_Close;
    errorInfoLabel = ui->label_err_info;
    thread = new InstallThread();
  }

  void Install_widget::afterClose()
  {
    if (activedWidget->currentIndex() == 3)  //��װʧ��
    {

    }
    else
    {
      QProcess process;
      process.startDetached("cmd.exe", QStringList() << "/c" << "cloneInstaller.bat");
    }

    //ֻ�а�װ����TempĿ¼������������ɾ�����Ա�����ɾ
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

  inline Install_widget::~Install_widget() {
    delete thread;
  }
} // tianli