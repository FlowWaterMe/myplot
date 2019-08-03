#include "CommunicateDev.h"

CCommunicateDev::CCommunicateDev(QObject *parent /*= nullptr*/)
    :QObject(parent)
    , m_iNo(-1)
    , m_bRtn(false)
    , m_Mutex()
{
    m_ReadBuffQueue.clear();
}

