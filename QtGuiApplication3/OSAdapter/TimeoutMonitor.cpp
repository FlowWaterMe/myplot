#include "TimeoutMonitor.h"



CTimeoutMonitor::CTimeoutMonitor(unsigned int uiTimeoutMS, function<void(void)> func)
    : m_dwuiTimeoutMS(uiTimeoutMS)
    , m_func(func)
{
    Start();
}

CTimeoutMonitor::~CTimeoutMonitor()
{
    if (IsTimeout())
    {
        m_func();
    }
}

bool CTimeoutMonitor::IsTimeout( DWORD *pdwTimeElapse )
{
    DWORD dwNowTimeMS = GetTickCount();

    DWORD dwTimeElapse = dwNowTimeMS - m_dwStartTimeMS;
    if (pdwTimeElapse != nullptr)
        *pdwTimeElapse = dwTimeElapse;

    if (dwTimeElapse >= m_dwuiTimeoutMS)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void CTimeoutMonitor::Start()
{
    m_dwStartTimeMS = GetTickCount();
}
