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
    void virtual mousePressEvent(QMouseEvent* event) Q_DECL_OVERRIDE;
    void virtual mouseReleaseEvent(QMouseEvent* event) Q_DECL_OVERRIDE;
    void virtual mouseMoveEvent(QMouseEvent* event) Q_DECL_OVERRIDE;
    void virtual closeEvent(QCloseEvent* event) Q_DECL_OVERRIDE;

  //����װ��Ľ���ָ��
  protected:
    QStackedWidget* activedWidget;    //�������ҳ��
    QPushButton* fastButton;          //��һҳ�����ٲ�����ť
    QPushButton* customButton;        //��һҳ���Զ��尴ť
    QPushButton* previewButton;       //��һҳ��Ԥ����ť
    QLineEdit* pathLineEdit;          //��һҳ��·����
    QCheckBox* desktopCheckBox;       //��һҳ�������ݷ�ʽѡ��
    QCheckBox* startmenuCheckBox;     //��һҳ����ʼ�˵���ݷ�ʽѡ��
    QCheckBox* removeUserDataCheckBox;//��һҳ��ɾ���û����ݵ�ѡ��
    QPushButton* cancelButton;        //�ڶ�ҳ��ȡ����ť
    QPushButton* startProgramButton;  //����ҳ�����������ť
    QPushButton* finishExitButton;    //����ҳ���رհ�ť
    QPushButton* errorExitButton;     //����ҳ������رհ�ť
    QLabel* errorInfoLabel;                //����ҳ��������Ϣ

  //װ�䷽��
    virtual void initRefQObejct();   //װ��ָ��
    void connectSignal();    //װ���ź�

  //�ڲ�����
  private:
    void initTimeLine();    //��ʼ��������
    void setTimeLine(int step);   //���û�Ľ�����
    void virtual beginProcess();  //��װǰ��׼������

  //����
  private:
    std::vector<time_line_label*> timeLineLabelList;
    int activedTimeLabelIdx;

  //�ۺ���
  protected slots:
    //ǰ��->�����
    void pushButton_UI_Close();       //�����رհ�ť
    void pushButton_UI_Mini();        //������С����ť

    void virtual pushButton_Fast();    //������һҳ���ٲ�����ť
    void virtual pushButton_Customize(); //������һҳ�Զ��尴ť
    void virtual pushButton_preview();          //������һҳ·��Ԥ����ť          
    void virtual pushButton_Cancel();           //�����ڶ�ҳȡ����ť 
    void virtual pushButton_Finished_Run();     //��������ҳ���������ť          
    void virtual pushButton_Finished_Exit();    //��������ҳ�رհ�ť
    void virtual pushButton_Error_exit();       //��������ҳ����رհ�ť

    //�߳�->ǰ�˲�
    void virtual setThreadPrecent(int percent);         //�߳̽�����
    void virtual changeThreadState(int state);          //���ò���
    void virtual onThreadFinish();                      //�߳̽���
    void virtual onThreadThrowError(QString error);     //�߳�ʧ��
  //�ź�
  signals:
    void setInstallConfig(QString, bool, bool); //��ʼ����װ�߳�
  };
};
