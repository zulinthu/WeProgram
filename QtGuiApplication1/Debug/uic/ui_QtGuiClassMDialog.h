/********************************************************************************
** Form generated from reading UI file 'QtGuiClassMDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTGUICLASSMDIALOG_H
#define UI_QTGUICLASSMDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtGuiClassMDialog
{
public:

    void setupUi(QWidget *QtGuiClassMDialog)
    {
        if (QtGuiClassMDialog->objectName().isEmpty())
            QtGuiClassMDialog->setObjectName(QString::fromUtf8("QtGuiClassMDialog"));
        QtGuiClassMDialog->resize(400, 300);

        retranslateUi(QtGuiClassMDialog);

        QMetaObject::connectSlotsByName(QtGuiClassMDialog);
    } // setupUi

    void retranslateUi(QWidget *QtGuiClassMDialog)
    {
        QtGuiClassMDialog->setWindowTitle(QCoreApplication::translate("QtGuiClassMDialog", "QtGuiClassMDialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QtGuiClassMDialog: public Ui_QtGuiClassMDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTGUICLASSMDIALOG_H
