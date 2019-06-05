
#include <QPainter>
#include <QMouseEvent>
#include "MySlideSwitch.h"

CMySlideSwitch::CMySlideSwitch(QWidget *parent)
	: QLabel(parent)
{

}


void CMySlideSwitch::paintEvent(QPaintEvent *)
{
	QPainter painter(this);
	painter.drawPixmap(QPoint(0,0), m_pixmap);
}

void CMySlideSwitch::mousePressEvent(QMouseEvent *event)
{
	if (event->button() == Qt::LeftButton)
	{
		if (!m_bLBtnDown)  // นุ
		{
			m_bLBtnDown = true;
			m_pixmap.load(m_csOff);
		}
		else
		{
			m_bLBtnDown = false;
			m_pixmap.load(m_csOn);
		}
	}

	repaint();

	QWidget::mousePressEvent(event);
}

void CMySlideSwitch::mouseReleaseEvent(QMouseEvent *e)
{
	if(m_bLBtnDown) 
	{
		m_bIsOn = false;
		//m_bLBtnDown = false;
	}
	else
	{
		m_bIsOn = true;
	}

	emit SignalUpdateSwitchStatus(m_bIsOn);
	update();
}

void CMySlideSwitch::Initialize(const QString& strImageOff, const QString& strImageOn, bool bIsImageOn)
{
	m_csOff = strImageOff;
	m_csOn = strImageOn;
    if (bIsImageOn)
    {
        m_bLBtnDown = false;
        m_pixmap.load(m_csOn);
    }
    else
    {
        m_bLBtnDown = true;
        m_pixmap.load(m_csOff);
    }

	m_bIsOn = bIsImageOn;
    update();
// 	QPainter painter(this);
// 	QRect rect = this->geometry();
// 	painter.drawPixmap(rect, m_pixmap);
}

bool CMySlideSwitch::GetSwitchStatus()
{
	return m_bIsOn;
}

void CMySlideSwitch::SetSwitchStatus(bool bIsOn)
{
	m_bIsOn	= bIsOn;
	if(m_bIsOn) 
		m_pixmap.load(m_csOn);
	else
		m_pixmap.load(m_csOff);
	update();
}