#pragma once
#include <QObject>
#include <QString>
#include "serialdevice_global.h"
#include "CommunicateDev.h"
#include "../QtGuiApplication3/GlobalDefine.h"
//#include "GlobalDefines.h"
#include "../OSAdapter/VAZLock.h"
enum EDeviceType
{
    eDeviceType_Serial = 0,
    eDeviceType_Network
};

enum EDeviceNo
{
    eDeviceNo_Invalid = -1,
    eDeviceNo_LisSerial = 0,
    eDeviceNo_LisNetwork = 1,
    eDeviceNo_RetestNet = 2,
    eDeviceNo_RFIDSerial,
};

class SERIALDEVICE_EXPORT CDeviceMgr : public QObject
{
    Q_OBJECT

public:
    static CDeviceMgr& GetInstance();

public:
    ~CDeviceMgr();   

public:
    // 串口：串口号(COM1),波特率(19200),检验位(No\Odd\Even),数据位(5\6\7\8),停止位(1\1.5\2)
    // 网口：IP(192.168.1.1),端口(6000) 
    bool AddDevice(IN EDeviceType eType, IN EDeviceNo eNo, IN const QString& sParam);

    bool OpenDevice(IN EDeviceNo eNo, IN const QString& sParam);
    bool IsOpenDevice(IN EDeviceNo eNo);

    bool CloseDevice(IN EDeviceNo eNo);

    bool WriteData(IN EDeviceNo eNo, IN const QString& sData);
    bool ReadData(IN EDeviceNo eNo, OUT QString& sData);

signals:
    void SiganlReceiveData(int iNo, QString sData);
    void SignalConnectState(int iNo, bool bIsConnect);

private:
    CDeviceMgr(QObject* parent = nullptr);
    map<EDeviceNo, PtrCommunicateDev> m_mapDevice;

    static CVAZLock st_Lock;
    CVAZLock m_Lock;
};