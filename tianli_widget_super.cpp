#include "pch.h"
#include "tianli_widget_super.h"


//×°Åä·½·¨

inline void tianli::tianli_widget_super::init()
{
  connect(ui->pushButton_UI_Close, &QPushButton::clicked, this, &tianli_widget_super::pushButton_UI_Close);
  connect(ui->pushButton_UI_Mini, &QPushButton::clicked, this, &tianli_widget_super::pushButton_UI_Mini);
}

void tianli::tianli_widget_super::pushButton_UI_Mini()
{
}

void tianli::tianli_widget_super::pushButton_FastInstall()
{
}

void tianli::tianli_widget_super::pushButton_CustomizeInstall()
{
}

void tianli::tianli_widget_super::pushButton_preview()
{
}

void tianli::tianli_widget_super::pushButton_Cancel()
{
}

void tianli::tianli_widget_super::pushButton_Finished_Run()
{
}

void tianli::tianli_widget_super::pushButton_Finished_Exit()
{
}

void tianli::tianli_widget_super::pushButton_Error_exit()
{
}

void tianli::tianli_widget_super::setThreadPrecent(int percent)
{
}

void tianli::tianli_widget_super::changeThreadState(int state)
{
}

void tianli::tianli_widget_super::onThreadFinish()
{
}

void tianli::tianli_widget_super::onThreadThrowError(QString error)
{
}
