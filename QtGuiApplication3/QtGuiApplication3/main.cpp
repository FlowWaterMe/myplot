#include "QtGuiApplication3.h"
#include <QtWidgets/QApplication>
//#include "QtGuiClass.h"
#include "myqwizard.hpp"
#include <QDateTime>
#include <QDebug>
#include <QTextCodec>
#include "GlobalDllheader.h"
#include "VAZApplication.h"
#include "MyKeyBoardButton.h"
void SetAppStyleSheet(QApplication &App);
void SetAppCodec(QApplication &App);
bool InitBase(QString &errStr);

int main(int argc, char *argv[])
{
	//QApplication a(argc, argv);


	CVAZApplication &App = CVAZApplication::GetInstance(argc, argv);
	SetAppStyleSheet(App);
	SetAppCodec(App);

	QtGuiApplication3 MainWin;
	App.setMainWindow(&MainWin);
	MainWin.show();
	//QtGuiClass w1;
	//w1.show();
	QDateTime dateTime;
	QString dateTime_str = dateTime.currentDateTime().toString("yyyy-MM-dd hh:mm:ss");

	// ���ַ���ת��Ϊ���루��������������ʱ���룩
	dateTime_str = dateTime.fromString("2011-09-10 12:07:50:541", "yyyy-MM-dd hh:mm:ss:zzz").toMSecsSinceEpoch();

	// ���ַ���ת��Ϊ�루��������������ʱ���룩
	dateTime_str = dateTime.fromString("2011-09-10 12:07:50:541", "yyyy-MM-dd hh:mm:ss:zzz").toTime_t();

	// �Ӻ���ת����������ʱ����
	dateTime_str = dateTime.fromMSecsSinceEpoch(1315193829218).toString("yyyy-MM-dd hh:mm:ss:zzz");

	// ����ת����������ʱ���루����zzz����Ϊ000��
	dateTime_str = dateTime.fromTime_t(1315193829).toString("yyyy-MM-dd hh:mm:ss[:zzz]");

	QByteArray ba;
	ba.resize(5);
	ba[0] = 0x3c;
	ba[1] = 0xb8;
	ba[2] = 0x3e;
	ba[3] = 0x2f;
	ba[4] = 0xca;
	for (int i = 0; i < ba.size(); ++i)
	{
		if (ba.at(i) >= 'a' && ba.at(i) <= 'f')
		{
			qDebug() << "end found character in range";
		}
	}


	QByteArray bal("ca\0r\0t");
	bal.size();
	bal.constData();
	for (int i = 0; i < bal.size(); ++i)
	{

		qDebug() << bal[i];
	}
	QString  m_qsInitErrStr;
	InitBase(m_qsInitErrStr);


	return App.exec();
}
bool InitBase(QString &errStr)
{
	DBInit    DBInit;
	DBInit.exec();
	if (false == DBInit.getResult())
	{
		errStr = QString("���ݿ��ʼ��ʧ��");
		return false;
	}
	return true;
}

void SetAppStyleSheet(QApplication &App)
{
	QString qsFullName = QApplication::applicationDirPath() + QString::fromUtf8("/analyser.qss");
	QFile QssFile(qsFullName);

	bool bRtn = false;
	bRtn = QssFile.open(QFile::ReadOnly);
	if (bRtn)
	{
		App.setStyleSheet(QssFile.readAll());
		QssFile.close();
	}

	return;
}

void SetAppCodec(QApplication &App)
{
	QTextCodec *codec = QTextCodec::codecForName("System");    //��ȡϵͳ����
	QTextCodec::setCodecForLocale(codec);
	// 	QTextCodec::setCodecForCStrings(codec);
	// 	dQTextCodec::setCodecForQStringLiteral(codec);

	return;
}