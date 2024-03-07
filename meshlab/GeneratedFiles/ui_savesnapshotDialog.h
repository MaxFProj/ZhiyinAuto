/********************************************************************************
** Form generated from reading UI file 'savesnapshotDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SAVESNAPSHOTDIALOG_H
#define UI_SAVESNAPSHOTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_SSDialog
{
public:
    QVBoxLayout *vboxLayout;
    QHBoxLayout *hboxLayout;
    QLabel *label;
    QLineEdit *outDirLineEdit;
    QPushButton *browseDir;
    QSpacerItem *spacerItem;
    QHBoxLayout *hboxLayout1;
    QLabel *label_2;
    QLineEdit *baseNameLineEdit;
    QLabel *label_3;
    QSpinBox *counterSpinBox;
    QSpacerItem *spacerItem1;
    QCheckBox *alllayersCheckBox;
    QSpacerItem *horizontalSpacer_3;
    QCheckBox *tiledSaveCheckBox;
    QHBoxLayout *hboxLayout2;
    QSpacerItem *spacerItem2;
    QLabel *label_5;
    QComboBox *backgroundComboBox;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_4;
    QSpinBox *resolutionSpinBox;
    QSpacerItem *horizontalSpacer;
    QCheckBox *addToRastersCheckBox;
    QHBoxLayout *hboxLayout3;
    QSpacerItem *spacerItem3;
    QPushButton *cancelButton;
    QPushButton *saveButton;

    void setupUi(QDialog *SSDialog)
    {
        if (SSDialog->objectName().isEmpty())
            SSDialog->setObjectName(QStringLiteral("SSDialog"));
        SSDialog->resize(616, 225);
        vboxLayout = new QVBoxLayout(SSDialog);
        vboxLayout->setSpacing(6);
        vboxLayout->setContentsMargins(11, 11, 11, 11);
        vboxLayout->setObjectName(QStringLiteral("vboxLayout"));
        hboxLayout = new QHBoxLayout();
        hboxLayout->setSpacing(6);
        hboxLayout->setObjectName(QStringLiteral("hboxLayout"));
        label = new QLabel(SSDialog);
        label->setObjectName(QStringLiteral("label"));

        hboxLayout->addWidget(label);

        outDirLineEdit = new QLineEdit(SSDialog);
        outDirLineEdit->setObjectName(QStringLiteral("outDirLineEdit"));

        hboxLayout->addWidget(outDirLineEdit);

        browseDir = new QPushButton(SSDialog);
        browseDir->setObjectName(QStringLiteral("browseDir"));
        browseDir->setMinimumSize(QSize(20, 20));
        browseDir->setMaximumSize(QSize(20, 20));

        hboxLayout->addWidget(browseDir);

        spacerItem = new QSpacerItem(16, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout->addItem(spacerItem);


        vboxLayout->addLayout(hboxLayout);

        hboxLayout1 = new QHBoxLayout();
        hboxLayout1->setSpacing(6);
        hboxLayout1->setObjectName(QStringLiteral("hboxLayout1"));
        label_2 = new QLabel(SSDialog);
        label_2->setObjectName(QStringLiteral("label_2"));

        hboxLayout1->addWidget(label_2);

        baseNameLineEdit = new QLineEdit(SSDialog);
        baseNameLineEdit->setObjectName(QStringLiteral("baseNameLineEdit"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(baseNameLineEdit->sizePolicy().hasHeightForWidth());
        baseNameLineEdit->setSizePolicy(sizePolicy);
        baseNameLineEdit->setMinimumSize(QSize(200, 20));

        hboxLayout1->addWidget(baseNameLineEdit);

        label_3 = new QLabel(SSDialog);
        label_3->setObjectName(QStringLiteral("label_3"));

        hboxLayout1->addWidget(label_3);

        counterSpinBox = new QSpinBox(SSDialog);
        counterSpinBox->setObjectName(QStringLiteral("counterSpinBox"));
        counterSpinBox->setMaximum(999);

        hboxLayout1->addWidget(counterSpinBox);

        spacerItem1 = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout1->addItem(spacerItem1);

        alllayersCheckBox = new QCheckBox(SSDialog);
        alllayersCheckBox->setObjectName(QStringLiteral("alllayersCheckBox"));

        hboxLayout1->addWidget(alllayersCheckBox);

        horizontalSpacer_3 = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout1->addItem(horizontalSpacer_3);

        tiledSaveCheckBox = new QCheckBox(SSDialog);
        tiledSaveCheckBox->setObjectName(QStringLiteral("tiledSaveCheckBox"));

        hboxLayout1->addWidget(tiledSaveCheckBox);


        vboxLayout->addLayout(hboxLayout1);

        hboxLayout2 = new QHBoxLayout();
        hboxLayout2->setSpacing(6);
        hboxLayout2->setObjectName(QStringLiteral("hboxLayout2"));
        spacerItem2 = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout2->addItem(spacerItem2);

        label_5 = new QLabel(SSDialog);
        label_5->setObjectName(QStringLiteral("label_5"));

        hboxLayout2->addWidget(label_5);

        backgroundComboBox = new QComboBox(SSDialog);
        backgroundComboBox->setObjectName(QStringLiteral("backgroundComboBox"));

        hboxLayout2->addWidget(backgroundComboBox);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout2->addItem(horizontalSpacer_2);

        label_4 = new QLabel(SSDialog);
        label_4->setObjectName(QStringLiteral("label_4"));

        hboxLayout2->addWidget(label_4);

        resolutionSpinBox = new QSpinBox(SSDialog);
        resolutionSpinBox->setObjectName(QStringLiteral("resolutionSpinBox"));
        resolutionSpinBox->setMinimum(1);

        hboxLayout2->addWidget(resolutionSpinBox);

        horizontalSpacer = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout2->addItem(horizontalSpacer);

        addToRastersCheckBox = new QCheckBox(SSDialog);
        addToRastersCheckBox->setObjectName(QStringLiteral("addToRastersCheckBox"));

        hboxLayout2->addWidget(addToRastersCheckBox);


        vboxLayout->addLayout(hboxLayout2);

        hboxLayout3 = new QHBoxLayout();
        hboxLayout3->setSpacing(6);
        hboxLayout3->setObjectName(QStringLiteral("hboxLayout3"));
        spacerItem3 = new QSpacerItem(51, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout3->addItem(spacerItem3);

        cancelButton = new QPushButton(SSDialog);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        cancelButton->setMinimumSize(QSize(0, 25));
        cancelButton->setMaximumSize(QSize(16777215, 25));

        hboxLayout3->addWidget(cancelButton);

        saveButton = new QPushButton(SSDialog);
        saveButton->setObjectName(QStringLiteral("saveButton"));
        saveButton->setMinimumSize(QSize(0, 25));
        saveButton->setMaximumSize(QSize(16777215, 25));

        hboxLayout3->addWidget(saveButton);


        vboxLayout->addLayout(hboxLayout3);


        retranslateUi(SSDialog);

        saveButton->setDefault(true);


        QMetaObject::connectSlotsByName(SSDialog);
    } // setupUi

    void retranslateUi(QDialog *SSDialog)
    {
        SSDialog->setWindowTitle(QApplication::translate("SSDialog", "Save snapshot", Q_NULLPTR));
        label->setText(QApplication::translate("SSDialog", "Output folder  ", Q_NULLPTR));
        browseDir->setText(QApplication::translate("SSDialog", "...", Q_NULLPTR));
        label_2->setText(QApplication::translate("SSDialog", "Base name  ", Q_NULLPTR));
        label_3->setText(QApplication::translate("SSDialog", "Counter", Q_NULLPTR));
        alllayersCheckBox->setText(QApplication::translate("SSDialog", "Snap All Layers", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        tiledSaveCheckBox->setToolTip(QApplication::translate("SSDialog", "If checked, save each image independently, allowing to later combine the saved images into a very very large image", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        tiledSaveCheckBox->setText(QApplication::translate("SSDialog", "Tiled Save", Q_NULLPTR));
        label_5->setText(QApplication::translate("SSDialog", "Background", Q_NULLPTR));
        backgroundComboBox->clear();
        backgroundComboBox->insertItems(0, QStringList()
         << QApplication::translate("SSDialog", "MeshLab Gradient", Q_NULLPTR)
         << QApplication::translate("SSDialog", "Alpha Transparent", Q_NULLPTR)
         << QApplication::translate("SSDialog", "Solid White", Q_NULLPTR)
         << QApplication::translate("SSDialog", "Solid Black", Q_NULLPTR)
        );
#ifndef QT_NO_TOOLTIP
        label_4->setToolTip(QApplication::translate("SSDialog", "The resolution of the screenshot is the resolution of the current window multiplied by this number", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label_4->setText(QApplication::translate("SSDialog", "Screen Multiplier  ", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        resolutionSpinBox->setToolTip(QApplication::translate("SSDialog", "The resolution of the screenshot is the resolution of the current window multiplied by this number", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        addToRastersCheckBox->setText(QApplication::translate("SSDialog", "Add Snapshot as new Raster Layer", Q_NULLPTR));
        cancelButton->setText(QApplication::translate("SSDialog", "Cancel", Q_NULLPTR));
        saveButton->setText(QApplication::translate("SSDialog", "Save", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SSDialog: public Ui_SSDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SAVESNAPSHOTDIALOG_H
