//
// Created by YuSuiXian on 2023/2/9.
//

#ifndef TIANLI_INSTALLER_TIANLI_WIDGET_H
#define TIANLI_INSTALLER_TIANLI_WIDGET_H
#include <pch.h>
#include "installThread.h"
#include "time_line_label.h"

class QGraphicsDropShadowEffect;
class QPropertyAnimation;
namespace tianli {
    QT_BEGIN_NAMESPACE
    namespace Ui { class tianli_widget; }
    QT_END_NAMESPACE

    class tianli_widget : public QWidget {
    Q_OBJECT

    public:
        explicit tianli_widget(QWidget *parent = nullptr);

        ~tianli_widget() override;

    private:
        Ui::tianli_widget *ui;

    private:
      void initTimeLine();
      void setTimeLine(int step);

      void setupInstallOrUpdate();

    private:
        QGraphicsDropShadowEffect* mainShadow_A;
        QGraphicsDropShadowEffect* mainShadow_B;
        QGraphicsDropShadowEffect* mainShadow;
        QPropertyAnimation* mainShadowAnimation;
        QPropertyAnimation* exitAnimation;
        QPropertyAnimation* exitAnimation_hide;
    private:
        QPoint m_Press;
        QPoint m_Move;
        bool leftBtnClk = false;
        void mousePressEvent(QMouseEvent* event) Q_DECL_OVERRIDE;
        void mouseReleaseEvent(QMouseEvent* event) Q_DECL_OVERRIDE;
        void mouseMoveEvent(QMouseEvent* event) Q_DECL_OVERRIDE;
        void closeEvent(QCloseEvent* event) Q_DECL_OVERRIDE;
    private:
        bool eventFilter(QObject* object, QEvent* event) Q_DECL_OVERRIDE;
    private slots:
        void pushButton_UI_Close();
        void pushButton_UI_Mini();
        void pushButton_FastInstall();
        void pushButton_CustomizeInstall();
        void pushButton_Finishing_Cancel();
        void pushButton_Finished_Run();
        void pushButton_Finished_Exit();
        void pushButton_preview();

        void changeInstallState(int state);
    //安装器进度条相关
    private:
        std::vector<time_line_label*> timeLineLabelList;
        int activedTimeLabelIdx;
        void setProgress(int percent);
    //安装相关的方法和线程
    private:
      void beginInstall();
      void endInstall();
      InstallThread* installThread = new InstallThread;
    signals:
      void setInstallConfig(QString, bool, bool);
    };


} // tianli

#endif //TIANLI_INSTALLER_TIANLI_WIDGET_H
