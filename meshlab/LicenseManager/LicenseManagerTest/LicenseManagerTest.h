#ifndef LICENSEMANAGERTEST_H
#define LICENSEMANAGERTEST_H

#include <QtWidgets/QMainWindow>
#include "ui_LicenseManagerTest.h"

class LicenseManagerTest : public QMainWindow
{
	Q_OBJECT

public:
	LicenseManagerTest(QWidget *parent = 0);
	~LicenseManagerTest();

private:
	Ui::LicenseManagerTestClass ui;
};

#endif // LICENSEMANAGERTEST_H
