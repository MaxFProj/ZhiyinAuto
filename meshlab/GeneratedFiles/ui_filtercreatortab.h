/********************************************************************************
** Form generated from reading UI file 'filtercreatortab.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILTERCREATORTAB_H
#define UI_FILTERCREATORTAB_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include "additionalgui.h"
#include "xmlgeneratorgui.h"

QT_BEGIN_NAMESPACE

class Ui_FilterCreatorTab
{
public:
    QGridLayout *mainlayout;
    PrimitiveButton *jsbut;
    QLabel *label;
    QFrame *jsframe;
    QGridLayout *gridLayout;
    MLScriptEditor *jscode;
    PrimitiveButton *guibut;
    QLabel *label_2;
    FilterGeneratorGUI *guiframe;

    void setupUi(QFrame *FilterCreatorTab)
    {
        if (FilterCreatorTab->objectName().isEmpty())
            FilterCreatorTab->setObjectName(QStringLiteral("FilterCreatorTab"));
        FilterCreatorTab->resize(785, 700);
        FilterCreatorTab->setFrameShape(QFrame::StyledPanel);
        FilterCreatorTab->setFrameShadow(QFrame::Raised);
        mainlayout = new QGridLayout(FilterCreatorTab);
        mainlayout->setObjectName(QStringLiteral("mainlayout"));
        jsbut = new PrimitiveButton(FilterCreatorTab);
        jsbut->setObjectName(QStringLiteral("jsbut"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(jsbut->sizePolicy().hasHeightForWidth());
        jsbut->setSizePolicy(sizePolicy);
        jsbut->setFlat(true);

        mainlayout->addWidget(jsbut, 0, 0, 1, 1);

        label = new QLabel(FilterCreatorTab);
        label->setObjectName(QStringLiteral("label"));
        label->setFrameShape(QFrame::NoFrame);
        label->setFrameShadow(QFrame::Plain);

        mainlayout->addWidget(label, 0, 1, 1, 1);

        jsframe = new QFrame(FilterCreatorTab);
        jsframe->setObjectName(QStringLiteral("jsframe"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(jsframe->sizePolicy().hasHeightForWidth());
        jsframe->setSizePolicy(sizePolicy1);
        jsframe->setFrameShape(QFrame::StyledPanel);
        jsframe->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(jsframe);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        jscode = new MLScriptEditor(jsframe);
        jscode->setObjectName(QStringLiteral("jscode"));

        gridLayout->addWidget(jscode, 0, 0, 1, 1);


        mainlayout->addWidget(jsframe, 1, 0, 1, 2);

        guibut = new PrimitiveButton(FilterCreatorTab);
        guibut->setObjectName(QStringLiteral("guibut"));
        sizePolicy.setHeightForWidth(guibut->sizePolicy().hasHeightForWidth());
        guibut->setSizePolicy(sizePolicy);
        guibut->setFlat(true);

        mainlayout->addWidget(guibut, 2, 0, 1, 1);

        label_2 = new QLabel(FilterCreatorTab);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFrameShape(QFrame::NoFrame);
        label_2->setFrameShadow(QFrame::Plain);

        mainlayout->addWidget(label_2, 2, 1, 1, 1);

        guiframe = new FilterGeneratorGUI(FilterCreatorTab);
        guiframe->setObjectName(QStringLiteral("guiframe"));
        guiframe->setFrameShape(QFrame::StyledPanel);
        guiframe->setFrameShadow(QFrame::Raised);

        mainlayout->addWidget(guiframe, 3, 0, 1, 2);


        retranslateUi(FilterCreatorTab);

        QMetaObject::connectSlotsByName(FilterCreatorTab);
    } // setupUi

    void retranslateUi(QFrame *FilterCreatorTab)
    {
        FilterCreatorTab->setWindowTitle(QApplication::translate("FilterCreatorTab", "Frame", Q_NULLPTR));
        jsbut->setText(QString());
        label->setText(QApplication::translate("FilterCreatorTab", "JavaScript Code Area", Q_NULLPTR));
        guibut->setText(QString());
        label_2->setText(QApplication::translate("FilterCreatorTab", "Filter Generator GUI", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class FilterCreatorTab: public Ui_FilterCreatorTab {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILTERCREATORTAB_H
