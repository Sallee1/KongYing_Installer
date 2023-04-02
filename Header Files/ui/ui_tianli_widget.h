/********************************************************************************
** Form generated from reading UI file 'tianli_widget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TIANLI_WIDGET_H
#define UI_TIANLI_WIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

namespace tianli {

class Ui_tianli_widget
{
public:
    QLabel *label_MainShadow;
    QLabel *label_MainShadow_A;
    QLabel *label_MainShadow_B;
    QLabel *label_Satellite_Orbit;
    QLabel *label_Star;
    QLabel *label_Title;
    QPushButton *pushButton_UI_Close;
    QPushButton *pushButton_UI_Mini;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QLabel *label_Wizard_start;
    QLabel *label_Tag_Down;
    QLabel *label_Readme;
    QLabel *label_Tag_Up;
    QWidget *widget_CustomOption;
    QPushButton *pushButton_preview;
    QLineEdit *lineEdit_installPath;
    QCheckBox *checkBox_desktopShortcut;
    QCheckBox *checkBox_startMenuShortCut;
    QWidget *widget_CustomButtom;
    QPushButton *pushButton_CustomizeInstall;
    QLabel *label_CustomizeInstall_Icon;
    QLabel *label_CustomizeInstall_Documentation;
    QLabel *label_CustomizeInstall;
    QWidget *widget_FastButtom;
    QLabel *label_FastInstall;
    QLabel *label_FastInstall_Documentation;
    QPushButton *pushButton_FastInstall;
    QLabel *label_FastInstall_Icon;
    QWidget *page_2;
    QLabel *label_Wizard_installing;
    QPushButton *pushButton_Finishing_Cancel;
    QWidget *page_3;
    QLabel *label_Wizard_finish;
    QLabel *label_Documentation;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_Icon_0;
    QLabel *label_Icon_1;
    QPushButton *pushButton_Finished_Run;
    QPushButton *pushButton_Finished_Exit;
    QWidget *page_4;
    QLabel *label_Wizard_failed;
    QLabel *label_err_documentation;
    QPushButton *pushButton_Fail_Close_2;
    QLabel *label_err_info;
    QLabel *label_MainImage;

    void setupUi(QWidget *tianli__tianli_widget)
    {
        if (tianli__tianli_widget->objectName().isEmpty())
            tianli__tianli_widget->setObjectName(QString::fromUtf8("tianli__tianli_widget"));
        tianli__tianli_widget->resize(740, 424);
        QFont font;
        font.setBold(true);
        tianli__tianli_widget->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/logo/resource/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        tianli__tianli_widget->setWindowIcon(icon);
        tianli__tianli_widget->setStyleSheet(QString::fromUtf8(""));
        label_MainShadow = new QLabel(tianli__tianli_widget);
        label_MainShadow->setObjectName(QString::fromUtf8("label_MainShadow"));
        label_MainShadow->setGeometry(QRect(10, 10, 721, 404));
        label_MainShadow->setStyleSheet(QString::fromUtf8("\n"
"                    background-color:rgb(255, 255, 255);\n"
"                    border:none;\n"
"                    border-radius:5px;\n"
"                "));
        label_MainShadow_A = new QLabel(tianli__tianli_widget);
        label_MainShadow_A->setObjectName(QString::fromUtf8("label_MainShadow_A"));
        label_MainShadow_A->setGeometry(QRect(10, 10, 721, 404));
        label_MainShadow_A->setStyleSheet(QString::fromUtf8("\n"
"                    background-color:rgb(255, 255, 255);\n"
"                    border:none;\n"
"                    border-radius:5px;\n"
"                "));
        label_MainShadow_B = new QLabel(tianli__tianli_widget);
        label_MainShadow_B->setObjectName(QString::fromUtf8("label_MainShadow_B"));
        label_MainShadow_B->setGeometry(QRect(10, 10, 720, 404));
        label_MainShadow_B->setStyleSheet(QString::fromUtf8("\n"
"                    background-color:rgb(255, 255, 255);\n"
"                    border:none;\n"
"                    border-radius:5px;\n"
"                "));
        label_Satellite_Orbit = new QLabel(tianli__tianli_widget);
        label_Satellite_Orbit->setObjectName(QString::fromUtf8("label_Satellite_Orbit"));
        label_Satellite_Orbit->setGeometry(QRect(458, 10, 272, 90));
        label_Satellite_Orbit->setStyleSheet(QString::fromUtf8("\n"
"                    background-image:url(:/parts/resource/bg_star.png);\n"
"                "));
        label_Star = new QLabel(tianli__tianli_widget);
        label_Star->setObjectName(QString::fromUtf8("label_Star"));
        label_Star->setGeometry(QRect(370, 48, 48, 48));
        label_Star->setStyleSheet(QString::fromUtf8("\n"
"                    background-image:url(:/parts/resource/bg_big_star.png);\n"
"                "));
        label_Title = new QLabel(tianli__tianli_widget);
        label_Title->setObjectName(QString::fromUtf8("label_Title"));
        label_Title->setGeometry(QRect(395, 56, 140, 40));
        QFont font1;
        label_Title->setFont(font1);
        label_Title->setStyleSheet(QString::fromUtf8("\n"
"                    color:rgb(47, 47, 47);\n"
"                    font-size:28px;\n"
"                "));
        pushButton_UI_Close = new QPushButton(tianli__tianli_widget);
        pushButton_UI_Close->setObjectName(QString::fromUtf8("pushButton_UI_Close"));
        pushButton_UI_Close->setGeometry(QRect(690, 20, 32, 32));
        pushButton_UI_Close->setStyleSheet(QString::fromUtf8("\n"
"                    QPushButton{\n"
"                    background-image:url(:/sys_button/resource/sys_button/exit.png);\n"
"                    color:rgb(220, 188, 96);\n"
"                    border-radius:0px;\n"
"                    }\n"
"                    QPushButton:hover {\n"
"                    background-image:url(:/sys_button/resource/sys_button/exit_hover.png);\n"
"                    }\n"
"                    QPushButton:pressed {\n"
"                    background-image:url(:/sys_button/resource/sys_button/exit_click.png);\n"
"                    }\n"
"                "));
        pushButton_UI_Mini = new QPushButton(tianli__tianli_widget);
        pushButton_UI_Mini->setObjectName(QString::fromUtf8("pushButton_UI_Mini"));
        pushButton_UI_Mini->setGeometry(QRect(650, 20, 32, 32));
        pushButton_UI_Mini->setStyleSheet(QString::fromUtf8("\n"
"                    QPushButton{\n"
"                    background-image:url(:/sys_button/resource/sys_button/mini.png);\n"
"                    color:rgb(220, 188, 96);\n"
"                    border-radius:0px;\n"
"                    }\n"
"                    QPushButton:hover {\n"
"                    background-image:url(:/sys_button/resource/sys_button/mini_hover.png);\n"
"                    }\n"
"                    QPushButton:pressed {\n"
"                    background-image:url(:/sys_button/resource/sys_button/mini_click.png);\n"
"                    }\n"
"                "));
        stackedWidget = new QStackedWidget(tianli__tianli_widget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(280, 100, 451, 311));
        stackedWidget->setAutoFillBackground(false);
        stackedWidget->setStyleSheet(QString::fromUtf8("QCheckBox::indicator:unchecked {\n"
"	width:16px;\n"
"	height:16px;\n"
"	padding:-4px;\n"
"	margin:4px;\n"
"	background-color:#999999;\n"
"	border-radius:4px;\n"
"}\n"
"\n"
"QCheckBox::indicator:checked {\n"
"	width:16px;\n"
"	height:16px;\n"
"	background-image: url(:/parts/Resource/checked.png);\n"
"    background-repeat:no-repeat;\n"
"    background-position:center;\n"
"    background-origin:border;\n"
"}"));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        label_Wizard_start = new QLabel(page);
        label_Wizard_start->setObjectName(QString::fromUtf8("label_Wizard_start"));
        label_Wizard_start->setGeometry(QRect(115, 10, 281, 21));
        label_Wizard_start->setFont(font);
        label_Wizard_start->setStyleSheet(QString::fromUtf8("\n"
"                            color:rgb(47, 47, 47);\n"
"                            font-size:16px;\n"
"                        "));
        label_Tag_Down = new QLabel(page);
        label_Tag_Down->setObjectName(QString::fromUtf8("label_Tag_Down"));
        label_Tag_Down->setGeometry(QRect(110, 210, 16, 2));
        label_Tag_Down->setStyleSheet(QString::fromUtf8("\n"
"                            background-color:rgb(219, 219, 219);\n"
"                        "));
        label_Readme = new QLabel(page);
        label_Readme->setObjectName(QString::fromUtf8("label_Readme"));
        label_Readme->setGeometry(QRect(110, 220, 331, 50));
        QFont font2;
        font2.setPointSize(10);
        font2.setBold(false);
        label_Readme->setFont(font2);
        label_Readme->setMouseTracking(true);
        label_Readme->setTextFormat(Qt::AutoText);
        label_Tag_Up = new QLabel(page);
        label_Tag_Up->setObjectName(QString::fromUtf8("label_Tag_Up"));
        label_Tag_Up->setGeometry(QRect(120, 0, 16, 2));
        label_Tag_Up->setStyleSheet(QString::fromUtf8("\n"
"                            background-color:rgb(219, 219, 219);\n"
"                        "));
        widget_CustomOption = new QWidget(page);
        widget_CustomOption->setObjectName(QString::fromUtf8("widget_CustomOption"));
        widget_CustomOption->setGeometry(QRect(110, 150, 331, 51));
        pushButton_preview = new QPushButton(widget_CustomOption);
        pushButton_preview->setObjectName(QString::fromUtf8("pushButton_preview"));
        pushButton_preview->setGeometry(QRect(290, 0, 38, 31));
        QFont font3;
        font3.setStyleStrategy(QFont::PreferDefault);
        pushButton_preview->setFont(font3);
        pushButton_preview->setStyleSheet(QString::fromUtf8("\n"
"                            color: #FFFFFF;\n"
"\n"
"                            font-size:13px;\n"
"                            position: absolute;\n"
"                            width: 58px;\n"
"                            height: 32px;\n"
"                            background: #FFC01C;\n"
"                            border-radius: 4px;\n"
"                        "));
        lineEdit_installPath = new QLineEdit(widget_CustomOption);
        lineEdit_installPath->setObjectName(QString::fromUtf8("lineEdit_installPath"));
        lineEdit_installPath->setGeometry(QRect(0, 0, 291, 30));
        QFont font4;
        font4.setFamily(QString::fromUtf8("sans-serif"));
        font4.setPointSize(9);
        font4.setBold(false);
        lineEdit_installPath->setFont(font4);
        lineEdit_installPath->setStyleSheet(QString::fromUtf8("background-color: rgba(0, 0, 0, 0);\n"
"border-bottom-color: rgb(242, 110, 75);\n"
"border-bottom-color: rgba(0, 0, 0, 0);\n"
"font-family: sans-serif\n"
""));
        lineEdit_installPath->setClearButtonEnabled(false);
        checkBox_desktopShortcut = new QCheckBox(widget_CustomOption);
        checkBox_desktopShortcut->setObjectName(QString::fromUtf8("checkBox_desktopShortcut"));
        checkBox_desktopShortcut->setGeometry(QRect(0, 30, 131, 20));
        checkBox_desktopShortcut->setFont(font2);
        checkBox_desktopShortcut->setChecked(true);
        checkBox_startMenuShortCut = new QCheckBox(widget_CustomOption);
        checkBox_startMenuShortCut->setObjectName(QString::fromUtf8("checkBox_startMenuShortCut"));
        checkBox_startMenuShortCut->setGeometry(QRect(130, 30, 181, 21));
        checkBox_startMenuShortCut->setFont(font2);
        checkBox_startMenuShortCut->setChecked(true);
        widget_CustomButtom = new QWidget(page);
        widget_CustomButtom->setObjectName(QString::fromUtf8("widget_CustomButtom"));
        widget_CustomButtom->setGeometry(QRect(10, 140, 451, 71));
        pushButton_CustomizeInstall = new QPushButton(widget_CustomButtom);
        pushButton_CustomizeInstall->setObjectName(QString::fromUtf8("pushButton_CustomizeInstall"));
        pushButton_CustomizeInstall->setGeometry(QRect(0, 0, 451, 64));
        pushButton_CustomizeInstall->setStyleSheet(QString::fromUtf8("\n"
"                            QPushButton{\n"
"                            background-color:rgba(255, 255, 255,0);\n"
"                            color:rgb(220, 188, 96);\n"
"                            border:0px solid rgb(204, 204, 204);\n"
"                            }\n"
"                            QPushButton:hover {\n"
"                            background-color:rgba(0,0,0, 24);\n"
"                            }\n"
"                            QPushButton:pressed {\n"
"                            background-color:rgba(0,0,0,12);\n"
"                            }\n"
"                        "));
        label_CustomizeInstall_Icon = new QLabel(widget_CustomButtom);
        label_CustomizeInstall_Icon->setObjectName(QString::fromUtf8("label_CustomizeInstall_Icon"));
        label_CustomizeInstall_Icon->setGeometry(QRect(100, 14, 16, 14));
        label_CustomizeInstall_Icon->setMouseTracking(true);
        label_CustomizeInstall_Icon->setStyleSheet(QString::fromUtf8("\n"
"                            background-image:url(:/parts/resource/vector.png);\n"
"                        "));
        label_CustomizeInstall_Documentation = new QLabel(widget_CustomButtom);
        label_CustomizeInstall_Documentation->setObjectName(QString::fromUtf8("label_CustomizeInstall_Documentation"));
        label_CustomizeInstall_Documentation->setGeometry(QRect(130, 35, 161, 17));
        label_CustomizeInstall_Documentation->setFont(font1);
        label_CustomizeInstall_Documentation->setMouseTracking(true);
        label_CustomizeInstall_Documentation->setStyleSheet(QString::fromUtf8("\n"
"                            color:rgba(0, 0, 0, 128);\n"
"                            font-size:13px;\n"
"                        "));
        label_CustomizeInstall = new QLabel(widget_CustomButtom);
        label_CustomizeInstall->setObjectName(QString::fromUtf8("label_CustomizeInstall"));
        label_CustomizeInstall->setGeometry(QRect(130, 10, 101, 19));
        label_CustomizeInstall->setFont(font);
        label_CustomizeInstall->setMouseTracking(true);
        label_CustomizeInstall->setStyleSheet(QString::fromUtf8("\n"
"                            font-size:14px;\n"
"                        "));
        label_CustomizeInstall_Icon->raise();
        label_CustomizeInstall_Documentation->raise();
        label_CustomizeInstall->raise();
        pushButton_CustomizeInstall->raise();
        widget_FastButtom = new QWidget(page);
        widget_FastButtom->setObjectName(QString::fromUtf8("widget_FastButtom"));
        widget_FastButtom->setGeometry(QRect(10, 70, 451, 71));
        label_FastInstall = new QLabel(widget_FastButtom);
        label_FastInstall->setObjectName(QString::fromUtf8("label_FastInstall"));
        label_FastInstall->setGeometry(QRect(130, 10, 81, 19));
        label_FastInstall->setFont(font);
        label_FastInstall->setMouseTracking(true);
        label_FastInstall->setStyleSheet(QString::fromUtf8("\n"
"                            font-size:14px;\n"
"                        "));
        label_FastInstall_Documentation = new QLabel(widget_FastButtom);
        label_FastInstall_Documentation->setObjectName(QString::fromUtf8("label_FastInstall_Documentation"));
        label_FastInstall_Documentation->setGeometry(QRect(130, 36, 161, 17));
        label_FastInstall_Documentation->setFont(font1);
        label_FastInstall_Documentation->setMouseTracking(true);
        label_FastInstall_Documentation->setStyleSheet(QString::fromUtf8("\n"
"                            color:rgba(0, 0, 0, 128);\n"
"                            font-size:13px;\n"
"                        "));
        pushButton_FastInstall = new QPushButton(widget_FastButtom);
        pushButton_FastInstall->setObjectName(QString::fromUtf8("pushButton_FastInstall"));
        pushButton_FastInstall->setGeometry(QRect(0, 0, 451, 64));
        pushButton_FastInstall->setStyleSheet(QString::fromUtf8("\n"
"                            QPushButton{\n"
"                            background-color:rgba(255, 255, 255,0);\n"
"                            color:rgb(220, 188, 96);\n"
"                            border:0px solid rgb(204, 204, 204);\n"
"                            }\n"
"                            QPushButton:hover {\n"
"                            background-color:rgba(0,0,0, 24);\n"
"                            }\n"
"                            QPushButton:pressed {\n"
"                            background-color:rgba(0,0,0,12);\n"
"                            }\n"
"                        "));
        label_FastInstall_Icon = new QLabel(widget_FastButtom);
        label_FastInstall_Icon->setObjectName(QString::fromUtf8("label_FastInstall_Icon"));
        label_FastInstall_Icon->setGeometry(QRect(100, 12, 16, 14));
        label_FastInstall_Icon->setMouseTracking(true);
        label_FastInstall_Icon->setStyleSheet(QString::fromUtf8("\n"
"                            background-image:url(:/parts/resource/vector.png);\n"
"                        "));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        label_Wizard_installing = new QLabel(page_2);
        label_Wizard_installing->setObjectName(QString::fromUtf8("label_Wizard_installing"));
        label_Wizard_installing->setGeometry(QRect(115, 10, 291, 21));
        label_Wizard_installing->setFont(font);
        label_Wizard_installing->setStyleSheet(QString::fromUtf8("\n"
"                            color:rgb(47, 47, 47);\n"
"                            font-size:16px;\n"
"                        "));
        pushButton_Finishing_Cancel = new QPushButton(page_2);
        pushButton_Finishing_Cancel->setObjectName(QString::fromUtf8("pushButton_Finishing_Cancel"));
        pushButton_Finishing_Cancel->setGeometry(QRect(115, 220, 84, 32));
        pushButton_Finishing_Cancel->setFont(font1);
        pushButton_Finishing_Cancel->setStyleSheet(QString::fromUtf8("\n"
"                            color: #7B7B7B;\n"
"                            font-size:13px;\n"
"                            position: absolute;\n"
"                            width: 58px;\n"
"                            height: 32px;\n"
"                            left: calc(50% - 58px/2 + 132.5px);\n"
"                            top: calc(50% - 32px/2 + 134px);\n"
"                            border: 2px solid #D1D1D1;\n"
"                            border-radius: 4px;\n"
"                        "));
        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        label_Wizard_finish = new QLabel(page_3);
        label_Wizard_finish->setObjectName(QString::fromUtf8("label_Wizard_finish"));
        label_Wizard_finish->setGeometry(QRect(115, 10, 301, 21));
        label_Wizard_finish->setFont(font);
        label_Wizard_finish->setStyleSheet(QString::fromUtf8("\n"
"                            color:rgb(47, 47, 47);\n"
"                            font-size:16px;\n"
"                        "));
        label_Documentation = new QLabel(page_3);
        label_Documentation->setObjectName(QString::fromUtf8("label_Documentation"));
        label_Documentation->setGeometry(QRect(110, 40, 281, 41));
        label_Documentation->setFont(font2);
        label_Documentation->setStyleSheet(QString::fromUtf8("\n"
"                            color:rgb(47, 47, 47);\n"
"                        "));
        label_Documentation->setTextFormat(Qt::RichText);
        label_Documentation->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label_Documentation->setWordWrap(true);
        horizontalLayoutWidget = new QWidget(page_3);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(119, 99, 231, 81));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_Icon_0 = new QLabel(horizontalLayoutWidget);
        label_Icon_0->setObjectName(QString::fromUtf8("label_Icon_0"));
        label_Icon_0->setMinimumSize(QSize(64, 64));
        label_Icon_0->setMaximumSize(QSize(64, 64));
        label_Icon_0->setStyleSheet(QString::fromUtf8("\n"
"                                        font-size:13px;\n"
"                                    "));

        horizontalLayout->addWidget(label_Icon_0);

        label_Icon_1 = new QLabel(horizontalLayoutWidget);
        label_Icon_1->setObjectName(QString::fromUtf8("label_Icon_1"));
        label_Icon_1->setMinimumSize(QSize(64, 64));
        label_Icon_1->setMaximumSize(QSize(64, 64));
        label_Icon_1->setStyleSheet(QString::fromUtf8("\n"
"                                        font-size:13px;\n"
"                                    "));

        horizontalLayout->addWidget(label_Icon_1);

        pushButton_Finished_Run = new QPushButton(page_3);
        pushButton_Finished_Run->setObjectName(QString::fromUtf8("pushButton_Finished_Run"));
        pushButton_Finished_Run->setGeometry(QRect(115, 220, 58, 32));
        pushButton_Finished_Run->setFont(font1);
        pushButton_Finished_Run->setStyleSheet(QString::fromUtf8("\n"
"                            color: #FFFFFF;\n"
"                            font-size:13px;\n"
"                            position: absolute;\n"
"                            width: 58px;\n"
"                            height: 32px;\n"
"                            left: calc(50% - 58px/2 + 62.5px);\n"
"                            top: calc(50% - 32px/2 + 134px);\n"
"                            background: #FFC01C;\n"
"                            border-radius: 4px;\n"
"                        "));
        pushButton_Finished_Exit = new QPushButton(page_3);
        pushButton_Finished_Exit->setObjectName(QString::fromUtf8("pushButton_Finished_Exit"));
        pushButton_Finished_Exit->setGeometry(QRect(190, 220, 58, 32));
        pushButton_Finished_Exit->setFont(font1);
        pushButton_Finished_Exit->setStyleSheet(QString::fromUtf8("\n"
"                            color: #7B7B7B;\n"
"                            font-size:13px;\n"
"                            position: absolute;\n"
"                            width: 58px;\n"
"                            height: 32px;\n"
"                            left: calc(50% - 58px/2 + 132.5px);\n"
"                            top: calc(50% - 32px/2 + 134px);\n"
"                            border: 2px solid #D1D1D1;\n"
"                            border-radius: 4px;\n"
"                        "));
        stackedWidget->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName(QString::fromUtf8("page_4"));
        label_Wizard_failed = new QLabel(page_4);
        label_Wizard_failed->setObjectName(QString::fromUtf8("label_Wizard_failed"));
        label_Wizard_failed->setGeometry(QRect(115, 10, 301, 21));
        label_Wizard_failed->setFont(font);
        label_Wizard_failed->setStyleSheet(QString::fromUtf8("\n"
"                            color:rgb(47, 47, 47);\n"
"                            font-size:16px;\n"
"                        "));
        label_err_documentation = new QLabel(page_4);
        label_err_documentation->setObjectName(QString::fromUtf8("label_err_documentation"));
        label_err_documentation->setGeometry(QRect(110, 40, 281, 21));
        label_err_documentation->setFont(font2);
        label_err_documentation->setStyleSheet(QString::fromUtf8("\n"
"                            color:rgb(47, 47, 47);\n"
"                        "));
        label_err_documentation->setTextFormat(Qt::RichText);
        label_err_documentation->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label_err_documentation->setWordWrap(true);
        pushButton_Fail_Close_2 = new QPushButton(page_4);
        pushButton_Fail_Close_2->setObjectName(QString::fromUtf8("pushButton_Fail_Close_2"));
        pushButton_Fail_Close_2->setGeometry(QRect(120, 220, 84, 32));
        pushButton_Fail_Close_2->setFont(font1);
        pushButton_Fail_Close_2->setStyleSheet(QString::fromUtf8("\n"
"                            color: #7B7B7B;\n"
"                            font-size:13px;\n"
"                            position: absolute;\n"
"                            width: 58px;\n"
"                            height: 32px;\n"
"                            left: calc(50% - 58px/2 + 132.5px);\n"
"                            top: calc(50% - 32px/2 + 134px);\n"
"                            border: 2px solid #D1D1D1;\n"
"                            border-radius: 4px;\n"
"                        "));
        label_err_info = new QLabel(page_4);
        label_err_info->setObjectName(QString::fromUtf8("label_err_info"));
        label_err_info->setGeometry(QRect(120, 70, 301, 111));
        QFont font5;
        font5.setPointSize(10);
        label_err_info->setFont(font5);
        label_err_info->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        stackedWidget->addWidget(page_4);
        label_MainImage = new QLabel(tianli__tianli_widget);
        label_MainImage->setObjectName(QString::fromUtf8("label_MainImage"));
        label_MainImage->setGeometry(QRect(10, 10, 345, 404));
        label_MainImage->setStyleSheet(QString::fromUtf8("\n"
"                    background-image:url(:/tianli/resource/bg.png);\n"
"                    border:none;\n"
"                    border-radius:5px;\n"
"                "));
#if QT_CONFIG(shortcut)
        label_MainImage->setBuddy(pushButton_UI_Mini);
#endif // QT_CONFIG(shortcut)

        retranslateUi(tianli__tianli_widget);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(tianli__tianli_widget);
    } // setupUi

    void retranslateUi(QWidget *tianli__tianli_widget)
    {
        tianli__tianli_widget->setWindowTitle(QCoreApplication::translate("tianli::tianli_widget", "\347\251\272\350\215\247\351\205\222\351\246\206\345\216\237\347\245\236\345\234\260\345\233\276\345\256\211\350\243\205\345\220\221\345\257\274", nullptr));
        label_MainShadow->setText(QString());
        label_MainShadow_A->setText(QString());
        label_MainShadow_B->setText(QString());
        label_Satellite_Orbit->setText(QString());
        label_Star->setText(QString());
        label_Title->setText(QCoreApplication::translate("tianli::tianli_widget", "\347\251\272\350\215\247\351\205\222\351\246\206\342\204\242", nullptr));
        pushButton_UI_Close->setText(QString());
        pushButton_UI_Mini->setText(QString());
        label_Wizard_start->setText(QCoreApplication::translate("tianli::tianli_widget", "\345\216\237\347\245\236\350\265\204\346\272\220\345\234\260\345\233\276 \345\256\211\350\243\205\345\220\221\345\257\274", nullptr));
        label_Tag_Down->setText(QString());
        label_Readme->setText(QCoreApplication::translate("tianli::tianli_widget", "<html><head/><body><p style=\"margin:5px;\"><span style=\" color:#909090;\">Tips: \345\256\211\350\243\205\345\271\266\344\275\277\347\224\250\342\200\234\347\251\272\350\215\247\351\205\222\351\246\206\345\216\237\347\245\236\345\234\260\345\233\276\342\200\235</span></p><p style=\"margin:5px;\"><span style=\" color:#909090;\">\346\204\217\345\221\263\347\235\200\346\202\250\345\220\214\346\204\217\345\271\266\351\201\265\345\256\210</span><a href=\"https://yuanshen.site/docs/disclaimer.html\"><span style=\" text-decoration: underline; color:#ee623c;\">\343\200\212\347\224\250\346\210\267\344\275\277\347\224\250\345\215\217\350\256\256\343\200\213</span></a></p></body></html>", nullptr));
        label_Tag_Up->setText(QString());
        pushButton_preview->setText(QCoreApplication::translate("tianli::tianli_widget", "\351\242\204\350\247\210", nullptr));
        lineEdit_installPath->setText(QCoreApplication::translate("tianli::tianli_widget", "C:\\Program Files\\KongYingMap", nullptr));
        checkBox_desktopShortcut->setText(QCoreApplication::translate("tianli::tianli_widget", "\346\241\214\351\235\242\345\277\253\346\215\267\346\226\271\345\274\217", nullptr));
        checkBox_startMenuShortCut->setText(QCoreApplication::translate("tianli::tianli_widget", "\345\274\200\345\247\213\350\217\234\345\215\225\345\277\253\346\215\267\346\226\271\345\274\217", nullptr));
        pushButton_CustomizeInstall->setText(QString());
        label_CustomizeInstall_Icon->setText(QString());
        label_CustomizeInstall_Documentation->setText(QCoreApplication::translate("tianli::tianli_widget", "\350\256\276\345\256\232\345\256\211\350\243\205\346\227\266\347\232\204\351\200\211\351\241\271", nullptr));
        label_CustomizeInstall->setText(QCoreApplication::translate("tianli::tianli_widget", "\350\207\252\345\256\232\344\271\211", nullptr));
        label_FastInstall->setText(QCoreApplication::translate("tianli::tianli_widget", "\345\277\253\351\200\237\345\256\211\350\243\205", nullptr));
        label_FastInstall_Documentation->setText(QCoreApplication::translate("tianli::tianli_widget", "\346\214\211\347\205\247\347\250\213\345\272\217\351\242\204\350\256\276\350\277\233\350\241\214\345\256\211\350\243\205", nullptr));
        pushButton_FastInstall->setText(QString());
        label_FastInstall_Icon->setText(QString());
        label_Wizard_installing->setText(QCoreApplication::translate("tianli::tianli_widget", "\345\216\237\347\245\236\350\265\204\346\272\220\345\234\260\345\233\276 \346\255\243\345\234\250\345\256\211\350\243\205", nullptr));
        pushButton_Finishing_Cancel->setText(QCoreApplication::translate("tianli::tianli_widget", "\345\217\226\346\266\210\345\256\211\350\243\205", nullptr));
        label_Wizard_finish->setText(QCoreApplication::translate("tianli::tianli_widget", "\345\216\237\347\245\236\350\265\204\346\272\220\345\234\260\345\233\276 \345\256\211\350\243\205\345\256\214\346\210\220", nullptr));
        label_Documentation->setText(QCoreApplication::translate("tianli::tianli_widget", "<html><head/><body><p>\346\204\237\350\260\242\346\202\250\347\232\204\345\256\211\350\243\205\357\274\214\346\202\250\345\217\257\344\273\245\351\200\232\350\277\207\344\273\245\344\270\213\346\226\271\345\274\217\345\205\263\346\263\250\346\210\221\344\273\254\347\232\204\347\244\276\344\272\244\350\264\246\345\217\267\357\274\232</p></body></html>", nullptr));
        label_Icon_0->setText(QString());
        label_Icon_1->setText(QString());
        pushButton_Finished_Run->setText(QCoreApplication::translate("tianli::tianli_widget", "\345\220\257\345\212\250", nullptr));
        pushButton_Finished_Exit->setText(QCoreApplication::translate("tianli::tianli_widget", "\351\200\200\345\207\272", nullptr));
        label_Wizard_failed->setText(QCoreApplication::translate("tianli::tianli_widget", "\345\216\237\347\245\236\350\265\204\346\272\220\345\234\260\345\233\276 \345\256\211\350\243\205\345\244\261\350\264\245", nullptr));
        label_err_documentation->setText(QCoreApplication::translate("tianli::tianli_widget", "<html><head/><body><p>\345\276\210\351\201\227\346\206\276\357\274\214\345\256\211\350\243\205\345\244\261\350\264\245\344\272\206\357\274\214\350\257\267\345\217\202\351\230\205\344\273\245\344\270\213\344\277\241\346\201\257\357\274\232</p></body></html>", nullptr));
        pushButton_Fail_Close_2->setText(QCoreApplication::translate("tianli::tianli_widget", "\345\205\263\351\227\255", nullptr));
        label_err_info->setText(QCoreApplication::translate("tianli::tianli_widget", "\347\224\250\346\210\267\345\217\226\346\266\210\344\272\206\345\256\211\350\243\205", nullptr));
        label_MainImage->setText(QString());
    } // retranslateUi

};

} // namespace tianli

namespace tianli {
namespace Ui {
    class tianli_widget: public Ui_tianli_widget {};
} // namespace Ui
} // namespace tianli

#endif // UI_TIANLI_WIDGET_H
