/********************************************************************************
** Form generated from reading UI file 'selectVerticesDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELECTVERTICESDIALOG_H
#define UI_SELECTVERTICESDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_SelectVerticesDialog
{
public:
    QRadioButton *radioButton_fixed;
    QRadioButton *radioButton_handled;
    QPushButton *pushButton_confirmSelection;
    QPushButton *pushButton_output;

    void setupUi(QDialog *SelectVerticesDialog)
    {
        if (SelectVerticesDialog->objectName().isEmpty())
            SelectVerticesDialog->setObjectName(QStringLiteral("SelectVerticesDialog"));
        SelectVerticesDialog->resize(400, 300);
        radioButton_fixed = new QRadioButton(SelectVerticesDialog);
        radioButton_fixed->setObjectName(QStringLiteral("radioButton_fixed"));
        radioButton_fixed->setGeometry(QRect(50, 40, 89, 16));
        radioButton_fixed->setChecked(true);
        radioButton_handled = new QRadioButton(SelectVerticesDialog);
        radioButton_handled->setObjectName(QStringLiteral("radioButton_handled"));
        radioButton_handled->setGeometry(QRect(50, 70, 121, 16));
        pushButton_confirmSelection = new QPushButton(SelectVerticesDialog);
        pushButton_confirmSelection->setObjectName(QStringLiteral("pushButton_confirmSelection"));
        pushButton_confirmSelection->setGeometry(QRect(50, 100, 75, 23));
        pushButton_output = new QPushButton(SelectVerticesDialog);
        pushButton_output->setObjectName(QStringLiteral("pushButton_output"));
        pushButton_output->setGeometry(QRect(140, 100, 75, 23));

        retranslateUi(SelectVerticesDialog);

        QMetaObject::connectSlotsByName(SelectVerticesDialog);
    } // setupUi

    void retranslateUi(QDialog *SelectVerticesDialog)
    {
        SelectVerticesDialog->setWindowTitle(QApplication::translate("SelectVerticesDialog", "\351\200\211\346\213\251\345\275\242\345\217\230\346\216\247\345\210\266\347\202\271", Q_NULLPTR));
        radioButton_fixed->setText(QApplication::translate("SelectVerticesDialog", "\351\200\211\346\213\251\344\270\215\345\212\250\347\202\271", Q_NULLPTR));
        radioButton_handled->setText(QApplication::translate("SelectVerticesDialog", "\351\200\211\346\213\251\350\267\237\351\232\217\347\247\273\345\212\250\347\202\271", Q_NULLPTR));
        pushButton_confirmSelection->setText(QApplication::translate("SelectVerticesDialog", "\347\241\256\350\256\244\351\200\211\346\213\251", Q_NULLPTR));
        pushButton_output->setText(QApplication::translate("SelectVerticesDialog", "\345\257\274\345\207\272\346\216\247\345\210\266\347\202\271", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SelectVerticesDialog: public Ui_SelectVerticesDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELECTVERTICESDIALOG_H
