#include "emxMessageHandler.h"
#include <QApplication>

QMutex mutex;
QWaitCondition msgDlgClosed;

void emxMessageHandler::messageBox( int icon, const QString & title, const QString & text, int* ret, QMessageBox::StandardButtons buttons /*= Ok*/, QMessageBox::StandardButton defaultButton /*= NoButton*/ )
{
	mutex.lock();
	switch(icon)
	{
	case QMessageBox::Information:
		(*ret) = QMessageBox::information((QWidget*)(this->parent()), title, text, buttons, defaultButton);
		break;
	case QMessageBox::Warning:
		(*ret) = QMessageBox::warning((QWidget*)(this->parent()), title, text, buttons, defaultButton);
		break;
	case QMessageBox::Critical:
		(*ret) = QMessageBox::critical((QWidget*)(this->parent()), title, text, buttons, defaultButton);
		break;
	default:
		(*ret) = QMessageBox::information((QWidget*)(this->parent()), title, text, buttons, defaultButton);
	}
	msgDlgClosed.wakeAll();
	mutex.unlock();
}
