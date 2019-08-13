#pragma once

#include <QApplication>
#include <QObject>
#include <QAbstractNativeEventFilter>
#include "QtGuiApplication3.h"
class QtGuiApplication3;

class VAZNativeEventFilter : public QAbstractNativeEventFilter
{
public:
	bool nativeEventFilter(const QByteArray &eventType, void *message, long *result) override;
};

/*自定义虚拟软键盘*/
typedef void(*fpRegisterObject)(QObject* obj);
typedef void(*fpShowKeyboard)();
typedef QObject *(*fpGetRegisterObject)();
/*自定义虚拟软键盘*/

class CVAZApplication : public QApplication
{
	Q_OBJECT

public:
	static CVAZApplication &GetInstance ();
	static CVAZApplication &GetInstance ( int & argc, char ** argv );
	~CVAZApplication();
	
	void setMainWindow(QtGuiApplication3* pWindow);

protected:
	bool notify(QObject *, QEvent *) override;

signals:
	void SignalNotifyKeyPressEvent(unsigned int iKeyVal, QString sObjName);
	void SignalNotifyMouseBtnPressEvent();

private slots:
	void SlotsQuit(bool bIsQiutWindow);

private:
	static CVAZApplication *st_pApplication;
	CVAZApplication( int & argc, char ** argv);
    void InitKeyboard();
    void MonitorUserOpr(QObject *obj, QEvent *e);
    void NotifyKeyboard(QObject *obj, QEvent *e);
    void NotifyStandby(QObject *obj, QEvent *e);
    void NotifyKeyRequest(QObject *obj, QEvent *e);

	QtGuiApplication3 *m_MainWin;
    fpRegisterObject m_fpRegisterObject;
    fpShowKeyboard m_fpShowKeyboard;
	fpGetRegisterObject m_GetRegisterObject;
};

CVAZApplication &GetApplication();
