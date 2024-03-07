#ifndef EMXMESSAGEHANDLER_H
#define EMXMESSAGEHANDLER_H

#include <QObject>
#include <QMessageBox>

// �������߳�ͬ�����ź��������߳���Ҫ��message box�ر��ټ���ִ��ʱ��ʹ�ø��ź������еȴ�
#include <QWaitCondition>
#include <QMutex>
extern QMutex mutex;
extern QWaitCondition msgDlgClosed;

class emxMessageHandler : public QObject
{
	Q_OBJECT
public slots:
	void messageBox(int icon, const QString & title, const QString & text, int* ret, QMessageBox::StandardButtons buttons = QMessageBox::Ok, QMessageBox::StandardButton defaultButton = QMessageBox::NoButton);
};

#endif // EMXMESSAGEHANDLER_H