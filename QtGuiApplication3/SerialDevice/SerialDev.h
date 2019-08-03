#pragma once

#include <QObject>
#include <QtSerialPort/QSerialPort>
#include "CommunicateDev.h"
#include "serialdevice_global.h"
#include <QVector>
#include <QTextCodec>
//#include "../QtGuiApplication3/APPFun.h"
struct SSerialParam
{
    QString sPortName;
    QSerialPort::BaudRate eBaudRate;
    QSerialPort::DataBits eDataBits;
    QSerialPort::FlowControl eFlowControl;
    QSerialPort::Parity eParity;
    QSerialPort::StopBits eStopBits;

    void Init()
    {
        sPortName = "";
        eBaudRate = QSerialPort::UnknownBaud;
        eDataBits = QSerialPort::UnknownDataBits;
        eFlowControl = QSerialPort::UnknownFlowControl;
        eParity = QSerialPort::UnknownParity;
        eStopBits = QSerialPort::UnknownStopBits;
    }

    bool operator != (SSerialParam SerialParam)
    {
        if (sPortName != SerialParam.sPortName || eBaudRate != SerialParam.eBaudRate
            || eDataBits != SerialParam.eDataBits || eFlowControl != SerialParam.eFlowControl
            || eParity != SerialParam.eParity || eStopBits != SerialParam.eStopBits)
            return true;
        else
            return false;
    }
};



class SERIALDEVICE_EXPORT CSerialDev : public QObject
{
    Q_OBJECT

public:
    CSerialDev(QObject *parent = nullptr);
    ~CSerialDev();

    bool CloseDev();
    bool IsOpenDev();

    // 串口：串口号(COM1),波特率(19200),检验位(No\Odd\Even),数据位(5\6\7\8),停止位(1\1.5\2)
    // COM4,115200,No,8,1
    bool OpenDev(const QString& SerialParam);

    bool ChangeParamAndRecon(const QString& SerialParam);
    bool WriteData(const QString &sData);
    bool WriteData(const QByteArray& byteData);
    bool ReadData(QString &sData);
    bool ReadData(QByteArray& sCurData);

signals:
    void SignalReceiveData();
    void SignalConnectState(bool bIsConnect);

    void SignalClose();
    void SignalWriteData(QString);
    void SignalWriteData(QByteArray);
    void SignalOpenDev(QString);

private slots:
    void SlotReadyData();
    void SlotClose();
    void SlotWriteData(QString sData);
    void SlotWriteData(QByteArray byteData);
    void SlotOpenDev(QString SerialParam);

private:
    bool ConverFromQString(const QString sParam, SSerialParam& SerialParam);

    QSerialPort::DataBits ConvToQtDataBit(QString sDataBit);
    QSerialPort::Parity ConvToQtParity(QString sParity);
    QSerialPort::StopBits ConvToQtStopBit(QString sStopBit);
    QSerialPort::FlowControl ConvToQtFlowControl(QString sFlowControl);

    QSerialPort*    m_SerialPort;
    QThread*        m_Thread;
    QMutex          m_Mutex;
    bool            m_bRtn;
    QQueue<QByteArray> m_ReadBuffQueue;
    //QVector<QByteArray> m_ReadBuffQueue;
};
