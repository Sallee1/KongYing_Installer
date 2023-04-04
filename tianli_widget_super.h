#pragma once
//
// Created by Sallee on 2023/4/4.
//

#include "pch.h"
#include "tianli_widget.h"
#include "ui_tianli_widget.h"
#include "tianli_widget_utils.h"
#include "time_line_label.h"
#include "config.h"

class QGraphicsDropShadowEffect;
class QPropertyAnimation;
namespace tianli{
  QT_BEGIN_NAMESPACE
    namespace Ui { class tianli_widget; }
  QT_END_NAMESPACE

  class tianli_widget_super:public QWidget
  {
    Q_OBJECT
  public:
    explicit tianli_widget_super(QWidget* parent = nullptr);
    ~tianli_widget_super() override;

  protected:
    Ui::tianli_widget* ui;

  //子类装配的界面指针
  protected:
    QStackedWidget* activedWidget;    //活动的流程页面
    QPushButton* fastButton;          //第一页，快速操作按钮
    QPushButton* customButton;        //第一页，自定义按钮
    QCheckBox* desktopCheckBox;       //第一页，桌面快捷方式选框
    QCheckBox* startmenuCheckBox;     //第一页，开始菜单快捷方式选框
    QCheckBox* removeUserDataCheckBox;//第一页，删除用户数据的选框
    QPushButton* cancelButton;        //第二页，取消按钮
    QPushButton* startProgramButton;  //第三页，启动软件按钮
    QPushButton* finishExitButton;    //第三页，关闭按钮
    QPushButton* errorExitButton;     //第四页，错误关闭按钮

  //装配方法
    virtual void init();

  //槽函数
  protected slots:
    //前端->界面槽
    void pushButton_UI_Close();       //单击关闭按钮
    void pushButton_UI_Mini();        //单击最小化按钮
    void pushButton_FastInstall();    //单击第一页快速操作按钮
    void pushButton_CustomizeInstall(); //单击第一页自定义按钮
    void pushButton_preview();          //单机第一页路径预览按钮
    void pushButton_Cancel();           //单击第二页取消按钮 
    void pushButton_Finished_Run();     //单击第三页启动软件按钮
    void pushButton_Finished_Exit();    //单击第三页关闭按钮
    void pushButton_Error_exit();       //单击第四页错误关闭按钮

    //线程->前端槽
    void setThreadPrecent(int percent);         //线程进度条
    void changeThreadState(int state);          //设置步骤
    void onThreadFinish();                      //线程结束
    void onThreadThrowError(QString error);     //线程失败
  //信号
  signals:
    void setInstallConfig(QString, bool, bool); //初始化安装线程

  //其他内部方法
  private:

  };
};
