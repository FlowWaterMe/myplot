#include "SerialDevice.h"
#include "RS232Device.h"

//CVAZSerialDevice& GetInstruSerialDev()
//{
//	static CVAZSerialDevice *st_pInstruSerialDev = nullptr;
//	if (nullptr == st_pInstruSerialDev)
//	{
//		st_pInstruSerialDev = new CRS232Device;
//	}
//	return *st_pInstruSerialDev;
//}

CVAZSerialDevice *CreateASerialDev()
{
	CVAZSerialDevice *pSerialDev = nullptr;
	pSerialDev = new CRS232Device; 
	return pSerialDev;
}



CVAZSerialDevice& GetLISSerialDev()
{
	static CVAZSerialDevice *st_pLISSerialDev = nullptr;
	if (nullptr == st_pLISSerialDev)
	{
		st_pLISSerialDev = new CRS232Device;
	}
	return *st_pLISSerialDev;
}

CVAZSerialDevice& GetPrinterSerialDev()
{
	static CVAZSerialDevice *st_pPrinterSerialDev = nullptr;
	if (nullptr == st_pPrinterSerialDev)
	{
		st_pPrinterSerialDev = new CRS232Device;
	}
	return *st_pPrinterSerialDev;
}
