#ifndef MYSLIDESWITCH_H
#define MYSLIDESWITCH_H

// »¬¶¯¿ª¹Ø

#include <QLabel>

class  CMySlideSwitch : public QLabel
{
	Q_OBJECT

public:
	explicit CMySlideSwitch(QWidget *parent = 0);
	bool GetSwitchStatus();
	void SetSwitchStatus(bool bIsOn);

	void Initialize(const QString& strImageOff, const QString& strImageOn, bool bIsImageOn);
protected:
	virtual void paintEvent(QPaintEvent *);
	virtual void mousePressEvent(QMouseEvent *);
	virtual void mouseReleaseEvent(QMouseEvent *);

signals:
	void SignalUpdateSwitchStatus(bool bIsOn);

private:
	QPixmap     m_pixmap;
	
	QString		m_csOn;
	QString		m_csOff;

	bool        m_bIsOn;

	bool        m_bLBtnDown;
};

#endif // MYSLIDESWITCH_H
