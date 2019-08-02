#include "MyKeyBoardButton.h"
#include <QPainter>
#include <QPixmap>
#include <QDebug>
#include <QMouseEvent>
#include <QPushButton>
MyKeyBoardButton::MyKeyBoardButton(QWidget *parent)
	: QWidget(parent)
{
	resize(600, 500); //���ڴ�С����Ϊ600*500
	pix = QPixmap(200, 200);
	pix.fill(Qt::green);
	scale = 1; //���ó�ʼ�Ŵ���Ϊ1�������Ŵ�
	pushBtn = new QPushButton(this); //�½���ť����
	pushBtn->setText(tr("zoomIn")); //���ð�ť��ʾ�ı�
	pushBtn->move(200, 150); //���ð�ť����λ��
	connect(pushBtn, SIGNAL(clicked()), this, SLOT(zoomIn())); //�԰�ť�ĵ����¼�����ۺ������й���
	pushBtn1 = new QPushButton(this); //�½���ť����
	pushBtn1->setText(tr("zoomOut")); //���ð�ť��ʾ�ı�
	pushBtn1->move(300, 150); //���ð�ť����λ��
	connect(pushBtn1, SIGNAL(clicked()), this, SLOT(zoomOut())); //�԰�ť�ĵ����¼�����ۺ������й���
}

MyKeyBoardButton::~MyKeyBoardButton()
{
}

void MyKeyBoardButton::mousePressEvent(QMouseEvent *event)
{
	//qDebug() << event->pos();
	if (event->button() == Qt::LeftButton) //����������
		lastPoint = event->pos();
}
void MyKeyBoardButton::mouseMoveEvent(QMouseEvent *event)
{
	if (event->buttons()&Qt::LeftButton) //���������µ�ͬʱ�ƶ����
	{
		endPoint = event->pos();
		update();
	}
}
void MyKeyBoardButton::mouseReleaseEvent(QMouseEvent *event)
{
	if (event->button() == Qt::LeftButton) //�������ͷ�
	{
		endPoint = event->pos();
		update();
	}
}
void MyKeyBoardButton::paintEvent(QPaintEvent *)
{
	QPainter pp(&pix);
	pp.drawLine(lastPoint, endPoint);
	lastPoint = endPoint; //��ǰһ������ֵ���ں�һ������ֵ����������ʵ�ֻ�����������
	QPainter painter(this);
	painter.scale(scale, scale); //���зŴ����
	painter.drawPixmap(0, 0, pix);
}

void MyKeyBoardButton::zoomIn() //��ť�����¼��Ĳۺ���
{
	scale *= 2;
	update();
	QMessageBox messagem(QMessageBox::Information, "information", "really to clear data?", QMessageBox::Yes | QMessageBox::No, NULL);
	messagem.exec();
}
void MyKeyBoardButton::zoomOut() //��ť�����¼��Ĳۺ���
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