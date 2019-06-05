#pragma once

#include "selfcheck_global.h"
#include "StpeBase.h"
class SELFCHECK_EXPORT DBInit : StpeBase
{
public:
	DBInit();
	virtual void exec();
	virtual bool getResult();
private:
	static bool CFGInit_SystemConfig(QString & strError);
	static bool DBInit_StartDataBase(QString & strError);
};
