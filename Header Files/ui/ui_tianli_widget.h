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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
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
    QLabel *label_MainImage;
    QStackedWidget *stackedWidget_2;
    QWidget *page_install;
    QStackedWidget *stackedWidget_install;
    QWidget *page_1;
    QLabel *label_Wizard_start;
    QLabel *label_Tag_Down;
    QLabel *label_Readme;
    QLabel *label_Tag_Up;
    QWidget *widget_CustomOption;
    QStackedWidget *stackedWidget_InstallCustom;
    QWidget *page1_CustomInstallButtom;
    QPushButton *pushButton_CustomizeInstall;
    QLabel *label_CustomizeInstall_Icon;
    QLabel *label_CustomizeInstall_Documentation;
    QLabel *label_CustomizeInstall;
    QWidget *page2_CustomInstallOption;
    QCheckBox *checkBox_startMenuShortCut;
    QPushButton *pushButton_preview;
    QLineEdit *lineEdit_installPath;
    QCheckBox *checkBox_desktopShortcut;
    QWidget *widget_FastButtom;
    QLabel *label_FastInstall;
    QLabel *label_FastInstall_Documentation;
    QPushButton *pushButton_FastInstall;
    QLabel *label_FastInstall_Icon;
    QWidget *page_2;
    QLabel *label_Wizard_installing;
    QPushButton *pushButton_installing_Cancel;
    QWidget *page_3;
    QLabel *label_Wizard_finish;
    QLabel *label_Documentation;
    QWidget *horizontalLayoutWidget;
    QGridLayout *gridLayout_externLink;
    QSpacerItem *horizontalSpacer;
    QLabel *label_Icon_bilibili;
    QLabel *label_Icon_youtube;
    QLabel *label_bilibili;
    QLabel *label_youtube;
    QPushButton *pushButton_Finished_Run;
    QPushButton *pushButton_Finished_Exit;
    QWidget *page_4;
    QLabel *label_Wizard_failed;
    QLabel *label_err_documentation;
    QPushButton *pushButton_Fail_Close;
    QLabel *label_err_info;
    QWidget *page_update;
    QStackedWidget *stackedWidget_update;
    QWidget *page_6;
    QLabel *label_Wizard_start_Update;
    QLabel *label_Tag_Down_2;
    QLabel *label_Readme_Update;
    QLabel *label_Tag_Up_2;
    QStackedWidget *stackedWidget_UpdataCustom;
    QWidget *page1_CustomUpdateButtom;
    QPushButton *pushButton_CustomizeUpdate;
    QLabel *label_CustomizeUpdate_Icon;
    QLabel *label_CustomizeUpdate_Documentation;
    QLabel *label_CustomizeUpdate;
    QWidget *page2_CustomUpdateOption;
    QCheckBox *checkBox_startMenuShortCutUpdate;
    QCheckBox *checkBox_desktopShortcutUpdate;
    QWidget *widget_FastButtom_Update;
    QLabel *label_FastUpdate;
    QLabel *label_FastUpdate_Documentation;
    QPushButton *pushButton_FastUpdate;
    QLabel *label_FastUpdate_Icon;
    QWidget *page_7;
    QLabel *label_Wizard_updateing;
    QPushButton *pushButton_update_Cancel;
    QWidget *page_8;
    QLabel *label_Wizard_finish_Update;
    QLabel *label_Documentation_Update;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_Icon_2;
    QLabel *label_Icon_3;
    QPushButton *pushButton_Finished_Run_Update;
    QPushButton *pushButton_Finished_Exit_Update;
    QWidget *page_9;
    QLabel *label_Wizard_failed_Update;
    QLabel *label_err_documentation_Update;
    QPushButton *pushButton_Fail_Close_Updaye;
    QLabel *label_err_info_Update;
    QWidget *page_uninstall;
    QStackedWidget *stackedWidget_uninstall;
    QWidget *page_14;
    QLabel *label_Wizard_start_uninstall;
    QLabel *label_Tag_Down_4;
    QLabel *label_Tag_Up_4;
    QStackedWidget *stackedWidget_UnInstallCustom;
    QWidget *page2_CustomUnInstallOption;
    QCheckBox *checkBox_removeUserData;
    QWidget *widget_FastUninstallButtom;
    QLabel *label_FastUninstall;
    QLabel *label_FastUninstall_Documentation;
    QPushButton *pushButton_FastUninstall;
    QLabel *label_FastUninstall_Icon;
    QLabel *label_Uninstall_ReadMe;
    QWidget *page_15;
    QLabel *label_Wizard_Uninstalling;
    QPushButton *pushButton_Uninstall_Cancel;
    QWidget *page_16;
    QLabel *label_Wizard_finish_Uninstall;
    QLabel *label_Documentation_Uninstall;
    QWidget *horizontalLayoutWidget_4;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_Icon_6;
    QLabel *label_Icon_7;
    QPushButton *pushButton_Finished_Exit_Uninstall;
    QWidget *page_17;
    QLabel *label_Wizard_failed_Uninstall;
    QLabel *label_err_documentation_Uninstall;
    QPushButton *pushButton_Fail_Close_Uninstall;
    QLabel *label_err_info_Uninstall;

    void setupUi(QWidget *tianli__tianli_widget)
    {
        if (tianli__tianli_widget->objectName().isEmpty())
            tianli__tianli_widget->setObjectName(QString::fromUtf8("tianli__tianli_widget"));
        tianli__tianli_widget->resize(743, 425);
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
        label_Title->setGeometry(QRect(390, 56, 140, 40));
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
        label_MainImage = new QLabel(tianli__tianli_widget);
        label_MainImage->setObjectName(QString::fromUtf8("label_MainImage"));
        label_MainImage->setGeometry(QRect(10, 10, 345, 404));
        label_MainImage->setStyleSheet(QString::fromUtf8("\n"
"                    background-image:url(:/tianli/resource/bg.png);\n"
"                    border:none;\n"
"                    border-radius:5px;\n"
"                "));
        stackedWidget_2 = new QStackedWidget(tianli__tianli_widget);
        stackedWidget_2->setObjectName(QString::fromUtf8("stackedWidget_2"));
        stackedWidget_2->setGeometry(QRect(280, 90, 451, 331));
        page_install = new QWidget();
        page_install->setObjectName(QString::fromUtf8("page_install"));
        stackedWidget_install = new QStackedWidget(page_install);
        stackedWidget_install->setObjectName(QString::fromUtf8("stackedWidget_install"));
        stackedWidget_install->setGeometry(QRect(0, 10, 451, 301));
        stackedWidget_install->setAutoFillBackground(false);
        stackedWidget_install->setStyleSheet(QString::fromUtf8("QCheckBox::indicator:unchecked {\n"
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
        page_1 = new QWidget();
        page_1->setObjectName(QString::fromUtf8("page_1"));
        label_Wizard_start = new QLabel(page_1);
        label_Wizard_start->setObjectName(QString::fromUtf8("label_Wizard_start"));
        label_Wizard_start->setGeometry(QRect(115, 10, 281, 21));
        label_Wizard_start->setFont(font);
        label_Wizard_start->setStyleSheet(QString::fromUtf8("\n"
"                            color:rgb(47, 47, 47);\n"
"                            font-size:16px;\n"
"                        "));
        label_Tag_Down = new QLabel(page_1);
        label_Tag_Down->setObjectName(QString::fromUtf8("label_Tag_Down"));
        label_Tag_Down->setGeometry(QRect(110, 210, 16, 2));
        label_Tag_Down->setStyleSheet(QString::fromUtf8("\n"
"                            background-color:rgb(219, 219, 219);\n"
"                        "));
        label_Readme = new QLabel(page_1);
        label_Readme->setObjectName(QString::fromUtf8("label_Readme"));
        label_Readme->setGeometry(QRect(110, 220, 331, 50));
        QFont font2;
        font2.setPointSize(10);
        font2.setBold(false);
        label_Readme->setFont(font2);
        label_Readme->setMouseTracking(true);
        label_Readme->setTextFormat(Qt::AutoText);
        label_Readme->setOpenExternalLinks(true);
        label_Tag_Up = new QLabel(page_1);
        label_Tag_Up->setObjectName(QString::fromUtf8("label_Tag_Up"));
        label_Tag_Up->setGeometry(QRect(110, 0, 16, 2));
        label_Tag_Up->setStyleSheet(QString::fromUtf8("\n"
"                            background-color:rgb(219, 219, 219);\n"
"                        "));
        widget_CustomOption = new QWidget(page_1);
        widget_CustomOption->setObjectName(QString::fromUtf8("widget_CustomOption"));
        widget_CustomOption->setGeometry(QRect(110, 150, 331, 51));
        stackedWidget_InstallCustom = new QStackedWidget(page_1);
        stackedWidget_InstallCustom->setObjectName(QString::fromUtf8("stackedWidget_InstallCustom"));
        stackedWidget_InstallCustom->setGeometry(QRect(10, 140, 451, 71));
        page1_CustomInstallButtom = new QWidget();
        page1_CustomInstallButtom->setObjectName(QString::fromUtf8("page1_CustomInstallButtom"));
        pushButton_CustomizeInstall = new QPushButton(page1_CustomInstallButtom);
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
        label_CustomizeInstall_Icon = new QLabel(page1_CustomInstallButtom);
        label_CustomizeInstall_Icon->setObjectName(QString::fromUtf8("label_CustomizeInstall_Icon"));
        label_CustomizeInstall_Icon->setGeometry(QRect(100, 14, 16, 14));
        label_CustomizeInstall_Icon->setMouseTracking(true);
        label_CustomizeInstall_Icon->setStyleSheet(QString::fromUtf8("\n"
"                            background-image:url(:/parts/resource/vector.png);\n"
"                        "));
        label_CustomizeInstall_Documentation = new QLabel(page1_CustomInstallButtom);
        label_CustomizeInstall_Documentation->setObjectName(QString::fromUtf8("label_CustomizeInstall_Documentation"));
        label_CustomizeInstall_Documentation->setGeometry(QRect(130, 35, 261, 17));
        label_CustomizeInstall_Documentation->setFont(font1);
        label_CustomizeInstall_Documentation->setMouseTracking(true);
        label_CustomizeInstall_Documentation->setStyleSheet(QString::fromUtf8("\n"
"                            color:rgba(0, 0, 0, 128);\n"
"                            font-size:13px;\n"
"                        "));
        label_CustomizeInstall = new QLabel(page1_CustomInstallButtom);
        label_CustomizeInstall->setObjectName(QString::fromUtf8("label_CustomizeInstall"));
        label_CustomizeInstall->setGeometry(QRect(130, 10, 101, 19));
        label_CustomizeInstall->setFont(font);
        label_CustomizeInstall->setMouseTracking(true);
        label_CustomizeInstall->setStyleSheet(QString::fromUtf8("\n"
"                            font-size:14px;\n"
"                        "));
        stackedWidget_InstallCustom->addWidget(page1_CustomInstallButtom);
        label_CustomizeInstall_Icon->raise();
        label_CustomizeInstall_Documentation->raise();
        label_CustomizeInstall->raise();
        pushButton_CustomizeInstall->raise();
        page2_CustomInstallOption = new QWidget();
        page2_CustomInstallOption->setObjectName(QString::fromUtf8("page2_CustomInstallOption"));
        checkBox_startMenuShortCut = new QCheckBox(page2_CustomInstallOption);
        checkBox_startMenuShortCut->setObjectName(QString::fromUtf8("checkBox_startMenuShortCut"));
        checkBox_startMenuShortCut->setGeometry(QRect(230, 40, 181, 21));
        checkBox_startMenuShortCut->setFont(font2);
        checkBox_startMenuShortCut->setChecked(true);
        pushButton_preview = new QPushButton(page2_CustomInstallOption);
        pushButton_preview->setObjectName(QString::fromUtf8("pushButton_preview"));
        pushButton_preview->setGeometry(QRect(390, 10, 38, 31));
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
        lineEdit_installPath = new QLineEdit(page2_CustomInstallOption);
        lineEdit_installPath->setObjectName(QString::fromUtf8("lineEdit_installPath"));
        lineEdit_installPath->setGeometry(QRect(100, 10, 291, 30));
        lineEdit_installPath->setStyleSheet(QString::fromUtf8("background-color: rgba(0, 0, 0, 0);\n"
"border-bottom-color: rgb(242, 110, 75);\n"
"border-bottom-color: rgba(0, 0, 0, 0);\n"
""));
        lineEdit_installPath->setClearButtonEnabled(false);
        checkBox_desktopShortcut = new QCheckBox(page2_CustomInstallOption);
        checkBox_desktopShortcut->setObjectName(QString::fromUtf8("checkBox_desktopShortcut"));
        checkBox_desktopShortcut->setGeometry(QRect(100, 40, 131, 20));
        checkBox_desktopShortcut->setFont(font2);
        checkBox_desktopShortcut->setChecked(true);
        stackedWidget_InstallCustom->addWidget(page2_CustomInstallOption);
        widget_FastButtom = new QWidget(page_1);
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
        stackedWidget_install->addWidget(page_1);
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
        pushButton_installing_Cancel = new QPushButton(page_2);
        pushButton_installing_Cancel->setObjectName(QString::fromUtf8("pushButton_installing_Cancel"));
        pushButton_installing_Cancel->setGeometry(QRect(115, 220, 84, 32));
        pushButton_installing_Cancel->setFont(font1);
        pushButton_installing_Cancel->setStyleSheet(QString::fromUtf8("\n"
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
        stackedWidget_install->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        label_Wizard_finish = new QLabel(page_3);
        label_Wizard_finish->setObjectName(QString::fromUtf8("label_Wizard_finish"));
        label_Wizard_finish->setGeometry(QRect(110, 10, 301, 21));
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
        horizontalLayoutWidget->setGeometry(QRect(110, 90, 321, 102));
        gridLayout_externLink = new QGridLayout(horizontalLayoutWidget);
        gridLayout_externLink->setSpacing(10);
        gridLayout_externLink->setObjectName(QString::fromUtf8("gridLayout_externLink"));
        gridLayout_externLink->setSizeConstraint(QLayout::SetDefaultConstraint);
        gridLayout_externLink->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_externLink->addItem(horizontalSpacer, 1, 2, 1, 1);

        label_Icon_bilibili = new QLabel(horizontalLayoutWidget);
        label_Icon_bilibili->setObjectName(QString::fromUtf8("label_Icon_bilibili"));
        label_Icon_bilibili->setStyleSheet(QString::fromUtf8("\n"
"                                        font-size:13px;\n"
"                                    "));
        label_Icon_bilibili->setPixmap(QPixmap(QString::fromUtf8(":/link/Resource/bilibili.png")));
        label_Icon_bilibili->setOpenExternalLinks(true);

        gridLayout_externLink->addWidget(label_Icon_bilibili, 1, 0, 1, 1);

        label_Icon_youtube = new QLabel(horizontalLayoutWidget);
        label_Icon_youtube->setObjectName(QString::fromUtf8("label_Icon_youtube"));
        label_Icon_youtube->setStyleSheet(QString::fromUtf8("\n"
"                                        font-size:13px;\n"
"                                    "));
        label_Icon_youtube->setPixmap(QPixmap(QString::fromUtf8(":/link/Resource/youtube.png")));
        label_Icon_youtube->setOpenExternalLinks(true);

        gridLayout_externLink->addWidget(label_Icon_youtube, 2, 0, 1, 1);

        label_bilibili = new QLabel(horizontalLayoutWidget);
        label_bilibili->setObjectName(QString::fromUtf8("label_bilibili"));
        QFont font4;
        font4.setPointSize(11);
        font4.setBold(false);
        label_bilibili->setFont(font4);
        label_bilibili->setOpenExternalLinks(true);

        gridLayout_externLink->addWidget(label_bilibili, 1, 1, 1, 1);

        label_youtube = new QLabel(horizontalLayoutWidget);
        label_youtube->setObjectName(QString::fromUtf8("label_youtube"));
        label_youtube->setFont(font4);
        label_youtube->setOpenExternalLinks(true);

        gridLayout_externLink->addWidget(label_youtube, 2, 1, 1, 1);

        pushButton_Finished_Run = new QPushButton(page_3);
        pushButton_Finished_Run->setObjectName(QString::fromUtf8("pushButton_Finished_Run"));
        pushButton_Finished_Run->setGeometry(QRect(110, 220, 61, 32));
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
        pushButton_Finished_Exit->setGeometry(QRect(190, 220, 61, 32));
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
        stackedWidget_install->addWidget(page_3);
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
        label_err_documentation->setGeometry(QRect(110, 40, 281, 41));
        label_err_documentation->setFont(font2);
        label_err_documentation->setStyleSheet(QString::fromUtf8("\n"
"                            color:rgb(47, 47, 47);\n"
"                        "));
        label_err_documentation->setTextFormat(Qt::RichText);
        label_err_documentation->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label_err_documentation->setWordWrap(true);
        pushButton_Fail_Close = new QPushButton(page_4);
        pushButton_Fail_Close->setObjectName(QString::fromUtf8("pushButton_Fail_Close"));
        pushButton_Fail_Close->setGeometry(QRect(120, 220, 84, 32));
        pushButton_Fail_Close->setFont(font1);
        pushButton_Fail_Close->setStyleSheet(QString::fromUtf8("\n"
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
        label_err_info->setGeometry(QRect(120, 90, 301, 91));
        QFont font5;
        font5.setPointSize(10);
        label_err_info->setFont(font5);
        label_err_info->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label_err_info->setWordWrap(true);
        stackedWidget_install->addWidget(page_4);
        stackedWidget_2->addWidget(page_install);
        page_update = new QWidget();
        page_update->setObjectName(QString::fromUtf8("page_update"));
        stackedWidget_update = new QStackedWidget(page_update);
        stackedWidget_update->setObjectName(QString::fromUtf8("stackedWidget_update"));
        stackedWidget_update->setGeometry(QRect(0, 10, 451, 301));
        stackedWidget_update->setAutoFillBackground(false);
        stackedWidget_update->setStyleSheet(QString::fromUtf8("QCheckBox::indicator:unchecked {\n"
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
        page_6 = new QWidget();
        page_6->setObjectName(QString::fromUtf8("page_6"));
        label_Wizard_start_Update = new QLabel(page_6);
        label_Wizard_start_Update->setObjectName(QString::fromUtf8("label_Wizard_start_Update"));
        label_Wizard_start_Update->setGeometry(QRect(115, 10, 281, 21));
        label_Wizard_start_Update->setFont(font);
        label_Wizard_start_Update->setStyleSheet(QString::fromUtf8("\n"
"                            color:rgb(47, 47, 47);\n"
"                            font-size:16px;\n"
"                        "));
        label_Tag_Down_2 = new QLabel(page_6);
        label_Tag_Down_2->setObjectName(QString::fromUtf8("label_Tag_Down_2"));
        label_Tag_Down_2->setGeometry(QRect(110, 210, 16, 2));
        label_Tag_Down_2->setStyleSheet(QString::fromUtf8("\n"
"                            background-color:rgb(219, 219, 219);\n"
"                        "));
        label_Readme_Update = new QLabel(page_6);
        label_Readme_Update->setObjectName(QString::fromUtf8("label_Readme_Update"));
        label_Readme_Update->setGeometry(QRect(110, 220, 331, 50));
        label_Readme_Update->setFont(font2);
        label_Readme_Update->setMouseTracking(true);
        label_Readme_Update->setTextFormat(Qt::AutoText);
        label_Readme_Update->setOpenExternalLinks(true);
        label_Tag_Up_2 = new QLabel(page_6);
        label_Tag_Up_2->setObjectName(QString::fromUtf8("label_Tag_Up_2"));
        label_Tag_Up_2->setGeometry(QRect(110, 0, 16, 2));
        label_Tag_Up_2->setStyleSheet(QString::fromUtf8("\n"
"                            background-color:rgb(219, 219, 219);\n"
"                        "));
        stackedWidget_UpdataCustom = new QStackedWidget(page_6);
        stackedWidget_UpdataCustom->setObjectName(QString::fromUtf8("stackedWidget_UpdataCustom"));
        stackedWidget_UpdataCustom->setGeometry(QRect(10, 140, 451, 71));
        page1_CustomUpdateButtom = new QWidget();
        page1_CustomUpdateButtom->setObjectName(QString::fromUtf8("page1_CustomUpdateButtom"));
        pushButton_CustomizeUpdate = new QPushButton(page1_CustomUpdateButtom);
        pushButton_CustomizeUpdate->setObjectName(QString::fromUtf8("pushButton_CustomizeUpdate"));
        pushButton_CustomizeUpdate->setGeometry(QRect(0, 0, 451, 64));
        pushButton_CustomizeUpdate->setStyleSheet(QString::fromUtf8("\n"
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
        label_CustomizeUpdate_Icon = new QLabel(page1_CustomUpdateButtom);
        label_CustomizeUpdate_Icon->setObjectName(QString::fromUtf8("label_CustomizeUpdate_Icon"));
        label_CustomizeUpdate_Icon->setGeometry(QRect(100, 14, 16, 14));
        label_CustomizeUpdate_Icon->setMouseTracking(true);
        label_CustomizeUpdate_Icon->setStyleSheet(QString::fromUtf8("\n"
"                            background-image:url(:/parts/resource/vector.png);\n"
"                        "));
        label_CustomizeUpdate_Documentation = new QLabel(page1_CustomUpdateButtom);
        label_CustomizeUpdate_Documentation->setObjectName(QString::fromUtf8("label_CustomizeUpdate_Documentation"));
        label_CustomizeUpdate_Documentation->setGeometry(QRect(130, 35, 161, 17));
        label_CustomizeUpdate_Documentation->setFont(font1);
        label_CustomizeUpdate_Documentation->setMouseTracking(true);
        label_CustomizeUpdate_Documentation->setStyleSheet(QString::fromUtf8("\n"
"                            color:rgba(0, 0, 0, 128);\n"
"                            font-size:13px;\n"
"                        "));
        label_CustomizeUpdate = new QLabel(page1_CustomUpdateButtom);
        label_CustomizeUpdate->setObjectName(QString::fromUtf8("label_CustomizeUpdate"));
        label_CustomizeUpdate->setGeometry(QRect(130, 10, 101, 19));
        label_CustomizeUpdate->setFont(font);
        label_CustomizeUpdate->setMouseTracking(true);
        label_CustomizeUpdate->setStyleSheet(QString::fromUtf8("\n"
"                            font-size:14px;\n"
"                        "));
        stackedWidget_UpdataCustom->addWidget(page1_CustomUpdateButtom);
        label_CustomizeUpdate_Icon->raise();
        label_CustomizeUpdate_Documentation->raise();
        label_CustomizeUpdate->raise();
        pushButton_CustomizeUpdate->raise();
        page2_CustomUpdateOption = new QWidget();
        page2_CustomUpdateOption->setObjectName(QString::fromUtf8("page2_CustomUpdateOption"));
        checkBox_startMenuShortCutUpdate = new QCheckBox(page2_CustomUpdateOption);
        checkBox_startMenuShortCutUpdate->setObjectName(QString::fromUtf8("checkBox_startMenuShortCutUpdate"));
        checkBox_startMenuShortCutUpdate->setGeometry(QRect(230, 10, 181, 21));
        checkBox_startMenuShortCutUpdate->setFont(font2);
        checkBox_startMenuShortCutUpdate->setChecked(true);
        checkBox_desktopShortcutUpdate = new QCheckBox(page2_CustomUpdateOption);
        checkBox_desktopShortcutUpdate->setObjectName(QString::fromUtf8("checkBox_desktopShortcutUpdate"));
        checkBox_desktopShortcutUpdate->setGeometry(QRect(100, 10, 131, 20));
        checkBox_desktopShortcutUpdate->setFont(font2);
        checkBox_desktopShortcutUpdate->setChecked(true);
        stackedWidget_UpdataCustom->addWidget(page2_CustomUpdateOption);
        widget_FastButtom_Update = new QWidget(page_6);
        widget_FastButtom_Update->setObjectName(QString::fromUtf8("widget_FastButtom_Update"));
        widget_FastButtom_Update->setGeometry(QRect(10, 70, 451, 71));
        label_FastUpdate = new QLabel(widget_FastButtom_Update);
        label_FastUpdate->setObjectName(QString::fromUtf8("label_FastUpdate"));
        label_FastUpdate->setGeometry(QRect(130, 10, 81, 19));
        label_FastUpdate->setFont(font);
        label_FastUpdate->setMouseTracking(true);
        label_FastUpdate->setStyleSheet(QString::fromUtf8("\n"
"                            font-size:14px;\n"
"                        "));
        label_FastUpdate_Documentation = new QLabel(widget_FastButtom_Update);
        label_FastUpdate_Documentation->setObjectName(QString::fromUtf8("label_FastUpdate_Documentation"));
        label_FastUpdate_Documentation->setGeometry(QRect(130, 36, 161, 17));
        label_FastUpdate_Documentation->setFont(font1);
        label_FastUpdate_Documentation->setMouseTracking(true);
        label_FastUpdate_Documentation->setStyleSheet(QString::fromUtf8("\n"
"                            color:rgba(0, 0, 0, 128);\n"
"                            font-size:13px;\n"
"                        "));
        pushButton_FastUpdate = new QPushButton(widget_FastButtom_Update);
        pushButton_FastUpdate->setObjectName(QString::fromUtf8("pushButton_FastUpdate"));
        pushButton_FastUpdate->setGeometry(QRect(0, 0, 451, 64));
        pushButton_FastUpdate->setStyleSheet(QString::fromUtf8("\n"
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
        label_FastUpdate_Icon = new QLabel(widget_FastButtom_Update);
        label_FastUpdate_Icon->setObjectName(QString::fromUtf8("label_FastUpdate_Icon"));
        label_FastUpdate_Icon->setGeometry(QRect(100, 12, 16, 14));
        label_FastUpdate_Icon->setMouseTracking(true);
        label_FastUpdate_Icon->setStyleSheet(QString::fromUtf8("\n"
"                            background-image:url(:/parts/resource/vector.png);\n"
"                        "));
        stackedWidget_update->addWidget(page_6);
        page_7 = new QWidget();
        page_7->setObjectName(QString::fromUtf8("page_7"));
        label_Wizard_updateing = new QLabel(page_7);
        label_Wizard_updateing->setObjectName(QString::fromUtf8("label_Wizard_updateing"));
        label_Wizard_updateing->setGeometry(QRect(115, 10, 291, 21));
        label_Wizard_updateing->setFont(font);
        label_Wizard_updateing->setStyleSheet(QString::fromUtf8("\n"
"                            color:rgb(47, 47, 47);\n"
"                            font-size:16px;\n"
"                        "));
        pushButton_update_Cancel = new QPushButton(page_7);
        pushButton_update_Cancel->setObjectName(QString::fromUtf8("pushButton_update_Cancel"));
        pushButton_update_Cancel->setGeometry(QRect(115, 220, 84, 32));
        pushButton_update_Cancel->setFont(font1);
        pushButton_update_Cancel->setStyleSheet(QString::fromUtf8("\n"
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
        stackedWidget_update->addWidget(page_7);
        page_8 = new QWidget();
        page_8->setObjectName(QString::fromUtf8("page_8"));
        label_Wizard_finish_Update = new QLabel(page_8);
        label_Wizard_finish_Update->setObjectName(QString::fromUtf8("label_Wizard_finish_Update"));
        label_Wizard_finish_Update->setGeometry(QRect(115, 10, 301, 21));
        label_Wizard_finish_Update->setFont(font);
        label_Wizard_finish_Update->setStyleSheet(QString::fromUtf8("\n"
"                            color:rgb(47, 47, 47);\n"
"                            font-size:16px;\n"
"                        "));
        label_Documentation_Update = new QLabel(page_8);
        label_Documentation_Update->setObjectName(QString::fromUtf8("label_Documentation_Update"));
        label_Documentation_Update->setGeometry(QRect(110, 40, 281, 41));
        label_Documentation_Update->setFont(font2);
        label_Documentation_Update->setStyleSheet(QString::fromUtf8("\n"
"                            color:rgb(47, 47, 47);\n"
"                        "));
        label_Documentation_Update->setTextFormat(Qt::RichText);
        label_Documentation_Update->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label_Documentation_Update->setWordWrap(true);
        horizontalLayoutWidget_2 = new QWidget(page_8);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(119, 99, 231, 81));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_Icon_2 = new QLabel(horizontalLayoutWidget_2);
        label_Icon_2->setObjectName(QString::fromUtf8("label_Icon_2"));
        label_Icon_2->setMinimumSize(QSize(64, 64));
        label_Icon_2->setMaximumSize(QSize(64, 64));
        label_Icon_2->setStyleSheet(QString::fromUtf8("\n"
"                                        font-size:13px;\n"
"                                    "));

        horizontalLayout_2->addWidget(label_Icon_2);

        label_Icon_3 = new QLabel(horizontalLayoutWidget_2);
        label_Icon_3->setObjectName(QString::fromUtf8("label_Icon_3"));
        label_Icon_3->setMinimumSize(QSize(64, 64));
        label_Icon_3->setMaximumSize(QSize(64, 64));
        label_Icon_3->setStyleSheet(QString::fromUtf8("\n"
"                                        font-size:13px;\n"
"                                    "));

        horizontalLayout_2->addWidget(label_Icon_3);

        pushButton_Finished_Run_Update = new QPushButton(page_8);
        pushButton_Finished_Run_Update->setObjectName(QString::fromUtf8("pushButton_Finished_Run_Update"));
        pushButton_Finished_Run_Update->setGeometry(QRect(115, 220, 58, 32));
        pushButton_Finished_Run_Update->setFont(font1);
        pushButton_Finished_Run_Update->setStyleSheet(QString::fromUtf8("\n"
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
        pushButton_Finished_Exit_Update = new QPushButton(page_8);
        pushButton_Finished_Exit_Update->setObjectName(QString::fromUtf8("pushButton_Finished_Exit_Update"));
        pushButton_Finished_Exit_Update->setGeometry(QRect(190, 220, 58, 32));
        pushButton_Finished_Exit_Update->setFont(font1);
        pushButton_Finished_Exit_Update->setStyleSheet(QString::fromUtf8("\n"
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
        stackedWidget_update->addWidget(page_8);
        page_9 = new QWidget();
        page_9->setObjectName(QString::fromUtf8("page_9"));
        label_Wizard_failed_Update = new QLabel(page_9);
        label_Wizard_failed_Update->setObjectName(QString::fromUtf8("label_Wizard_failed_Update"));
        label_Wizard_failed_Update->setGeometry(QRect(115, 10, 301, 21));
        label_Wizard_failed_Update->setFont(font);
        label_Wizard_failed_Update->setStyleSheet(QString::fromUtf8("\n"
"                            color:rgb(47, 47, 47);\n"
"                            font-size:16px;\n"
"                        "));
        label_err_documentation_Update = new QLabel(page_9);
        label_err_documentation_Update->setObjectName(QString::fromUtf8("label_err_documentation_Update"));
        label_err_documentation_Update->setGeometry(QRect(110, 40, 281, 41));
        label_err_documentation_Update->setFont(font2);
        label_err_documentation_Update->setStyleSheet(QString::fromUtf8("\n"
"                            color:rgb(47, 47, 47);\n"
"                        "));
        label_err_documentation_Update->setTextFormat(Qt::RichText);
        label_err_documentation_Update->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label_err_documentation_Update->setWordWrap(true);
        pushButton_Fail_Close_Updaye = new QPushButton(page_9);
        pushButton_Fail_Close_Updaye->setObjectName(QString::fromUtf8("pushButton_Fail_Close_Updaye"));
        pushButton_Fail_Close_Updaye->setGeometry(QRect(120, 220, 84, 32));
        pushButton_Fail_Close_Updaye->setFont(font1);
        pushButton_Fail_Close_Updaye->setStyleSheet(QString::fromUtf8("\n"
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
        label_err_info_Update = new QLabel(page_9);
        label_err_info_Update->setObjectName(QString::fromUtf8("label_err_info_Update"));
        label_err_info_Update->setGeometry(QRect(120, 90, 301, 91));
        label_err_info_Update->setFont(font5);
        label_err_info_Update->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label_err_info_Update->setWordWrap(true);
        stackedWidget_update->addWidget(page_9);
        stackedWidget_2->addWidget(page_update);
        page_uninstall = new QWidget();
        page_uninstall->setObjectName(QString::fromUtf8("page_uninstall"));
        stackedWidget_uninstall = new QStackedWidget(page_uninstall);
        stackedWidget_uninstall->setObjectName(QString::fromUtf8("stackedWidget_uninstall"));
        stackedWidget_uninstall->setGeometry(QRect(0, 10, 451, 301));
        stackedWidget_uninstall->setAutoFillBackground(false);
        stackedWidget_uninstall->setStyleSheet(QString::fromUtf8("QCheckBox::indicator:unchecked {\n"
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
        page_14 = new QWidget();
        page_14->setObjectName(QString::fromUtf8("page_14"));
        label_Wizard_start_uninstall = new QLabel(page_14);
        label_Wizard_start_uninstall->setObjectName(QString::fromUtf8("label_Wizard_start_uninstall"));
        label_Wizard_start_uninstall->setGeometry(QRect(115, 10, 281, 21));
        label_Wizard_start_uninstall->setFont(font);
        label_Wizard_start_uninstall->setStyleSheet(QString::fromUtf8("\n"
"                            color:rgb(47, 47, 47);\n"
"                            font-size:16px;\n"
"                        "));
        label_Tag_Down_4 = new QLabel(page_14);
        label_Tag_Down_4->setObjectName(QString::fromUtf8("label_Tag_Down_4"));
        label_Tag_Down_4->setGeometry(QRect(110, 210, 16, 2));
        label_Tag_Down_4->setStyleSheet(QString::fromUtf8("\n"
"                            background-color:rgb(219, 219, 219);\n"
"                        "));
        label_Tag_Up_4 = new QLabel(page_14);
        label_Tag_Up_4->setObjectName(QString::fromUtf8("label_Tag_Up_4"));
        label_Tag_Up_4->setGeometry(QRect(110, 0, 16, 2));
        label_Tag_Up_4->setStyleSheet(QString::fromUtf8("\n"
"                            background-color:rgb(219, 219, 219);\n"
"                        "));
        stackedWidget_UnInstallCustom = new QStackedWidget(page_14);
        stackedWidget_UnInstallCustom->setObjectName(QString::fromUtf8("stackedWidget_UnInstallCustom"));
        stackedWidget_UnInstallCustom->setGeometry(QRect(10, 170, 451, 41));
        page2_CustomUnInstallOption = new QWidget();
        page2_CustomUnInstallOption->setObjectName(QString::fromUtf8("page2_CustomUnInstallOption"));
        checkBox_removeUserData = new QCheckBox(page2_CustomUnInstallOption);
        checkBox_removeUserData->setObjectName(QString::fromUtf8("checkBox_removeUserData"));
        checkBox_removeUserData->setGeometry(QRect(100, 10, 301, 20));
        checkBox_removeUserData->setFont(font2);
        checkBox_removeUserData->setChecked(false);
        stackedWidget_UnInstallCustom->addWidget(page2_CustomUnInstallOption);
        widget_FastUninstallButtom = new QWidget(page_14);
        widget_FastUninstallButtom->setObjectName(QString::fromUtf8("widget_FastUninstallButtom"));
        widget_FastUninstallButtom->setGeometry(QRect(10, 80, 451, 71));
        label_FastUninstall = new QLabel(widget_FastUninstallButtom);
        label_FastUninstall->setObjectName(QString::fromUtf8("label_FastUninstall"));
        label_FastUninstall->setGeometry(QRect(130, 10, 81, 19));
        label_FastUninstall->setFont(font);
        label_FastUninstall->setMouseTracking(true);
        label_FastUninstall->setStyleSheet(QString::fromUtf8("\n"
"                            font-size:14px;\n"
"                        "));
        label_FastUninstall_Documentation = new QLabel(widget_FastUninstallButtom);
        label_FastUninstall_Documentation->setObjectName(QString::fromUtf8("label_FastUninstall_Documentation"));
        label_FastUninstall_Documentation->setGeometry(QRect(130, 36, 161, 17));
        label_FastUninstall_Documentation->setFont(font1);
        label_FastUninstall_Documentation->setMouseTracking(true);
        label_FastUninstall_Documentation->setStyleSheet(QString::fromUtf8("\n"
"                            color:rgba(0, 0, 0, 128);\n"
"                            font-size:13px;\n"
"                        "));
        pushButton_FastUninstall = new QPushButton(widget_FastUninstallButtom);
        pushButton_FastUninstall->setObjectName(QString::fromUtf8("pushButton_FastUninstall"));
        pushButton_FastUninstall->setGeometry(QRect(0, 0, 451, 64));
        pushButton_FastUninstall->setStyleSheet(QString::fromUtf8("\n"
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
        label_FastUninstall_Icon = new QLabel(widget_FastUninstallButtom);
        label_FastUninstall_Icon->setObjectName(QString::fromUtf8("label_FastUninstall_Icon"));
        label_FastUninstall_Icon->setGeometry(QRect(100, 12, 16, 14));
        label_FastUninstall_Icon->setMouseTracking(true);
        label_FastUninstall_Icon->setStyleSheet(QString::fromUtf8("\n"
"                            background-image:url(:/parts/resource/vector.png);\n"
"                        "));
        label_Uninstall_ReadMe = new QLabel(page_14);
        label_Uninstall_ReadMe->setObjectName(QString::fromUtf8("label_Uninstall_ReadMe"));
        label_Uninstall_ReadMe->setGeometry(QRect(110, 220, 331, 61));
        label_Uninstall_ReadMe->setFont(font2);
        label_Uninstall_ReadMe->setMouseTracking(true);
        label_Uninstall_ReadMe->setTextFormat(Qt::RichText);
        label_Uninstall_ReadMe->setWordWrap(true);
        stackedWidget_uninstall->addWidget(page_14);
        page_15 = new QWidget();
        page_15->setObjectName(QString::fromUtf8("page_15"));
        label_Wizard_Uninstalling = new QLabel(page_15);
        label_Wizard_Uninstalling->setObjectName(QString::fromUtf8("label_Wizard_Uninstalling"));
        label_Wizard_Uninstalling->setGeometry(QRect(115, 10, 291, 21));
        label_Wizard_Uninstalling->setFont(font);
        label_Wizard_Uninstalling->setStyleSheet(QString::fromUtf8("\n"
"                            color:rgb(47, 47, 47);\n"
"                            font-size:16px;\n"
"                        "));
        pushButton_Uninstall_Cancel = new QPushButton(page_15);
        pushButton_Uninstall_Cancel->setObjectName(QString::fromUtf8("pushButton_Uninstall_Cancel"));
        pushButton_Uninstall_Cancel->setGeometry(QRect(115, 220, 84, 32));
        pushButton_Uninstall_Cancel->setFont(font1);
        pushButton_Uninstall_Cancel->setStyleSheet(QString::fromUtf8("\n"
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
        stackedWidget_uninstall->addWidget(page_15);
        page_16 = new QWidget();
        page_16->setObjectName(QString::fromUtf8("page_16"));
        label_Wizard_finish_Uninstall = new QLabel(page_16);
        label_Wizard_finish_Uninstall->setObjectName(QString::fromUtf8("label_Wizard_finish_Uninstall"));
        label_Wizard_finish_Uninstall->setGeometry(QRect(115, 10, 301, 21));
        label_Wizard_finish_Uninstall->setFont(font);
        label_Wizard_finish_Uninstall->setStyleSheet(QString::fromUtf8("\n"
"                            color:rgb(47, 47, 47);\n"
"                            font-size:16px;\n"
"                        "));
        label_Documentation_Uninstall = new QLabel(page_16);
        label_Documentation_Uninstall->setObjectName(QString::fromUtf8("label_Documentation_Uninstall"));
        label_Documentation_Uninstall->setGeometry(QRect(110, 40, 281, 41));
        label_Documentation_Uninstall->setFont(font2);
        label_Documentation_Uninstall->setStyleSheet(QString::fromUtf8("\n"
"                            color:rgb(47, 47, 47);\n"
"                        "));
        label_Documentation_Uninstall->setTextFormat(Qt::RichText);
        label_Documentation_Uninstall->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label_Documentation_Uninstall->setWordWrap(true);
        horizontalLayoutWidget_4 = new QWidget(page_16);
        horizontalLayoutWidget_4->setObjectName(QString::fromUtf8("horizontalLayoutWidget_4"));
        horizontalLayoutWidget_4->setGeometry(QRect(119, 99, 231, 81));
        horizontalLayout_4 = new QHBoxLayout(horizontalLayoutWidget_4);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_Icon_6 = new QLabel(horizontalLayoutWidget_4);
        label_Icon_6->setObjectName(QString::fromUtf8("label_Icon_6"));
        label_Icon_6->setMinimumSize(QSize(64, 64));
        label_Icon_6->setMaximumSize(QSize(64, 64));
        label_Icon_6->setStyleSheet(QString::fromUtf8("\n"
"                                        font-size:13px;\n"
"                                    "));

        horizontalLayout_4->addWidget(label_Icon_6);

        label_Icon_7 = new QLabel(horizontalLayoutWidget_4);
        label_Icon_7->setObjectName(QString::fromUtf8("label_Icon_7"));
        label_Icon_7->setMinimumSize(QSize(64, 64));
        label_Icon_7->setMaximumSize(QSize(64, 64));
        label_Icon_7->setStyleSheet(QString::fromUtf8("\n"
"                                        font-size:13px;\n"
"                                    "));

        horizontalLayout_4->addWidget(label_Icon_7);

        pushButton_Finished_Exit_Uninstall = new QPushButton(page_16);
        pushButton_Finished_Exit_Uninstall->setObjectName(QString::fromUtf8("pushButton_Finished_Exit_Uninstall"));
        pushButton_Finished_Exit_Uninstall->setGeometry(QRect(117, 220, 81, 32));
        pushButton_Finished_Exit_Uninstall->setFont(font1);
        pushButton_Finished_Exit_Uninstall->setStyleSheet(QString::fromUtf8("\n"
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
        stackedWidget_uninstall->addWidget(page_16);
        page_17 = new QWidget();
        page_17->setObjectName(QString::fromUtf8("page_17"));
        label_Wizard_failed_Uninstall = new QLabel(page_17);
        label_Wizard_failed_Uninstall->setObjectName(QString::fromUtf8("label_Wizard_failed_Uninstall"));
        label_Wizard_failed_Uninstall->setGeometry(QRect(115, 10, 301, 21));
        label_Wizard_failed_Uninstall->setFont(font);
        label_Wizard_failed_Uninstall->setStyleSheet(QString::fromUtf8("\n"
"                            color:rgb(47, 47, 47);\n"
"                            font-size:16px;\n"
"                        "));
        label_err_documentation_Uninstall = new QLabel(page_17);
        label_err_documentation_Uninstall->setObjectName(QString::fromUtf8("label_err_documentation_Uninstall"));
        label_err_documentation_Uninstall->setGeometry(QRect(110, 40, 331, 41));
        label_err_documentation_Uninstall->setFont(font2);
        label_err_documentation_Uninstall->setStyleSheet(QString::fromUtf8("\n"
"                            color:rgb(47, 47, 47);\n"
"                        "));
        label_err_documentation_Uninstall->setTextFormat(Qt::RichText);
        label_err_documentation_Uninstall->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label_err_documentation_Uninstall->setWordWrap(true);
        pushButton_Fail_Close_Uninstall = new QPushButton(page_17);
        pushButton_Fail_Close_Uninstall->setObjectName(QString::fromUtf8("pushButton_Fail_Close_Uninstall"));
        pushButton_Fail_Close_Uninstall->setGeometry(QRect(120, 220, 84, 32));
        pushButton_Fail_Close_Uninstall->setFont(font1);
        pushButton_Fail_Close_Uninstall->setStyleSheet(QString::fromUtf8("\n"
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
        label_err_info_Uninstall = new QLabel(page_17);
        label_err_info_Uninstall->setObjectName(QString::fromUtf8("label_err_info_Uninstall"));
        label_err_info_Uninstall->setGeometry(QRect(120, 90, 301, 91));
        label_err_info_Uninstall->setFont(font5);
        label_err_info_Uninstall->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label_err_info_Uninstall->setWordWrap(true);
        stackedWidget_uninstall->addWidget(page_17);
        stackedWidget_2->addWidget(page_uninstall);
        label_MainShadow->raise();
        label_MainShadow_B->raise();
        label_MainShadow_A->raise();
        label_Satellite_Orbit->raise();
        label_Star->raise();
        label_Title->raise();
        pushButton_UI_Close->raise();
        pushButton_UI_Mini->raise();
        stackedWidget_2->raise();
        label_MainImage->raise();
#if QT_CONFIG(shortcut)
        label_MainImage->setBuddy(pushButton_UI_Mini);
#endif // QT_CONFIG(shortcut)

        retranslateUi(tianli__tianli_widget);

        stackedWidget_2->setCurrentIndex(0);
        stackedWidget_install->setCurrentIndex(0);
        stackedWidget_InstallCustom->setCurrentIndex(0);
        stackedWidget_update->setCurrentIndex(0);
        stackedWidget_UpdataCustom->setCurrentIndex(0);
        stackedWidget_uninstall->setCurrentIndex(0);
        stackedWidget_UnInstallCustom->setCurrentIndex(0);


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
        label_Title->setText(QCoreApplication::translate("tianli::tianli_widget", "\347\251\272\350\215\247\351\205\222\351\246\206", nullptr));
        pushButton_UI_Close->setText(QString());
        pushButton_UI_Mini->setText(QString());
        label_MainImage->setText(QString());
        label_Wizard_start->setText(QCoreApplication::translate("tianli::tianli_widget", "\345\216\237\347\245\236\350\265\204\346\272\220\345\234\260\345\233\276 \345\256\211\350\243\205\345\220\221\345\257\274", nullptr));
        label_Tag_Down->setText(QString());
        label_Readme->setText(QCoreApplication::translate("tianli::tianli_widget", "<html><head/><body><p style=\"margin:5px;\"><span style=\" color:#909090;\">Tips: \345\256\211\350\243\205\345\271\266\344\275\277\347\224\250\342\200\234\347\251\272\350\215\247\351\205\222\351\246\206\345\216\237\347\245\236\345\234\260\345\233\276\342\200\235</span></p><p style=\"margin:5px;\"><span style=\" color:#909090;\">\346\204\217\345\221\263\347\235\200\346\202\250\345\220\214\346\204\217\345\271\266\351\201\265\345\256\210</span><a href=\"https://yuanshen.site/docs/disclaimer.html\"><span style=\" text-decoration: underline; color:#ee623c;\">\343\200\212\347\224\250\346\210\267\344\275\277\347\224\250\345\215\217\350\256\256\343\200\213</span></a></p></body></html>", nullptr));
        label_Tag_Up->setText(QString());
        pushButton_CustomizeInstall->setText(QString());
        label_CustomizeInstall_Icon->setText(QString());
        label_CustomizeInstall_Documentation->setText(QCoreApplication::translate("tianli::tianli_widget", "\350\256\276\347\275\256\345\256\211\350\243\205\347\232\204\350\267\257\345\276\204\344\273\245\345\217\212\345\277\253\346\215\267\346\226\271\345\274\217", nullptr));
        label_CustomizeInstall->setText(QCoreApplication::translate("tianli::tianli_widget", "\350\207\252\345\256\232\344\271\211", nullptr));
        checkBox_startMenuShortCut->setText(QCoreApplication::translate("tianli::tianli_widget", "\345\274\200\345\247\213\350\217\234\345\215\225\345\277\253\346\215\267\346\226\271\345\274\217", nullptr));
        pushButton_preview->setText(QCoreApplication::translate("tianli::tianli_widget", "\351\242\204\350\247\210", nullptr));
        lineEdit_installPath->setText(QCoreApplication::translate("tianli::tianli_widget", "C:\\Program Files\\KongYingMap", nullptr));
        checkBox_desktopShortcut->setText(QCoreApplication::translate("tianli::tianli_widget", "\346\241\214\351\235\242\345\277\253\346\215\267\346\226\271\345\274\217", nullptr));
        label_FastInstall->setText(QCoreApplication::translate("tianli::tianli_widget", "\345\277\253\351\200\237\345\256\211\350\243\205", nullptr));
        label_FastInstall_Documentation->setText(QCoreApplication::translate("tianli::tianli_widget", "\346\214\211\347\205\247\347\250\213\345\272\217\351\242\204\350\256\276\350\277\233\350\241\214\345\256\211\350\243\205", nullptr));
        pushButton_FastInstall->setText(QString());
        label_FastInstall_Icon->setText(QString());
        label_Wizard_installing->setText(QCoreApplication::translate("tianli::tianli_widget", "\345\216\237\347\245\236\350\265\204\346\272\220\345\234\260\345\233\276 \346\255\243\345\234\250\345\256\211\350\243\205", nullptr));
        pushButton_installing_Cancel->setText(QCoreApplication::translate("tianli::tianli_widget", "\345\217\226\346\266\210\345\256\211\350\243\205", nullptr));
        label_Wizard_finish->setText(QCoreApplication::translate("tianli::tianli_widget", "\345\216\237\347\245\236\350\265\204\346\272\220\345\234\260\345\233\276 \345\256\211\350\243\205\345\256\214\346\210\220", nullptr));
        label_Documentation->setText(QCoreApplication::translate("tianli::tianli_widget", "<html><head/><body><p>\346\204\237\350\260\242\346\202\250\347\232\204\345\256\211\350\243\205\357\274\214\346\202\250\345\217\257\344\273\245\351\200\232\350\277\207\344\273\245\344\270\213\346\226\271\345\274\217\345\205\263\346\263\250\346\210\221\344\273\254\347\232\204\347\244\276\344\272\244\350\264\246\345\217\267\357\274\232</p></body></html>", nullptr));
        label_Icon_bilibili->setText(QString());
        label_Icon_youtube->setText(QString());
        label_bilibili->setText(QCoreApplication::translate("tianli::tianli_widget", "<html><head/><body><p><a href=\"https://space.bilibili.com/518076785\"><span style=\" text-decoration: underline; color:#000000;\">@\345\216\237\347\245\236\347\251\272\350\215\247\351\205\222\351\246\206</span></a></p></body></html>", nullptr));
        label_youtube->setText(QCoreApplication::translate("tianli::tianli_widget", "<html><head/><body><p><a href=\"https://www.youtube.com/@KongyingTavernOfficial\"><span style=\" text-decoration: underline; color:#000000;\">@Kongying Tavern Official</span></a></p></body></html>", nullptr));
        pushButton_Finished_Run->setText(QCoreApplication::translate("tianli::tianli_widget", "\345\220\257\345\212\250", nullptr));
        pushButton_Finished_Exit->setText(QCoreApplication::translate("tianli::tianli_widget", "\351\200\200\345\207\272", nullptr));
        label_Wizard_failed->setText(QCoreApplication::translate("tianli::tianli_widget", "\345\216\237\347\245\236\350\265\204\346\272\220\345\234\260\345\233\276 \345\256\211\350\243\205\345\244\261\350\264\245", nullptr));
        label_err_documentation->setText(QCoreApplication::translate("tianli::tianli_widget", "<html><head/><body><p>\345\276\210\351\201\227\346\206\276\357\274\214\345\256\211\350\243\205\345\244\261\350\264\245\344\272\206\357\274\214\344\275\240\345\217\257\344\273\245\345\260\235\350\257\225\346\211\213\345\212\250\345\210\240\351\231\244\346\226\207\344\273\266\345\220\216\351\207\215\346\226\260\345\256\211\350\243\205\343\200\202\346\212\245\351\224\231\344\277\241\346\201\257\345\246\202\344\270\213\357\274\232</p></body></html>", nullptr));
        pushButton_Fail_Close->setText(QCoreApplication::translate("tianli::tianli_widget", "\345\205\263\351\227\255", nullptr));
        label_err_info->setText(QCoreApplication::translate("tianli::tianli_widget", "\347\224\250\346\210\267\345\217\226\346\266\210\344\272\206\345\256\211\350\243\205", nullptr));
        label_Wizard_start_Update->setText(QCoreApplication::translate("tianli::tianli_widget", "\345\216\237\347\245\236\350\265\204\346\272\220\345\234\260\345\233\276 \345\215\207\347\272\247\345\220\221\345\257\274", nullptr));
        label_Tag_Down_2->setText(QString());
        label_Readme_Update->setText(QCoreApplication::translate("tianli::tianli_widget", "<html><head/><body><p style=\"margin:5px;\"><span style=\" color:#909090;\">Tips: \345\256\211\350\243\205\345\271\266\344\275\277\347\224\250\342\200\234\347\251\272\350\215\247\351\205\222\351\246\206\345\216\237\347\245\236\345\234\260\345\233\276\342\200\235</span></p><p style=\"margin:5px;\"><span style=\" color:#909090;\">\346\204\217\345\221\263\347\235\200\346\202\250\345\220\214\346\204\217\345\271\266\351\201\265\345\256\210</span><a href=\"https://yuanshen.site/docs/disclaimer.html\"><span style=\" text-decoration: underline; color:#ee623c;\">\343\200\212\347\224\250\346\210\267\344\275\277\347\224\250\345\215\217\350\256\256\343\200\213</span></a></p></body></html>", nullptr));
        label_Tag_Up_2->setText(QString());
        pushButton_CustomizeUpdate->setText(QString());
        label_CustomizeUpdate_Icon->setText(QString());
        label_CustomizeUpdate_Documentation->setText(QCoreApplication::translate("tianli::tianli_widget", "\345\277\253\346\215\267\346\226\271\345\274\217\347\233\270\345\205\263\350\256\276\345\256\232", nullptr));
        label_CustomizeUpdate->setText(QCoreApplication::translate("tianli::tianli_widget", "\350\207\252\345\256\232\344\271\211", nullptr));
        checkBox_startMenuShortCutUpdate->setText(QCoreApplication::translate("tianli::tianli_widget", "\345\274\200\345\247\213\350\217\234\345\215\225\345\277\253\346\215\267\346\226\271\345\274\217", nullptr));
        checkBox_desktopShortcutUpdate->setText(QCoreApplication::translate("tianli::tianli_widget", "\346\241\214\351\235\242\345\277\253\346\215\267\346\226\271\345\274\217", nullptr));
        label_FastUpdate->setText(QCoreApplication::translate("tianli::tianli_widget", "\345\215\207\347\272\247/\344\277\256\345\244\215", nullptr));
        label_FastUpdate_Documentation->setText(QCoreApplication::translate("tianli::tianli_widget", "\346\214\211\347\205\247\347\250\213\345\272\217\351\242\204\350\256\276\350\277\233\350\241\214\345\256\211\350\243\205", nullptr));
        pushButton_FastUpdate->setText(QString());
        label_FastUpdate_Icon->setText(QString());
        label_Wizard_updateing->setText(QCoreApplication::translate("tianli::tianli_widget", "\345\216\237\347\245\236\350\265\204\346\272\220\345\234\260\345\233\276 \346\255\243\345\234\250\345\215\207\347\272\247", nullptr));
        pushButton_update_Cancel->setText(QCoreApplication::translate("tianli::tianli_widget", "\345\201\234\346\255\242", nullptr));
        label_Wizard_finish_Update->setText(QCoreApplication::translate("tianli::tianli_widget", "\345\216\237\347\245\236\350\265\204\346\272\220\345\234\260\345\233\276 \345\215\207\347\272\247\345\256\214\346\210\220", nullptr));
        label_Documentation_Update->setText(QCoreApplication::translate("tianli::tianli_widget", "<html><head/><body><p>\346\204\237\350\260\242\346\202\250\347\232\204\345\256\211\350\243\205\357\274\214\346\202\250\345\217\257\344\273\245\351\200\232\350\277\207\344\273\245\344\270\213\346\226\271\345\274\217\345\205\263\346\263\250\346\210\221\344\273\254\347\232\204\347\244\276\344\272\244\350\264\246\345\217\267\357\274\232</p></body></html>", nullptr));
        label_Icon_2->setText(QString());
        label_Icon_3->setText(QString());
        pushButton_Finished_Run_Update->setText(QCoreApplication::translate("tianli::tianli_widget", "\345\220\257\345\212\250", nullptr));
        pushButton_Finished_Exit_Update->setText(QCoreApplication::translate("tianli::tianli_widget", "\351\200\200\345\207\272", nullptr));
        label_Wizard_failed_Update->setText(QCoreApplication::translate("tianli::tianli_widget", "\345\216\237\347\245\236\350\265\204\346\272\220\345\234\260\345\233\276 \345\215\207\347\272\247\345\244\261\350\264\245", nullptr));
        label_err_documentation_Update->setText(QCoreApplication::translate("tianli::tianli_widget", "<html><head/><body><p>\345\276\210\351\201\227\346\206\276\357\274\214\345\215\207\347\272\247\345\244\261\350\264\245\344\272\206\357\274\214\344\275\240\345\217\257\344\273\245\345\260\235\350\257\225\346\211\213\345\212\250\345\210\240\351\231\244\346\226\207\344\273\266\345\220\216\351\207\215\346\226\260\345\256\211\350\243\205\343\200\202\346\212\245\351\224\231\344\277\241\346\201\257\345\246\202\344\270\213\357\274\232</p></body></html>", nullptr));
        pushButton_Fail_Close_Updaye->setText(QCoreApplication::translate("tianli::tianli_widget", "\345\205\263\351\227\255", nullptr));
        label_err_info_Update->setText(QCoreApplication::translate("tianli::tianli_widget", "\347\224\250\346\210\267\345\217\226\346\266\210\344\272\206\345\256\211\350\243\205", nullptr));
        label_Wizard_start_uninstall->setText(QCoreApplication::translate("tianli::tianli_widget", "\345\216\237\347\245\236\350\265\204\346\272\220\345\234\260\345\233\276 \345\215\270\350\275\275\345\220\221\345\257\274", nullptr));
        label_Tag_Down_4->setText(QString());
        label_Tag_Up_4->setText(QString());
        checkBox_removeUserData->setText(QCoreApplication::translate("tianli::tianli_widget", "\345\210\240\351\231\244\346\234\254\346\234\272\347\224\250\346\210\267\346\225\260\346\215\256", nullptr));
        label_FastUninstall->setText(QCoreApplication::translate("tianli::tianli_widget", "\345\215\270\350\275\275", nullptr));
        label_FastUninstall_Documentation->setText(QCoreApplication::translate("tianli::tianli_widget", "\344\273\216\346\234\254\346\234\272\345\210\240\351\231\244\345\216\237\347\245\236\350\265\204\346\272\220\345\234\260\345\233\276", nullptr));
        pushButton_FastUninstall->setText(QString());
        label_FastUninstall_Icon->setText(QString());
        label_Uninstall_ReadMe->setText(QCoreApplication::translate("tianli::tianli_widget", "<html><head/><body><p><span style=\" font-weight:700; color:#ed5f39;\">\350\255\246\345\221\212\357\274\232\345\246\202\346\236\234\351\200\211\346\213\251\345\210\240\351\231\244\347\224\250\346\210\267\346\225\260\346\215\256\357\274\214\345\210\231\351\207\215\346\226\260\345\256\211\350\243\205\345\220\216\346\211\200\346\234\211\347\202\271\344\275\215\346\240\207\350\256\260\344\277\241\346\201\257\345\260\206\344\274\232\344\270\242\345\244\261\357\274\201</span><br/><span style=\" font-weight:700; color:#ed5f39;\">\350\257\267\347\241\256\344\277\235\344\275\240\347\232\204\345\255\230\346\241\243\345\267\262\347\273\217\344\272\221\345\244\207\344\273\275\357\274\201</span></p></body></html>", nullptr));
        label_Wizard_Uninstalling->setText(QCoreApplication::translate("tianli::tianli_widget", "\345\216\237\347\245\236\350\265\204\346\272\220\345\234\260\345\233\276 \346\255\243\345\234\250\345\215\270\350\275\275", nullptr));
        pushButton_Uninstall_Cancel->setText(QCoreApplication::translate("tianli::tianli_widget", "\345\201\234\346\255\242", nullptr));
        label_Wizard_finish_Uninstall->setText(QCoreApplication::translate("tianli::tianli_widget", "\345\216\237\347\245\236\350\265\204\346\272\220\345\234\260\345\233\276 \345\215\270\350\275\275\345\256\214\346\210\220", nullptr));
        label_Documentation_Uninstall->setText(QCoreApplication::translate("tianli::tianli_widget", "<html><head/><body><p>\346\202\250\345\267\262\346\210\220\345\212\237\345\215\270\350\275\275\347\251\272\350\215\247\351\205\222\351\246\206\342\204\242\345\216\237\347\245\236\345\234\260\345\233\276\357\274\214\346\234\237\345\276\205\344\270\216\346\202\250\347\232\204\345\206\215\346\254\241\347\233\270\344\274\232\357\274\201</p></body></html>", nullptr));
        label_Icon_6->setText(QString());
        label_Icon_7->setText(QString());
        pushButton_Finished_Exit_Uninstall->setText(QCoreApplication::translate("tianli::tianli_widget", "\351\200\200\345\207\272", nullptr));
        label_Wizard_failed_Uninstall->setText(QCoreApplication::translate("tianli::tianli_widget", "\345\216\237\347\245\236\350\265\204\346\272\220\345\234\260\345\233\276 \345\215\270\350\275\275\345\244\261\350\264\245", nullptr));
        label_err_documentation_Uninstall->setText(QCoreApplication::translate("tianli::tianli_widget", "<html><head/><body><p>\345\276\210\351\201\227\346\206\276\357\274\214\345\215\270\350\275\275\345\244\261\350\264\245\344\272\206\343\200\202\344\270\215\350\277\207\344\270\215\347\224\250\346\213\205\345\277\203\357\274\214\346\263\250\345\206\214\350\241\250\351\241\271\345\267\262\346\270\205\351\231\244\357\274\214\344\275\240\345\217\252\351\234\200\350\246\201\345\210\240\351\231\244\345\211\251\344\275\231\347\232\204\346\226\207\344\273\266\345\215\263\345\217\257\343\200\202</p></body></html>", nullptr));
        pushButton_Fail_Close_Uninstall->setText(QCoreApplication::translate("tianli::tianli_widget", "\345\205\263\351\227\255", nullptr));
        label_err_info_Uninstall->setText(QCoreApplication::translate("tianli::tianli_widget", "\347\224\250\346\210\267\345\217\226\346\266\210\344\272\206\345\256\211\350\243\205", nullptr));
    } // retranslateUi

};

} // namespace tianli

namespace tianli {
namespace Ui {
    class tianli_widget: public Ui_tianli_widget {};
} // namespace Ui
} // namespace tianli

#endif // UI_TIANLI_WIDGET_H
