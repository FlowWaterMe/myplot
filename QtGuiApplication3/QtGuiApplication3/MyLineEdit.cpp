#include "MyLineEdit.h"

CMyLineEdit::CMyLineEdit(QWidget* parent /*= nullptr*/)
    : QLineEdit(parent)
{
    installEventFilter(this);
}

CMyLineEdit::~CMyLineEdit()
{

}

void CMyLineEdit::focusInEvent(QFocusEvent *e)
{
    QLineEdit::focusInEvent(e);
	qDebug() << "focusInEvent";
}


bool CMyLineEdit::eventFilter(QObject *obj, QEvent *event)
{
	if (event->type() == QEvent::KeyPress) {
		QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
		qDebug("Ate key press %d", keyEvent->key());
		if (keyEvent->key() == Qt::Key_Return)
		{
			setText(barstr);
			barstr.clear();
			return true;
		}
		else
		{
			barstr += keyEvent->text();
		}
		return true;
	}
	else {
		// standard event processing
		return QObject::eventFilter(obj, event);
	}
}