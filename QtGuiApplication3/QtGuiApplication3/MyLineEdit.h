#pragma once

#include <QTimer>
#include <QLineEdit>
#include <QKeyEvent>
#include <QDebug>
class CMyLineEdit : public QLineEdit
{
    Q_OBJECT
public:
    CMyLineEdit(QWidget* parent = nullptr);
    ~CMyLineEdit();

protected:
    void focusInEvent(QFocusEvent *e);
	bool eventFilter(QObject *obj, QEvent *event);
private:
	QString barstr;
};