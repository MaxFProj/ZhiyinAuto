/********************************************************************************
** Form generated from reading UI file 'LicenseManagerTest.ui'
**
** Created by: Qt User Interface Compiler version 5.12.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LICENSEMANAGERTEST_H
#define UI_LICENSEMANAGERTEST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LicenseManagerTestClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *LicenseManagerTestClass)
    {
        if (LicenseManagerTestClass->objectName().isEmpty())
            LicenseManagerTestClass->setObjectName(QString::fromUtf8("LicenseManagerTestClass"));
        LicenseManagerTestClass->resize(600, 400);
        menuBar = new QMenuBar(LicenseManagerTestClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        LicenseManagerTestClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(LicenseManagerTestClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        LicenseManagerTestClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(LicenseManagerTestClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        LicenseManagerTestClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(LicenseManagerTestClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        LicenseManagerTestClass->setStatusBar(statusBar);

        retranslateUi(LicenseManagerTestClass);

        QMetaObject::connectSlotsByName(LicenseManagerTestClass);
    } // setupUi

    void retranslateUi(QMainWindow *LicenseManagerTestClass)
    {
        LicenseManagerTestClass->setWindowTitle(QApplication::translate("LicenseManagerTestClass", "LicenseManagerTest", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LicenseManagerTestClass: public Ui_LicenseManagerTestClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LICENSEMANAGERTEST_H
