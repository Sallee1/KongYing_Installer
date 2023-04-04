//
// Created by Sallee on 2023/4/4.
//

#include "pch.h"
#include "install_widget.h"
#include "tianli_widget_utils.h"
#include "config.h"

namespace tianli {
  void install_widget::init()
  {
    activedWidget = ui->stackedWidget_install;
    fastButton = ui->pushButton_FastInstall;
    customButton = ui->pushButton_CustomizeInstall;
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

    ui->stackedWidget_2->setCurrentIndex(0);
    thread = new InstallThread();
  }
} // tianli
