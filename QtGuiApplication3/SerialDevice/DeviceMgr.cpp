#include "DeviceMgr.h"
#include "SerialDev.h"
#include "NetworkDev.h"
//#include "Platform/Logger/logger.h"
//#include "Platform/Common/misc.h"

CVAZLock CDeviceMgr::st_Lock(_T("DeviceMgr Lock"));
CDeviceMgr& CDeviceMgr::GetInstance()
{
    static CDeviceMgr *st_pDeviceMgr = nullptr;

    if (st_pDeviceMgr == nullptr)
    {
        CVAZUseLock UseLock(CDeviceMgr::st_Lock);
        if (st_pDeviceMgr == nullptr)
            st_pDeviceMgr = new CDeviceMgr();
    }

    if (st_pDeviceMgr == nullptr)
        throw exception("CDeviceMgr Init Error!");

    return *st_pDeviceMgr;
}

CDeviceMgr::CDeviceMgr(QObject* parent)
    : QObject(parent)
    , m_Lock(_T("CDeviceMgr"))
{
    m_mapDevice.clear();
}


CDeviceMgr::~CDeviceMgr()
{
    auto It = m_mapDevice.begin();
    for (; It != m_mapDevice.end(); ++It)
    {
        disconnect(It->second.get(), SIGNAL(SiganlReceiveData(int, QString)), this, SIGNAL(SiganlReceiveData(int, QString)));
        disconnect(It->second.get(), SIGNAL(SignalConnectState(int, bool)), this, SIGNAL(SignalConnectState(int, bool)));
    }
}

bool CDeviceMgr::AddDevice(IN EDeviceType eType, IN EDeviceNo eNo, IN const QString& sParam)
{
    CVAZUseLock lock(m_Lock);
    auto itDev = m_mapDevice.find(eNo);
    if (itDev != m_mapDevice.end())
        return true;

    PtrCommunicateDev pDev;
    switch (eType)
    {
    case eDeviceType_Network:
        pDev = PtrCommunicateDev(new CNetworkDev(eNo));
        break;
    default:  break;
    }

    ASSERT(pDev.get());
    m_mapDevice[eNo] = pDev;
    connect(pDev.get(), SIGNAL(SiganlReceiveData(int, QString)), this, SIGNAL(SiganlReceiveData(int, QString)));
    connect(pDev.get(), SIGNAL(SignalConnectState(int, bool)), this, SIGNAL(SignalConnectState(int, bool)));
    return true;
}

bool CDeviceMgr::OpenDevice(IN EDeviceNo eNo, IN const QString& sParam)
{
    CVAZUseLock lock(m_Lock);
    auto itDev = m_mapDevice.find(eNo);
    if (itDev == m_mapDevice.end())
    {
        return false;
    }

    return itDev->second->StartDev(sParam);
}

bool CDeviceMgr::IsOpenDevice(IN EDeviceNo eNo)
{
    CVAZUseLock lock(m_Lock);
    auto itDev = m_mapDevice.find(eNo);
    if (itDev == m_mapDevice.end())
    {
        return false;
    }

    return itDev->second->IsOpenDev();
}

bool CDeviceMgr::CloseDevice(IN EDeviceNo eNo)
{
    CVAZUseLock lock(m_Lock);
    auto itDev = m_mapDevice.find(eNo);
    if (itDev == m_mapDevice.end())
    {
        return false;
    }

    return itDev->second->CloseDev();
}

bool CDeviceMgr::WriteData(IN EDeviceNo eNo, IN const QString& sData)
{
    CVAZUseLock lock(m_Lock);
    auto itDev = m_mapDevice.find(eNo);
    if (itDev == m_mapDevice.end())
    {
        return false;
    }

    return itDev->second->WriteData(sData);
}

bool CDeviceMgr::ReadData(IN EDeviceNo eNo, OUT QString& sData)
{
    CVAZUseLock lock(m_Lock);
    auto itDev = m_mapDevice.find(eNo);
    if (itDev == m_mapDevice.end())
    {
        return false;
    }

    return itDev->second->ReadData(sData);
}
