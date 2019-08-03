#include "NetworkDev.h"
#include <QHostAddress>
//#include "Platform/Logger/logger.h"
//#include "Platform/Common/misc.h"

CNetworkDev::CNetworkDev(int iNo, QObject *parent)
    : CCommunicateDev(parent)
{
    m_iNo = iNo;

    m_Thread = new QThread(this);
    m_TcpSocket = new QTcpSocket(this);
    m_TcpSocket->moveToThread(m_Thread);

    // 这个信号槽必须连接，否则会内存泄漏
    QObject::connect(m_Thread, SIGNAL(finished()), this, SLOT(deleteLater()));
    QObject::connect(m_TcpSocket, SIGNAL(readyRead()), this, SLOT(SlotReadyData()));
    QObject::connect(m_TcpSocket, SIGNAL(disconnected()), this, SLOT(SlotDisconnected()));
    QObject::connect(m_TcpSocket, SIGNAL(connected()), this, SLOT(SlotConnected()));
    QObject::connect(this, SIGNAL(SignalWriteData(QString)), this, SLOT(SlotWriteData(QString)), Qt::BlockingQueuedConnection);
    QObject::connect(this, SIGNAL(SignalStartDev(QString)), this, SLOT(SlotStartDev(QString)), Qt::BlockingQueuedConnection);
    QObject::connect(this, SIGNAL(SignalClose()), this, SLOT(SlotClose()), Qt::BlockingQueuedConnection);

    moveToThread(m_Thread);
    m_Thread->start();
}

CNetworkDev::~CNetworkDev()
{
    QObject::disconnect(m_TcpSocket, SIGNAL(disconnected()), this, SLOT(SlotDisconnected()));
    QObject::disconnect(m_TcpSocket, SIGNAL(connected()), this, SLOT(SlotConnected()));
    QObject::disconnect(m_TcpSocket, SIGNAL(readyRead()), this, SLOT(SlotReadyData()));
    QObject::disconnect(m_Thread, SIGNAL(finished()), this, SLOT(deleteLater()));
    delete m_TcpSocket;
    m_Thread->quit();
    m_Thread->wait();
    delete m_Thread;
}

bool CNetworkDev::CloseDev()
{
    if (!IsOpenDev())
        return true;

    QMutexLocker locker(&m_Mutex);
    m_bRtn = false;
    emit SignalClose();
    return m_bRtn;
}


bool CNetworkDev::IsOpenDev()
{
    bool bIsCon = (m_TcpSocket->state() == QAbstractSocket::ConnectedState) ? true : false;
    return bIsCon;
}


bool CNetworkDev::StartDev(const QString& sParam)
{
    if (sParam.isEmpty())
        return false;

    QMutexLocker locker(&m_Mutex);
    m_bRtn = false;
    emit SignalStartDev(sParam);
    return m_bRtn;
}


bool CNetworkDev::ChangeParamAndRecon(const QString& sParam)
{
    if (sParam.isEmpty())
        return false;

    QMutexLocker locker(&m_Mutex);
    m_bRtn = false;
    emit SignalStartDev(sParam);
    return m_bRtn;
}


bool CNetworkDev::WriteData(const QString& sSendData)
{
    if (sSendData.isEmpty())
        return false;

    QMutexLocker locker(&m_Mutex);
    m_bRtn = false;
    emit SignalWriteData(sSendData);
    return m_bRtn;
}


bool CNetworkDev::ReadData(QString& sCurData)
{
    sCurData = "";
    QMutexLocker locker(&m_Mutex);
    while (!m_ReadBuffQueue.isEmpty())
        sCurData += m_ReadBuffQueue.dequeue();

    return true;
}

void CNetworkDev::SlotReadyData()
{
    QByteArray ByteData = m_TcpSocket->readAll();
    while (m_TcpSocket->waitForReadyRead(100))
        ByteData += m_TcpSocket->readAll();

    QTextCodec *codec = QTextCodec::codecForName("System");

    QMutexLocker locker(&m_Mutex);
    //WRITE_INFO_LOG(_T("SlotReadyRead:") + VAZConvStrQ2T(codec->toUnicode(ByteData)));
    m_ReadBuffQueue.enqueue(codec->toUnicode(ByteData));
    emit SiganlReceiveData(m_iNo, "");
}

void CNetworkDev::SlotDisconnected()
{
    emit SignalConnectState(m_iNo, false);
}

void CNetworkDev::SlotConnected()
{
    emit SignalConnectState(m_iNo, true);
}

void CNetworkDev::SlotClose()
{
    m_TcpSocket->close();
    Sleep(100);
    if (m_TcpSocket->state() == QAbstractSocket::ConnectedState)
    {
        return;
    }

    m_bRtn = true;
}


void CNetworkDev::SlotWriteData(QString sData)
{
    QByteArray ByteData = sData.toLocal8Bit();
    m_bRtn = m_TcpSocket->write(ByteData);
	if (!m_bRtn) {}
}

void CNetworkDev::SlotStartDev(QString sParam)
{
    vector<string> vecParam;
    //SplitStrToArrayKeepWhiteSpaceA(sParam.toStdString(), vecParam, ",");
    if (vecParam.size() < 2)
        return;

    SNetworkParam NetworkParam;
    NetworkParam.sHostName = QString::fromStdString(vecParam.at(0));
    NetworkParam.iPort = QString::fromStdString(vecParam.at(1)).toInt();

    QHostAddress HostAddress;
    if (NetworkParam.sHostName.compare("127.0.0.1") == 0)
        HostAddress.setAddress(QHostAddress::LocalHost);
    else
        HostAddress.setAddress(NetworkParam.sHostName);

    if (m_TcpSocket->state() == QAbstractSocket::ConnectedState)
        m_TcpSocket->close();

    const int iConTimeOut = 10 * 1000;
    m_TcpSocket->connectToHost(HostAddress, NetworkParam.iPort);
    if (!m_TcpSocket->waitForConnected(iConTimeOut))
    {
        return;
    }

    m_bRtn = true;
}

