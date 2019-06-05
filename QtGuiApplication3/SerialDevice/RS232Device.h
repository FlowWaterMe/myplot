#pragma once

#include "SerialDevice.h"
//#include "Platform/Common/VAZCircularQueue.h"
//#include "Platform/OSAdapter/VAZEvent.h"
//#include "Platform/OSAdapter/VAZThread.h"
#include <Windows.h>
#include "../QtGuiApplication3/GlobalDefine.h"
#include "../OSAdapter/VAZThread.h"
#include "../OSAdapter/VAZTimer.h"
#include "../OSAdapter/VAZEvent.h"
#include "../OSAdapter/VAZLock.h"
//#include "../QtGuiApplication3/APPFun.h"
class CRS232Device;

///////////////////////////////////////////////////////////////////////////////////////////////////////
class CRS232RecvThread : public CVAZThread
{
public:
	CRS232RecvThread();
	~CRS232RecvThread();

	void SetRS232Device(CRS232Device *pRS232Device);

protected:
	CRS232Device *m_pRS232Device;	
};

class CRS232NonOverlappedRecvThread : public CRS232RecvThread
{
protected:
	void run();
};

class CRS232OverlappedRecvThread : public CRS232RecvThread
{
protected:
	void run();

private:
	void ReadFromComPort();
};

///////////////////////////////////////////////////////////////////////////////////////////////////////
class CRS232SendThread : public CVAZThread
{
public:
	CRS232SendThread();
	~CRS232SendThread();

	void SetRS232Device(CRS232Device *pRS232Device);

protected:
	CRS232Device *m_pRS232Device;
};

class CRS232NonOverlappedSendThread : public CRS232SendThread
{
protected:
	void run();
};

class CRS232OverlappedSendThread : public CRS232SendThread
{
protected:
	void run();
};

///////////////////////////////////////////////////////////////////////////////////////////////////////
typedef void *HANDLE;
class CRS232Device : public CVAZSerialDevice
{
	friend class CRS232SendThread;
	friend class CRS232RecvThread;
	friend class CRS232NonOverlappedSendThread;
	friend class CRS232NonOverlappedRecvThread;
	friend class CRS232OverlappedSendThread;
	friend class CRS232OverlappedRecvThread;
public:
	CRS232Device();
	~CRS232Device();

	bool Open(const tstring& sDeviceParam);
	bool IsOpen();
	bool Close();

	bool Read(COMM_UNIT_ID UnitID, unsigned char *lpBuf, unsigned long dwBufSize, unsigned long dwReadLen, unsigned long *pActualReadLen);
	bool Write(COMM_UNIT_ID UnitID, const unsigned char *lpBuf, unsigned long dwWriteLen, unsigned long *pActualWriteLen);
	void RegRecvEvent(COMM_UNIT_ID UnitID, CVAZEvent *pRecvDataEvent);//TODO: pointer change to reference
	bool CheckSendBufIsEmpty() override;
	bool CheckRecvBufIsEmpty() override;
	bool ClearSendBuf() override;
	bool ClearRecvBuf() override;
private:
	bool ReOpen(tstring sDeviceParam);
	bool SetTimeOut(COMMTIMEOUTS &sTimeOut);
	bool GetTimeOut(COMMTIMEOUTS &sTimeOut);

	bool GetState(DCB &dcb);
	bool SetState(DCB &dcb);
	
	bool GetMask(DWORD &dwMask);
	bool SetMask(DWORD dwMask);

	bool SetComm(DWORD dwBaud, BYTE nParity, BYTE nDataBits, BYTE nStopBits);

	void NotifyRecvEvent(CVAZEvent *pRecvDataEvent);

private:
	HANDLE							m_hComm;

	CVAZEvent						m_SendEvent;					//串口写事件
	CRS232SendThread				*m_SendThread;
	CVAZThreadSafeCircularQueue<unsigned char>m_SendBuf;			//串口写缓冲区	

	CVAZEvent						*m_pReadEvent;					//串口读事件
	CRS232RecvThread				*m_RecvThread;
	CVAZThreadSafeCircularQueue<unsigned char> m_RecvBuf;			//串口读缓冲区
};
