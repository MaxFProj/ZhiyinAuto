/********************************************************************************
** Form generated from reading UI file 'congratsDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONGRATSDIALOG_H
#define UI_CONGRATSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_CongratsDialog
{
public:
    QVBoxLayout *vboxLayout;
    QTextBrowser *congratsTextBrowser;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *CongratsDialog)
    {
        if (CongratsDialog->objectName().isEmpty())
            CongratsDialog->setObjectName(QStringLiteral("CongratsDialog"));
        CongratsDialog->setWindowModality(Qt::ApplicationModal);
        CongratsDialog->resize(641, 449);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CongratsDialog->sizePolicy().hasHeightForWidth());
        CongratsDialog->setSizePolicy(sizePolicy);
        vboxLayout = new QVBoxLayout(CongratsDialog);
        vboxLayout->setObjectName(QStringLiteral("vboxLayout"));
        congratsTextBrowser = new QTextBrowser(CongratsDialog);
        congratsTextBrowser->setObjectName(QStringLiteral("congratsTextBrowser"));
        congratsTextBrowser->setSource(QUrl(QStringLiteral("qrc:/images/100mesh.html")));
        congratsTextBrowser->setOpenExternalLinks(true);

        vboxLayout->addWidget(congratsTextBrowser);

        buttonBox = new QDialogButtonBox(CongratsDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel);

        vboxLayout->addWidget(buttonBox);


        retranslateUi(CongratsDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), CongratsDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), CongratsDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(CongratsDialog);
    } // setupUi

    void retranslateUi(QDialog *CongratsDialog)
    {
        CongratsDialog->setWindowTitle(QApplication::translate("CongratsDialog", "MeshLab Congratulations!", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CongratsDialog: public Ui_CongratsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONGRATSDIALOG_H
