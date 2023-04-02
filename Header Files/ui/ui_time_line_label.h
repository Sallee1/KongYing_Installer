/********************************************************************************
** Form generated from reading UI file 'time_line_label.ui'
**
** Created by: Qt User Interface Compiler version 5.15.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TIME_LINE_LABEL_H
#define UI_TIME_LINE_LABEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

namespace tianli {

class Ui_time_line_label
{
public:
    QLabel *label_Title;
    QLabel *label_ProgressBackground;
    QLabel *label_ProgressBar;

    void setupUi(QWidget *tianli__time_line_label)
    {
        if (tianli__time_line_label->objectName().isEmpty())
            tianli__time_line_label->setObjectName(QString::fromUtf8("tianli__time_line_label"));
        tianli__time_line_label->resize(280, 31);
        tianli__time_line_label->setMinimumSize(QSize(280, 31));
        tianli__time_line_label->setMaximumSize(QSize(280, 31));
        tianli__time_line_label->setStyleSheet(QString::fromUtf8(""));
        label_Title = new QLabel(tianli__time_line_label);
        label_Title->setObjectName(QString::fromUtf8("label_Title"));
        label_Title->setGeometry(QRect(22, 0, 258, 17));
        QFont font;
        font.setPointSize(9);
        font.setBold(false);
        label_Title->setFont(font);
        label_Title->setStyleSheet(QString::fromUtf8("                    color: #000000;"));
        label_ProgressBackground = new QLabel(tianli__time_line_label);
        label_ProgressBackground->setObjectName(QString::fromUtf8("label_ProgressBackground"));
        label_ProgressBackground->setGeometry(QRect(22, 21, 258, 3));
        label_ProgressBackground->setStyleSheet(QString::fromUtf8(".QLabel{\n"
"                    background-color:rgba(0,0,0,26);\n"
"                    }"));
        label_ProgressBar = new QLabel(tianli__time_line_label);
        label_ProgressBar->setObjectName(QString::fromUtf8("label_ProgressBar"));
        label_ProgressBar->setGeometry(QRect(22, 21, 10, 3));
        label_ProgressBar->setStyleSheet(QString::fromUtf8(".QLabel{\n"
"                    background-color:rgb(253, 77, 77);\n"
"                    }"));

        retranslateUi(tianli__time_line_label);

        QMetaObject::connectSlotsByName(tianli__time_line_label);
    } // setupUi

    void retranslateUi(QWidget *tianli__time_line_label)
    {
        tianli__time_line_label->setWindowTitle(QCoreApplication::translate("tianli::time_line_label", "time_line_label", nullptr));
        label_Title->setText(QCoreApplication::translate("tianli::time_line_label", "\346\255\245\351\252\244", nullptr));
        label_ProgressBackground->setText(QString());
        label_ProgressBar->setText(QString());
    } // retranslateUi

};

} // namespace tianli

namespace tianli {
namespace Ui {
    class time_line_label: public Ui_time_line_label {};
} // namespace Ui
} // namespace tianli

#endif // UI_TIME_LINE_LABEL_H
