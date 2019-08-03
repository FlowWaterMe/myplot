#include "StpeBase.h"

CTask::CTask(QString taskName, TaskFun pFun) 
	:m_Name(taskName)
	, m_Fun(pFun)
	, m_status(eTaskStatus_NOSTART)
	, m_ErrorStr("")
{

}
CTask::~CTask()
{

}
QString CTask::getName() const
{
	return m_Name;
}
eTaskStatus CTask::getStatus() const
{
	return m_status;
}
bool CTask::exec()
{
	bool bRet = false;
	m_status = eTaskStatus_STARTED;
	bRet = m_Fun(m_ErrorStr);
	if (bRet == true)
		m_status = eTaskStatus_SUCCESSFUL;
	else
		m_status = eTaskStatus_FAILED;
	return bRet;
}

StpeBase::StpeBase()
{
	m_stepResult = true;
	bSkip = false;
	m_Timer = new QTimer();
	m_Timer->setInterval(m_timeout);
	connect(m_Timer, SIGNAL(timeout()), this, SLOT(TimeOutSlot()));
}


StpeBase::~StpeBase()
{
	int size = m_TaskList.size();
	for (int i = 0; i < size; ++i)
	{
		delete m_TaskList[i];
	}
	m_TaskList.clear();

	disconnect(m_Timer, SIGNAL(timeout()), this, SLOT(TimeOutSlot()));
	delete m_Timer;
}

void StpeBase::skip()
{
	bSkip = true;
	getResult();
}
bool StpeBase::getResult()
{
	QMutex mutex;
	QMutexLocker lock(&mutex);
	while (m_bAllTaskFinished == false && bSkip == false)
	{
		QThread::msleep(500);
	}

	if (bSkip)
	{
		qDebug() << "CStepBase::getResult()1:: sTaskName = " << m_stepName << ", stepResult = " << m_stepResult;
		return false;
	}

	qDebug() << "CStepBase::getResult()2:: sTaskName = " << m_stepName << ", stepResult = " << m_stepResult;
	return m_stepResult;
}

void StpeBase::TimeOutSlot()
{
	skip();
	m_Timer->stop();
}

void StpeBase::exec()
{
	m_Timer->start();
	m_bAllTaskFinished = false;
	int size = m_TaskList.size();
	for (int i = 0; i < size; ++i)
	{
		CTask *pTask = m_TaskList.at(i);

		if (bSkip)
		{
			m_stepResult = false;
			emit taskResultSignal(m_stepName, pTask->getName(), m_stepResult, tr("流程被人为中断"));
			break;
		}
		emit taskStartSignal(m_stepName, pTask->getName());  //任务开始执行信号
		m_stepResult = pTask->exec();
		emit taskResultSignal(m_stepName, pTask->getName(), m_stepResult, pTask->getErrorStr());  //任务执行结束信号

		if (false == m_stepResult)
			break;
	}
	m_bAllTaskFinished = true;
}

int StpeBase::getTaskCount()
{
	return m_TaskList.size();
}
uint getStepTimeOut(const char * step)
{
	return getIniValue("STEP", step);
}
uint getIniValue(QString strGroup, QString strKey)
{
	uint ret = 0;
	QString configFilePath = QCoreApplication::applicationDirPath() + "/ChemSoft.int";
	    QSettings config(configFilePath, QSettings ::IniFormat);
    config.beginGroup(strGroup);
    ret = config.value(QString(strKey)).toUInt();
    config.endGroup();
    return ret;

}
