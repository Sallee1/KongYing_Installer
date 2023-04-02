/********************************************************************************
** Form generated from reading UI file 'rounded_rectangle.ui'
**
** Created by: Qt User Interface Compiler version 5.15.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ROUNDED_RECTANGLE_H
#define UI_ROUNDED_RECTANGLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

namespace tianli {

class Ui_rounded_rectangle
{
public:

    void setupUi(QWidget *tianli__rounded_rectangle)
    {
        if (tianli__rounded_rectangle->objectName().isEmpty())
            tianli__rounded_rectangle->setObjectName(QString::fromUtf8("tianli__rounded_rectangle"));
        tianli__rounded_rectangle->resize(400, 300);

        retranslateUi(tianli__rounded_rectangle);

        QMetaObject::connectSlotsByName(tianli__rounded_rectangle);
    } // setupUi

    void retranslateUi(QWidget *tianli__rounded_rectangle)
    {
        tianli__rounded_rectangle->setWindowTitle(QCoreApplication::translate("tianli::rounded_rectangle", "rounded_rectangle", nullptr));
    } // retranslateUi

};

} // namespace tianli

namespace tianli {
namespace Ui {
    class rounded_rectangle: public Ui_rounded_rectangle {};
} // namespace Ui
} // namespace tianli

#endif // UI_ROUNDED_RECTANGLE_H
