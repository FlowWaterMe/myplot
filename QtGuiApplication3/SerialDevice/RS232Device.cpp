#include "RS232Device.h"
#include <mbstring.h>
#include <vector>
#include <map>
#include <utility>
#include "../QtGuiApplication3/GlobalDefine.h"
//#include "Platform/Common/misc.h"
//#include "Platform/Common/IniFile.h"
//#include "Platform/Logger/logger.h"

#define MAX_BUFFER_SIZE		40960
#define MAX_SIZE			256

////////////////////////////////////////////////////////////////////////////////////////////////////////
CRS232RecvThread::CRS232RecvThread() : CVAZThread(_T("RS232RecvThread"))
{
	
}

CRS232RecvThread::~CRS232RecvThread()
{

}


void CRS232RecvThread::SetRS232Device(CRS232Device *pRS232Device)
{
	m_pRS232Device = pRS232Device;
}

void CRS232NonOverlappedRecvThread::run()
{
	DWORD		dwActualReadLen = 0;
	DWORD		dwWillReadLen = 0;
	DWORD		dwCommModemStatus = 0;
	DWORD		dwReadErrors = 0;
	COMSTAT 	cmState;

	DWORD		dwReadCount = 0;

	unsigned char pszReadBuf[MAX_SIZE] = {0};

	ASSERT(m_pRS232Device->m_hComm != INVALID_HANDLE_VALUE);
	if(INVALID_HANDLE_VALUE == m_pRS232Device->m_hComm)
	{
		return;
	}

	while(!m_bExitThread && m_pRS232Device->m_hComm != INVALID_HANDLE_VALUE)
	{
		WaitCommEvent (m_pRS232Device->m_hComm, &dwCommModemStatus, 0);
		if(dwCommModemStatus & EV_RXCHAR) 
		{
			ClearCommError(m_pRS232Device->m_hComm, &dwReadErrors, &cmState);
			dwWillReadLen = cmState.cbInQue;
			if(dwWillReadLen > 0)
			{
				dwReadCount = min<DWORD>(dwWillReadLen, MAX_SIZE);
				if(ReadFile(m_pRS232Device->m_hComm, pszReadBuf, dwReadCount, &dwActualReadLen, NULL))
				{
					if(dwActualReadLen > 0)
					{						
						if (m_pRS232Device->m_RecvBuf.GetCount() + dwActualReadLen > m_pRS232Device->m_RecvBuf.GetBufSize())
						{
							string sLog = "";
							while(!m_pRS232Device->m_RecvBuf.IsEmpty())
							{
								unsigned char ch = 0;
								m_pRS232Device->m_RecvBuf.DeQueue(&ch,1);
								sLog += ch;
							}
						}

						if (!m_pRS232Device->m_RecvBuf.EnQueue(pszReadBuf, dwActualReadLen))
						{
							ASSERT(false);
						}

						m_pRS232Device->NotifyRecvEvent(m_pRS232Device->m_pReadEvent);
					}
				}	
				else
				{
				}
			}
		}
		GetCommModemStatus(m_pRS232Device->m_hComm, &dwCommModemStatus);
	}
}

void CRS232OverlappedRecvThread::run()
{
	BOOL		fWaitingOnStates = FALSE;
	OVERLAPPED	osStatus = {0};
	DWORD		dwWaitStates;
	DWORD		dwOvRes;

	DWORD		dwCommEvent = 0;

	ASSERT(m_pRS232Device->m_hComm != INVALID_HANDLE_VALUE);
	if(INVALID_HANDLE_VALUE == m_pRS232Device->m_hComm)
	{
		return;
	}

	osStatus.hEvent = CreateEvent(NULL, TRUE, FALSE, NULL);
	ASSERT(osStatus.hEvent != NULL);
	if (osStatus.hEvent == NULL)
	{
		return;
	}

	while(!m_bExitThread && m_pRS232Device->m_hComm != INVALID_HANDLE_VALUE)
	{
		if (!fWaitingOnStates)
		{
			if (!WaitCommEvent(m_pRS232Device->m_hComm, &dwCommEvent, &osStatus))
			{
				if (GetLastError() == ERROR_IO_PENDING)
				{
					fWaitingOnStates = TRUE;
				}
				else
				{
					Sleep(100);
				}				
			}
			else
			{
				if (dwCommEvent & EV_RXCHAR)
				{
					ReadFromComPort();
				}
			}
		}

		if (fWaitingOnStates)
		{
			dwWaitStates = WaitForSingleObject(osStatus.hEvent, INFINITE);
			switch (dwWaitStates)
			{
			case WAIT_OBJECT_0:
				if (!GetOverlappedResult(m_pRS232Device->m_hComm, &osStatus, &dwOvRes, FALSE))
				{
					Sleep(100);
				}
				else
				{
					if (dwCommEvent & EV_RXCHAR)
					{
						ReadFromComPort();
					}
				}
				ResetEvent(osStatus.hEvent);
				fWaitingOnStates = FALSE;
				break;

			default:
				ASSERT(FALSE);
				break;
			}
		}
	}

	CloseHandle(osStatus.hEvent);
}

//overlapped
void CRS232OverlappedRecvThread::ReadFromComPort()
{
	DWORD		dwErrors = 0;
	COMSTAT		comStat;

	BOOL		fWaitingOnRead = FALSE;
	OVERLAPPED	osReader = {0};
	DWORD		dwWaitStates;
	DWORD		dwNeedReadLen = 0;
	DWORD		dwActualReadLen = 0;
	unsigned char pszReadBuf[MAX_SIZE] = {0};

	BOOL		bNotifyFlag = FALSE;
	int			iReadTimes = 0;// 当串口缓冲区的数据较多时，每读4次，通知上层处理数据

	osReader.hEvent = CreateEvent(NULL, TRUE, FALSE, NULL);
	if (osReader.hEvent == NULL)
	{
		return;
	}

	do
	{
		if (!fWaitingOnRead)
		{
			++iReadTimes;
			if (iReadTimes > 4 && bNotifyFlag)
			{
				iReadTimes = 1;
				bNotifyFlag = FALSE;
				m_pRS232Device->NotifyRecvEvent(m_pRS232Device->m_pReadEvent);
			}

			dwErrors = 0;
			comStat.cbInQue = 0;
			if (!ClearCommError(m_pRS232Device->m_hComm, &dwErrors, &comStat))
			{
				break;
			}

			dwNeedReadLen = comStat.cbInQue;
			if (dwNeedReadLen <= 0)
				break;

			if (!ReadFile(m_pRS232Device->m_hComm, pszReadBuf, min<DWORD>(dwNeedReadLen, MAX_SIZE), &dwActualReadLen, &osReader))
			{
				if (GetLastError() == ERROR_IO_PENDING)
				{
					fWaitingOnRead = TRUE;
				} 
				else
				{
					break;
				}
			}
			else
			{
				if (!m_pRS232Device->m_RecvBuf.EnQueue(pszReadBuf, dwActualReadLen))
				{
					m_pRS232Device->m_RecvBuf.Clear();
				}

				bNotifyFlag = TRUE;
				dwNeedReadLen = dwNeedReadLen - dwActualReadLen;
			}
		} 

		if (fWaitingOnRead)
		{
			dwWaitStates = WaitForSingleObject(osReader.hEvent, INFINITE);// 操作超时、等待超时的选择
			switch (dwWaitStates)
			{
			case WAIT_OBJECT_0:
				if(!GetOverlappedResult(m_pRS232Device->m_hComm, &osReader, &dwActualReadLen, FALSE))
				{
					Sleep(100);
				}
				else
				{
					if (!m_pRS232Device->m_RecvBuf.EnQueue(pszReadBuf, dwActualReadLen))
					{
						m_pRS232Device->m_RecvBuf.Clear();
					}

					bNotifyFlag = TRUE;
					dwNeedReadLen = dwNeedReadLen - dwActualReadLen;
				}
				ResetEvent(osReader.hEvent);
				fWaitingOnRead = FALSE;
				break;

			default:
				ASSERT(FALSE);
				break;
			}
		}
	}while (dwNeedReadLen > 0);

	CloseHandle(osReader.hEvent);
	if (bNotifyFlag)
	{
		m_pRS232Device->NotifyRecvEvent(m_pRS232Device->m_pReadEvent);
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
CRS232SendThread::CRS232SendThread() : CVAZThread(_T("RS232SendThread"))
{

}

CRS232SendThread::~CRS232SendThread()
{

}

void CRS232SendThread::SetRS232Device(CRS232Device *pRS232Device)
{
	m_pRS232Device = pRS232Device;
}

void CRS232NonOverlappedSendThread::run()
{
	DWORD		dwWriteLen = 0;
	DWORD		dwWriteCount = 0;
	DWORD		dwActualWriteLen = 0;

	unsigned char pszWriteBuf[MAX_SIZE];

	while(!m_bExitThread)
	{

		if(WAITEVENT(m_pRS232Device->m_SendEvent, 500) == WAIT_OBJECT_0)
		{
			dwWriteLen = m_pRS232Device->m_SendBuf.GetCount();
			while(dwWriteLen)
			{
				dwWriteCount = min<DWORD>(dwWriteLen, MAX_SIZE);
				if (!m_pRS232Device->m_SendBuf.DeQueue(pszWriteBuf, dwWriteCount))
				{
					break;
				}

				if(!WriteFile(m_pRS232Device->m_hComm, pszWriteBuf, dwWriteCount, &dwActualWriteLen, NULL))
				{						
					break;
				}
				dwWriteLen = m_pRS232Device->m_SendBuf.GetCount();
			}
		}
	}
}

void CRS232OverlappedSendThread::run()
{
	DWORD		dwNeedWriteLen = 0;
	DWORD		dwCurWriteLen = 0;
	DWORD		dwActualWriteLen = 0;

	BOOL		fWaitingOnWrite = FALSE;
	OVERLAPPED	osWrite = {0};
	DWORD		dwWaitStates;

	unsigned char pszSendBuf[MAX_SIZE] = {0};

	osWrite.hEvent = CreateEvent(NULL, TRUE, FALSE, NULL);
	ASSERT(osWrite.hEvent != NULL);
	if (osWrite.hEvent == NULL)
	{
		return;
	}

	while (!m_bExitThread && m_pRS232Device->m_hComm != INVALID_HANDLE_VALUE)
	{
		if (WAITEVENT(m_pRS232Device->m_SendEvent, 500) == WAIT_OBJECT_0)
		{
			do
			{
				if(!fWaitingOnWrite)
				{
					dwNeedWriteLen = m_pRS232Device->m_SendBuf.GetCount();

					if (dwNeedWriteLen <= 0)
						break;

					dwCurWriteLen = min<DWORD>(dwNeedWriteLen, MAX_SIZE);

					if (!m_pRS232Device->m_SendBuf.DeQueue(pszSendBuf, dwCurWriteLen))
					{
						break;
					}

					dwNeedWriteLen = dwNeedWriteLen - dwCurWriteLen;

					if (!WriteFile(m_pRS232Device->m_hComm, pszSendBuf, dwCurWriteLen, &dwActualWriteLen, &osWrite))
					{
						if (GetLastError() == ERROR_IO_PENDING)
						{
							fWaitingOnWrite = TRUE;
						}
						else
						{
							Sleep(100);
						}
					} 
					else
					{
						if (dwCurWriteLen != dwActualWriteLen)
						{
						}
						//Write Direct success!
					}
				}

				if (fWaitingOnWrite)
				{
					dwWaitStates = WaitForSingleObject(osWrite.hEvent, INFINITE);
					switch (dwWaitStates)
					{
					case WAIT_OBJECT_0:
						if (!GetOverlappedResult(m_pRS232Device->m_hComm, &osWrite, &dwActualWriteLen, FALSE))
						{
							Sleep(100);
						}
						else
						{
							if (dwCurWriteLen != dwActualWriteLen)
							{
							}
							//Write Asy success
						}
						ResetEvent(osWrite.hEvent);
						fWaitingOnWrite = FALSE;
						break;

					default:
						ASSERT(FALSE);
						break;
					}
				}
			}while (dwNeedWriteLen > 0);
		}// if (WAITEVENT(m_pRS232Device->m_SendEvent, 500) == WAIT_OBJECT_0)
	}

	CloseHandle(osWrite.hEvent);
}

CRS232Device::CRS232Device() :
m_hComm(INVALID_HANDLE_VALUE),
m_pReadEvent(NULL), m_SendEvent(_T("RS232Device_WriteEvent")), 
m_RecvBuf(MAX_BUFFER_SIZE),m_SendBuf(MAX_BUFFER_SIZE),
m_RecvThread(NULL),m_SendThread(NULL)
{
}

CRS232Device::~CRS232Device()
{
	Close();
	m_SendEvent.Close();
}

bool CRS232Device::Open(const tstring& sDeviceParam)
{
	TCHAR szPort[15] ={0};   
	int iCount = 0;

	vector<int> vecParam;
	bool bOverlappedFlag = false;
	
#if 0 //_DEBUG	//调试使用
	tstring strIni = VAZGetCurrExePath() + _T("Config.ini");
	bool isExist = VAZIsFileExist(strIni);
	if(isExist)
	{ 
		CIniFile IniFile(strIni);
		vecParam.push_back(1);
		vecParam.push_back(IniFile.GetItemInt(_T("RS232"),_T("BaudRate")));
		vecParam.push_back(IniFile.GetItemInt(_T("RS232"),_T("Parity")));
		vecParam.push_back(IniFile.GetItemInt(_T("RS232"),_T("ByteSize")));
		vecParam.push_back(IniFile.GetItemInt(_T("RS232"),_T("StopBits")));
	}
	else
	{
		vecParam.push_back(1);
		vecParam.push_back(115200);
		vecParam.push_back(0);
		vecParam.push_back(8);
		vecParam.push_back(0);
	}
#else
	ASSERT(!sDeviceParam.empty());
	if (sDeviceParam.empty())
	{
		return false;
	}

	vecParam.clear();
	//VAZSplitStrToIntArray(sDeviceParam, vecParam, _T(","));
	iCount = vecParam.size();
	if (iCount != 6)
	{
		ASSERT(false);
		return false;
	}
#endif

	if (vecParam[0] > 9 == 1)
	{
		_stprintf(szPort, _T("\\\\.\\COM%d"), vecParam[0]);
	} 
	else
	{
		_stprintf(szPort, _T("COM%d:"), vecParam[0]);
	}
	
	if (vecParam[5] == 1)
	{
		bOverlappedFlag = true;
	} 
	else
	{
		bOverlappedFlag = false;
	}

	if (IsOpen())
		Close();

	m_hComm = CreateFile(szPort, GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, (bOverlappedFlag ? FILE_FLAG_OVERLAPPED : 0), 0);
	if (m_hComm == INVALID_HANDLE_VALUE)
	{
		CloseHandle(m_hComm);
		return false;
	}

	
	if (!SetComm(vecParam[1], (BYTE)vecParam[2], (BYTE)vecParam[3], (BYTE)vecParam[4]))
	{
		CloseHandle(m_hComm);
		m_hComm = INVALID_HANDLE_VALUE;
		return false;
	}

	ASSERT(m_RecvThread == NULL);
	if (m_RecvThread == NULL)
	{
		if (bOverlappedFlag)
		{
			m_RecvThread = new CRS232OverlappedRecvThread();
		} 
		else
		{
			m_RecvThread = new CRS232NonOverlappedRecvThread();
		}
		m_RecvThread->SetRS232Device(this);
		m_RecvThread->Start();
	}

	ASSERT(m_SendThread == NULL);
	if (m_SendThread == NULL)
	{
		if (bOverlappedFlag)
		{
			m_SendThread = new CRS232OverlappedSendThread();
		} 
		else
		{
			m_SendThread = new CRS232NonOverlappedSendThread();
		}
		m_SendThread->SetRS232Device(this);
		m_SendThread->Start();
	}

	return true;
}

// this function is not ready to use
bool CRS232Device::ReOpen(tstring sDeviceParam)
{
	TCHAR szPort[15] = {0};
	vector<int> vecParam;
	bool bOverlappedFlag = false;
	int iCount = 0;

	ASSERT(!sDeviceParam.empty());
	if(sDeviceParam.empty())
	{
		return false;
	}

	vecParam.clear();
	//VAZSplitStrToIntArray(sDeviceParam, vecParam, _T(","));
	iCount = vecParam.size();
	if (iCount != 6)
	{
		ASSERT(false);
		return false;
	}

	if (/*vecParam[0] > 9*/0 == 1)
	{
		_stprintf(szPort, _T("\\\\.\\COM%d:"), vecParam[0]);
	} 
	else
	{
		_stprintf(szPort, _T("COM%d:"), vecParam[0]);
	}

	if (vecParam[5] == 1)
	{
		bOverlappedFlag = true;
	} 
	else
	{
		bOverlappedFlag = false;
	}

	if(m_hComm != INVALID_HANDLE_VALUE)
	{
		CloseHandle(m_hComm);
		m_hComm = INVALID_HANDLE_VALUE;
	}

	m_hComm = CreateFile(szPort, GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, (bOverlappedFlag ? FILE_FLAG_OVERLAPPED : 0), NULL);
	if(INVALID_HANDLE_VALUE == m_hComm)
	{
		CloseHandle(m_hComm);
		return false;
	}

	if (!SetComm(vecParam[1], (BYTE)vecParam[2], (BYTE)vecParam[3], (BYTE)vecParam[4]))
	{
		return false;
	}

	return true;
}

bool CRS232Device::Close()
{
	ASSERT(m_hComm != INVALID_HANDLE_VALUE);
	if(m_hComm != INVALID_HANDLE_VALUE)
	{
		CloseHandle(m_hComm);
		m_hComm = INVALID_HANDLE_VALUE;
	}
	
	m_RecvThread->Exit();
	m_SendThread->Exit();

    SAFE_DELETE(m_RecvThread);
    SAFE_DELETE(m_SendThread);

	return true;
}

bool CRS232Device::IsOpen()
{
	return (m_hComm != INVALID_HANDLE_VALUE);
}

void CRS232Device::RegRecvEvent(COMM_UNIT_ID UnitID, CVAZEvent *pRecvDataEvent)
{
	m_pReadEvent = pRecvDataEvent;
}

bool CRS232Device::Write(COMM_UNIT_ID UnitID, const unsigned char *lpBuf, unsigned long dwWriteLen, unsigned long *pActualWriteLen)
{
	if (!IsOpen())
	{
		ASSERT(false);
		return false;
	}

	if (pActualWriteLen)
		*pActualWriteLen = 0;

	if(NULL == lpBuf)
	{
		return false;
	}

	if(dwWriteLen < 0)
	{
		return false;
	}
	if(dwWriteLen >= MAX_BUFFER_SIZE)
	{
		return false;
	}

	if(m_SendBuf.IsFull())
	{
		return false;
	}

	if(!m_SendBuf.EnQueue(lpBuf, dwWriteLen))
	{
		return false;
	}

	if (pActualWriteLen)
		*pActualWriteLen = dwWriteLen;

	SETEVENT(m_SendEvent);

	return true;
}

bool CRS232Device::Read(COMM_UNIT_ID UnitID, unsigned char *lpBuf, unsigned long dwBufSize, unsigned long dwReadLen, unsigned long *pActualReadLen)
{
	unsigned long ulCount = 0;

	if (!IsOpen())
	{
		ASSERT(false);
		return false;
	}

	ASSERT1(dwReadLen > 0, _T("Read the Data's Length is NULL!"));
	ASSERT1(dwBufSize >= dwReadLen, _T("The Read Buffer size is not enough!"));

	if (pActualReadLen)
		*pActualReadLen = 0;

	if (dwReadLen <= 0)
		return false;

	ulCount = (unsigned long)m_RecvBuf.GetCount();

	dwReadLen = MIN(dwReadLen, ulCount);

	if (dwReadLen <= 0)
		return false;

	bool bRet = m_RecvBuf.DeQueue(lpBuf, dwReadLen);

	ASSERT(bRet);
	if (bRet && pActualReadLen)
		*pActualReadLen = dwReadLen;

	return bRet;
}

void CRS232Device::NotifyRecvEvent(CVAZEvent *pRecvDataEvent)
{
	if(NULL == pRecvDataEvent)
	{
		ASSERT(false);
		return ;
	}
	SETEVENT(*pRecvDataEvent);
}

bool CRS232Device::GetState(DCB &dcb)
{
	ASSERT(IsOpen());
	if (INVALID_HANDLE_VALUE == m_hComm)
	{
		return false;
	}

	return GetCommState(m_hComm, &dcb);
}

bool CRS232Device::SetState(DCB &dcb)
{
	ASSERT(IsOpen());
	if (INVALID_HANDLE_VALUE == m_hComm)
	{
		return false;
	}

	return SetCommState(m_hComm, &dcb);
}

bool CRS232Device::SetTimeOut(COMMTIMEOUTS &sTimeOut)
{
	ASSERT(IsOpen());
	if (INVALID_HANDLE_VALUE == m_hComm)
	{
		return false;
	}

	sTimeOut.ReadIntervalTimeout = MAXDWORD;
	sTimeOut.ReadTotalTimeoutMultiplier = 0;
	sTimeOut.ReadTotalTimeoutConstant = 0;
	sTimeOut.WriteTotalTimeoutMultiplier = 0;
	sTimeOut.WriteTotalTimeoutConstant = 1000;
	return SetCommTimeouts(m_hComm, &sTimeOut);
}

bool CRS232Device::GetTimeOut(COMMTIMEOUTS &sTimeOut)
{
	ASSERT(IsOpen());
	if (INVALID_HANDLE_VALUE == m_hComm)
	{
		return false;
	}

	return GetCommTimeouts(m_hComm, &sTimeOut);
}

bool CRS232Device::SetMask(DWORD dwMask)
{
	ASSERT(IsOpen());
	if (INVALID_HANDLE_VALUE == m_hComm)
	{
		return false;
	}

	return SetCommMask(m_hComm, dwMask);
}

bool CRS232Device::GetMask(DWORD &dwMask)
{
	ASSERT(IsOpen());
	if (INVALID_HANDLE_VALUE == m_hComm)
	{
		return false;
	}

	return GetCommMask(m_hComm, &dwMask);
}

bool CRS232Device::SetComm(DWORD dwBaud, BYTE nParity, BYTE nDataBits, BYTE nStopBits)
{
	DCB comDCB;
	COMMTIMEOUTS sCommTS;

	if (!GetState(comDCB))
	{
		return false;
	}

	comDCB.DCBlength = sizeof(DCB);
	comDCB.BaudRate = dwBaud;				//波特率 
	comDCB.fBinary = true;					//Win32不支持非二进制串行传输模式，必须为TRUE 
	comDCB.fParity = true;					//启用奇偶校验 
	comDCB.ByteSize = nDataBits;
	comDCB.Parity = nParity;
	comDCB.StopBits = nStopBits;
	comDCB.fOutxCtsFlow = false;				//串行端口的输出由CTS线控制	
	comDCB.fOutxDsrFlow = false;				//关闭串行端口的DSR流控制 
	comDCB.fDtrControl = DTR_CONTROL_DISABLE;	//DTR线
	comDCB.fDsrSensitivity = false;				//如果设为TRUE将忽略任何输入的字节，除非DSR线被启用 
	comDCB.fTXContinueOnXoff = true;			
	comDCB.fOutX = false;						//设为TRUE指定XON/XOFF控制被用于控制串行输出 
	comDCB.fInX = false;						//设为TRUE指定XON/XOFF控制被用于控制串行输入 
	comDCB.fErrorChar = false;					
	comDCB.fNull = false;						//设为TRUE将使串行驱动程序忽略收到的空字节 
	comDCB.fRtsControl = DTR_CONTROL_DISABLE;	//启用RTS线 
	comDCB.fAbortOnError = false;				
	comDCB.EvtChar = 10;
	
	if (!SetState(comDCB))
	{
		return false;
	}

	if (!GetTimeOut(sCommTS))
	{
		return false;
	}

	if (!SetTimeOut(sCommTS))
	{
		return false;
	}

	if (!SetMask(EV_RXCHAR))
	{
		return false;
	}

	if(m_hComm != INVALID_HANDLE_VALUE)
	{
		//分配设备缓冲区
		if (!SetupComm(m_hComm, MAX_BUFFER_SIZE, MAX_BUFFER_SIZE))
		{
			return false;
		}


		//初始化缓冲区中的信息
		if (!PurgeComm(m_hComm, PURGE_RXCLEAR | PURGE_TXCLEAR))
		{
			return false;
		}
	}

	//设置端口上指定信号的状态
	// SETDTR: 发送DTR (data-terminal-ready)信号
	// SETRTS: 发送RTS (request-to-send)信号
	//EscapeCommFunction(m_hComm, SETDTR);
	//EscapeCommFunction(m_hComm, SETRTS);	
	return true;
}

bool CRS232Device::CheckSendBufIsEmpty()
{
	if (m_SendBuf.GetCount() > 0)
		return false;
	return true;
}

bool CRS232Device::ClearSendBuf()
{
    if (m_SendBuf.GetCount() > 0)
    {
        m_SendBuf.Clear();
        return true;
    }
        return false;
}
bool CRS232Device::CheckRecvBufIsEmpty()
{
	if (m_RecvBuf.GetCount() > 0)
		return false;
	return true;
}
bool CRS232Device::ClearRecvBuf()
{
	if (m_RecvBuf.GetCount() > 0)
	{
		m_RecvBuf.Clear();
		return true;
	}
	return false;
}

