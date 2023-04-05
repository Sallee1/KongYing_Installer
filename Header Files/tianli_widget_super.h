#pragma once
//
// Created by Sallee on 2023/4/4.
//

#include "pch.h"
#include "ui_tianli_widget.h"
#include "tianli_widget_utils.h"
#include "time_line_label.h"
#include "config.h"
#include "thread_super.h"

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
  
  //�������
  private:
    QGraphicsDropShadowEffect* mainShadow_A;
    QGraphicsDropShadowEffect* mainShadow_B;
    QGraphicsDropShadowEffect* mainShadow;
    QPropertyAnimation* mainShadowAnimation;
    QPropertyAnimation* exitAnimation;
    QPropertyAnimation* exitAnimation_hide;

  //�¼����
  protected:
    QPoint m_Press;
    QPoint m_Move;
    bool leftBtnClk = false;
    void mousePressEvent(QMouseEvent* event) Q_DECL_OVERRIDE;
    void mouseReleaseEvent(QMouseEvent* event) Q_DECL_OVERRIDE;
    void mouseMoveEvent(QMouseEvent* event) Q_DECL_OVERRIDE;
    void closeEvent(QCloseEvent* event) Q_DECL_OVERRIDE;
    bool eventFilter(QObject* object, QEvent* event) Q_DECL_OVERRIDE;

  //������Ҫװ��Ľ���ָ��
  protected:
    QStackedWidget* activedWidget;    //�������ҳ��
    QPushButton* fastButton;          //��һҳ�����ٲ�����ť
    QPushButton* customButton;        //��һҳ���Զ��尴ť
    QStackedWidget* customStackedWidget;  //��һҳ���Զ��尴ť�л���ҳ
    QPushButton* previewButton;       //��һҳ��Ԥ����ť
    QLineEdit* pathLineEdit;          //��һҳ��·����
    QCheckBox* desktopCheckBox;       //��һҳ�������ݷ�ʽѡ��
    QCheckBox* startmenuCheckBox;     //��һҳ����ʼ�˵���ݷ�ʽѡ��
    QCheckBox* removeUserDataCheckBox;//��һҳ��ɾ���û����ݵ�ѡ��
    QPushButton* cancelButton;        //�ڶ�ҳ��ȡ����ť
    QPushButton* startProgramButton;  //����ҳ�����������ť
    QPushButton* finishExitButton;    //����ҳ���رհ�ť
    QPushButton* errorExitButton;     //����ҳ������رհ�ť
    QLabel* errorInfoLabel;           //����ҳ��������Ϣ

  //����д�ķ���
  public:
    void virtual init() = 0;         //��ʼ������Ҫ����ִ�г�ʼ�����ź�
    void virtual afterInit();
    void virtual initTimeLine();     //��ʼ��������
    void virtual beginProcess();     //�߳̿�ʼǰ��׼������
    void virtual connectSignal();    //װ���źţ���Ϊ�ۺ���������д��������Ҫ�������ֶ�ָ��Ҫ��д�Ĳۺ���
    void virtual afterClose() {};    //�رպ�Ҫִ�еķ���

  //��������
  protected:
    void setTimeLine(int step);   //���û�Ľ�����

  //����
  protected:
    std::vector<time_line_label*> timeLineLabelList;
    int activedTimeLabelIdx;

  //�߳�
  protected:
    Thread_super* thread;

  //�ۺ���
  protected slots:
    //ǰ��->�����
    void pushButton_UI_Close();         //�����رհ�ť
    void pushButton_UI_Mini();         //������С����ť

    void pushButton_Fast();             //������һҳ���ٲ�����ť
    void pushButton_Customize();        //������һҳ�Զ��尴ť
    void pushButton_preview();          //������һҳ·��Ԥ����ť          
    void pushButton_Cancel();           //�����ڶ�ҳȡ����ť 
    void pushButton_Finished_Run();     //��������ҳ���������ť          
    void pushButton_Finished_Exit();    //��������ҳ�رհ�ť
    void pushButton_Error_exit();       //��������ҳ����رհ�ť

    //�߳�->ǰ�˲�
    void processPercent(int percent);         //�߳̽�����
    void processChange(int state);          //���ò���
    void onThreadFinish();                      //�߳̽���
    void onThreadThrowError(QString error);     //�߳�ʧ��
  //�ź�
  signals:
    void setInstallConfig(QString, bool, bool); //��ʼ����װ�߳�
  };
};
