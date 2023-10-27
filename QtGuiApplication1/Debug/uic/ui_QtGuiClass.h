/********************************************************************************
** Form generated from reading UI file 'QtGuiClass.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTGUICLASS_H
#define UI_QTGUICLASS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtGuiClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QtGuiClass)
    {
        if (QtGuiClass->objectName().isEmpty())
            QtGuiClass->setObjectName(QString::fromUtf8("QtGuiClass"));
        QtGuiClass->resize(400, 300);
        menuBar = new QMenuBar(QtGuiClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        QtGuiClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QtGuiClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        QtGuiClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(QtGuiClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        QtGuiClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(QtGuiClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        QtGuiClass->setStatusBar(statusBar);

        retranslateUi(QtGuiClass);

        QMetaObject::connectSlotsByName(QtGuiClass);
    } // setupUi

    void retranslateUi(QMainWindow *QtGuiClass)
    {
        QtGuiClass->setWindowTitle(QCoreApplication::translate("QtGuiClass", "QtGuiClass", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QtGuiClass: public Ui_QtGuiClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTGUICLASS_H
