/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LogInClass
{
public:
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *LogInClass)
    {
        if (LogInClass->objectName().isEmpty())
            LogInClass->setObjectName(QString::fromUtf8("LogInClass"));
        LogInClass->setWindowModality(Qt::NonModal);
        LogInClass->setEnabled(false);
        LogInClass->resize(600, 400);
        centralWidget = new QWidget(LogInClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        LogInClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(LogInClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 23));
        LogInClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(LogInClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        LogInClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(LogInClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        LogInClass->setStatusBar(statusBar);

        retranslateUi(LogInClass);

        QMetaObject::connectSlotsByName(LogInClass);
    } // setupUi

    void retranslateUi(QMainWindow *LogInClass)
    {
        LogInClass->setWindowTitle(QApplication::translate("LogInClass", "LogIn", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class LogInClass: public Ui_LogInClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
