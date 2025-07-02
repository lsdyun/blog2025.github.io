/********************************************************************************
** Form generated from reading UI file 'hellodialog.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HELLODIALOG_H
#define UI_HELLODIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_HelloDialog
{
public:
    QLabel *dialog;

    void setupUi(QDialog *HelloDialog)
    {
        if (HelloDialog->objectName().isEmpty())
            HelloDialog->setObjectName("HelloDialog");
        HelloDialog->setEnabled(true);
        HelloDialog->resize(400, 300);
        dialog = new QLabel(HelloDialog);
        dialog->setObjectName("dialog");
        dialog->setGeometry(QRect(120, 120, 201, 16));

        retranslateUi(HelloDialog);

        QMetaObject::connectSlotsByName(HelloDialog);
    } // setupUi

    void retranslateUi(QDialog *HelloDialog)
    {
        HelloDialog->setWindowTitle(QCoreApplication::translate("HelloDialog", "Dialog", nullptr));
        dialog->setText(QCoreApplication::translate("HelloDialog", "Hello World!  UI", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HelloDialog: public Ui_HelloDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HELLODIALOG_H
