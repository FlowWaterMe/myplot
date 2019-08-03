#pragma once
#include <QThread>
#include <QtCore>

#include "../QtGuiApplication3/GlobalDefine.h"
#include "osadapter_global.h"
using namespace std;

class OSADAPTER_EXPORT CVAZThread : public QThread
{
public:
	CVAZThread(const tchar *pszThreadName);
	~CVAZThread();
	void Start();
	void Exit();

	void SetPriority(Priority priority);
	int GetPriority();

	void SetTerminationEnabled ( bool enabled);

protected:
	bool m_bExitThread;

private:
	tstring m_ThreadName;
};

OSADAPTER_EXPORT void VAZSleep(unsigned long uiSleepTime);