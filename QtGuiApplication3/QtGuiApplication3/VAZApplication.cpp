#include <QtCore/QDebug>
#include <QLineEdit>
#include <QTextEdit>
#include <QPlainTextEdit>
#include <QComboBox>
#include "VAZApplication.h"
#include <WinUser.h>
#include <assert.h>
bool VAZNativeEventFilter::nativeEventFilter(const QByteArray &eventType, void *message, long *result)
{
	bool bRtn = false;
	if (eventType == "windows_generic_MSG" || eventType == "windows_dispatcher_MSG")
	{
		MSG *pWinMsg = static_cast<MSG *>(message);

		int iErr = pWinMsg->lParam;
		int iLisReqID = pWinMsg->wParam;
		switch (pWinMsg->message)
		{
		case WM_QUERYENDSESSION:
			bRtn = true;
			break;

		case WM_ENDSESSION:
			bRtn = true;
			break;
		case WM_KEYDOWN:
		case WM_KEYUP:
			{
				bRtn = false;
			}
			break;
		default:
			break;
		}
	}

	return bRtn;
}

CVAZApplication *CVAZApplication::st_pApplication = NULL;

CVAZApplication & CVAZApplication::GetInstance()
{
	assert(st_pApplication != NULL);

	return *st_pApplication;
}

CVAZApplication & CVAZApplication::GetInstance( int & argc, char ** argv )
{
	if (st_pApplication == NULL)
	{
		st_pApplication = new CVAZApplication( argc, argv );
	}

	assert(st_pApplication != NULL);

	return *st_pApplication;
}

CVAZApplication::CVAZApplication( int & argc, char ** argv )
	: QApplication(argc, argv)
	, m_MainWin(nullptr)
{
    InitKeyboard();
}

CVAZApplication::~CVAZApplication()
{
	if(m_MainWin != nullptr)
		disconnect(this, SIGNAL(SignalNotifyKeyPressEvent(unsigned int, QString)), m_MainWin, SLOT(SlotKeyPressEvent(unsigned int, QString)));
}

CVAZApplication & GetApplication()
{
	return CVAZApplication::GetInstance();
}

bool CVAZApplication::notify(QObject *obj, QEvent *e)
{
    MonitorUserOpr(obj, e);
    NotifyKeyboard(obj, e);
    NotifyStandby(obj, e);
    NotifyKeyRequest(obj, e);

	return QApplication::notify(obj, e);  
}

void CVAZApplication::setMainWindow(QtGuiApplication3* pWindow)
{
	m_MainWin = pWindow; 
	connect(this, SIGNAL(SignalNotifyKeyPressEvent(unsigned int, QString)), pWindow, SLOT(SlotKeyPressEvent(unsigned int, QString)));
}

void CVAZApplication::SlotsQuit(bool bIsQiutWindows)
{
	//TODO:根据windows的CheckBox选项，关闭windows
	if(bIsQiutWindows)
	{
		//TODO:执行关闭windows
		//WRITE_LOG(eLogChannelID_Default, eLogLevel_Info, _T("InitiateShutdown(关闭计算机!)"));
		HANDLE hToken; 
		TOKEN_PRIVILEGES tkp; 

		if (!OpenProcessToken(GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, &hToken)) 
			return; 

		//获得LUID关机的 特权 
		LookupPrivilegeValue(NULL, SE_SHUTDOWN_NAME, 
			&tkp.Privileges[0].Luid); 

		tkp.PrivilegeCount = 1;  // 设置一个特权   
		tkp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED; 

		//获取此过程的关机特权
		AdjustTokenPrivileges(hToken, FALSE, &tkp, 0, (PTOKEN_PRIVILEGES)NULL, 0); 
		if (GetLastError() != ERROR_SUCCESS) 
			return; 

		//关闭计算机
		if (!ExitWindowsEx(EWX_SHUTDOWN | EWX_FORCE, 
			SHTDN_REASON_MAJOR_OPERATINGSYSTEM |SHTDN_REASON_MINOR_UPGRADE | SHTDN_REASON_FLAG_PLANNED)) 
			return; 
	}

	//WRITE_LOG(eLogChannelID_Default, eLogLevel_Info, _T("quit(退出软件)"));
	quit();	//退出软件
}


void CVAZApplication::InitKeyboard()
{
	QString sPath = "E:\\Young\\project\\myPlot\\QtGuiApplication3\\Win32\\Debug\\SoftKeyboard_dll.dll";
	QLibrary lib(sPath);
	bool bIsLoad = lib.load();
	if (!bIsLoad)
	{
		//WRITE_ERROR_LOG(_T("Load Keyboard Library failed! Path:") + sPath + _T("; Reason:") + lib.errorString().toStdWString());
		return;
	}

	m_fpRegisterObject = (fpRegisterObject)lib.resolve("RegisterObject");
	if (m_fpRegisterObject == nullptr) {}
	//WRITE_ERROR_LOG(_T("resolve 'RegisterObject' failed! Reason:") + lib.errorString().toStdWString());

	m_fpShowKeyboard = (fpShowKeyboard)lib.resolve("ShowKeyboard");
	if (m_fpShowKeyboard == nullptr) {}
	//WRITE_ERROR_LOG(_T("resolve 'ShowKeyboard' failed! Reason:") + lib.errorString().toStdWString());
}

void CVAZApplication::MonitorUserOpr(QObject *obj, QEvent *e)
{
    if (e->type() != QEvent::MouseButtonPress 
        && e->type() != QEvent::MouseButtonRelease)
        return;

    QString sText = "";
    do {
        if (e->type() == QEvent::MouseButtonRelease)
        {
            if (obj->inherits("QAbstractSpinBox"))
            {
                QAbstractSpinBox* pAbstractSpinBox = dynamic_cast<QAbstractSpinBox*>(obj);
                if (pAbstractSpinBox == Q_NULLPTR)
                    return;

                sText = pAbstractSpinBox->text();
                pAbstractSpinBox = Q_NULLPTR;
                break;
            }

            QWidget* pWidget = dynamic_cast<QWidget*>(obj);
            QWidget* pParentWidget = Q_NULLPTR;
            if (pWidget != Q_NULLPTR)
            {
                pParentWidget = pWidget->parentWidget();
                if (pParentWidget != Q_NULLPTR && pParentWidget->inherits("QAbstractItemView"))
                {
                    QAbstractItemView* pAbstractItemView = dynamic_cast<QAbstractItemView*>(pParentWidget);
                    if (pAbstractItemView == Q_NULLPTR)
                        return;

                    sText = pAbstractItemView->currentIndex().data().toString() +
                        ", Row:" + QString::number(pAbstractItemView->currentIndex().row()) +
                        ", Column:" + QString::number(pAbstractItemView->currentIndex().column());
                    pAbstractItemView = Q_NULLPTR;
                    break;
                }
            }

            return;
        }

        if (obj->inherits("QComboBox"))
        {
            QComboBox* pComboBox = dynamic_cast<QComboBox*>(obj);
            if (pComboBox == Q_NULLPTR)
                return;

            sText = pComboBox->currentText();
            pComboBox = Q_NULLPTR;
        }
        else if (obj->inherits("QLineEdit"))
        {
            QLineEdit* pLineEdit = dynamic_cast<QLineEdit*>(obj);
            if (pLineEdit == Q_NULLPTR)
                return;

            sText = pLineEdit->text();
            pLineEdit = Q_NULLPTR;
        }
        else if (obj->inherits("QAbstractButton"))
        {
            QAbstractButton* pAbstractButton = dynamic_cast<QAbstractButton*>(obj);
            if (pAbstractButton == Q_NULLPTR)
                return;

            sText = pAbstractButton->text();
            pAbstractButton = Q_NULLPTR;
        }
        else return;
    } while (0);

    //WriteLogSpec(eLogChannelID_UserOpr, eLogLevel_Info, _T("Obj: %s, Text: %s"), 
    //    VAZConvStrQ2T(obj->objectName()).c_str(), VAZConvStrQ2T(sText).c_str());
}

void CVAZApplication::NotifyKeyboard(QObject *obj, QEvent *e)
{
    if (dynamic_cast<QWidget*>(obj) != Q_NULLPTR
        && e->type() == QEvent::MouseButtonPress)
    {
        QWidget* pWidget = dynamic_cast<QWidget*>(obj);
        QWidget* pParentWidget = pWidget->parentWidget();
        if (dynamic_cast<QLineEdit*>(obj) == Q_NULLPTR)
        {
            if (pParentWidget == Q_NULLPTR)
                return;

            if (!pParentWidget->inherits("QTextEdit")
                && !pParentWidget->inherits("QPlainTextEdit"))
                return;

            if (pParentWidget->inherits("QTextEdit"))
            {
                if (dynamic_cast<QTextEdit*>(pParentWidget)->isReadOnly()
                    || !dynamic_cast<QTextEdit*>(pParentWidget)->isEnabled())
                    return;

            }
            else
            {
                if (dynamic_cast<QPlainTextEdit*>(pParentWidget)->isReadOnly()
                    || !dynamic_cast<QPlainTextEdit*>(pParentWidget)->isEnabled())
                    return;

            }

            m_fpRegisterObject(pParentWidget);
        }
        else
        {
            if (dynamic_cast<QLineEdit*>(obj)->isReadOnly()
                || !dynamic_cast<QLineEdit*>(obj)->isEnabled())
                return;
            m_fpRegisterObject(obj);
        }


        m_fpShowKeyboard();
    }
}

void CVAZApplication::NotifyStandby(QObject *obj, QEvent *e)
{
    if ((e->type() == QEvent::KeyPress
        || e->type() == QEvent::KeyRelease
        || e->type() == QEvent::MouseButtonPress
        || e->type() == QEvent::MouseButtonRelease
        || e->type() == QEvent::MouseButtonDblClick
        || e->type() == QEvent::MouseButtonRelease
        || e->type() == QEvent::MouseMove)
        && m_MainWin != nullptr)
    {
       // m_MainWin->ExitStandby();
    }
}

void CVAZApplication::NotifyKeyRequest(QObject *obj, QEvent *e)
{
    if (e->type() == QEvent::KeyPress
        || e->type() == QEvent::KeyRelease)
    {
        QKeyEvent *pKeyEvent = (QKeyEvent *)e;
        if (pKeyEvent->key() == Qt::Key_Escape)
            return;

        if (pKeyEvent->key() == Qt::Key_F7
            || pKeyEvent->key() == Qt::Key_F8)
        {
            QString sObjName = obj->objectName();
            if (sObjName == m_MainWin->objectName() + "Window"
                || sObjName == "CShutDownDialogWindow")
            {
                // qDebug() << "notify1 MainWin:" << m_MainWin << "vs receiver:" << obj << " keyevent->type:" << pKeyEvent->type() << " keyevent->key" << pKeyEvent->key();
                if (pKeyEvent->type() == QEvent::KeyPress)
                    emit SignalNotifyKeyPressEvent(unsigned int(pKeyEvent->key()), sObjName);
            }
            else
            {
            }
            //qDebug() << "notify2 MainWin:"<<m_MainWin<<"vs receiver:" << obj << " keyevent->type:" << pKeyEvent->type() << " keyevent->key" << pKeyEvent->key();
            //return true;
        }
        else if (pKeyEvent->key() == Qt::Key_F35)
        {
            // 关闭软件
            if (obj->objectName().compare("btnHolidayShutdown") == 0)
                SlotsQuit(true);
        }
    }
}
