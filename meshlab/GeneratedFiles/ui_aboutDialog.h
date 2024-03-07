/********************************************************************************
** Form generated from reading UI file 'aboutDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUTDIALOG_H
#define UI_ABOUTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_aboutDialog
{
public:
    QVBoxLayout *vboxLayout;
    QGroupBox *groupBoxSx;
    QHBoxLayout *hboxLayout;
    QVBoxLayout *vboxLayout1;
    QLabel *labelMLLogo;
    QSpacerItem *spacerItem;
    QLabel *labelMLName;
    QLabel *labelMLLink;
    QSpacerItem *spacerItem1;
    QVBoxLayout *vboxLayout2;
    QLabel *label;
    QHBoxLayout *hboxLayout1;
    QHBoxLayout *hboxLayout2;
    QLabel *labelVCGLogo_4;
    QLabel *labelVCGDescription;
    QVBoxLayout *vboxLayout3;
    QSpacerItem *spacerItem2;
    QHBoxLayout *hboxLayout3;
    QSpacerItem *spacerItem3;
    QPushButton *okButton;

    void setupUi(QDialog *aboutDialog)
    {
        if (aboutDialog->objectName().isEmpty())
            aboutDialog->setObjectName(QStringLiteral("aboutDialog"));
        aboutDialog->resize(808, 784);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(aboutDialog->sizePolicy().hasHeightForWidth());
        aboutDialog->setSizePolicy(sizePolicy);
        aboutDialog->setMinimumSize(QSize(0, 0));
        aboutDialog->setMaximumSize(QSize(65536, 65536));
        QIcon icon;
        icon.addFile(QStringLiteral("."), QSize(), QIcon::Normal, QIcon::Off);
        aboutDialog->setWindowIcon(icon);
        aboutDialog->setModal(true);
        vboxLayout = new QVBoxLayout(aboutDialog);
        vboxLayout->setObjectName(QStringLiteral("vboxLayout"));
        groupBoxSx = new QGroupBox(aboutDialog);
        groupBoxSx->setObjectName(QStringLiteral("groupBoxSx"));
        groupBoxSx->setFlat(false);
        hboxLayout = new QHBoxLayout(groupBoxSx);
        hboxLayout->setSpacing(0);
        hboxLayout->setObjectName(QStringLiteral("hboxLayout"));
        hboxLayout->setContentsMargins(0, 0, 0, 0);
        vboxLayout1 = new QVBoxLayout();
        vboxLayout1->setObjectName(QStringLiteral("vboxLayout1"));
        labelMLLogo = new QLabel(groupBoxSx);
        labelMLLogo->setObjectName(QStringLiteral("labelMLLogo"));
        labelMLLogo->setPixmap(QPixmap(QString::fromUtf8(":/images/meshlabLogo_256x256.png")));
        labelMLLogo->setAlignment(Qt::AlignCenter);

        vboxLayout1->addWidget(labelMLLogo);

        spacerItem = new QSpacerItem(20, 5, QSizePolicy::Minimum, QSizePolicy::Expanding);

        vboxLayout1->addItem(spacerItem);

        labelMLName = new QLabel(groupBoxSx);
        labelMLName->setObjectName(QStringLiteral("labelMLName"));
        QFont font;
        font.setPointSize(12);
        labelMLName->setFont(font);
        labelMLName->setAlignment(Qt::AlignCenter);

        vboxLayout1->addWidget(labelMLName);

        labelMLLink = new QLabel(groupBoxSx);
        labelMLLink->setObjectName(QStringLiteral("labelMLLink"));
        labelMLLink->setAlignment(Qt::AlignCenter);
        labelMLLink->setOpenExternalLinks(true);

        vboxLayout1->addWidget(labelMLLink);

        spacerItem1 = new QSpacerItem(20, 5, QSizePolicy::Minimum, QSizePolicy::Expanding);

        vboxLayout1->addItem(spacerItem1);


        hboxLayout->addLayout(vboxLayout1);

        vboxLayout2 = new QVBoxLayout();
        vboxLayout2->setObjectName(QStringLiteral("vboxLayout2"));
        label = new QLabel(groupBoxSx);
        label->setObjectName(QStringLiteral("label"));
        label->setWordWrap(true);
        label->setMargin(3);
        label->setOpenExternalLinks(true);

        vboxLayout2->addWidget(label);


        hboxLayout->addLayout(vboxLayout2);


        vboxLayout->addWidget(groupBoxSx);

        hboxLayout1 = new QHBoxLayout();
        hboxLayout1->setObjectName(QStringLiteral("hboxLayout1"));
        hboxLayout2 = new QHBoxLayout();
        hboxLayout2->setObjectName(QStringLiteral("hboxLayout2"));
        labelVCGLogo_4 = new QLabel(aboutDialog);
        labelVCGLogo_4->setObjectName(QStringLiteral("labelVCGLogo_4"));
        labelVCGLogo_4->setMinimumSize(QSize(186, 150));
        labelVCGLogo_4->setPixmap(QPixmap(QString::fromUtf8(":/images/logo.png")));
        labelVCGLogo_4->setScaledContents(false);

        hboxLayout2->addWidget(labelVCGLogo_4);

        labelVCGDescription = new QLabel(aboutDialog);
        labelVCGDescription->setObjectName(QStringLiteral("labelVCGDescription"));
        labelVCGDescription->setOpenExternalLinks(true);

        hboxLayout2->addWidget(labelVCGDescription);


        hboxLayout1->addLayout(hboxLayout2);

        vboxLayout3 = new QVBoxLayout();
        vboxLayout3->setObjectName(QStringLiteral("vboxLayout3"));
        spacerItem2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        vboxLayout3->addItem(spacerItem2);

        hboxLayout3 = new QHBoxLayout();
        hboxLayout3->setObjectName(QStringLiteral("hboxLayout3"));
        spacerItem3 = new QSpacerItem(2, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout3->addItem(spacerItem3);

        okButton = new QPushButton(aboutDialog);
        okButton->setObjectName(QStringLiteral("okButton"));

        hboxLayout3->addWidget(okButton);


        vboxLayout3->addLayout(hboxLayout3);


        hboxLayout1->addLayout(vboxLayout3);


        vboxLayout->addLayout(hboxLayout1);


        retranslateUi(aboutDialog);
        QObject::connect(okButton, SIGNAL(clicked()), aboutDialog, SLOT(close()));

        QMetaObject::connectSlotsByName(aboutDialog);
    } // setupUi

    void retranslateUi(QDialog *aboutDialog)
    {
        aboutDialog->setWindowTitle(QApplication::translate("aboutDialog", "About MeshLab", Q_NULLPTR));
        groupBoxSx->setTitle(QString());
        labelMLLogo->setText(QString());
        labelMLName->setText(QString());
        labelMLLink->setText(QApplication::translate("aboutDialog", "<html><head/><body><p><span style=\" font-size:16pt; font-weight:600;\"><br/></span><a href=\"http://www.meshlab.net\"><span style=\" font-family:'MS Shell Dlg'; font-size:16pt; font-weight:600; text-decoration: underline; color:#0000ff;\">http://www.meshlab.net/ </span></a></p><p><span style=\" font-family:'MS Shell Dlg'; font-size:13pt;\">Protected by the GPL</span></p></body></html>", Q_NULLPTR));
        label->setText(QApplication::translate("aboutDialog", "<html><head/><body><p><span style=\" font-weight:600;\">General Info</span><br/>MeshLab is the most used open source system for processing and editing 3D triangular meshes. It provides a set of tools for editing, cleaning, healing, inspecting, rendering, texturing and converting meshes. It offers features for processing raw data produced by 3D digitization tools/devices and for preparing models for 3D printing. The system is heavily based on the <a href=\"http://www.vcglib.net\"><span style=\" text-decoration: underline; color:#0000ff;\">VCG library</span></a>. <br/>Source code is available on <a href=\"https://github.com/cnr-isti-vclab/meshlab\"><span style=\" text-decoration: underline; color:#0000ff;\">GitHub</span></a>.<br/><br/><span style=\" font-weight:600;\">References</span><br/>Please, when using this tool in any academic activity, cite its use with the following reference:<br/><br/>Meshlab: an open-source mesh processing tool.<br/>P. Cignoni, M. Callieri, M. Corsini, M. Dellepiane, F. Ganovelli, G. "
                        "Ranzuglia<br/>Proceedings of the 2008 Eurographics Italian Chapter Conference,<br/>ISBN: 978-3-905673-68-5, pp. 129-136, <br/>DOI: 10.2312/LocalChapterEvents/ItalChap/ItalianChapConf2008/129-136<br/><br/>Paper available on the<a href=\"https://diglib.eg.org/handle/10.2312/LocalChapterEvents.ItalChap.ItalianChapConf2008.129-136\"><span style=\" text-decoration: underline; color:#0000ff;\">Eurographics Digital Library</span></a> (<a href=\"http://vcg.isti.cnr.it/Publications/2008/CCCDGR08/\"><span style=\" text-decoration: underline; color:#0000ff;\">PDF)</span></a><br/><br/><span style=\" font-weight:600;\">Contacts</span><br/>For detailed bug reports, meaningful feature requests and grounded technical issues please use the <a href=\"https://github.com/cnr-isti-vclab/meshlab/issues\"><span style=\" text-decoration: underline; color:#0000ff;\">GitHub services</span></a>.<br/>For any other high-level question about MeshLab (no bugs or feature requests, please) contact:<br/>- Paolo Cignoni (<a href=\"mailto:p.cign"
                        "oni@isti.cnr.it?subject=%5BMeshLab%5D%20Info%20request\"><span style=\" text-decoration: underline; color:#0000ff;\">paolo.cignoni@isti.cnr.it</span></a>)<br/>The complete list of contributors is available <a href=\"https://github.com/cnr-isti-vclab/meshlab/graphs/contributors\"><span style=\" text-decoration: underline; color:#0000ff;\">here.</span></a><br/>Some of the contributors of MeshLab have received financial support from various projects, acknowledged <a href=\"http://vcg.isti.cnr.it/projects.php\"><span style=\" text-decoration: underline; color:#0000ff;\">here.</span></a></p></body></html>", Q_NULLPTR));
        labelVCGLogo_4->setText(QString());
        labelVCGDescription->setText(QApplication::translate("aboutDialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'.SF NS Text'; font-size:13pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Lucida Grande'; font-size:11pt;\">Copyright(C) 2005-2017<br /><br />Paolo Cignoni</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><a href=\"http://vcg.isti.cnr.it/%7Ecignoni\"><span style=\" font-family:'Lucida Grande'; font-size:11pt; color:#0000ff;\">http://vcg.isti.cnr.it/~cignoni</span></a></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-fami"
                        "ly:'Lucida Grande'; font-size:11pt;\">Visual Computing Lab</span><span style=\" font-family:'Lucida Grande'; font-size:11pt; font-weight:600; font-style:italic;\"><br /></span><a href=\"http://vcg.isti.cnr.it\"><span style=\" font-family:'Lucida Grande'; font-size:11pt; color:#0000ff;\">http://vcg.isti.cnr.it</span></a><span style=\" font-family:'Lucida Grande'; font-size:11pt; font-weight:600; font-style:italic;\"><br /></span><span style=\" font-family:'Lucida Grande'; font-size:11pt;\">ISTI - CNR</span><span style=\" font-family:'Lucida Grande'; font-size:11pt; font-weight:600; font-style:italic;\"><br /></span><a href=\"http://www.isti.cnr.it\"><span style=\" font-family:'Lucida Grande'; font-size:11pt; text-decoration: underline; color:#0000ff;\">http://www.isti.cnr.it</span></a><span style=\" font-family:'Lucida Grande'; font-size:11pt; font-weight:600; font-style:italic;\"><br /></span></p></body></html>", Q_NULLPTR));
        okButton->setText(QApplication::translate("aboutDialog", "OK", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class aboutDialog: public Ui_aboutDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUTDIALOG_H
