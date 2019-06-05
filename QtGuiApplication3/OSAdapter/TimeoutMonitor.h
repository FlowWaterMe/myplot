#pragma once
#include "../QtGuiApplication3/GlobalDefine.h"
#include "osadapter_global.h"
#include <functional>

class OSADAPTER_EXPORT CTimeoutMonitor
{
public:
    CTimeoutMonitor(unsigned int uiTimeoutMS, function<void(void)> func = []() {});
    virtual ~CTimeoutMonitor();
    bool    IsTimeout(DWORD *pdwTimeElapse = nullptr);

protected:
    void    Start();

private:
    DWORD                       m_dwStartTimeMS;
    DWORD                       m_dwuiTimeoutMS;
    function<void(void)>        m_func;
};

