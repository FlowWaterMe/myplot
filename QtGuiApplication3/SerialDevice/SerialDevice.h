#pragma once

#include "serialdevice_global.h"
#include "../QtGuiApplication3/GlobalDefine.h"

typedef unsigned int COMM_UNIT_ID;

class CVAZEvent;
class CVAZSerialDevice
{
public:
	CVAZSerialDevice()
	{
	}

	virtual ~CVAZSerialDevice()
	{
	}

	virtual bool Open(const tstring& sDeviceParam) = 0;
	virtual bool IsOpen() = 0;
	virtual bool Close() = 0;
	virtual bool Read(COMM_UNIT_ID UnitID, unsigned char *lpBuf, unsigned long dwBufSize, unsigned long dwReadLen, unsigned long *pActualReadLen) = 0;
	virtual bool Write(COMM_UNIT_ID UnitID, const unsigned char *lpBuf, unsigned long dwWriteLen, unsigned long *pActualWriteLen) = 0;
	virtual void RegRecvEvent(COMM_UNIT_ID UnitID, CVAZEvent *pRecvDataEvent) = 0;
	virtual bool CheckSendBufIsEmpty() = 0;
    virtual bool ClearSendBuf() = 0;
	virtual bool ClearRecvBuf() = 0;
	virtual bool CheckRecvBufIsEmpty() = 0;
};

//SERIALDEVICE_EXPORT CVAZSerialDevice& GetInstruSerialDev();
SERIALDEVICE_EXPORT CVAZSerialDevice* CreateASerialDev();
SERIALDEVICE_EXPORT CVAZSerialDevice& GetLISSerialDev();
SERIALDEVICE_EXPORT CVAZSerialDevice& GetPrinterSerialDev();
