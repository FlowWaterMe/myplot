#pragma once
#include "../QtGuiApplication3/GlobalDefine.h"
#include "osadapter_global.h"
#include <stack>
using namespace std;

//struct SLockPos
//{
//	string	sFileName;
//	int		iLine;
//	DATE	dtTime;
//};
typedef void *	HANDLE;
class OSADAPTER_EXPORT CVAZLock
{
public:
	CVAZLock(const tchar *pszLockName);
	~CVAZLock(void);
	void Lock(const char *pszFileName, int iLineNo);
	void Unlock(const char *pszFileName,int iLineNo);
	bool TryLock(unsigned long ulMilliseconds, const char *pszFileName,int iLineNo);
private:
	HANDLE m_hMutex;

	tstring m_LockName;

	//stack<SLockPos> m_LockPosition;
	//SLockPos m_UnlockPosition;
};

class OSADAPTER_EXPORT CVAZUseLock
{
public:
	CVAZUseLock(CVAZLock &Lock);
	~CVAZUseLock();

	void* operator new(size_t t) = delete;
private:
	CVAZLock		&m_LockUsing;
};

#define LOCK(eventObj) eventObj.Lock(__FILE__, __LINE__);
#define UNLOCK(eventObj) eventObj.Unlock(__FILE__, __LINE__);
