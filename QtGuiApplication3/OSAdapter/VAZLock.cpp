#include <tchar.h>
#include <VAZLock.h>
//#include "Platform/Logger/logger.h"
//#include "Platform/Common/misc.h"
#include <windows.h>

#define DEFAULT_TRY_LOCK_TIME 50

CVAZLock::CVAZLock( const tchar * pszLockName )
{	
	//m_hMutex = CreateMutex(NULL, FALSE, pszLockName);
	m_hMutex = CreateMutex(NULL, FALSE, NULL);
	if(NULL == m_hMutex)
	{		
		//WRITE_LOG(eLogChannelID_Default,eLogLevel_Error, tstring(pszLockName) + _T("Create Mutex failed!"));
		return ;
	}

	m_LockName = pszLockName;
}

CVAZLock::~CVAZLock(void)
{
	ASSERT(m_hMutex != NULL);
	if(m_hMutex != NULL)
	{
		CloseHandle(m_hMutex);
		m_hMutex = NULL;
	}

}

void CVAZLock::Lock(const char *pszFileName, int iLineNo)
{
	//WriteLog(eLogChannelID_Default,eLogLevel_Info, m_LockName + _T(" lock"), pszFileName, iLineNo);
	unsigned long dwRet = 0;
	bool bRet = false;
	//SLockPos LockPos;

	int i = GetCurrentThreadId();

	//LockPos.dtTime = VAZGetCurrentDateTime();
	ASSERT(m_hMutex != NULL);
	if(NULL == m_hMutex)
	{		
		//WRITE_LOG(eLogChannelID_Default,eLogLevel_Error, m_LockName + _T(" Add Lock but m_hMetex is NULL!"));
		return;
	}

	dwRet = WaitForSingleObject(m_hMutex, DEFAULT_TRY_LOCK_TIME);
	if(WAIT_TIMEOUT == dwRet)
	{
		/*if (!m_LockPosition.empty())
		{
			SLockPos LockPosLast = m_LockPosition.top();

			tstring sLog = _T("");

			sLog = m_LockName + VAZStrFormat(_T(" lock.timeout! "));
			WriteLog( eLogChannelID_Default, eLogLevel_Warn, sLog, pszFileName, iLineNo);

			sLog = m_LockName + VAZStrFormat(_T("Last lock info time:%s"), VAZDateToStrMS(LockPosLast.dtTime).c_str());
			WriteLog( eLogChannelID_Default, eLogLevel_Warn, sLog,LockPosLast.sFileName.c_str(), LockPosLast.iLine);

			sLog = m_LockName + VAZStrFormat(_T("Last unlock info time:%s"), VAZDateToStrMS(m_UnlockPosition.dtTime).c_str());
			WriteLog( eLogChannelID_Default, eLogLevel_Warn, sLog,m_UnlockPosition.sFileName.c_str(), m_UnlockPosition.iLine);
		}*/
		dwRet = WaitForSingleObject(m_hMutex, -1);
	}
	if( WAIT_OBJECT_0 != dwRet)
	{
		//WRITE_LOG(eLogChannelID_Default, eLogLevel_Error, m_LockName +  _T(" Add Lock but wait ret :") + VAZConvToStr(dwRet) );
		int iErrCode = GetLastError();
		ASSERT(false);
		return;
	}

	//LockPos.sFileName = pszFileName;
	//LockPos.iLine = iLineNo;
	//m_LockPosition.push(LockPos);
}

void CVAZLock::Unlock(const char *pszFileName,int iLineNo)
{
	//WriteLog(eLogChannelID_Default,eLogLevel_Info, m_LockName + _T(" unlock"), pszFileName, iLineNo);
	//m_UnlockPosition.sFileName = pszFileName;
	//m_UnlockPosition.iLine = iLineNo;
	//m_UnlockPosition.dtTime = VAZGetCurrentDateTime();
	
	if(NULL == m_hMutex)
	{
		//WRITE_LOG(eLogChannelID_Default,eLogLevel_Error, m_LockName +  _T("UnLocking but m_hMetex is NULL!"));
		return;
	}

	BOOL bRet = ReleaseMutex(m_hMutex);
	if (!bRet)
	{
		ASSERT(false);
		//WRITE_LOG(eLogChannelID_Default,eLogLevel_Error, m_LockName +  _T("UnLocking but m_hMetex is NULL!"));
	}

	/*if (!m_LockPosition.empty())
		m_LockPosition.pop();*/

}

CVAZUseLock::CVAZUseLock( CVAZLock &Lock )
:m_LockUsing(Lock)
{
	m_LockUsing.Lock(__FILE__, __LINE__);
}

CVAZUseLock::~CVAZUseLock()
{
	m_LockUsing.Unlock(__FILE__, __LINE__);
}
