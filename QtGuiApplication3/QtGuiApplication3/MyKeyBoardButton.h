#pragma once

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QMessageBox>
class MyKeyBoardButton : public QWidget
{
	Q_OBJECT

public:
	MyKeyBoardButton(QWidget *parent = 0);
	~MyKeyBoardButton();
private:
	QPixmap pix;
	QPoint lastPoint;
	QPoint endPoint;
	int scale;
	QPushButton *pushBtn;
	QPushButton *pushBtn1;
protected:
	void paintEvent(QPaintEvent *);
	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
	void mouseReleaseEvent(QMouseEvent *event);
private slots:
	void zoomIn();
	void zoomOut();
	void BoxOut();
};
