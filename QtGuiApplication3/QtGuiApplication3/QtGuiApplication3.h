#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QtGuiApplication3.h"
#include <QEvent>
#include <QMimeData>
#include <QDragEnterEvent>
#include <QUrl>
#include <QFile>
#include <QTextStream>
#include "control/MySlideSwitch.h"
#include "MyLineEdit.h"
enum ETablePara
{
	eTablePara_No = 0,
	eTablePara_CuvtteNo,
	eTablePara_LiquidType,
	eTablePara_AssayName,
	eTablePara_TestStatusAndResult,
	eTablePara_ResultFlag,
	eTablePara_PatientName,
	eTablePara_CreateTime,
	eTablePara_Response,
	eTablePara_TestID,
	eTablePara_OrderID,
	eTablePara_SampleID,
	eTablePara_Barcode,
	eTablePara_Num,
};
class QtGuiApplication3 : public QMainWindow
{
	Q_OBJECT

public:
	QtGuiApplication3(QWidget *parent = Q_NULLPTR);
	void initCustomPlot();
protected:
	void dragEnterEvent(QDragEnterEvent *event);//拖动进入事件
	void dropEvent(QDropEvent *event);//放下事件
	private slots :
	void on_pushButton_clicked();
	void setTextFont(bool t);
	void InitUITableWidget();
private:
	Ui::QtGuiApplication3Class *ui;

public slots:
	void dealDrawLine();
	void dealDrawBarChart();
	void dealDrawYB();
	void dealDrawZK();
	void dealDrawDQ();
	void dealDrawFN();
};
