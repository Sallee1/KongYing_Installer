#pragma once
//
// Created by Sallee on 2023/4/4. 
//

#include "pch.h"
#include "ui_tianli_widget.h"
#include "tianli_utils.h"
#include "time_line_label.h"
#include "config.h"
#include "thread_super.h"

class QGraphicsDropShadowEffect;
class QPropertyAnimation;
namespace tianli {
  QT_BEGIN_NAMESPACE
    namespace Ui { class tianli_widget; }
  QT_END_NAMESPACE

    class tianli_widget_super :public QWidget
  {
    Q_OBJECT
  public:
    explicit tianli_widget_super(QWidget* parent = nullptr);
    ~tianli_widget_super() override;

  protected:
    Ui::tianli_widget* ui;

    //动画组件
  private:
    QGraphicsDropShadowEffect* mainShadow_A;
    QGraphicsDropShadowEffect* mainShadow_B;
    QGraphicsDropShadowEffect* mainShadow;
    QPropertyAnimation* mainShadowAnimation;
    QPropertyAnimation* exitAnimation;
    QPropertyAnimation* exitAnimation_hide;

    //事件组件
  protected:
    QPoint m_Press;
    QPoint m_Move;
    bool leftBtnClk = false;
    void mousePressEvent(QMouseEvent* event) Q_DECL_OVERRIDE;
    void mouseReleaseEvent(QMouseEvent* event) Q_DECL_OVERRIDE;
    void mouseMoveEvent(QMouseEvent* event) Q_DECL_OVERRIDE;
    void closeEvent(QCloseEvent* event) Q_DECL_OVERRIDE;
    bool eventFilter(QObject* object, QEvent* event) Q_DECL_OVERRIDE;

    //子类需要装配的界面指针
  protected:
    QStackedWidget* activedWidget;    //活动的流程页面
    QPushButton* fastButton;          //第一页，快速操作按钮
    QPushButton* customButton;        //第一页，自定义按钮
    QStackedWidget* customStackedWidget;  //第一页，自定义按钮切换翻页
    QPushButton* previewButton;       //第一页，预览按钮
    QLineEdit* pathLineEdit;          //第一页，路径栏
    QCheckBox* desktopCheckBox;       //第一页，桌面快捷方式选框
    QCheckBox* startmenuCheckBox;     //第一页，开始菜单快捷方式选框
    QCheckBox* removeUserDataCheckBox;//第一页，删除用户数据的选框
    QPushButton* cancelButton;        //第二页，取消按钮
    QPushButton* startProgramButton;  //第三页，启动软件按钮
    QPushButton* finishExitButton;    //第三页，关闭按钮
    QPushButton* errorExitButton;     //第四页，错误关闭按钮
    QLabel* errorInfoLabel;           //第四页，报错信息

    //可重写的方法
  public:
    void virtual init() = 0;         //初始化，需要子类执行初始化的信号
    void virtual afterInit();
    void virtual initTimeLine();     //初始化进度条
    void virtual beginProcess();     //线程开始前的准备工作
    void virtual connectSignal();    //装配信号，因为槽函数不能重写，所以需要在这里手动指定要重写的槽函数
    void virtual afterClose();    //关闭后要执行的方法

    //其他方法
  protected:
    void setTimeLine(int step);   //设置活动的进度条

    //容器
  protected:
    std::vector<time_line_label*> timeLineLabelList;
    int activedTimeLabelIdx;

    //线程
  protected:
    Thread_super* thread;

    //槽函数
  protected slots:
    //前端->界面槽
    void pushButton_UI_Close();         //单击关闭按钮
    void pushButton_UI_Mini();         //单击最小化按钮

    void pushButton_Fast();             //单击第一页快速操作按钮
    void pushButton_Customize();        //单击第一页自定义按钮
    void pushButton_preview();          //单击第一页路径预览按钮          
    void pushButton_Cancel();           //单击第二页取消按钮 
    void pushButton_Finished_Run();     //单击第三页启动软件按钮          
    void pushButton_Finished_Exit();    //单击第三页关闭按钮
    void pushButton_Error_exit();       //单击第四页错误关闭按钮

    //线程->前端槽
    void processPercent(int percent);         //线程进度条
    void processChange(int state);          //设置步骤
    void onThreadFinish();                      //线程结束
    void onThreadThrowError(QString error);     //线程失败
    //信号
  signals:
    void setInstallConfig(QString, bool, bool); //初始化安装线程
  };
};
