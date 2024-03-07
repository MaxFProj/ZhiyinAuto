#ifndef QTLICENSEMANAGER_H
#define QTLICENSEMANAGER_H

#include "LicenseManager.h"
#include <QThread>
#include <QMessageBox>
#include "emxRegisterDialog.h"


class LicenseCheckerThread : public QThread
{
	Q_OBJECT
public:
	void run() override;
	static LicenseCheckerThread* instance();
	void setMessageHandler(void* pHandler) const;
	void message(const QString & title, const QString & text, int* ret);
	void error(const QString & title, const QString & text, int* ret);
	void warning(const QString & title, const QString & text, int* ret);

signals:
	void message(int icon, const QString & title, const QString & text, int* ret, QMessageBox::StandardButtons buttons = QMessageBox::Ok, QMessageBox::StandardButton defaultButton = QMessageBox::NoButton);
	void exitApp();

private:
	static LicenseCheckerThread* m_pInstance;
};

class QtLicenseManager :public LicenseManager
{
public:
	virtual unsigned long check(char* msg = nullptr, const char* moduleName = nullptr) override;
	virtual void startLicenseThread() override;
	virtual void setMessageHandler(void* pHandler) override;
	static void init();

private:
	QtLicenseManager(void);
	~QtLicenseManager(void);
//	unsigned long isAppValid(char* msg);
	emxRegisterDialog* m_registerDialog;
	emxCodeRegister* m_codeRegister;
};

#endif // QTLICENSEMANAGER_H