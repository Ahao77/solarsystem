/********************************************************************************
** Form generated from reading UI file 'Mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainwindowClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainwindowClass)
    {
        if (MainwindowClass->objectName().isEmpty())
            MainwindowClass->setObjectName(QStringLiteral("MainwindowClass"));
        MainwindowClass->resize(600, 400);
        menuBar = new QMenuBar(MainwindowClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        MainwindowClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainwindowClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainwindowClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(MainwindowClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        MainwindowClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainwindowClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainwindowClass->setStatusBar(statusBar);

        retranslateUi(MainwindowClass);

        QMetaObject::connectSlotsByName(MainwindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *MainwindowClass)
    {
        MainwindowClass->setWindowTitle(QApplication::translate("MainwindowClass", "Mainwindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainwindowClass: public Ui_MainwindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
