/********************************************************************************
** Form generated from reading UI file 'filterScriptDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILTERSCRIPTDIALOG_H
#define UI_FILTERSCRIPTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_scriptDialog
{
public:
    QGridLayout *gridLayout;
    QListWidget *scriptListWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *moveUpButton;
    QPushButton *moveDownButton;
    QPushButton *removeFilterButton;
    QPushButton *editParameterButton;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *hboxLayout;
    QPushButton *saveScriptButton;
    QPushButton *openScriptButton;
    QPushButton *clearScriptButton;
    QSpacerItem *spacerItem;
    QPushButton *okButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *scriptDialog)
    {
        if (scriptDialog->objectName().isEmpty())
            scriptDialog->setObjectName(QStringLiteral("scriptDialog"));
        scriptDialog->resize(727, 404);
        gridLayout = new QGridLayout(scriptDialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        scriptListWidget = new QListWidget(scriptDialog);
        scriptListWidget->setObjectName(QStringLiteral("scriptListWidget"));

        gridLayout->addWidget(scriptListWidget, 0, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        moveUpButton = new QPushButton(scriptDialog);
        moveUpButton->setObjectName(QStringLiteral("moveUpButton"));

        verticalLayout->addWidget(moveUpButton);

        moveDownButton = new QPushButton(scriptDialog);
        moveDownButton->setObjectName(QStringLiteral("moveDownButton"));

        verticalLayout->addWidget(moveDownButton);

        removeFilterButton = new QPushButton(scriptDialog);
        removeFilterButton->setObjectName(QStringLiteral("removeFilterButton"));

        verticalLayout->addWidget(removeFilterButton);

        editParameterButton = new QPushButton(scriptDialog);
        editParameterButton->setObjectName(QStringLiteral("editParameterButton"));

        verticalLayout->addWidget(editParameterButton);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        gridLayout->addLayout(verticalLayout, 0, 1, 1, 1);

        hboxLayout = new QHBoxLayout();
        hboxLayout->setObjectName(QStringLiteral("hboxLayout"));
        saveScriptButton = new QPushButton(scriptDialog);
        saveScriptButton->setObjectName(QStringLiteral("saveScriptButton"));

        hboxLayout->addWidget(saveScriptButton);

        openScriptButton = new QPushButton(scriptDialog);
        openScriptButton->setObjectName(QStringLiteral("openScriptButton"));

        hboxLayout->addWidget(openScriptButton);

        clearScriptButton = new QPushButton(scriptDialog);
        clearScriptButton->setObjectName(QStringLiteral("clearScriptButton"));

        hboxLayout->addWidget(clearScriptButton);

        spacerItem = new QSpacerItem(131, 31, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout->addItem(spacerItem);

        okButton = new QPushButton(scriptDialog);
        okButton->setObjectName(QStringLiteral("okButton"));

        hboxLayout->addWidget(okButton);

        cancelButton = new QPushButton(scriptDialog);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));

        hboxLayout->addWidget(cancelButton);


        gridLayout->addLayout(hboxLayout, 1, 0, 1, 1);


        retranslateUi(scriptDialog);
        QObject::connect(cancelButton, SIGNAL(clicked()), scriptDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(scriptDialog);
    } // setupUi

    void retranslateUi(QDialog *scriptDialog)
    {
        scriptDialog->setWindowTitle(QApplication::translate("scriptDialog", "Dialog", Q_NULLPTR));
        moveUpButton->setText(QApplication::translate("scriptDialog", "Move Up", Q_NULLPTR));
        moveDownButton->setText(QApplication::translate("scriptDialog", "Move Down", Q_NULLPTR));
        removeFilterButton->setText(QApplication::translate("scriptDialog", "Remove", Q_NULLPTR));
        editParameterButton->setText(QApplication::translate("scriptDialog", "Edit Parameters", Q_NULLPTR));
        saveScriptButton->setText(QApplication::translate("scriptDialog", "Save Script", Q_NULLPTR));
        openScriptButton->setText(QApplication::translate("scriptDialog", "Open Script", Q_NULLPTR));
        clearScriptButton->setText(QApplication::translate("scriptDialog", "Clear Script", Q_NULLPTR));
        okButton->setText(QApplication::translate("scriptDialog", "Apply Script", Q_NULLPTR));
        cancelButton->setText(QApplication::translate("scriptDialog", "Close", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class scriptDialog: public Ui_scriptDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILTERSCRIPTDIALOG_H
