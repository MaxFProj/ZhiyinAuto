/********************************************************************************
** Form generated from reading UI file 'renametexture.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RENAMETEXTURE_H
#define UI_RENAMETEXTURE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RenameTextureDialog
{
public:
    QSplitter *splitter;
    QSplitter *splitter_2;
    QSplitter *splitter_3;
    QWidget *layoutWidget;
    QSplitter *splitter_4;
    QPushButton *okButton;
    QPushButton *cancelButton;
    QLineEdit *newtexturename;
    QLabel *label;
    QPushButton *searchButton;

    void setupUi(QDialog *RenameTextureDialog)
    {
        if (RenameTextureDialog->objectName().isEmpty())
            RenameTextureDialog->setObjectName(QStringLiteral("RenameTextureDialog"));
        RenameTextureDialog->resize(473, 71);
        splitter = new QSplitter(RenameTextureDialog);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setGeometry(QRect(10, 10, 351, 17));
        splitter->setOrientation(Qt::Horizontal);
        splitter_2 = new QSplitter(RenameTextureDialog);
        splitter_2->setObjectName(QStringLiteral("splitter_2"));
        splitter_2->setGeometry(QRect(10, 10, 238, 23));
        splitter_2->setOrientation(Qt::Horizontal);
        splitter_3 = new QSplitter(RenameTextureDialog);
        splitter_3->setObjectName(QStringLiteral("splitter_3"));
        splitter_3->setGeometry(QRect(10, 10, 391, 17));
        splitter_3->setOrientation(Qt::Horizontal);
        layoutWidget = new QWidget(RenameTextureDialog);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 60, 351, 33));
        splitter_4 = new QSplitter(RenameTextureDialog);
        splitter_4->setObjectName(QStringLiteral("splitter_4"));
        splitter_4->setGeometry(QRect(10, 30, 367, 23));
        splitter_4->setOrientation(Qt::Horizontal);
        okButton = new QPushButton(RenameTextureDialog);
        okButton->setObjectName(QStringLiteral("okButton"));
        okButton->setGeometry(QRect(390, 40, 71, 23));
        cancelButton = new QPushButton(RenameTextureDialog);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        cancelButton->setGeometry(QRect(320, 40, 71, 23));
        newtexturename = new QLineEdit(RenameTextureDialog);
        newtexturename->setObjectName(QStringLiteral("newtexturename"));
        newtexturename->setGeometry(QRect(82, 10, 291, 21));
        label = new QLabel(RenameTextureDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 67, 21));
        searchButton = new QPushButton(RenameTextureDialog);
        searchButton->setObjectName(QStringLiteral("searchButton"));
        searchButton->setGeometry(QRect(380, 10, 81, 23));

        retranslateUi(RenameTextureDialog);
        QObject::connect(okButton, SIGNAL(clicked()), RenameTextureDialog, SLOT(accept()));
        QObject::connect(cancelButton, SIGNAL(clicked()), RenameTextureDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(RenameTextureDialog);
    } // setupUi

    void retranslateUi(QDialog *RenameTextureDialog)
    {
        RenameTextureDialog->setWindowTitle(QApplication::translate("RenameTextureDialog", "Dialog", Q_NULLPTR));
        okButton->setText(QApplication::translate("RenameTextureDialog", "OK", Q_NULLPTR));
        cancelButton->setText(QApplication::translate("RenameTextureDialog", "Cancel", Q_NULLPTR));
        newtexturename->setText(QString());
        label->setText(QApplication::translate("RenameTextureDialog", "<html><head><meta name=\"qrichtext\" content=\"1\" /></head><body style=\" white-space: pre-wrap; font-family:MS Shell Dlg; font-weight:400; font-style:normal; text-decoration:none;\"><p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Texture Name</p></body></html>", Q_NULLPTR));
        searchButton->setText(QApplication::translate("RenameTextureDialog", "Search Texture", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class RenameTextureDialog: public Ui_RenameTextureDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RENAMETEXTURE_H
