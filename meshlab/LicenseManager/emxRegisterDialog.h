#ifndef EMXREGISTERDIALOG_H
#define EMXREGISTERDIALOG_H
#include <QWizard>
#include "emxCodeRegister.h"
#include "emxMessageHandler.h"
#define REG_ID_LENGTH 21
class QVBoxLayout;
class QHBoxLayout;
class QLabel;
class QRadioButton;
class QButtonGroup;
class QLineEdit;
class QGridLayout;

class emxRegisterDialog:public QWizard
{
	Q_OBJECT
public:
	enum { Page_Intro, Page_RegisterMode, Page_Register,Page_SentinelCheck};
	emxRegisterDialog(QWidget* parent=0);
	~emxRegisterDialog();
	void setRegID(QString regID);
	QString getRegCode();
	bool codecheck();
	bool getStatus();
	QString getRegID();
	emxCodeRegister* getCodeRegister();
// protected:
// 	void timerEvent(QTimerEvent *event);
private:
	void init();
	/**
	* @brief create a page to select Register method (register code or Sentinel Dog)
	* @since 2014/04/29
	*/
	//QWizardPage *createRegistrationModePage();
		/**
	* @brief create a page to input the register code
	* @since 2014/04/29
	*/
	//QWizardPage *createRegistrationPage();
// public slots:
// 	/**
// 	  *@brief used for detect sentinel dog when get in the sentinel page
// 	  *@since 2014/5/6
// 	  */
// 	void sentinelDetect();
private slots:
	void accept();
	void reject();
private:
	QSettings* settings;
	int timeid;
	emxCodeRegister* m_codeRegister;
	QString m_RegID;
	QString m_TrialRegID;
	QString m_LimitedRegID;
	QString m_FullRegID;
	emxMessageHandler* msgHandler;
	bool m_status;
};
class IntroPage:public QWizardPage
{
	Q_OBJECT
public:
	IntroPage(QWizard *parent =0);
	virtual int nextId()const;
private:
	QVBoxLayout* verticalLayout;
	QLabel* label;
};
class registerationModePage:public QWizardPage
{
	Q_OBJECT
public:
	registerationModePage(QWizard *parent =0);
	virtual int nextId()const;
private:
	QVBoxLayout* verticalLayout;
	QLabel* label;
	QHBoxLayout* horizontalLayout;
	QRadioButton* codeRadioButton;
//	QRadioButton* dogRadioButton;
	QButtonGroup* registerModeGroup;
};

class registerationPage:public QWizardPage
{
	Q_OBJECT
public:
	registerationPage(QWizard *parent =0);
	virtual int nextId()const;
private:
	QGridLayout* gridlayout;
	QLabel* label;
	QLineEdit* regIDEdit;
	QLabel* label_2;
	QLineEdit* regCodeEdit;
};
// 
// class sentinelCheckPage:public QWizardPage
// {
// 	Q_OBJECT
// public:
// 	sentinelCheckPage(QWizard *parent =0);
// 	virtual int nextId()const;
// private:
// 	QVBoxLayout* verticalLayout;
// 	QLabel* label;
// };
#endif//EMXREGISTERDIALOG_H
