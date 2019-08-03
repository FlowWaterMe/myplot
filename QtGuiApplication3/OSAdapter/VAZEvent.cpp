#include <Windows.h>
#include <VAZEvent.h>
//#include "Platform/Logger/logger.h"
//#include "Platform/Common/misc.h"

#define MIN_WAIT_TIME 10000


CVAZEvent::CVAZEvent(const tchar* pszName, int bInitiallyOwn, int bManualReset)
{
	m_hEvent = CreateEvent(NULL, bManualReset, bInitiallyOwn, NULL);
	m_sName = pszName;

	if(NULL == m_hEvent)
	{
	/*	WRITE_ERROR_LOG(m_sName + _T(" Create Event failed!"));*/
		return ;
	}
}

CVAZEvent::~CVAZEvent()
{
	Close();
}

void CVAZEvent::Close()
{
	ASSERT(m_hEvent != NULL);
	if(m_hEvent != NULL)
	{
		CloseHandle(m_hEvent);
		m_hEvent = NULL;
	}
}

void CVAZEvent::Set(const char *pszFileName, int iLineNo)
{
	/*m_LastSetPos.iLine = iLineNo;
	m_LastSetPos.sFileName = pszFileName;
	m_LastSetPos.dtTime = VAZGetCurrentDateTime();*/

	ASSERT(m_hEvent != NULL);
	if(NULL == m_hEvent)
	{
		return ;
	}

	if(!SetEvent(m_hEvent))
	{
		//WRITE_ERROR_LOG( m_sName + _T(" Set Event Failed!"));
		return ;
	}
}

void CVAZEvent::Reset(const char *pszFileName, int iLineNo)
{
	/*m_LastResetPos.iLine = iLineNo;
	m_LastResetPos.sFileName = pszFileName;
	m_LastResetPos.dtTime = VAZGetCurrentDateTime();*/

	//ASSERT(m_hEvent != NULL);
	if(NULL == m_hEvent)
	{
		return ;
	}

	if(!ResetEvent(m_hEvent))
	{
		//WRITE_ERROR_LOG( m_sName + _T(" Reset Event failed!"));
		return ;
	}
}

unsigned long  CVAZEvent::Wait(unsigned long  uiMilliseconds, const char *pszFileName, int iLineNo) const
{
	unsigned long uiRet = 0;
	unsigned long uiTime = 0;

	ASSERT(m_hEvent != NULL);
	if(NULL == m_hEvent)
	{
		//WRITE_ERROR_LOG( m_sName+ _T(" Wait Event but m_hEvent is NULL!"));
		return WAIT_FAILED;
	}

	uiRet = WaitForSingleObject(m_hEvent, min(uiMilliseconds, MIN_WAIT_TIME));
	if (WAIT_TIMEOUT == uiRet && uiMilliseconds > MIN_WAIT_TIME)
	{
		tstring sLog = _T("");

		/*sLog = m_sName + VAZStrFormat(_T(" Wait Event timeout!, Last Set time:%s"), VAZDateToStrMS(m_LastSetPos.dtTime).c_str());
		WriteLog( eLogChannelID_Default, eLogLevel_Warn, sLog, m_LastSetPos.sFileName.c_str(), m_LastSetPos.iLine);
	
		sLog = m_sName + VAZStrFormat(_T(" Wait Event timeout!, Last Reset time:%s"), VAZDateToStrMS(m_LastResetPos.dtTime).c_str());
		WriteLog( eLogChannelID_Default, eLogLevel_Warn, sLog,m_LastResetPos.sFileName.c_str(), m_LastResetPos.iLine);*/

		uiTime = uiMilliseconds - MIN_WAIT_TIME;
		uiRet = WaitForSingleObject(m_hEvent, uiTime);
	}	

	if(WAIT_OBJECT_0 != uiRet && WAIT_TIMEOUT != uiRet)
	{
		//WRITE_ERROR_LOG( m_sName + _T(" Wait Ret:") + VAZConvToStr(uiRet));
	}

	return uiRet;
}


unsigned long VAZWaitForMultipleObjects(unsigned long uiCount,CVAZEvent **pEvents, bool fWaitAll,unsigned long uiMilliSeconds, const char *pszFileName, int iLineNo)
{
	unsigned long i = 0;
	HANDLE *arrEventsHandle = NULL;
	unsigned long	uiRet = 0;
	unsigned long	uiTime = 0;

	ASSERT(uiCount != 0);
	if (uiCount == 0)
	{
		//WRITE_ERROR_LOG(_T("VAZ WaitForMultipleObjects' count is zero!"));
		return WAIT_FAILED;
	}

	ASSERT(pEvents != NULL);
	if (NULL == pEvents)
	{
		//WRITE_ERROR_LOG(_T("VAZ Wait event is NULL!"));
		return WAIT_FAILED;
	}

	arrEventsHandle = new HANDLE[uiCount];
	memset(arrEventsHandle, 0, sizeof(HANDLE) * uiCount);

	for (i=0; i< uiCount; i++)
	{
		arrEventsHandle[i] = pEvents[i]->m_hEvent;
	}

	uiRet = WaitForMultipleObjects(uiCount, arrEventsHandle, fWaitAll ? TRUE : FALSE, min(MIN_WAIT_TIME, uiMilliSeconds));
	i = GetLastError();

	if (WAIT_TIMEOUT == uiRet && uiMilliSeconds > MIN_WAIT_TIME)
	{
		uiTime = uiMilliSeconds - MIN_WAIT_TIME;
		uiRet = WaitForMultipleObjects(uiCount, arrEventsHandle, fWaitAll, uiTime);
	}

	if((WAIT_OBJECT_0 > uiRet || (WAIT_OBJECT_0 + uiCount) < uiRet) && (WAIT_TIMEOUT != uiRet))
	{
		//WRITE_ERROR_LOG( _T(" VAZWaitForMultipleObjects Ret:") + VAZConvToStr(uiRet));
	}
	delete[] arrEventsHandle;
	return uiRet;
}