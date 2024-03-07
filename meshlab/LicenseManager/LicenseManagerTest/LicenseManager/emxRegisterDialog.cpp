#include "emxRegisterDialog.h"
#include <QVBoxLayout> 
#include <QHBoxLayout> 
#include <QLabel> 
#include <QRadioButton> 
#include <QButtonGroup> 
#include <QLineEdit> 
#include <QGridLayout> 
#include <QSettings>
#include <QTimerEvent>
#include "QtLicenseManager.h"
#include "config.h"
//#include "sentinel/SentinelKeys.h"
#ifdef Q_OS_WIN32
#include <windows.h>
#endif // Q_OS_WIN32
#define  DEVELOPERID                                         0xA97BF285

#define  LICENSEID                                           0x209
//Q_DECLARE_METATYPE(void*)//QVariant declare void pointer type for convert
//extern unsigned char SOFTWARE_KEY[SP_SOFTWARE_KEY_LEN];


emxRegisterDialog::emxRegisterDialog(QWidget * parent):QWizard(parent)
{
	//setWindowTitle(tr("emX Register Dialog"));
	settings= new QSettings(QSettings::NativeFormat, QSettings::UserScope, ORGNIZATION, APPLICATION);
	//setWizardStyle(QWizard::ClassicStyle);
	//FILE* file = fopen("doc/emX_help.chm","r");
	//QPixmap* pic= new QPixmap("res\register.png");
	//setPixmap(QWizard::BackgroundPixmap	,*pic);
	m_status = false;
	msgHandler = new emxMessageHandler;
	m_codeRegister = new emxCodeRegister(msgHandler);
	m_codeRegister->setRegisterDialog(this);
	//setField("codeRegister", m_codeRegister);
	init();
//	connect(button(QWizard::NextButton),SIGNAL(clicked()),this,SLOT(sentinelDetect()));
}

emxRegisterDialog::~emxRegisterDialog()
{
	delete msgHandler;	
	delete m_codeRegister;
}

void emxRegisterDialog::setRegID(QString regID)
{
	setField("regID", regID);
	/*QVariant temp = field("regID");
	void* t = temp.value<void*>();
	QLineEdit* regEdit = static_cast<QLineEdit*>(field("regID").value<void*>());
	regEdit->setText(regID);*/
//ui.regIDEdit->setText(regID);
	printf("[%s][%d] %s\n", __FUNCTION__, __LINE__, regID.toLocal8Bit().data());
}

QString emxRegisterDialog::getRegCode()
{
	//QLineEdit* codeEdit = static_cast<QLineEdit*>(field("regCodeEdit").value<void*>());
	//return codeEdit->text();
	//return ui.regCodeEdit->text();
	return field("regCodeEdit").value<QString>();
}

void emxRegisterDialog::accept()
{
// 	if(field("codeRadioButton").value<bool>())
// 	{
		settings->setValue("RegisterMode",0);
		if (codecheck())
		{
			m_status = true;
		}else{
			m_status = false;
		}
// 	}else
// 	{
// 		settings->setValue("RegisterMode",1);
// 		char errInfo[256];
// 		if(LicenseManager::instance()->check(errInfo) != LM_SUCCESS)
// 		{
// 			QMessageBox::critical(NULL, tr("Error"), QString::fromLocal8Bit(errInfo));
// 			m_status = false;
// 		}else{
// 			m_status = true;
// 		}
// 	}
	QDialog::accept();
}

void emxRegisterDialog::reject()
{
	QDialog::reject();
}

//QWizardPage * emxRegisterDialog::createRegistrationModePage()
//{
//	QWizardPage *page = new QWizardPage;
//	QVBoxLayout* verticalLayout = new QVBoxLayout();
//	QLabel* label = new QLabel();
//	verticalLayout->addWidget(label);
//	QHBoxLayout* horizontalLayout = new QHBoxLayout();
//	QRadioButton* codeRadioButton = new QRadioButton();
//	horizontalLayout->addWidget(codeRadioButton);
//	QRadioButton* dogRadioButton = new QRadioButton();
//	horizontalLayout->addWidget(dogRadioButton);
//	verticalLayout->addLayout(horizontalLayout);
//	page->setLayout(verticalLayout);
//	label->setText(tr("Please Select Register Mode"));
//	codeRadioButton->setText(tr("Register Code"));
//	dogRadioButton->setText(tr("Sentinel Dog"));
//	QButtonGroup* registerModeGroup = new QButtonGroup();
//	registerModeGroup->addButton(codeRadioButton,0);
//	registerModeGroup->addButton(dogRadioButton,1);
//	return page;
//}

// QWizardPage * emxRegisterDialog::createRegistrationPage()
// {
// 	QWizardPage *page = new QWizardPage;
// 	QGridLayout* gridlayout= new QGridLayout();
// 	QLabel* label = new QLabel();
// 	label->setText(tr("RegID"));
// 	gridlayout->addWidget(label,0,0);
// 	//QSpacerItem *horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
// 	//horizontalLayout->addItem(horizontalSpacer);
// 	QLineEdit* regIDEdit = new QLineEdit();
// 	gridlayout->addWidget(regIDEdit,0,1);
// 
// 	QLabel* label_2 = new QLabel();
// 	label_2->setText(tr( "RegCode"));
// 	gridlayout->addWidget(label_2,1,0);
// 	//QSpacerItem * horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
// 	//horizontalLayout_2->addItem(horizontalSpacer_2);
// 	QLineEdit* regCodeEdit = new QLineEdit();
// 	gridlayout->addWidget(regCodeEdit,1,1);
// 	//gridlayout->setRowStretch()
// 	page->setLayout(gridlayout);
// 	
// 	return page;
// }

void emxRegisterDialog::init()
{
//	setPage(Page_Intro,new IntroPage);
//	setPage(Page_RegisterMode,new registerationModePage);
	setPage(Page_Register,new registerationPage);
//	setPage(Page_SentinelCheck,new sentinelCheckPage);
	m_RegID = m_codeRegister->GetRegID(m_RegID, m_TrialRegID, m_LimitedRegID, m_FullRegID);
	setRegID(m_RegID);
	//if(!GenerateVolumeInfo(m_RegID, m_TrialRegID, m_LimitedRegID, m_FullRegID)) {
	//	// 无法获取本地C盘序列号
	//	//AfxMessageBox("读取注册信息失败，请联系浙江大学CAD&CG国家重点实验室");
	//	QMessageBox::critical(this, tr("Register Error"),tr("emX read the register information error,please contact Hangzhou Meiqi Technology"));
	//	exit(0);
	//}
	
	//addPage(createRegistrationModePage());
	//addPage(createRegistrationPage());
	//connect(ui.okButton,SIGNAL(clicked()),this,SLOT(accept()));
	//connect(ui.cancelButton,SIGNAL(clicked()),this,SLOT(reject()));
}

bool emxRegisterDialog::codecheck()
{
	return m_codeRegister->FullRegisterAndValidate(m_RegID, m_TrialRegID, m_LimitedRegID, m_FullRegID);
}

bool emxRegisterDialog::getStatus()
{
	return m_status;
}


QString emxRegisterDialog::getRegID()
{
	if (m_RegID.length()==0)
	{
		if(!m_codeRegister->GenerateVolumeInfo(m_RegID, m_TrialRegID, m_LimitedRegID, m_FullRegID)) {
			// 无法获取本地C盘序列号
			//AfxMessageBox("读取注册信息失败，请联系浙江大学CAD&CG国家重点实验室");
			QMessageBox::critical(this, tr("Register Error"),tr("imQ read the register information error,please contact Hangzhou Meiqi Technology"));
			exit(0);
		}
	}
	return m_RegID;
}

emxCodeRegister* emxRegisterDialog::getCodeRegister()
{
	return m_codeRegister;
}
// 
// void emxRegisterDialog::sentinelDetect()
// {
// 	if (currentId()==emxRegisterDialog::Page_SentinelCheck)
// 	{
// 		button(QWizard::FinishButton)->setDisabled(true);
// 		settings->setValue("RegisterMode",1);
// 		timeid = startTimer(1000);
// 		//emit accept();
// 	}
// }	
// 
// void emxRegisterDialog::timerEvent( QTimerEvent *event )
// {
// 	char errInfo[256];
// 	if (event->timerId() == timeid)
// 	{
// 		SP_DWORD  flags = SP_STANDALONE_MODE;	/* flags for License  */
// 		SP_HANDLE licHandle;
// 		if(SFNTGetLicense(DEVELOPERID, SOFTWARE_KEY, LICENSEID, flags, &licHandle ) == SP_SUCCESS)
// 		{
// 			killTimer(timeid);
// 			timeid = 0;
// 			emit accept();
// 		}
// 	}else
// 	{
// 		QWizard::timerEvent(event);
// 	}
// 	
// }


registerationModePage::registerationModePage( QWizard *parent /*=0*/ ):QWizardPage(parent)
{
	setTitle(tr("Registration Method"));
	setSubTitle(tr("Select a method to register iMQ. We offer two methods. You can register emX with registration code or Sentinel Dog"));
	verticalLayout = new QVBoxLayout();
	label = new QLabel();
	verticalLayout->addWidget(label);
	horizontalLayout = new QHBoxLayout();
	codeRadioButton = new QRadioButton();
	horizontalLayout->addWidget(codeRadioButton);
//	dogRadioButton = new QRadioButton();
//	horizontalLayout->addWidget(dogRadioButton);
//	verticalLayout->addLayout(horizontalLayout);
	this->setLayout(verticalLayout);
	label->setText(tr("Please Select Register Mode"));
	codeRadioButton->setText(tr("Register Code"));
//	dogRadioButton->setText(tr("Sentinel Dog"));
	codeRadioButton->setChecked(true);
	//registerModeGroup = new QButtonGroup();
// 	registerModeGroup->addButton(codeRadioButton,0);
// 	registerModeGroup->addButton(dogRadioButton,1);
	registerField("codeRadioButton", codeRadioButton);
//	registerField("dogRadioButton", dogRadioButton);
}

int registerationModePage::nextId() const
{
	if (codeRadioButton->isChecked())
	{
		return emxRegisterDialog::Page_Register;
	} else
	{
// 		if (dogRadioButton->isChecked())
// 		{
// 			return emxRegisterDialog::Page_SentinelCheck;
// 		}else
		{
			QMessageBox::information(nullptr, tr("Registration Error"),tr("please select registration method."));
			return emxRegisterDialog::Page_RegisterMode;
		}
		
	}
}

registerationPage::registerationPage( QWizard *parent /*=0*/ ):QWizardPage(parent)
{
// 	setTitle(tr("Registration Code"));
// 	//setSubTitle(tr("Please enter the registration code below.If you haven't registration code,please contact Hangzhou Meiqi Technology."));
// 	setSubTitle(tr("Please enter the Registration code below."));
	setTitle(tr("iMQ Registration"));
	setSubTitle(tr("iMQ is a simulation system used for invisible orthodontic treatment for orthodontic doctor. This distribution of the software is a trial version which is only used for technique preview. Please enter the registration code below to continue.If you don't have a registration code, please contact Hangzhou Meiqi Technology."));
	gridlayout= new QGridLayout();
	label = new QLabel();
	label->setText(tr("RegID"));
	gridlayout->addWidget(label,0,0);
	//QSpacerItem *horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
	//horizontalLayout->addItem(horizontalSpacer);
	regIDEdit = new QLineEdit();
	gridlayout->addWidget(regIDEdit,0,1);
	regIDEdit->setReadOnly(true);

	label_2 = new QLabel();
	label_2->setText(tr( "RegCode"));
	gridlayout->addWidget(label_2,1,0);
	//QSpacerItem * horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
	//horizontalLayout_2->addItem(horizontalSpacer_2);
	regCodeEdit = new QLineEdit();
	gridlayout->addWidget(regCodeEdit,1,1);
	//gridlayout->setRowStretch()
	this->setLayout(gridlayout);
	registerField("regID",regIDEdit);
	registerField("regCodeEdit",regCodeEdit);
}

int registerationPage::nextId() const
{
	return -1;
}
// 
// sentinelCheckPage::sentinelCheckPage( QWizard *parent /*=0*/ )
// {
// 	setTitle(tr("Sentinel Dog"));
// 	setSubTitle(tr("Insert Sentinel Dog into this computer."));
// 	verticalLayout = new QVBoxLayout();
// 	label = new QLabel;
// 	label->setText(tr("Sentinel Dog is checking..."));
// 	verticalLayout->addWidget(label);
// 	this->setLayout(verticalLayout);
// 	//registerField("SentinelErrorMsg",label);
// }
// 
// int sentinelCheckPage::nextId() const
// {
// 	return -1;
// }

IntroPage::IntroPage( QWizard *parent /*=0*/ )
{
	setTitle(tr("iMQ Intorduction"));
	setSubTitle(tr("iMQ is a simulation system used for invisible orthodontic treatment for orthodontic doctor. This distribution of the software is a trial version which is only used for technique preview."));
	verticalLayout = new QVBoxLayout();
	label = new QLabel("");
	//label = new QLabel(("emx is a high frequency electromagnetic scattering simulation system designed by Hangzhou Meiqi Technology."));
	QFont ft;
	ft.setPointSize(14);
	label->setFont(ft);
	verticalLayout->addWidget(label);
	this->setLayout(verticalLayout);
}

int IntroPage::nextId() const
{
	return emxRegisterDialog::Page_RegisterMode;
}
