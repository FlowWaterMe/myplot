#pragma once

#include <QObject>
#include <QTcpSocket>
#include "CommunicateDev.h"
#include <QTextCodec>
//#include <../QtGuiApplication3/APPFun.h>
struct SNetworkParam
{
    QString sHostName;
    int iPort;

    SNetworkParam()
    {
        Init();
    }

    void Init()
    {
        sHostName = "127.0.0.1";
        iPort = 6000;
    }

    bool operator != (SNetworkParam NetworkParam)
    {
        if (sHostName != NetworkParam.sHostName || iPort != NetworkParam.iPort)
            return true;
        else
            return false;
    }
};

class CNetworkDev : public CCommunicateDev
{
    Q_OBJECT
public:
    CNetworkDev(int iNo, QObject *parent = nullptr);
    ~CNetworkDev();

    bool CloseDev();
    bool IsOpenDev();
    bool StartDev(const QString& sParam);

    bool ChangeParamAndRecon(const QString& sParam);
    bool WriteData(const QString& sSendData);
    bool ReadData(QString& sCurData);

private slots:
    void SlotReadyData();
    void SlotDisconnected();
    void SlotConnected();

    void SlotClose();
    void SlotWriteData(QString sData);
    void SlotStartDev(QString SerialParam);

private:
    QTcpSocket* m_TcpSocket;
};