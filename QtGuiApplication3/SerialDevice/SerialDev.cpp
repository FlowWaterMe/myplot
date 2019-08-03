#include "SerialDev.h"
//#include "Platform/Logger/logger.h"
//#include "Platform/Common/misc.h"


CSerialDev::CSerialDev(QObject *parent)
    : QObject(parent)
    , m_bRtn(false)
    , m_Mutex()
{
    m_Thread = new QThread(this);
    m_SerialPort = new QSerialPort(this);

    QObject::connect(m_Thread, SIGNAL(finished()), this, SLOT(deleteLater()));
    QObject::connect(m_SerialPort, SIGNAL(readyRead()), this, SLOT(SlotReadyData()));
    QObject::connect(this, SIGNAL(SignalWriteData(QByteArray)), this, SLOT(SlotWriteData(QByteArray)), Qt::BlockingQueuedConnection);
    QObject::connect(this, SIGNAL(SignalWriteData(QString)), this, SLOT(SlotWriteData(QString)), Qt::BlockingQueuedConnection);
    QObject::connect(this, SIGNAL(SignalOpenDev(QString)), this, SLOT(SlotOpenDev(QString)), Qt::BlockingQueuedConnection);
    QObject::connect(this, SIGNAL(SignalClose()), this, SLOT(SlotClose()), Qt::BlockingQueuedConnection);

    moveToThread(m_Thread);
    m_Thread->start();
}

CSerialDev::~CSerialDev()
{
    if (m_SerialPort->isOpen())
        m_SerialPort->close();

    delete m_SerialPort;
    m_Thread->quit();
    m_Thread->wait();
    delete m_Thread;
}

bool CSerialDev::CloseDev()
{
    QMutexLocker locker(&m_Mutex);
    m_bRtn = false;
    emit SignalClose();
    return m_bRtn;
}

bool CSerialDev::IsOpenDev()
{
    return m_SerialPort->isOpen();
}

bool CSerialDev::OpenDev(const QString& sSerialParam)
{
    if (sSerialParam.isEmpty())
        return false;

    QMutexLocker locker(&m_Mutex);
    m_bRtn = false;
    emit SignalOpenDev(sSerialParam);
    return m_bRtn;
}

bool CSerialDev::ChangeParamAndRecon(const QString& sSerialParam)
{
    if (sSerialParam.isEmpty())
        return false;

    QMutexLocker locker(&m_Mutex);
    m_bRtn = false;
    emit SignalOpenDev(sSerialParam);
    return m_bRtn;
}

bool CSerialDev::WriteData(const QString &sData)
{
    if (sData.isEmpty())
        return false;

    QMutexLocker locker(&m_Mutex);
    m_bRtn = false;

    emit SignalWriteData(sData);
    return m_bRtn;
}

bool CSerialDev::WriteData(const QByteArray& byteData)
{
    if (byteData.isEmpty())
        return false;

    QMutexLocker locker(&m_Mutex);
    m_bRtn = false;

    emit SignalWriteData(byteData);
    return m_bRtn;
}

bool CSerialDev::ReadData(QString &sData)
{
    sData.clear();
    QByteArray byteData;
    byteData.clear();
    if (!ReadData(byteData))
    {
        return false;
    }

    for (auto it = byteData.begin(); it != byteData.end(); ++it)
    {
        sData += QString("%1").arg(*it, 2, 16, QLatin1Char('0'));
    }

    return true;
}

bool CSerialDev::ReadData(QByteArray& byteData)
{
    byteData.clear();
    QMutexLocker locker(&m_Mutex);
    if (m_ReadBuffQueue.isEmpty())
    {
        return false;
    }
    while (!m_ReadBuffQueue.isEmpty())
    {
        byteData += m_ReadBuffQueue.dequeue();
    }
    return !byteData.isEmpty();
}

// 此函数在串口有数据时触发
void CSerialDev::SlotReadyData()
{
    DWORD dwStartTick = GetTickCount();
    QByteArray ByteData = m_SerialPort->readAll();
    QTextCodec *codec = QTextCodec::codecForName("System");
    QMutexLocker locker(&m_Mutex);
    m_ReadBuffQueue.enqueue(ByteData);
    //emit SignalReceiveData();
}

void CSerialDev::SlotClose()
{
    m_SerialPort->close();
    if (m_SerialPort->isOpen())
    {
        return;
    }

    emit SignalConnectState(false);
    m_bRtn = true;
}

void CSerialDev::SlotWriteData(QString sData)
{
    SlotWriteData(sData.toLocal8Bit());
}

void CSerialDev::SlotWriteData(QByteArray byteData)
{
    m_bRtn = m_SerialPort->write(byteData);
    if (!m_bRtn)
    {
    }
}

void CSerialDev::SlotOpenDev(QString sSerialParam)
{
    m_bRtn = false;
    if (sSerialParam.isEmpty())
        return;

    SSerialParam SerialParam;
    if (!ConverFromQString(sSerialParam, SerialParam))
        return;

    if (m_SerialPort->isOpen())
        m_SerialPort->close();

    m_SerialPort->setPortName(SerialParam.sPortName);
    m_SerialPort->setBaudRate(SerialParam.eBaudRate);
    m_SerialPort->setDataBits(SerialParam.eDataBits);
    m_SerialPort->setParity(SerialParam.eParity);
    m_SerialPort->setStopBits(SerialParam.eStopBits);

    if (!m_SerialPort->open(QIODevice::ReadWrite))
    {
        emit SignalConnectState(false);
        return;
    }

    emit SignalConnectState(true);
    m_bRtn = true;
}

bool CSerialDev::ConverFromQString(QString sParam, SSerialParam& SerialParam)
{
    if (sParam.isEmpty())
        return false;

    vector<string> vecParam;
    vecParam.clear();
    //SplitStrToArrayKeepWhiteSpaceA(sParam.toStdString(), vecParam, ",");
    if (vecParam.size() < 5)
        return false;

    SerialParam.sPortName = QString::fromStdString(vecParam.at(0));
    SerialParam.eBaudRate = QSerialPort::BaudRate(QString::fromStdString(vecParam.at(1)).toInt());
    SerialParam.eParity = ConvToQtParity(QString::fromStdString(vecParam.at(2)));
    SerialParam.eDataBits = ConvToQtDataBit(QString::fromStdString(vecParam.at(3)));
    SerialParam.eStopBits = ConvToQtStopBit(QString::fromStdString(vecParam.at(4)));

    return true;
}

QSerialPort::DataBits CSerialDev::ConvToQtDataBit(QString sDataBit)
{
    if (sDataBit.compare("5") == 0)
        return QSerialPort::Data5;
    else if (sDataBit.compare("6") == 0)
        return QSerialPort::Data6;
    else if (sDataBit.compare("7") == 0)
        return QSerialPort::Data7;
    else if (sDataBit.compare("8") == 0)
        return QSerialPort::Data8;
    else
        return QSerialPort::UnknownDataBits;

    return QSerialPort::UnknownDataBits;
}

QSerialPort::Parity CSerialDev::ConvToQtParity(QString sParity)
{
    if (sParity.compare("No") == 0)
        return QSerialPort::NoParity;
    else if (sParity.compare("Odd") == 0)
        return QSerialPort::OddParity;
    else if (sParity.compare("Even") == 0)
        return QSerialPort::EvenParity;
    else
        return QSerialPort::UnknownParity;

    return QSerialPort::UnknownParity;
}

QSerialPort::StopBits CSerialDev::ConvToQtStopBit(QString sStopBit)
{
    if (sStopBit.compare("1") == 0)
        return QSerialPort::OneStop;
    else if (sStopBit.compare("1.5") == 0)
        return QSerialPort::OneAndHalfStop;
    else if (sStopBit.compare("2") == 0)
        return QSerialPort::TwoStop;
    else
        return QSerialPort::UnknownStopBits;

    return QSerialPort::UnknownStopBits;
}

QSerialPort::FlowControl CSerialDev::ConvToQtFlowControl(QString sFlowControl)
{
    if (sFlowControl.compare("No") == 0)
        return QSerialPort::NoFlowControl;
    else if (sFlowControl.compare("RCS/TCS") == 0)
        return QSerialPort::HardwareControl;
    else if (sFlowControl.compare("XON/XOFF") == 0)
        return QSerialPort::SoftwareControl;
    else
        return QSerialPort::UnknownFlowControl;

    return QSerialPort::UnknownFlowControl;
}

