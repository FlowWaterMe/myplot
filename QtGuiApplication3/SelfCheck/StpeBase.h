#pragma once
#include <QObject>
#include <QDebug>
#include <QTimer>
#include <QMutex>
#include <QThread>
#include <QCoreApplication>
#include <QSettings>
using namespace std;
enum eTaskStatus
{
	eTaskStatus_NOSTART,
	eTaskStatus_STARTED,
	eTaskStatus_SUCCESSFUL,
	eTaskStatus_FAILED
};
#define  IsTaskFinished(eStatus) ((eStatus >= eTaskStatus_SUCCESSFUL) && (eStatus <= eTaskStatus_FAILED))
#define  IsTaskStarted(eStatus) (eStatus == eTaskStatus_STARTED)

class CTask
{
public:
	typedef bool(*TaskFun)(QString & strError);
	CTask(QString taskName, TaskFun pFun);
	virtual ~CTask();
	QString getName() const;
	eTaskStatus getStatus() const;
	QString getErrorStr() { return m_ErrorStr; }
	virtual bool exec();
protected:
	QString             m_Name;         //任务名称
	TaskFun             m_Fun;
	eTaskStatus         m_status;
	QString             m_ErrorStr;     //错误信息


};
class StpeBase :
	public QObject
{
	Q_OBJECT
public:
	StpeBase();
	virtual ~StpeBase();
	virtual void skip();
	virtual bool getResult();
	virtual void exec();
	int getTaskCount();
protected:
	typedef QVector<CTask *>TaskVector;
	bool m_stepResult;
	bool bSkip;
	QVector < CTask*>m_TaskList;
	QString m_strError;
	//step info
	QString m_stepName;
	bool m_bAllTaskFinished;
	int m_timeout;   //任务超时时间,单位:ms
private:
	QTimer *m_Timer;
private slots:
void TimeOutSlot();
signals:
	void taskStartSignal(QString strUnitName, QString strTaskName);
	void taskResultSignal(QString strUnitName, QString strTaskName, bool bSuccess, QString ErrorStr);
};
uint getStepTimeOut(const char * step);
uint getIniValue(QString strGroup, QString strKey);

