#pragma once
#include <QString>
#include "../QtGuiApplication3/GlobalDefine.h"
#include "osadapter_global.h"

struct SEventPos
{
	string	sFileName;
	int		iLine;
	DATE	dtTime;
};


class OSADAPTER_EXPORT CVAZEvent
{
	friend OSADAPTER_EXPORT unsigned long VAZWaitForMultipleObjects(unsigned long uiCount,CVAZEvent **pEvents, bool fWaitAll,unsigned long uiMilliSeconds, const char *pszFileName, int iLineNo);

public:
	CVAZEvent(const tchar *pszName, int bInitiallyOwn = 0, int bManualReset = 0);
	virtual ~CVAZEvent();

public:
	void	Set(const char *pszFileName, int iLineNo);
	void	Reset(const char *pszFileName, int iLineNo);
	unsigned long Wait(unsigned long uiMilliseconds, const char *pszFileName, int iLineNo) const;
	void    Close();

private:
	void *	m_hEvent;
	tstring	m_sName;

	//SEventPos m_LastSetPos;
	//SEventPos m_LastResetPos;

};

#define SETEVENT(eventobj)		(eventobj).Set(__FILE__, __LINE__)
#define RESETEVENT(eventobj)     (eventobj).Reset(__FILE__, __LINE__)
#define WAITEVENT(eventobj, uiMilliseconds)     (eventobj).Wait(uiMilliseconds, __FILE__, __LINE__)
#define WAITMULTIEVENT(nCount, pEvents, fWaitAll, uiMilliseconds)     VAZWaitForMultipleObjects(nCount, pEvents, fWaitAll, uiMilliseconds, __FILE__, __LINE__)

#define VAZ_WAIT_OBJECT_0	WAIT_OBJECT_0
#define VAZ_WAIT_TIMEOUT	258L

OSADAPTER_EXPORT unsigned long VAZWaitForMultipleObjects(unsigned long uiCount,CVAZEvent **pEvents, bool fWaitAll,unsigned long uiMilliSeconds, const char *pszFileName, int iLineNo);
