#include "DBInit.h"

DBInit::DBInit()
{
	CTask * pTask = nullptr;
	pTask = new CTask(QObject::tr("�������ݿ�"),DBInit_StartDataBase);
	m_TaskList.push_back(pTask);
}

void DBInit::exec()
{
	StpeBase::exec();
}
bool DBInit::getResult()
{
	return StpeBase::getResult();
}
bool DBInit::CFGInit_SystemConfig(QString & strError)
{
	//bool bRet = AppConfig_Init();
	//if (bRet == false)
	//{
	//	strError = QObject::tr("��ʼ���ļ�ʧ��");
	//}
	//return bRet;
	return false;
}
bool DBInit::DBInit_StartDataBase(QString & strError)
{
	//bool bRet = StartDataBase();
	//if (bRet == false)
	//	strError = QObject::tr("�������ݿ�ʧ��");
	//return bRet;
	return false;
}