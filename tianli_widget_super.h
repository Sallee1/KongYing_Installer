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

  //����װ��Ľ���ָ��
  protected:
    QStackedWidget* activedWidget;    //�������ҳ��
    QPushButton* fastButton;          //��һҳ�����ٲ�����ť
    QPushButton* customButton;        //��һҳ���Զ��尴ť
    QCheckBox* desktopCheckBox;       //��һҳ�������ݷ�ʽѡ��
    QCheckBox* startmenuCheckBox;     //��һҳ����ʼ�˵���ݷ�ʽѡ��
    QCheckBox* removeUserDataCheckBox;//��һҳ��ɾ���û����ݵ�ѡ��
    QPushButton* cancelButton;        //�ڶ�ҳ��ȡ����ť
    QPushButton* startProgramButton;  //����ҳ�����������ť
    QPushButton* finishExitButton;    //����ҳ���رհ�ť
    QPushButton* errorExitButton;     //����ҳ������رհ�ť

  //װ�䷽��
    virtual void init();

  //�ۺ���
  protected slots:
    //ǰ��->�����
    void pushButton_UI_Close();       //�����رհ�ť
    void pushButton_UI_Mini();        //������С����ť
    void pushButton_FastInstall();    //������һҳ���ٲ�����ť
    void pushButton_CustomizeInstall(); //������һҳ�Զ��尴ť
    void pushButton_preview();          //������һҳ·��Ԥ����ť
    void pushButton_Cancel();           //�����ڶ�ҳȡ����ť 
    void pushButton_Finished_Run();     //��������ҳ���������ť
    void pushButton_Finished_Exit();    //��������ҳ�رհ�ť
    void pushButton_Error_exit();       //��������ҳ����رհ�ť

    //�߳�->ǰ�˲�
    void setThreadPrecent(int percent);         //�߳̽�����
    void changeThreadState(int state);          //���ò���
    void onThreadFinish();                      //�߳̽���
    void onThreadThrowError(QString error);     //�߳�ʧ��
  //�ź�
  signals:
    void setInstallConfig(QString, bool, bool); //��ʼ����װ�߳�

  //�����ڲ�����
  private:

  };
};
