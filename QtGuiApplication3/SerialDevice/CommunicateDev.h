#pragma once

#include <QObject>
#include <QString>
#include <QThread>
#include <QQueue>
#include <QMutexLocker>
#include <QMutex>
#include "../QtGuiApplication3/GlobalDefine.h"


class CCommunicateDev;
typedef std::shared_ptr<CCommunicateDev> PtrCommunicateDev;

class CCommunicateDev : public QObject
{
    Q_OBJECT

public:
    CCommunicateDev(QObject *parent = nullptr);
    virtual ~CCommunicateDev() {};

public:
    virtual bool CloseDev() = 0;
    virtual bool IsOpenDev() = 0;
    virtual bool StartDev(const QString& SerialParam) = 0;

    virtual bool ChangeParamAndRecon(const QString& SerialParam) = 0;
    virtual bool WriteData(const QString& sSendData) = 0;
    virtual bool ReadData(QString& sCurData) = 0;

signals:
    void SiganlReceiveData(int iNo, QString sData);
    void SignalConnectState(int iNo, bool bIsConnect);

    void SignalClose();
    void SignalWriteData(QString);
    void SignalStartDev(QString);

protected:
    QThread* m_Thread;
    int m_iNo; // …Ë±∏∫≈

    QMutex m_Mutex;
    bool m_bRtn;
    QQueue<QString> m_ReadBuffQueue;
};
