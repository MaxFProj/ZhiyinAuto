#include "LicenseManagerTest.h"
#include <QtWidgets/QApplication>
#include <QDebug>
#define USE_LICENSE_MANAGE
#ifdef USE_LICENSE_MANAGE
#include "LicenseManager\QtLicenseManager.h"
#include "LicenseManager\emxMessageHandler.h"
#endif

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
#ifdef USE_LICENSE_MANAGE
	//////////////////////////////////////////////////////////////////////////
	// !!! config.h中的宏定义决定了注册表中存储的位置
	// !!! 请根据实际情况修改其中宏定义的值
	emxMessageHandler* msgHandler = new emxMessageHandler;
	QtLicenseManager::init(); // init a license manager
	LicenseManager::instance()->setMessageHandler(msgHandler);
	char errInfo[256];
	sprintf(errInfo, "%s", QApplication::translate("QtLicenseManager", "Failed to get license! Please contact to MeiQi Tech and get a license to continue to use this software.", nullptr).toLocal8Bit().data()); // 请医生联系杭州美齐科技有限公司获得软件授权。
	if (LicenseManager::instance()->check(errInfo) != LM_SUCCESS)
	{
		QMessageBox::critical(nullptr, QApplication::translate("QtLicenseManager", "Error", 0), QString::fromLocal8Bit(errInfo));
		exit(0);
	}
#endif
	QString msg = QApplication::translate("MainWin", "\
<style type=\"text/css\">\
.producer{padding-left:40px;padding-bottom:45px;color:#888;}\
.license {padding-left:0px;color:#999;}\
</style>\
<table>\
<tr><td class=\"license\">%1</td></tr>\
</table>", nullptr);

#ifdef USE_LICENSE_MANAGE
	// 显示授权信息
	msg = msg.arg(QString::fromLocal8Bit(LicenseManager::instance()->getLicenseInfo().c_str()));
#else
	msg = msg.arg("");
#endif
	qDebug() << msg;

	// 显示主程序
	LicenseManagerTest w;
	w.show();

#ifdef USE_LICENSE_MANAGE
	// 启动授权检查线程
	LicenseManager::instance()->startLicenseThread();
	msgHandler->setParent(&w);
#endif
	return a.exec();
}
