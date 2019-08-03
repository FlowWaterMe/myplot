#include "MyKeyBoardButton.h"
#include <QPainter>
#include <QPixmap>
#include <QDebug>
#include <QMouseEvent>
#include <QPushButton>
MyKeyBoardButton::MyKeyBoardButton(QWidget *parent)
	: QWidget(parent)
{
	resize(600, 500); //窗口大小设置为600*500
	pix = QPixmap(200, 200);
	pix.fill(Qt::green);
	scale = 1; //设置初始放大倍数为1，即不放大
	pushBtn = new QPushButton(this); //新建按钮对象
	pushBtn->setText(tr("zoomIn")); //设置按钮显示文本
	pushBtn->move(200, 150); //设置按钮放置位置
	connect(pushBtn, SIGNAL(clicked()), this, SLOT(zoomIn())); //对按钮的单击事件和其槽函数进行关联
	pushBtn1 = new QPushButton(this); //新建按钮对象
	pushBtn1->setText(tr("zoomOut")); //设置按钮显示文本
	pushBtn1->move(300, 150); //设置按钮放置位置
	connect(pushBtn1, SIGNAL(clicked()), this, SLOT(zoomOut())); //对按钮的单击事件和其槽函数进行关联
}

MyKeyBoardButton::~MyKeyBoardButton()
{
}

void MyKeyBoardButton::mousePressEvent(QMouseEvent *event)
{
	//qDebug() << event->pos();
	if (event->button() == Qt::LeftButton) //鼠标左键按下
		lastPoint = event->pos();
}
void MyKeyBoardButton::mouseMoveEvent(QMouseEvent *event)
{
	if (event->buttons()&Qt::LeftButton) //鼠标左键按下的同时移动鼠标
	{
		endPoint = event->pos();
		update();
	}
}
void MyKeyBoardButton::mouseReleaseEvent(QMouseEvent *event)
{
	if (event->button() == Qt::LeftButton) //鼠标左键释放
	{
		endPoint = event->pos();
		update();
	}
}
void MyKeyBoardButton::paintEvent(QPaintEvent *)
{
	QPainter pp(&pix);
	pp.drawLine(lastPoint, endPoint);
	lastPoint = endPoint; //让前一个坐标值等于后一个坐标值，这样就能实现画出连续的线
	QPainter painter(this);
	painter.scale(scale, scale); //进行放大操作
	painter.drawPixmap(0, 0, pix);
}

void MyKeyBoardButton::zoomIn() //按钮单击事件的槽函数
{
	scale *= 2;
	update();
	QMessageBox messagem(QMessageBox::Information, "information", "really to clear data?", QMessageBox::Yes | QMessageBox::No, NULL);
	messagem.exec();
}
void MyKeyBoardButton::zoomOut() //按钮单击事件的槽函数
{
	scale *= 0.5;
	update();
}

void MyKeyBoardButton::BoxOut()
{
	QMessageBox label;
	label.setText("hello");
	label.show();
}