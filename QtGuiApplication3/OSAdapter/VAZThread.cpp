#include <QtCore>
#include <Windows.h>
#include "VAZThread.h"
//#include "Platform/Logger/logger.h"

CVAZThread::CVAZThread(const tchar *pszThreadName)
    :QThread(NULL)
{
	m_ThreadName = pszThreadName;
	m_bExitThread = false;
}

//Note that deleting a QThread object will not stop the execution of the thread it manages.
//Deleting a running QThread (i.e. isFinished() returns false) will result in a program crash. 
//Wait for the finished() signal before deleting the QThread.
CVAZThread::~CVAZThread()
{//TODO: close violently
    if (QThread::isRunning())
        QThread::terminate();
}

void CVAZThread::Start()
{
	if (QThread::isRunning())
	{
		ASSERT(false);
		return;
	}

	m_bExitThread = false;
	QThread::start();
	if (QThread::isRunning())
	{
		//WRITE_INFO_LOG(m_ThreadName + _T(" thread start succeed!"));
	}
	else
	{
		//WRITE_ERROR_LOG(m_ThreadName + _T(" thread start failed!"));
		ASSERT(false);
	}
}

void CVAZThread::Exit()
{
	if (!QThread::isRunning())
	{
		return;
	}

	m_bExitThread = true;
	//等线程自动退出，最多等10s
	int iLoop = 0;
	for (;iLoop < 1000; ++iLoop)
	{
		if (QThread::isRunning())
			VAZSleep(10); 
		else
			break;
	}

	if (QThread::isRunning())
	{
        ASSERT1(!isRunning(), _T("Thread is still running!"));
		//WRITE_WARN_LOG( m_ThreadName + _T("thread forced exit!") );
        QThread::terminate();
	}
}

void CVAZThread::SetPriority( Priority priority )
{
	//WRITE_INFO_LOG(m_ThreadName + _T(" Set Priority."));//写具体优先级到日志文件
	QThread::setPriority(priority);
}

int CVAZThread::GetPriority()
{	
	return QThread::priority();
}

void CVAZThread::SetTerminationEnabled( bool enabled )
{
	ASSERT(dynamic_cast<QThread*>(this) == QThread::currentThread());

	QThread::setTerminationEnabled(enabled);
}

void VAZSleep(unsigned long uiSleepTime)
{
	::Sleep(uiSleepTime);
}