#pragma once
#include <list>
#include "../QtGuiApplication3/GlobalDefine.h"
//#include "Platform/Common/misc.h"
#include "VAZLock.h"
#include "VAZCircularQueue.h"
#include <map>
using namespace std;

#define TIME_PERIODIC   0x0001
#define TIMER_INTERVAL	10

typedef LONG TIMER_CLIENT_OBJ_ID;
typedef LONG TIMER_ID;

class OSADAPTER_EXPORT CVAZTimerClient
{
	friend class CVAZTimerServer;
public:
	CVAZTimerClient(tstring sName);
	virtual ~CVAZTimerClient();

	void SetTimer(unsigned int uiTimerID, unsigned int uiTime, unsigned int uUseMode = TIME_PERIODIC);
	void KillTimer(unsigned int uiTimerID);

protected:
	virtual void OnTimer(unsigned int uiTimerID) = 0;

private:
	tstring				m_sName;
	TIMER_CLIENT_OBJ_ID	m_ID;
	volatile static TIMER_CLIENT_OBJ_ID m_GlobalID;
	bool				m_bWaitDestroy;
};

//CVAZTimer不需要暴露给外面
class OSADAPTER_EXPORT CVAZTimerServer
{
	struct STimerClientRegInfo 
	{
		CVAZTimerClient *pTimerClient;
		TIMER_CLIENT_OBJ_ID TimerClientObjID;
		bool			bIsDestroy;
		unsigned int	uiTimerID;	
		unsigned int    uiIntervalMS;
		unsigned int    uiPassedMS;
		unsigned int	uiUseMode;
	};

	struct SWaitToDelTimerID 
	{
		TIMER_CLIENT_OBJ_ID TimerClientObjID;
		unsigned int		uiTimerID;
	};

public:
	static CVAZTimerServer& GetInstance()
	{
		static CVAZTimerServer stTimer;
		return stTimer;
	}
	virtual ~CVAZTimerServer(void);

	void SetTimer(TIMER_CLIENT_OBJ_ID TimerClientObjID, CVAZTimerClient *pTimerClient, unsigned int uiTimerID, unsigned int uiTime, unsigned int uUseMode);
	void KillTimer(TIMER_CLIENT_OBJ_ID TimerClientObjID, unsigned int uiTimerID);
	void KillTimer(TIMER_CLIENT_OBJ_ID TimerClientObjID);
	bool IsReg(TIMER_CLIENT_OBJ_ID ObjID);

protected:		
	static void _stdcall TimeProc(unsigned int uiTimerID, unsigned int msg, unsigned long dwUser, unsigned long dwl, unsigned long dw2);

private:
	CVAZTimerServer(void);
	void PrivateSetTimer();
	void PrivateKillTimer();

	map<TIMER_CLIENT_OBJ_ID,map<TIMER_ID,STimerClientRegInfo> >	m_mapRegTimer;
	typedef map<TIMER_CLIENT_OBJ_ID,map<TIMER_ID,STimerClientRegInfo> >	::iterator	ItTimerObj;
	typedef map<TIMER_ID,STimerClientRegInfo>::iterator		ItTimer;

	CVAZLock										m_TimerServerLock;
	unsigned int									m_uiTimerID;

	CVAZCircularQueue<STimerClientRegInfo>	m_WaitToSetTimers;
	CVAZCircularQueue<SWaitToDelTimerID>	m_WaitToDelTimerIDs;
	CVAZCircularQueue<TIMER_CLIENT_OBJ_ID>	m_WaitToDelTimers;
};


