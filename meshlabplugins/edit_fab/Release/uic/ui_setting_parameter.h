/********************************************************************************
** Form generated from reading UI file 'setting_parameter.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTING_PARAMETER_H
#define UI_SETTING_PARAMETER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SettingDialog
{
public:
    QDialogButtonBox *buttonBox;
    QGroupBox *groupBox;
    QRadioButton *radioButton_Robotic;
    QRadioButton *radioButton_5or4Axis;
    QGroupBox *groupBox_2;
    QRadioButton *radioButton_QR;
    QRadioButton *radioButton_Info;
    QRadioButton *radioButton_None;
    QGroupBox *groupBox_3;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *comboBox_correction;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QDoubleSpinBox *doubleSpinBox_qrwidth;

    void setupUi(QDialog *SettingDialog)
    {
        if (SettingDialog->objectName().isEmpty())
            SettingDialog->setObjectName(QStringLiteral("SettingDialog"));
        SettingDialog->resize(189, 395);
        SettingDialog->setMaximumSize(QSize(220, 450));
        buttonBox = new QDialogButtonBox(SettingDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(20, 350, 151, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        groupBox = new QGroupBox(SettingDialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(20, 10, 151, 91));
        radioButton_Robotic = new QRadioButton(groupBox);
        radioButton_Robotic->setObjectName(QStringLiteral("radioButton_Robotic"));
        radioButton_Robotic->setGeometry(QRect(10, 30, 107, 17));
        radioButton_Robotic->setChecked(true);
        radioButton_5or4Axis = new QRadioButton(groupBox);
        radioButton_5or4Axis->setObjectName(QStringLiteral("radioButton_5or4Axis"));
        radioButton_5or4Axis->setGeometry(QRect(10, 60, 107, 21));
        groupBox_2 = new QGroupBox(SettingDialog);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(20, 110, 151, 111));
        radioButton_QR = new QRadioButton(groupBox_2);
        radioButton_QR->setObjectName(QStringLiteral("radioButton_QR"));
        radioButton_QR->setGeometry(QRect(20, 20, 89, 17));
        radioButton_QR->setChecked(true);
        radioButton_Info = new QRadioButton(groupBox_2);
        radioButton_Info->setObjectName(QStringLiteral("radioButton_Info"));
        radioButton_Info->setGeometry(QRect(20, 50, 89, 17));
        radioButton_None = new QRadioButton(groupBox_2);
        radioButton_None->setObjectName(QStringLiteral("radioButton_None"));
        radioButton_None->setGeometry(QRect(20, 80, 89, 17));
        groupBox_3 = new QGroupBox(SettingDialog);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(20, 230, 151, 111));
        layoutWidget = new QWidget(groupBox_3);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 20, 121, 31));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        comboBox_correction = new QComboBox(layoutWidget);
        comboBox_correction->setObjectName(QStringLiteral("comboBox_correction"));

        horizontalLayout->addWidget(comboBox_correction);

        layoutWidget1 = new QWidget(groupBox_3);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(20, 60, 121, 31));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        doubleSpinBox_qrwidth = new QDoubleSpinBox(layoutWidget1);
        doubleSpinBox_qrwidth->setObjectName(QStringLiteral("doubleSpinBox_qrwidth"));
        doubleSpinBox_qrwidth->setMinimum(5);
        doubleSpinBox_qrwidth->setMaximum(30);
        doubleSpinBox_qrwidth->setValue(15);

        horizontalLayout_2->addWidget(doubleSpinBox_qrwidth);


        retranslateUi(SettingDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), SettingDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), SettingDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(SettingDialog);
    } // setupUi

    void retranslateUi(QDialog *SettingDialog)
    {
        SettingDialog->setWindowTitle(QApplication::translate("SettingDialog", "\350\256\276\347\275\256", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("SettingDialog", "\345\272\225\345\272\247\351\200\211\346\213\251", Q_NULLPTR));
        radioButton_Robotic->setText(QApplication::translate("SettingDialog", "\346\240\200\351\237\263\346\234\272\346\242\260\350\207\202\345\272\225\345\272\247", Q_NULLPTR));
        radioButton_5or4Axis->setText(QApplication::translate("SettingDialog", "\346\240\200\351\237\263V1\345\272\225\345\272\247", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("SettingDialog", "\344\277\241\346\201\257\346\230\276\347\244\272\346\226\271\345\274\217", Q_NULLPTR));
        radioButton_QR->setText(QApplication::translate("SettingDialog", "\344\272\214\347\273\264\347\240\201\350\257\206\345\210\253", Q_NULLPTR));
        radioButton_Info->setText(QApplication::translate("SettingDialog", "OCR\345\255\227\347\254\246\350\257\206\345\210\253", Q_NULLPTR));
        radioButton_None->setText(QApplication::translate("SettingDialog", "\346\227\240\345\272\225\347\211\210\345\217\212\344\277\241\346\201\257", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("SettingDialog", "\344\272\214\347\273\264\347\240\201\345\217\202\346\225\260", Q_NULLPTR));
        label->setText(QApplication::translate("SettingDialog", "\347\272\240\351\224\231\347\216\207\357\274\232", Q_NULLPTR));
        comboBox_correction->clear();
        comboBox_correction->insertItems(0, QStringList()
         << QApplication::translate("SettingDialog", "L-7%", Q_NULLPTR)
         << QApplication::translate("SettingDialog", "M-15%", Q_NULLPTR)
         << QApplication::translate("SettingDialog", "Q-25%", Q_NULLPTR)
         << QApplication::translate("SettingDialog", "H-30%", Q_NULLPTR)
        );
        label_2->setText(QApplication::translate("SettingDialog", "\345\256\275\345\272\246", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SettingDialog: public Ui_SettingDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTING_PARAMETER_H
