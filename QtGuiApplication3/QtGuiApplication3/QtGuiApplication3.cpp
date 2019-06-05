#include "QtGuiApplication3.h"
#include <QMessageBox>
#include <Qdebug>
#include <windows.h>
#include <tchar.h>
#include "myqwizard.hpp"
#include <QEvent>
#include <QDragEnterEvent>
#include <QUrl>
#include <QFile>
#include <QTextStream>
#include <QObject>
#include "qcustomplot.h"
#include "AppParam.h"
#include "CurvePlot.h"
#include "QCCurvePlot.h"
static const QString ICON_SLIDESWITCH_OFF = "E:\\Young\project\\QtGuiApplication3 - ����\\QtGuiApplication3\\image\\switch_off.png";
static const QString ICON_SLIDESWITCH_ON = "E:\\Young\project\\QtGuiApplication3 - ����\\QtGuiApplication3\\image\\switch_on.png";
QtGuiApplication3::QtGuiApplication3(QWidget *parent)
	: QMainWindow(parent)
	,ui(new Ui::QtGuiApplication3Class)
{
	ui->setupUi(this);
	InitUITableWidget();
	QAction * action_font = new QAction(QStringLiteral("����"), this);
	action_font->setCheckable(true);
	connect(action_font, SIGNAL(toggled(bool)), this, SLOT(setTextFont(bool)));
	ui->mainToolBar->addAction(action_font);
	setAcceptDrops(true);
	ui->label->Initialize(ICON_SLIDESWITCH_OFF, ICON_SLIDESWITCH_ON, false);
	initCustomPlot();
	//dealDrawLine();
	ui->tabWidget->setCurrentIndex(0);
	connect(ui->pushButton_zhexian, SIGNAL(clicked()), this, SLOT(dealDrawLine()));
	connect(ui->pushButton_zhuxing, SIGNAL(clicked()), this, SLOT(dealDrawBarChart()));
	connect(ui->pushButton_yb, SIGNAL(clicked()), this, SLOT(dealDrawYB()));
	connect(ui->pushButton_zk, SIGNAL(clicked()), this, SLOT(dealDrawZK()));
	connect(ui->pushButton_dq, SIGNAL(clicked()), this, SLOT(dealDrawDQ()));
	connect(ui->pushButton_fn, SIGNAL(clicked()), this, SLOT(dealDrawFN()));
}

void QtGuiApplication3::dealDrawYB()
{
	ui->tabWidget->setCurrentIndex(0);
	SCurveParam CurveParam;
	CurveParam.sXName = QStringLiteral("���ڵ�");
	CurveParam.sYName = QStringLiteral("AD");
	CurveParam.eClickRule = eClickRule_Round;

	QVector<SCurvePoint> vecPoint;
	for (int i = 0;i < 100;i++)
	{
		vecPoint.push_back(SCurvePoint(i, i*i-20));
	}
	ui->widget->InitCurvePlot(CurveParam);
	ui->widget->SetData(vecPoint);//todo
}
void QtGuiApplication3::dealDrawZK()
{
	ui->tabWidget->setCurrentIndex(2);
	QVector<SQcPlotPoint> vecQcPlotPoint;
	for (int i = 0;i < 10;i++)
	{
		SQcPlotPoint QcPlotPoint;
		QcPlotPoint.iTestID = i;
		QcPlotPoint.iOrderID = i + 12;
		QcPlotPoint.dXData = 20190523+i;
		QcPlotPoint.dYData = i;
		QcPlotPoint.iQcRstType = 1;
		QcPlotPoint.dSD = 15 + i;
		QcPlotPoint.iQcTimeType = 1;
		vecQcPlotPoint.push_back(QcPlotPoint);
	}

	ui->widget_QC->SetQcPlotData(vecQcPlotPoint);
}
void QtGuiApplication3::dealDrawDQ()
{
	ui->tabWidget->setCurrentIndex(3);
	SCurveParam CurveParam;
	CurveParam.sXName = QStringLiteral("��Ӧ��");
	CurveParam.sYName = QStringLiteral("�����");
	CurveParam.eClickRule = eClickRule_Precise;

	QVector<SCurvePoint> vecPoint;
	for (int i = 0; i < 5; i++)
	{
		vecPoint.push_back(SCurvePoint(i, i*i - 10));
	}
	ui->widget_DB->InitCurvePlot(CurveParam);
	ui->widget_DB->SetData(vecPoint);//todo

}
void QtGuiApplication3::dealDrawFN()
{
	ui->tabWidget->setCurrentIndex(4);
	SCurveParam CurveParam;
	CurveParam.sXName = QStringLiteral("��Ӧ��");
	CurveParam.sYName = QStringLiteral("Ũ��");
	CurveParam.eClickRule = eClickRule_Precise;

	QVector<SCurvePoint> vecPoint;
	for (int i = 0; i < 10; i++)
	{
		vecPoint.push_back(SCurvePoint(i, 14 + i*i/2));
	}
	ui->widget_FN->InitCurvePlot(CurveParam);
	ui->widget_FN->SetData(vecPoint);//todo

}
void QtGuiApplication3::dealDrawLine()
{
	ui->tabWidget->setCurrentIndex(1);
	int plottableCount = ui->widget_com->plottableCount();
	if (plottableCount != 0)
		ui->widget_com->clearPlottables();

	ui->widget_com->xAxis->setRange(0, 30); //9���̶�
	ui->widget_com->yAxis->setRange(0, 30);

	ui->widget_com->xAxis->setLabel("time"); //9���̶�
	ui->widget_com->yAxis->setLabel("AD");
	ui->widget_com->setBackground(QBrush(QColor(Qt::gray)));

	QPen drawPen;
	drawPen.setColor(Qt::blue);
	drawPen.setWidth(1);
	QVector<double> xLineVector, yLineVector;
	xLineVector << 1 << 2 << 3 << 4 << 5 << 6 << 7;
	yLineVector << 4 << 1 << 2 << 4 << 5 << 6 << 7;
	QCPGraph * curGraph = ui->widget_com->addGraph();
	curGraph->setPen(drawPen);
	curGraph->setLineStyle(QCPGraph::lsLine);
	curGraph->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 2));
	curGraph->setData(xLineVector, yLineVector);
	xLineVector.clear();
	yLineVector.clear();
	xLineVector << 1 << 2 << 3 << 4 << 5 << 6 << 7;
	yLineVector << 14 << 21 << 23 << 24 << 15 << 16 << 27;
	QCPGraph * curGraph1 = ui->widget_com->addGraph();
	curGraph1->setPen(drawPen);
	curGraph1->setLineStyle(QCPGraph::lsLine);
	curGraph1->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 2));
	curGraph1->setData(xLineVector, yLineVector);
	ui->widget_com->replot();

}
void QtGuiApplication3::dealDrawBarChart()
{
	ui->tabWidget->setCurrentIndex(1);
	int plottableCount = ui->widget_com->plottableCount();
	if (plottableCount != 0)
		ui->widget_com->clearPlottables();

	ui->widget_com->xAxis->setRange(-1, 8);
	ui->widget_com->yAxis->setRange(-1, 12);
	QLinearGradient gradient(0, 0, 0, 400);
	gradient.setColorAt(0, QColor(90, 90, 90));
	gradient.setColorAt(0.38, QColor(100, 100, 100));
	gradient.setColorAt(1, QColor(70, 70, 70));
	ui->widget_com->setBackground(QBrush(gradient));

	QVector<double> xBarVector, yBarVector;
	xBarVector << 1 << 2 << 3 << 4 << 5 << 6 << 7;
	yBarVector << 0.86*10.5 << 0.83*5.5 << 0.84*5.5 << 0.52*5.8 << 0.89*5.2 << 0.90*4.2 << 0.67*11.2;
	QCPBars *rectBar = new QCPBars(ui->widget_com->xAxis, ui->widget_com->yAxis);
	rectBar->setAntialiased(false);
	rectBar->setStackingGap(1);
	rectBar->setPen(QPen(QColor(0, 168, 140).lighter(130)));
	rectBar->setBrush(QColor(0, 168, 140));
	rectBar->setData(xBarVector, yBarVector);
	ui->widget_com->replot();

}
void QtGuiApplication3::initCustomPlot()
{
	ui->widget_com->resize(this->width(), this->height());
	ui->widget_com->xAxis->setVisible(true);
	ui->widget_com->yAxis->setVisible(true);
	/// ���ö����ߺ��ұ�����ʾ������ʾ�̶�ֵ
	ui->widget_com->xAxis2->setVisible(true);
	ui->widget_com->xAxis2->setTickLabels(false);
	ui->widget_com->yAxis2->setVisible(true);
	ui->widget_com->yAxis2->setTickLabels(false);
	ui->widget_com->xAxis2->setTicks(false);
	ui->widget_com->yAxis2->setTicks(false);

	/// ���ö����ߺ��ұ�����x��y�仯���仯
	connect(ui->widget_com->xAxis, SIGNAL(rangeChanged(QCPRange)), ui->widget_com->xAxis2, SLOT(setRange(QCPRange)));
	connect(ui->widget_com->yAxis, SIGNAL(rangeChanged(QCPRange)), ui->widget_com->yAxis2, SLOT(setRange(QCPRange)));

	/// ������ק���Ŵ���С����
	ui->widget_com->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);

}

void QtGuiApplication3::setTextFont(bool t)
{
	if (t)
	{
		QTextCursor cursor = ui->textEdit->textCursor();
		QTextBlockFormat blockformat;
		blockformat.setAlignment(Qt::AlignCenter);//ˮƽ����
		cursor.insertBlock(blockformat);
		QTextCharFormat charFormat;
		charFormat.setBackground(Qt::lightGray);
		charFormat.setForeground(Qt::blue);
		charFormat.setFont(QFont(QStringLiteral("����"), 12, QFont::Bold, true));
		charFormat.setFontUnderline(true);//ʹ���»���
		cursor.setCharFormat(charFormat);//ʹ���ַ���ʽ
		cursor.insertText(QStringLiteral("��������"));//�����ı�

	}
}
void QtGuiApplication3::on_pushButton_clicked()
{
	/*QMessageBox message(QMessageBox::Warning, "information", "really to clear data?", QMessageBox::Yes | QMessageBox::No, NULL);
	if (message.exec() == QMessageBox::Yes)
	{
		qDebug() << "clicked yes\n";
	}
	else
	{
		qDebug() << "clicked no\n";
	}

	QMessageBox messageq(QMessageBox::Question, "information", "really to clear data?", QMessageBox::Yes | QMessageBox::No, NULL);
	if (messageq.exec() == QMessageBox::Yes)
	{
		qDebug() << "clicked yes\n";
	}
	else
	{
		qDebug() << "clicked no\n";
	}

	QMessageBox messagem(QMessageBox::Information, "information", "really to clear data?", QMessageBox::Yes | QMessageBox::No, NULL);
	if (messagem.exec() == QMessageBox::Yes)
	{
		qDebug() << "clicked yes\n";
	}
	else
	{
		qDebug() << "clicked no\n";
	}

	QMessageBox messagec(QMessageBox::Critical, "information", "really to clear data?", QMessageBox::Yes | QMessageBox::No, NULL);
	if (messagec.exec() == QMessageBox::Yes)
	{
		qDebug() << "clicked yes\n";
	}
	else
	{
		qDebug() << "clicked no\n";
	}
	::MessageBox(NULL, _T("��������!\n������������ӷ�ʽ���ȶϿ�����!"), _T("��ʾ"), MB_ICONEXCLAMATION);


	QMessageBox::information(0, QObject::tr("Simple Wizard"),
		QObject::tr("Cannot write file %1:\n%2")
		.arg("hello")
		.arg("world"));
	QMessageBox::question(0, QObject::tr("Simple Wizard"),
		QObject::tr("Cannot write file %1:\n%2")
		.arg("hello")
		.arg("world"));
	QMessageBox::warning(0, QObject::tr("Simple Wizard"),
		QObject::tr("Cannot write file %1:\n%2")
		.arg("hello")
		.arg("world"));
	QMessageBox::critical(0, QObject::tr("Simple Wizard"),
		QObject::tr("Cannot write file %1:\n%2")
		.arg("hello")
		.arg("world"));


	MyQwizard wizard;
	wizard.exec();*/
}


void QtGuiApplication3::dragEnterEvent(QDragEnterEvent *event)//�϶������¼�
{
	if (event->mimeData()->hasUrls())
	{
		event->acceptProposedAction();
	}
	else
		event->ignore();
}
void QtGuiApplication3::dropEvent(QDropEvent *event)//�����¼�
{
	const QMimeData * mimeData = event->mimeData();
	if (mimeData->hasUrls())
	{
		QList<QUrl>urlList = mimeData->urls();
		QString fileName = urlList.at(0).toLocalFile();
		if (!fileName.isEmpty())
		{
			QFile file(fileName);
			if (!file.open(QIODevice::ReadOnly))
				return;
			QTextStream in(&file);
			ui->textEdit->setText(in.readAll());
		}
	}
}

void QtGuiApplication3::InitUITableWidget()
{
	ui->tableWidget->setColumnCount(eTablePara_Num);
	ui->tableWidget->setHorizontalHeaderItem(eTablePara_No, new QTableWidgetItem(QStringLiteral("���")));
	ui->tableWidget->setHorizontalHeaderItem(eTablePara_Barcode, new QTableWidgetItem(QStringLiteral("����")));
	ui->tableWidget->setHorizontalHeaderItem(eTablePara_PatientName, new QTableWidgetItem(QStringLiteral("����")));
	ui->tableWidget->setHorizontalHeaderItem(eTablePara_TestStatusAndResult, new QTableWidgetItem(QStringLiteral("״̬/���")));
	ui->tableWidget->setHorizontalHeaderItem(eTablePara_LiquidType, new QTableWidgetItem(QStringLiteral("����")));
	ui->tableWidget->setHorizontalHeaderItem(eTablePara_AssayName, new QTableWidgetItem(QStringLiteral("��Ŀ")));
	ui->tableWidget->setHorizontalHeaderItem(eTablePara_CreateTime, new QTableWidgetItem(QStringLiteral("¼��ʱ��")));
	ui->tableWidget->setHorizontalHeaderItem(eTablePara_TestID, new QTableWidgetItem(QStringLiteral("����ID")));
	ui->tableWidget->setHorizontalHeaderItem(eTablePara_OrderID, new QTableWidgetItem(QStringLiteral("����ID")));
	ui->tableWidget->setHorizontalHeaderItem(eTablePara_SampleID, new QTableWidgetItem(QStringLiteral("����ID")));
	ui->tableWidget->setHorizontalHeaderItem(eTablePara_Response, new QTableWidgetItem(QStringLiteral("��Ӧ��")));
	ui->tableWidget->setHorizontalHeaderItem(eTablePara_ResultFlag, new QTableWidgetItem(QStringLiteral("���")));
	ui->tableWidget->setHorizontalHeaderItem(eTablePara_CuvtteNo, new QTableWidgetItem(QStringLiteral("����")));
	// ���ñ������
	ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);  //����ѡ��һ��
	ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection); //����ֻ��ѡ��һ�У����ܶ���ѡ��
	ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);   //����ÿ�����ݲ��ɸ���
	ui->tableWidget->setAlternatingRowColors(true);   //���ø�һ�б�һ��ɫ������һ��һ��
	ui->tableWidget->clearContents();
	ui->tableWidget->verticalHeader()->hide();

	// ���õ�Ԫ������
	ui->tableWidget->setColumnWidth(eTablePara_No, 50);
	ui->tableWidget->setColumnWidth(eTablePara_LiquidType, 115);
	ui->tableWidget->setColumnWidth(eTablePara_AssayName, 80);
	ui->tableWidget->setColumnWidth(eTablePara_TestStatusAndResult, 130);
	ui->tableWidget->setColumnWidth(eTablePara_ResultFlag, 60);
	ui->tableWidget->horizontalHeader()->setStretchLastSection(true);      // ���һ���������
	ui->tableWidget->setColumnWidth(eTablePara_CuvtteNo, 50);
	ui->tableWidget->setRowCount(4);   // 4����Ӧ�� 

	for (int iRow = 0; iRow <= 3; iRow++)
	{
		QTableWidgetItem *widgetItem = nullptr;

		// ���ÿ������
		for (int iColumn = eTablePara_No; iColumn < eTablePara_Num; iColumn++)
		{
			widgetItem = new QTableWidgetItem(QTableWidgetItem::Type);
			widgetItem->setText("");
			widgetItem->setTextAlignment(Qt::AlignCenter);
			ui->tableWidget->setItem(iRow, iColumn, widgetItem);
		}

		ui->tableWidget->setRowHeight(iRow, 50);
	}
}

