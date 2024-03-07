/********************************************************************************
** Form generated from reading UI file 'savemaskexporter.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SAVEMASKEXPORTER_H
#define UI_SAVEMASKEXPORTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MaskExporterDialog
{
public:
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *hboxLayout;
    QGroupBox *groupBox;
    QVBoxLayout *vboxLayout;
    QCheckBox *check_iom_vertflags;
    QCheckBox *check_iom_vertcolor;
    QCheckBox *check_iom_vertquality;
    QCheckBox *check_iom_vertnormal;
    QCheckBox *check_iom_verttexcoord;
    QCheckBox *check_iom_vertradius;
    QSpacerItem *verticalSpacer_3;
    QGroupBox *groupBox_2;
    QVBoxLayout *vboxLayout1;
    QCheckBox *check_iom_faceflags;
    QCheckBox *check_iom_facecolor;
    QCheckBox *check_iom_facequality;
    QCheckBox *check_iom_facenormal;
    QSpacerItem *verticalSpacer;
    QGroupBox *groupBox_3;
    QVBoxLayout *vboxLayout2;
    QCheckBox *check_iom_wedgcolor;
    QCheckBox *check_iom_wedgnormal;
    QCheckBox *check_iom_wedgtexcoord;
    QSpacerItem *verticalSpacer_2;
    QGroupBox *groupBox_4;
    QVBoxLayout *vboxLayout3;
    QListWidget *listTextureName;
    QPushButton *renametextureButton;
    QGroupBox *saveParBox;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *AllButton;
    QRadioButton *NoneButton;
    QVBoxLayout *verticalLayout;
    QCheckBox *check_iom_camera;
    QCheckBox *check_iom_polygonal;
    QCheckBox *check_help;
    QSpacerItem *spacerItem;
    QPushButton *okButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *MaskExporterDialog)
    {
        if (MaskExporterDialog->objectName().isEmpty())
            MaskExporterDialog->setObjectName(QStringLiteral("MaskExporterDialog"));
        MaskExporterDialog->resize(687, 337);
        verticalLayout_3 = new QVBoxLayout(MaskExporterDialog);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        hboxLayout = new QHBoxLayout();
        hboxLayout->setObjectName(QStringLiteral("hboxLayout"));
        groupBox = new QGroupBox(MaskExporterDialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        vboxLayout = new QVBoxLayout(groupBox);
        vboxLayout->setContentsMargins(8, 8, 8, 8);
        vboxLayout->setObjectName(QStringLiteral("vboxLayout"));
        check_iom_vertflags = new QCheckBox(groupBox);
        check_iom_vertflags->setObjectName(QStringLiteral("check_iom_vertflags"));

        vboxLayout->addWidget(check_iom_vertflags);

        check_iom_vertcolor = new QCheckBox(groupBox);
        check_iom_vertcolor->setObjectName(QStringLiteral("check_iom_vertcolor"));

        vboxLayout->addWidget(check_iom_vertcolor);

        check_iom_vertquality = new QCheckBox(groupBox);
        check_iom_vertquality->setObjectName(QStringLiteral("check_iom_vertquality"));

        vboxLayout->addWidget(check_iom_vertquality);

        check_iom_vertnormal = new QCheckBox(groupBox);
        check_iom_vertnormal->setObjectName(QStringLiteral("check_iom_vertnormal"));

        vboxLayout->addWidget(check_iom_vertnormal);

        check_iom_verttexcoord = new QCheckBox(groupBox);
        check_iom_verttexcoord->setObjectName(QStringLiteral("check_iom_verttexcoord"));

        vboxLayout->addWidget(check_iom_verttexcoord);

        check_iom_vertradius = new QCheckBox(groupBox);
        check_iom_vertradius->setObjectName(QStringLiteral("check_iom_vertradius"));

        vboxLayout->addWidget(check_iom_vertradius);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        vboxLayout->addItem(verticalSpacer_3);


        hboxLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(MaskExporterDialog);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        vboxLayout1 = new QVBoxLayout(groupBox_2);
        vboxLayout1->setContentsMargins(8, 8, 8, 8);
        vboxLayout1->setObjectName(QStringLiteral("vboxLayout1"));
        check_iom_faceflags = new QCheckBox(groupBox_2);
        check_iom_faceflags->setObjectName(QStringLiteral("check_iom_faceflags"));

        vboxLayout1->addWidget(check_iom_faceflags);

        check_iom_facecolor = new QCheckBox(groupBox_2);
        check_iom_facecolor->setObjectName(QStringLiteral("check_iom_facecolor"));

        vboxLayout1->addWidget(check_iom_facecolor);

        check_iom_facequality = new QCheckBox(groupBox_2);
        check_iom_facequality->setObjectName(QStringLiteral("check_iom_facequality"));

        vboxLayout1->addWidget(check_iom_facequality);

        check_iom_facenormal = new QCheckBox(groupBox_2);
        check_iom_facenormal->setObjectName(QStringLiteral("check_iom_facenormal"));

        vboxLayout1->addWidget(check_iom_facenormal);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        vboxLayout1->addItem(verticalSpacer);


        hboxLayout->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(MaskExporterDialog);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        vboxLayout2 = new QVBoxLayout(groupBox_3);
        vboxLayout2->setContentsMargins(8, 8, 8, 8);
        vboxLayout2->setObjectName(QStringLiteral("vboxLayout2"));
        check_iom_wedgcolor = new QCheckBox(groupBox_3);
        check_iom_wedgcolor->setObjectName(QStringLiteral("check_iom_wedgcolor"));

        vboxLayout2->addWidget(check_iom_wedgcolor);

        check_iom_wedgnormal = new QCheckBox(groupBox_3);
        check_iom_wedgnormal->setObjectName(QStringLiteral("check_iom_wedgnormal"));

        vboxLayout2->addWidget(check_iom_wedgnormal);

        check_iom_wedgtexcoord = new QCheckBox(groupBox_3);
        check_iom_wedgtexcoord->setObjectName(QStringLiteral("check_iom_wedgtexcoord"));

        vboxLayout2->addWidget(check_iom_wedgtexcoord);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        vboxLayout2->addItem(verticalSpacer_2);


        hboxLayout->addWidget(groupBox_3);

        groupBox_4 = new QGroupBox(MaskExporterDialog);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        vboxLayout3 = new QVBoxLayout(groupBox_4);
        vboxLayout3->setContentsMargins(8, 8, 8, 8);
        vboxLayout3->setObjectName(QStringLiteral("vboxLayout3"));
        listTextureName = new QListWidget(groupBox_4);
        listTextureName->setObjectName(QStringLiteral("listTextureName"));

        vboxLayout3->addWidget(listTextureName);

        renametextureButton = new QPushButton(groupBox_4);
        renametextureButton->setObjectName(QStringLiteral("renametextureButton"));

        vboxLayout3->addWidget(renametextureButton);


        hboxLayout->addWidget(groupBox_4);


        verticalLayout_3->addLayout(hboxLayout);

        saveParBox = new QGroupBox(MaskExporterDialog);
        saveParBox->setObjectName(QStringLiteral("saveParBox"));

        verticalLayout_3->addWidget(saveParBox);

        layoutWidget = new QWidget(MaskExporterDialog);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));

        verticalLayout_3->addWidget(layoutWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        AllButton = new QRadioButton(MaskExporterDialog);
        AllButton->setObjectName(QStringLiteral("AllButton"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(AllButton->sizePolicy().hasHeightForWidth());
        AllButton->setSizePolicy(sizePolicy);

        verticalLayout_2->addWidget(AllButton);

        NoneButton = new QRadioButton(MaskExporterDialog);
        NoneButton->setObjectName(QStringLiteral("NoneButton"));
        sizePolicy.setHeightForWidth(NoneButton->sizePolicy().hasHeightForWidth());
        NoneButton->setSizePolicy(sizePolicy);

        verticalLayout_2->addWidget(NoneButton);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        check_iom_camera = new QCheckBox(MaskExporterDialog);
        check_iom_camera->setObjectName(QStringLiteral("check_iom_camera"));
        check_iom_camera->setCheckable(true);

        verticalLayout->addWidget(check_iom_camera);

        check_iom_polygonal = new QCheckBox(MaskExporterDialog);
        check_iom_polygonal->setObjectName(QStringLiteral("check_iom_polygonal"));

        verticalLayout->addWidget(check_iom_polygonal);


        horizontalLayout->addLayout(verticalLayout);

        check_help = new QCheckBox(MaskExporterDialog);
        check_help->setObjectName(QStringLiteral("check_help"));
        check_help->setCheckable(true);

        horizontalLayout->addWidget(check_help);

        spacerItem = new QSpacerItem(199, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(spacerItem);

        okButton = new QPushButton(MaskExporterDialog);
        okButton->setObjectName(QStringLiteral("okButton"));

        horizontalLayout->addWidget(okButton);

        cancelButton = new QPushButton(MaskExporterDialog);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));

        horizontalLayout->addWidget(cancelButton);


        verticalLayout_3->addLayout(horizontalLayout);


        retranslateUi(MaskExporterDialog);
        QObject::connect(okButton, SIGNAL(clicked()), MaskExporterDialog, SLOT(accept()));
        QObject::connect(cancelButton, SIGNAL(clicked()), MaskExporterDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(MaskExporterDialog);
    } // setupUi

    void retranslateUi(QDialog *MaskExporterDialog)
    {
        MaskExporterDialog->setWindowTitle(QApplication::translate("MaskExporterDialog", "Dialog", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("MaskExporterDialog", "Vert", Q_NULLPTR));
        check_iom_vertflags->setText(QApplication::translate("MaskExporterDialog", "Flags", Q_NULLPTR));
        check_iom_vertcolor->setText(QApplication::translate("MaskExporterDialog", "Color", Q_NULLPTR));
        check_iom_vertquality->setText(QApplication::translate("MaskExporterDialog", "Quality", Q_NULLPTR));
        check_iom_vertnormal->setText(QApplication::translate("MaskExporterDialog", "Normal", Q_NULLPTR));
        check_iom_verttexcoord->setText(QApplication::translate("MaskExporterDialog", "TexCoord", Q_NULLPTR));
        check_iom_vertradius->setText(QApplication::translate("MaskExporterDialog", "Radius", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("MaskExporterDialog", "Face", Q_NULLPTR));
        check_iom_faceflags->setText(QApplication::translate("MaskExporterDialog", "Flags", Q_NULLPTR));
        check_iom_facecolor->setText(QApplication::translate("MaskExporterDialog", "Color", Q_NULLPTR));
        check_iom_facequality->setText(QApplication::translate("MaskExporterDialog", "Quality", Q_NULLPTR));
        check_iom_facenormal->setText(QApplication::translate("MaskExporterDialog", "Normal", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("MaskExporterDialog", "Wedge", Q_NULLPTR));
        check_iom_wedgcolor->setText(QApplication::translate("MaskExporterDialog", "Color", Q_NULLPTR));
        check_iom_wedgnormal->setText(QApplication::translate("MaskExporterDialog", "Normal", Q_NULLPTR));
        check_iom_wedgtexcoord->setText(QApplication::translate("MaskExporterDialog", "TexCoord", Q_NULLPTR));
        groupBox_4->setTitle(QApplication::translate("MaskExporterDialog", "Texture Name", Q_NULLPTR));
        renametextureButton->setText(QApplication::translate("MaskExporterDialog", "Rename Texture", Q_NULLPTR));
        saveParBox->setTitle(QApplication::translate("MaskExporterDialog", "Additional Parameters", Q_NULLPTR));
        AllButton->setText(QApplication::translate("MaskExporterDialog", "All", Q_NULLPTR));
        NoneButton->setText(QApplication::translate("MaskExporterDialog", "None", Q_NULLPTR));
        check_iom_camera->setText(QApplication::translate("MaskExporterDialog", "Camera", Q_NULLPTR));
        check_iom_polygonal->setText(QApplication::translate("MaskExporterDialog", "Polygonal", Q_NULLPTR));
        check_help->setText(QApplication::translate("MaskExporterDialog", "Help", Q_NULLPTR));
        okButton->setText(QApplication::translate("MaskExporterDialog", "OK", Q_NULLPTR));
        cancelButton->setText(QApplication::translate("MaskExporterDialog", "Cancel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MaskExporterDialog: public Ui_MaskExporterDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SAVEMASKEXPORTER_H
