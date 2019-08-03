#include "../QtGuiApplication3/GlobalDefine.h"
#include<windows.h>
#pragma comment(lib, "winmm.lib")
//#include "Platform/Logger/logger.h"
#include "VAZTimer.h"
#include "VAZLock.h"
#include "VAZThread.h"
#include <algorithm> 
#include "TimeoutMonitor.h"

CVAZTimerServer::CVAZTimerServer(void):m_TimerServerLock(_T("TimerServerLock"))
{
	UINT				uTimerRes = 0;
	TIMECAPS			tc;
	memset(&tc, 0, sizeof(TIMECAPS));

	if(timeGetDevCaps(&tc, sizeof(TIMECAPS)) != TIMERR_NOERROR)
	{
		//WRITE_ERROR_LOG(_T("timeGetDevCaps failed."));
		return ;
	}

	uTimerRes = min<UINT>(max<UINT>(tc.wPeriodMin, 1), tc.wPeriodMax);
	if (timeBeginPeriod(uTimerRes) != TIMERR_NOERROR)
	{
		ASSERT(false);
	}

	m_uiTimerID = timeSetEvent(TIMER_INTERVAL, uTimerRes, (LPTIMECALLBACK)TimeProc, (DWORD_PTR)this, TIME_PERIODIC);
	if(m_uiTimerID == 0)
	{
		//WRITE_ERROR_LOG(_T("Timer set Failed."));
		return ;
	}
}

CVAZTimerServer::~CVAZTimerServer(void)
{
	timeKillEvent(m_uiTimerID);
}


void CVAZTimerServer::SetTimer(TIMER_CLIENT_OBJ_ID TimerClientObjID, CVAZTimerClient *pTimerClient, unsigned int uiTimerID, unsigned int uiTime, unsigned int uUseMode )
{
	ASSERT(pTimerClient != NULL);
	if(NULL == pTimerClient)
	{
		//WRITE_ERROR_LOG(_T("Set Timer But pTimerClient is NULL"));
		return ;
	}	

	STimerClientRegInfo TimerRegInfo;
	TimerRegInfo.TimerClientObjID = TimerClientObjID;
	TimerRegInfo.pTimerClient = pTimerClient;
	TimerRegInfo.uiTimerID = uiTimerID;
	TimerRegInfo.uiPassedMS = 0;
	TimerRegInfo.uiIntervalMS = uiTime;
	TimerRegInfo.uiUseMode = uUseMode;
	LOCK(m_TimerServerLock);
	if (!m_WaitToSetTimers.EnQueue(TimerRegInfo))
	{
		ASSERT(false);
	}
	UNLOCK(m_TimerServerLock);
}

void CVAZTimerServer::KillTimer(TIMER_CLIENT_OBJ_ID TimerClientObjID)
{
	LOCK(m_TimerServerLock);
	if (!m_WaitToDelTimers.EnQueue(TimerClientObjID))
	{
		ASSERT(false);
	}
	UNLOCK(m_TimerServerLock);
}

void CVAZTimerServer::KillTimer( TIMER_CLIENT_OBJ_ID TimerClientObjID, unsigned int uiTimerID )
{
	SWaitToDelTimerID WaitToDelTimerID;
	WaitToDelTimerID.TimerClientObjID = TimerClientObjID;
	WaitToDelTimerID.uiTimerID = uiTimerID;
	LOCK(m_TimerServerLock);
	if (!m_WaitToDelTimerIDs.EnQueue(WaitToDelTimerID))
	{
		ASSERT(false);
	}
	UNLOCK(m_TimerServerLock);
}

bool CVAZTimerServer::IsReg( TIMER_CLIENT_OBJ_ID ObjID )
{
	bool bRet = false;

	LOCK(m_TimerServerLock);
	ItTimerObj itTimerObj = m_mapRegTimer.find(ObjID);
	if (itTimerObj != m_mapRegTimer.end())
		bRet = true;

	UNLOCK(m_TimerServerLock);

	return bRet;
}

void CVAZTimerServer::PrivateSetTimer()
{
	LOCK(m_TimerServerLock);
	while(!m_WaitToSetTimers.IsEmpty())
	{
		STimerClientRegInfo TimerClientRegInfo;
		ASSERT(m_WaitToSetTimers.DeQueue(&TimerClientRegInfo,1));

		ItTimerObj itTimerObj = m_mapRegTimer.find(TimerClientRegInfo.TimerClientObjID);
		if (itTimerObj == m_mapRegTimer.end())
		{			
			map<TIMER_ID,STimerClientRegInfo> TimerClient;
			TimerClient.insert(map<TIMER_ID,STimerClientRegInfo>::value_type(TimerClientRegInfo.uiTimerID, TimerClientRegInfo));
			m_mapRegTimer.insert(map<TIMER_CLIENT_OBJ_ID,map<TIMER_ID,STimerClientRegInfo> >::value_type(TimerClientRegInfo.TimerClientObjID, TimerClient));
		}
		else
		{
			ItTimer itTimer = itTimerObj->second.find(TimerClientRegInfo.uiTimerID);
			if (itTimer == itTimerObj->second.end())
			{
				itTimerObj->second.insert(map<TIMER_ID,STimerClientRegInfo>::value_type(TimerClientRegInfo.uiTimerID, TimerClientRegInfo));
			}
			else
			{
				itTimer->second.uiIntervalMS = TimerClientRegInfo.uiIntervalMS; 
				itTimer->second.uiPassedMS = 0;
				itTimer->second.uiUseMode = TimerClientRegInfo.uiUseMode;
			}
		}
	}
	UNLOCK(m_TimerServerLock);
}

void CVAZTimerServer::PrivateKillTimer()
{
	LOCK(m_TimerServerLock);
	//Kill TimerID
	while(!m_WaitToDelTimerIDs.IsEmpty())
	{		
		SWaitToDelTimerID WaitToDelTimerID;
		ASSERT(m_WaitToDelTimerIDs.DeQueue(&WaitToDelTimerID, 1));

		ItTimerObj itTimerObj = m_mapRegTimer.find(WaitToDelTimerID.TimerClientObjID);
		if (itTimerObj == m_mapRegTimer.end())
			continue;
			
		ItTimer itTimer = itTimerObj->second.find(WaitToDelTimerID.uiTimerID);
		if (itTimer == itTimerObj->second.end())
			continue;
		
		itTimerObj->second.erase(itTimer);
		if (itTimerObj->second.size() <=0)
			m_mapRegTimer.erase(itTimerObj);
	}

	//Kill Timerclient
	while(!m_WaitToDelTimers.IsEmpty())
	{		
		TIMER_CLIENT_OBJ_ID ClientObjID;
		ASSERT(m_WaitToDelTimers.DeQueue(&ClientObjID,1));

		ItTimerObj itTimerObj = m_mapRegTimer.find(ClientObjID);
		if (itTimerObj == m_mapRegTimer.end())
			continue;

		m_mapRegTimer.erase(itTimerObj);
	}
	UNLOCK(m_TimerServerLock);
}

#pragma  warning( disable: 4100)//msg, dw1,dw2属于保留未使用的参数
void _stdcall CVAZTimerServer::TimeProc(unsigned int uiTimerID, unsigned int msg, unsigned long dwUser, unsigned long dwl, unsigned long dw2)
{
	CVAZTimerServer&  VAZTimerServer = CVAZTimerServer::GetInstance();

	std::vector<STimerClientRegInfo> vecTimerClient;

	LOCK(VAZTimerServer.m_TimerServerLock);

	VAZTimerServer.PrivateSetTimer();

	ItTimerObj itTimerObj = VAZTimerServer.m_mapRegTimer.begin();
	for(; itTimerObj != VAZTimerServer.m_mapRegTimer.end(); ++itTimerObj)
	{
		ItTimer itTimer = itTimerObj->second.begin();
		for (; itTimer != itTimerObj->second.end(); ++itTimer)
		{
			if (itTimer->second.pTimerClient && !itTimer->second.pTimerClient->m_bWaitDestroy)
			{
				itTimer->second.uiPassedMS += TIMER_INTERVAL;
				if (itTimer->second.uiPassedMS >= itTimer->second.uiIntervalMS)
				{
					vecTimerClient.push_back(itTimer->second);

					itTimer->second.uiPassedMS = 0;
					//CVAZTimerClient *pTimerClient = itTimer->second.pTimerClient;
					if (TIME_ONESHOT == itTimer->second.uiUseMode)
					{
						VAZTimerServer.KillTimer(itTimer->second.TimerClientObjID,itTimer->second.uiTimerID);
					}
					//pTimerClient->OnTimer(itTimer->second.uiTimerID);
				}
			}
		}
	}
	UNLOCK(VAZTimerServer.m_TimerServerLock);

	std::vector<STimerClientRegInfo>::iterator itTimerClient;
	for ( itTimerClient = vecTimerClient.begin(); itTimerClient != vecTimerClient.end(); ++itTimerClient )
	{
        if (itTimerClient->pTimerClient)
        {
            CTimeoutMonitor TimeoutMonitor(500, [&VAZTimerServer, itTimerClient]() {/*WriteLogSpec(eLogChannelID_Default, eLogLevel_Warn, _T("TimerClient(%s) timeout"), itTimerClient->pTimerClient->m_sName.c_str());*/ });
            itTimerClient->pTimerClient->OnTimer(itTimerClient->uiTimerID);
        }
	}

	VAZTimerServer.PrivateKillTimer();	
}



#pragma  warning( default: 4100)

volatile TIMER_CLIENT_OBJ_ID CVAZTimerClient::m_GlobalID = 0;
CVAZTimerClient::CVAZTimerClient( tstring sName )
:m_bWaitDestroy(false)
{
	//不能简单将m_iGlobalObjID的值赋给m_iObjID，因为自增以后，赋值之前可能又有新的CVAZTimerClient对象创建
	TIMER_CLIENT_OBJ_ID OriObjID = 0;
	while(true)
	{
		OriObjID = InterlockedExchangeAdd(&m_GlobalID,1);
		m_ID = m_GlobalID;
		if (m_ID == (OriObjID + 1))
			break;
	}
	
	m_sName = sName;
}

CVAZTimerClient::~CVAZTimerClient()
{
	m_bWaitDestroy = true;
	CVAZTimerServer::GetInstance().KillTimer(m_ID);
	while(true)
	{
		if (!CVAZTimerServer::GetInstance().IsReg(m_ID))
			break;
		VAZSleep(10);
	}
}

void CVAZTimerClient::SetTimer( unsigned int uiTimerID, unsigned int uiTime, unsigned int uUseMode /*= TIME_PERIODIC*/ )
{
	if (m_bWaitDestroy)
		return;
//	WriteLogSpec(eLogChannelID_Default, eLogLevel_Debug,_T("%s SetTimer"),m_sName.c_str());
	CVAZTimerServer::GetInstance().SetTimer(this->m_ID, this, uiTimerID, uiTime, uUseMode);
}

void CVAZTimerClient::KillTimer( unsigned int uiTimerID )
{
//	WriteLogSpec(eLogChannelID_Default, eLogLevel_Debug,_T("%s KillTimer"),m_sName.c_str());
	CVAZTimerServer::GetInstance().KillTimer(this->m_ID,uiTimerID);
}

