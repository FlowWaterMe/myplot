#include "SoftKeyboard.h"
#include "ui_SoftKeyboard.h"
#include <QObjectList>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QTextCodec>
#include <QDoubleSpinBox>
static const QString st_ConnectionName = "virtaulKeyDB";
static const int st_ShowChNum = 9;

CSoftKeyboard *CSoftKeyboard::st_pKeyboard = Q_NULLPTR;
CSoftKeyboard &CSoftKeyboard::GetInstance()
{
    if (st_pKeyboard == Q_NULLPTR)
    {
        st_pKeyboard = new CSoftKeyboard();
    }

    return *st_pKeyboard;
}

CSoftKeyboard::CSoftKeyboard(QWidget *parent)
    : QDialog(parent, Qt::Popup)
    , ui(new Ui::SoftKeyboard)
    , m_CallObj(Q_NULLPTR)
    , m_ListAllPinYin()
    , m_iCurPinYinPage(0)
    , m_eCurInputStyle(eInputStyle_EN)
    , m_eCurLetterStyle(eLetterStyle_Lowercase)
    , m_bShift(false)
    , m_bCtrl(false)
    , m_bAlt(false)
{
    ui->setupUi(this);
    QObject::connect(this, SIGNAL(InputStyleChanged()), this, SLOT(SlotInputStyleChanged()));
    QObject::connect(this, SIGNAL(LetterStyleChanged()), this, SLOT(SlotLetterStyleChanged()));
    QObject::connect(this, SIGNAL(ShiftChanged()), this, SLOT(SlotShiftChanged()));
    QObject::connect(this, SIGNAL(CtrlChanged()), this, SLOT(SlotCtrlChanged()));
    QObject::connect(this, SIGNAL(AltChanged()), this, SLOT(SlotAltChanged()));
    setWindowOpacity(0.9);
	ui->stackedWidget->setCurrentIndex(ePageStyle_All);
    InitKeyboard();
    InitPinyinDB();
}

CSoftKeyboard::~CSoftKeyboard()
{
    m_CallObj = Q_NULLPTR;
    UninitPinyinDB();
}

void CSoftKeyboard::registerObject(QObject *object)
{
    m_CallObj = object;
}
void CSoftKeyboard::InitKeyboard()
{
	// ï¿½ï¿½Ê¼ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½
	QList<QPushButton *> lstMyBtn = ui->stackedWidget->findChildren<QPushButton *>();
	auto it = lstMyBtn.begin();
	QPushButton* pBtn = nullptr;
	for (; it != lstMyBtn.end(); ++it)
	{
		pBtn = dynamic_cast<QPushButton*>(*it);
		if (pBtn == nullptr)
			continue;
		QString button_style = "QPushButton{background-color:black;\
                                      color: white;   border-radius: 10px;  border: 2px groove gray;\
                                      border-style: outset;}"
			"QPushButton:hover{background-color:white; color: black;}"
			"QPushButton:pressed{background-color:rgb(85, 170, 255);\
                                                     border-style: inset; }";
		pBtn->setStyleSheet(button_style);
		connect(pBtn, SIGNAL(clicked()), this, SLOT(SlotBtnClicked()));
	}

	pBtn = nullptr;

	HiddenChinese();
}


void CSoftKeyboard::InitPinyinDB()
{
    m_DBName = QCoreApplication::applicationDirPath() + "/py.db";
    if (m_DBSql.isOpen())
        return;

    m_DBSql = QSqlDatabase::addDatabase("QSQLITE", st_ConnectionName);
    m_DBSql.setDatabaseName(m_DBName);
    m_DBSql.open();
}

void CSoftKeyboard::UninitPinyinDB()
{
    if (m_DBSql.isOpen())
        m_DBSql.close();

    m_DBSql = QSqlDatabase();
    QSqlDatabase::removeDatabase(m_DBName);
}

void CSoftKeyboard::SymbolDealWith(EKey eKey)
{
    QString sValue = "";
    switch (eKey) {
    case eKey_Symbol1: m_bShift ? sValue = "~" : sValue = "`"; break;         // ~ `
    case eKey_Symbol2: m_bShift ? sValue = "_" : sValue = "-"; break;         //  _ -
    case eKey_Symbol3: m_bShift ? sValue = "+" : sValue = "="; break;         //  + =
    case eKey_Symbol4: m_bShift ? sValue = "{" : sValue = "["; break;         // { [
    case eKey_Symbol5: m_bShift ? sValue = "}" : sValue = "]"; break;         // } ]
    case eKey_Symbol6: m_bShift ? sValue = "|" : sValue = "\\"; break;         // |
    case eKey_Symbol7: m_bShift ? sValue = ":" : sValue = ";"; break;          //  : ;
    case eKey_Symbol8: m_bShift ? sValue = "\"" : sValue = "\'"; break;         //  " '
    case eKey_Symbol9: m_bShift ? sValue = "<" : sValue = ","; break;         // < ,
    case eKey_Symbol10: m_bShift ? sValue = ">" : sValue = "."; break;         // > .
    case eKey_Symbol11: m_bShift ? sValue = "?" : sValue = "/"; break;        // ? /
    default: return;//break;
    }

    if(m_eCurInputStyle == eInputStyle_CH && ui->language_Pinyin->isVisible())
    {
        if(eKey_Symbol2 == eKey)
            LastPageChinese();
        else if(eKey_Symbol3 == eKey)
            NextPageChinese();
    }
    else
        WidgetValueInserted(sValue);
}

void CSoftKeyboard::NumberDealWith(EKey eKey)
{
    QString sValue = "";
    switch (eKey) {
    case eKey_Number1: sValue = m_bShift ? "!" : "1"; break;
    case eKey_Number2: sValue = m_bShift ? "@" : "2"; break;
    case eKey_Number3: sValue = m_bShift ? "#" : "3"; break;
    case eKey_Number4: sValue = m_bShift ? "$" : "4"; break;
    case eKey_Number5: sValue = m_bShift ? "%" : "5"; break;
    case eKey_Number6: sValue = m_bShift ? "^" : "6"; break;
    case eKey_Number7: sValue = m_bShift ? "&" : "7"; break;
    case eKey_Number8: sValue = m_bShift ? "*" : "8"; break;
    case eKey_Number9: sValue = m_bShift ? "(" : "9"; break;
    case eKey_Number0: sValue = m_bShift ? ")" : "0"; break;
    default: return;//break;
    }

    if(m_eCurInputStyle == eInputStyle_CH && !m_bShift && ui->language_Pinyin->isVisible())
        SelectedChinese(sValue.toInt());
    else
        WidgetValueInserted(sValue);
}

void CSoftKeyboard::LetterDealWith(EKey eKey)
{
    QString sValue = "";
    switch (eKey) {
    case eKey_Q: sValue = "q"; break;
    case eKey_W: sValue = "w"; break;
    case eKey_E: sValue = "e"; break;
    case eKey_R: sValue = "r"; break;
    case eKey_T: sValue = "t"; break;
    case eKey_Y: sValue = "y"; break;
    case eKey_U: sValue = "u"; break;
    case eKey_I: sValue = "i"; break;
    case eKey_O: sValue = "o"; break;
    case eKey_P: sValue = "p"; break;

    case eKey_A: sValue = "a"; break;
    case eKey_S: sValue = "s"; break;
    case eKey_D: sValue = "d"; break;
    case eKey_F: sValue = "f"; break;
    case eKey_G: sValue = "g"; break;
    case eKey_H: sValue = "h"; break;
    case eKey_J: sValue = "j"; break;
    case eKey_K: sValue = "k"; break;
    case eKey_L: sValue = "l"; break;

    case eKey_Z: sValue = "z"; break;
    case eKey_X: sValue = "x"; break;
    case eKey_C: sValue = "c"; break;
    case eKey_V: sValue = "v"; break;
    case eKey_B: sValue = "b"; break;
    case eKey_N: sValue = "n"; break;
    case eKey_M: sValue = "m"; break;
    default: return; //break;
    }

    if((m_eCurLetterStyle == eLetterStyle_Capital) || m_bShift || m_bAlt)
    {
        WidgetValueInserted(sValue.toUpper());
    }
    else
    {
        if(m_eCurInputStyle == eInputStyle_CH)
        {
            ui->language_Pinyin->setText(ui->language_Pinyin->text() + sValue);
            QueriedChinese();
        }
        else
            WidgetValueInserted(sValue);
    }
}

void CSoftKeyboard::FunctionKeyDealWith(EKey eKey)
{
    switch (eKey) {
    case eKey_Backspace: BackspaceFunctionKey(); break;
    case eKey_Tab: TabFunctionKey(); break;
    case eKey_CapsLock: CapsLockFunctionKey(); break;
    case eKey_Enter: EnterFunctionKey(); break;
    case eKey_Shift: ShiftFunctionKey(); break;
    case eKey_PgUp: PgFunctionKey(true); break;
    case eKey_Up: Key_Up_FunctionKey();break;            // ÉÏ
    case eKey_PgDn: PgFunctionKey(false); break;
    case eKey_Ctrl: CtrlFunctionKey(); break;
    case eKey_EN_CH: EN_CHFunctionKey(); break;
    case eKey_Alt: AltFunctionKey(); break;
    case eKey_Space: SpaceFunctionKey(); break;
    case eKey_Left: Key_Left_FunctionKey();break;
    case eKey_Down: Key_Down_FunctionKey();break;
	case eKey_Right:Key_Right_FunctionKey(); break;

    default: break;
    }
}

void CSoftKeyboard::BackspaceFunctionKey()
{
    if(m_eCurInputStyle == eInputStyle_CH)
    {
        QString txt = ui->language_Pinyin->text();
        int len = txt.length();
        if (len > 1)
        {
            ui->language_Pinyin->setText(txt.left(len - 1));
            QueriedChinese();
        }
        else
        {
            txt.isEmpty() ? DeletedWidgetValue() : HiddenChinese();
        }
    }
    else
        DeletedWidgetValue();
}

void CSoftKeyboard::TabFunctionKey()
{
    WidgetValueInserted("    ");
}

void CSoftKeyboard::CapsLockFunctionKey()
{
    m_eCurLetterStyle = (m_eCurLetterStyle == eLetterStyle_Capital) ? eLetterStyle_Lowercase : eLetterStyle_Capital;
    SwitchLetterStyle();
}

void CSoftKeyboard::EnterFunctionKey()
{
    if(dynamic_cast<QLineEdit*>(m_CallObj) != Q_NULLPTR)
    {
        m_CallObj = Q_NULLPTR;
        close();
    }

    else if(dynamic_cast<QTextEdit*>(m_CallObj) != Q_NULLPTR)
    {
        WidgetValueInserted("\r\n");
    }

    else if(dynamic_cast<QPlainTextEdit*>(m_CallObj) != Q_NULLPTR)
    {
        WidgetValueInserted("\r\n");
    }
}

void CSoftKeyboard::ShiftFunctionKey()
{
    m_bShift = !m_bShift;
    SwitchShift();
}

void CSoftKeyboard::CtrlFunctionKey()
{
    m_bCtrl = !m_bCtrl;
    SwitchCtrl();
}

void CSoftKeyboard::EN_CHFunctionKey()
{
    m_bShift = false; SwitchShift();
    m_bCtrl = false; SwitchCtrl();
    m_bAlt = false; SwitchAlt();
    m_eCurLetterStyle = eLetterStyle_Lowercase; SwitchLetterStyle();
    m_eCurInputStyle = (m_eCurInputStyle == eInputStyle_CH ? eInputStyle_EN : eInputStyle_CH);
    SwitchInputStyle();
}

void CSoftKeyboard::AltFunctionKey()
{
    m_bAlt = !m_bAlt;
    SwitchAlt();
}

void CSoftKeyboard::SpaceFunctionKey()
{
    if(m_eCurInputStyle == eInputStyle_CH && ui->language_Pinyin->isVisible())
        SelectedChinese(1);
    else
        WidgetValueInserted(" ");
}

void CSoftKeyboard::DirFunctionKey()
{

}

void CSoftKeyboard::PgFunctionKey(bool bIsUp)
{
    if(m_eCurInputStyle == eInputStyle_EN || !ui->language_Pinyin->isVisible())
        return;

    bIsUp ? LastPageChinese() : NextPageChinese();
}

void CSoftKeyboard::Key_Left_FunctionKey()
{
	Qt::KeyboardModifiers Modifier = Qt::NoModifier;
	int involvedKeys = 1;
	QString ch = ui->control_ArrowLeft->text();
	QKeyEvent keyEvent(QEvent::KeyPress, Qt::Key_Left, Modifier, ch, false, involvedKeys);
	QApplication::sendEvent(m_CallObj, &keyEvent);
}
void CSoftKeyboard::Key_Right_FunctionKey()
{
	Qt::KeyboardModifiers Modifier = Qt::NoModifier;
	int involvedKeys = 1;
	QString ch = ui->control_ArrowRight->text();
	QKeyEvent keyEvent(QEvent::KeyPress, Qt::Key_Right, Modifier, ch, false, involvedKeys);
	QApplication::sendEvent(m_CallObj, &keyEvent);
}
void CSoftKeyboard::Key_Down_FunctionKey()
{
	Qt::KeyboardModifiers Modifier = Qt::NoModifier;
	int involvedKeys = 1;
	QString ch = ui->control_ArrowDown->text();
	QKeyEvent keyEvent(QEvent::KeyPress, Qt::Key_Down, Modifier, ch, false, involvedKeys);
	QApplication::sendEvent(m_CallObj, &keyEvent);
}
void CSoftKeyboard::Key_Up_FunctionKey()
{
	Qt::KeyboardModifiers Modifier = Qt::NoModifier;
	int involvedKeys = 1;
	QString ch = ui->control_ArrowUp->text();
	QKeyEvent keyEvent(QEvent::KeyPress, Qt::Key_Up, Modifier, ch, false, involvedKeys);
	QApplication::sendEvent(m_CallObj, &keyEvent);
}
void CSoftKeyboard::QueriedChinese()
{
    if(!m_DBSql.isOpen())
        return;

    CleanedChinese();
    QString sql = QString("select word from pinyin where pinyin = '%1' ").arg(ui->language_Pinyin->text());

    QSqlQuery dbQuery(sql, m_DBSql);
    qDebug() << dbQuery.lastError().text();
    while(dbQuery.next())
    {
        m_ListAllPinYin << dbQuery.value(0).toString().split(" ");
    }

    NextPageChinese();
}

void CSoftKeyboard::SelectedChinese(int index)
{
    if(index < 1 || index > 9)
        return;

    QString sValue = "";
    switch (index) {
    case 1: sValue = ui->language_CH1->text(); break;
    case 2: sValue = ui->language_CH2->text(); break;
    case 3: sValue = ui->language_CH3->text(); break;
    case 4: sValue = ui->language_CH4->text(); break;
    case 5: sValue = ui->language_CH5->text(); break;
    case 6: sValue = ui->language_CH6->text(); break;
    case 7: sValue = ui->language_CH7->text(); break;
    case 8: sValue = ui->language_CH8->text(); break;
    case 9: sValue = ui->language_CH9->text(); break;
    default: return;
    }

    if(sValue.isEmpty())
        return;

    WidgetValueInserted(sValue.split(" ").at(1));
    HiddenChinese();
}

void CSoftKeyboard::ShowedChinese(QStringList strList)
{
    int iCount = strList.size();
    if(iCount < st_ShowChNum)
    {
        for(int ii = 0; ii < st_ShowChNum - iCount; ++ii)
            strList.append("");
    }

    ui->language_CH1->setText(strList.at(0).isEmpty() ? "" : "1 " + strList.at(0));
    ui->language_CH2->setText(strList.at(1).isEmpty() ? "" : "2 " + strList.at(1));
    ui->language_CH3->setText(strList.at(2).isEmpty() ? "" : "3 " + strList.at(2));
    ui->language_CH4->setText(strList.at(3).isEmpty() ? "" : "4 " + strList.at(3));
    ui->language_CH5->setText(strList.at(4).isEmpty() ? "" : "5 " + strList.at(4));
    ui->language_CH6->setText(strList.at(5).isEmpty() ? "" : "6 " + strList.at(5));
    ui->language_CH7->setText(strList.at(6).isEmpty() ? "" : "7 " + strList.at(6));
    ui->language_CH8->setText(strList.at(7).isEmpty() ? "" : "8 " + strList.at(7));
    ui->language_CH9->setText(strList.at(8).isEmpty() ? "" : "9 " + strList.at(8));

    ui->language_Pinyin->setVisible(true);
    ui->language_CH1->setVisible(true);
    ui->language_CH2->setVisible(true);
    ui->language_CH3->setVisible(true);
    ui->language_CH4->setVisible(true);
    ui->language_CH5->setVisible(true);
    ui->language_CH6->setVisible(true);
    ui->language_CH7->setVisible(true);
    ui->language_CH8->setVisible(true);
    ui->language_CH9->setVisible(true);
}

void CSoftKeyboard::HiddenChinese()
{
    ui->language_Pinyin->clear();
    ui->language_CH1->clear();
    ui->language_CH2->clear();
    ui->language_CH3->clear();
    ui->language_CH4->clear();
    ui->language_CH5->clear();
    ui->language_CH6->clear();
    ui->language_CH7->clear();
    ui->language_CH8->clear();
    ui->language_CH9->clear();

    ui->language_Pinyin->setVisible(false);
    ui->language_CH1->setVisible(false);
    ui->language_CH2->setVisible(false);
    ui->language_CH3->setVisible(false);
    ui->language_CH4->setVisible(false);
    ui->language_CH5->setVisible(false);
    ui->language_CH6->setVisible(false);
    ui->language_CH7->setVisible(false);
    ui->language_CH8->setVisible(false);
    ui->language_CH9->setVisible(false);
}

void CSoftKeyboard::CleanedChinese()
{
    m_ListAllPinYin.clear();
    m_iCurPinYinPage = 0;
}

void CSoftKeyboard::LastPageChinese()
{
    if(m_iCurPinYinPage <= 1)
        return;

    --m_iCurPinYinPage;
    QStringList strList = m_ListAllPinYin.mid((m_iCurPinYinPage - 1) * st_ShowChNum, st_ShowChNum);
    ShowedChinese(strList);
}

void CSoftKeyboard::NextPageChinese()
{
    int iCount = m_ListAllPinYin.size();
    if(m_iCurPinYinPage >= ceil(iCount / (st_ShowChNum * 1.0)))
        return;

    ++m_iCurPinYinPage;
    QStringList strList = m_ListAllPinYin.mid((m_iCurPinYinPage - 1) * st_ShowChNum, st_ShowChNum);
    ShowedChinese(strList);
}

void CSoftKeyboard::WidgetValueInserted(const QString &value)
{
    if(dynamic_cast<QLineEdit*>(m_CallObj) != Q_NULLPTR)
    {
        QLineEdit* pEdt = dynamic_cast<QLineEdit*>(m_CallObj);
        pEdt->insert(value);
    }

    else if(dynamic_cast<QTextEdit*>(m_CallObj) != Q_NULLPTR)
    {
        QTextEdit* pTextEdt = dynamic_cast<QTextEdit*>(m_CallObj);
        pTextEdt->insertPlainText(value);
    }

    else if(dynamic_cast<QPlainTextEdit*>(m_CallObj) != Q_NULLPTR)
    {
        QPlainTextEdit* pPlainTextEdt = dynamic_cast<QPlainTextEdit*>(m_CallObj);
        pPlainTextEdt->insertPlainText(value);
    }
}

void CSoftKeyboard::DeletedWidgetValue()
{
    if(dynamic_cast<QLineEdit*>(m_CallObj) != Q_NULLPTR)
    {
        QLineEdit* pEdt = dynamic_cast<QLineEdit*>(m_CallObj);
        pEdt->backspace();
    }

    else if(dynamic_cast<QTextEdit*>(m_CallObj) != Q_NULLPTR)
    {
        QTextEdit* pTextEdt = dynamic_cast<QTextEdit*>(m_CallObj);
        QTextCursor cursor = pTextEdt->textCursor();
        if(cursor.hasSelection())
            cursor.removeSelectedText();
        else
            cursor.deletePreviousChar();
    }

    else if(dynamic_cast<QPlainTextEdit*>(m_CallObj) != Q_NULLPTR)
    {
        QPlainTextEdit* pPlainTextEdt = dynamic_cast<QPlainTextEdit*>(m_CallObj);
        QTextCursor cursor = pPlainTextEdt->textCursor();
        if(cursor.hasSelection())
            cursor.removeSelectedText();
        else
            cursor.deletePreviousChar();
    }
}


void CSoftKeyboard::SlotBtnClicked()
{
    QPushButton* pBtn = dynamic_cast<QPushButton*>(this->sender());
    if(pBtn == nullptr)
    {
        pBtn = nullptr;
        return;
    }

    EKey eKey = EKey(pBtn->whatsThis().toInt());
    NumberDealWith(eKey);
    SymbolDealWith(eKey);
    LetterDealWith(eKey);
    FunctionKeyDealWith(eKey);
	QTextEdit* pTextEdt = dynamic_cast<QTextEdit*>(m_CallObj);
	if (pTextEdt != nullptr)
	{
		pTextEdt->setFocus();
	}
	QLineEdit* pLineEdt = dynamic_cast<QLineEdit*>(m_CallObj);
	if (pLineEdt != nullptr)
	{
		pLineEdt->setFocus();
	}
	QDoubleSpinBox* pDoubleSpinBox = dynamic_cast<QDoubleSpinBox*>(m_CallObj);
	if (pDoubleSpinBox != Q_NULLPTR)
	{
		pDoubleSpinBox->setFocus();
	}
}

void CSoftKeyboard::mousePressEvent(QMouseEvent *event)
{
    if (!isHidden() && event->button() == Qt::LeftButton)
    {
        m_bPressed = true;
        m_Point = event->pos();
    }

    QDialog::mousePressEvent(event);
}

void CSoftKeyboard::mouseReleaseEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    m_bPressed = false;
    QDialog::mouseReleaseEvent(event);
}

void CSoftKeyboard::mouseMoveEvent(QMouseEvent *event)
{
    if (m_bPressed)
        move(event->globalPos() - m_Point);

    QDialog::mouseMoveEvent(event);
}

void CSoftKeyboard::showEvent(QShowEvent *event)
{
    m_bPressed = false;
    QDialog::showEvent(event);
}

void CSoftKeyboard::closeEvent(QCloseEvent *event)
{
    HiddenChinese();
    QDialog::closeEvent(event);
}

void CSoftKeyboard::SwitchInputStyle()
{
    switch (m_eCurInputStyle) {
    case eInputStyle_EN:
        ui->control_Language->setText("EN");
        HiddenChinese();
        break;
    case eInputStyle_CH:
        ui->control_Language->setText("CH");
        break;
    default: break;
    }
}

void CSoftKeyboard::SwitchLetterStyle()
{
    ui->letter_Q->setText((m_eCurLetterStyle == eLetterStyle_Capital) ? "Q" : "q");
    ui->letter_W->setText((m_eCurLetterStyle == eLetterStyle_Capital) ? "W" : "w");
    ui->letter_E->setText((m_eCurLetterStyle == eLetterStyle_Capital) ? "E" : "e");
    ui->letter_R->setText((m_eCurLetterStyle == eLetterStyle_Capital) ? "R" : "r");
    ui->letter_T->setText((m_eCurLetterStyle == eLetterStyle_Capital) ? "T" : "t");
    ui->letter_Y->setText((m_eCurLetterStyle == eLetterStyle_Capital) ? "Y" : "y");
    ui->letter_U->setText((m_eCurLetterStyle == eLetterStyle_Capital) ? "U" : "u");
    ui->letter_I->setText((m_eCurLetterStyle == eLetterStyle_Capital) ? "I" : "i");
    ui->letter_O->setText((m_eCurLetterStyle == eLetterStyle_Capital) ? "O" : "o");
    ui->letter_P->setText((m_eCurLetterStyle == eLetterStyle_Capital) ? "P" : "p");
    ui->letter_A->setText((m_eCurLetterStyle == eLetterStyle_Capital) ? "A" : "a");
    ui->letter_S->setText((m_eCurLetterStyle == eLetterStyle_Capital) ? "S" : "s");
    ui->letter_D->setText((m_eCurLetterStyle == eLetterStyle_Capital) ? "D" : "d");
    ui->letter_F->setText((m_eCurLetterStyle == eLetterStyle_Capital) ? "F" : "f");
    ui->letter_G->setText((m_eCurLetterStyle == eLetterStyle_Capital) ? "G" : "g");
    ui->letter_H->setText((m_eCurLetterStyle == eLetterStyle_Capital) ? "H" : "h");
    ui->letter_J->setText((m_eCurLetterStyle == eLetterStyle_Capital) ? "J" : "j");
    ui->letter_K->setText((m_eCurLetterStyle == eLetterStyle_Capital) ? "K" : "k");
    ui->letter_L->setText((m_eCurLetterStyle == eLetterStyle_Capital) ? "L" : "l");
    ui->letter_Z->setText((m_eCurLetterStyle == eLetterStyle_Capital) ? "Z" : "z");
    ui->letter_X->setText((m_eCurLetterStyle == eLetterStyle_Capital) ? "X" : "x");
    ui->letter_C->setText((m_eCurLetterStyle == eLetterStyle_Capital) ? "C" : "c");
    ui->letter_V->setText((m_eCurLetterStyle == eLetterStyle_Capital) ? "V" : "v");
    ui->letter_B->setText((m_eCurLetterStyle == eLetterStyle_Capital) ? "B" : "b");
    ui->letter_N->setText((m_eCurLetterStyle == eLetterStyle_Capital) ? "N" : "n");
    ui->letter_M->setText((m_eCurLetterStyle == eLetterStyle_Capital) ? "M" : "m");

    // ï¿½ï¿½ï¿½ï¿½CapsLockï¿½Ä·ï¿½ï¿½ï¿½
}

void CSoftKeyboard::SwitchShift()
{

}

void CSoftKeyboard::SwitchCtrl()
{

}

void CSoftKeyboard::SwitchAlt()
{

}
void CSoftKeyboard::setDialog()
{
	if (dynamic_cast<QLineEdit*>(m_CallObj) != Q_NULLPTR)
	{
		QLineEdit* pEdt = dynamic_cast<QLineEdit*>(m_CallObj);
		if (pEdt->validator() != nullptr)
		{
			if (pEdt->validator()->inherits("QIntValidator") || pEdt->validator()->inherits("QDoubleValidator"))
			{
				ui->stackedWidget->setCurrentIndex(ePageStyle_OnlyNumber);
				return;
			}
		}
	}
	if (dynamic_cast<QDoubleSpinBox*>(m_CallObj) != Q_NULLPTR)
	{
		ui->stackedWidget->setCurrentIndex(ePageStyle_OnlyNumber);
		return;
	}
	ui->stackedWidget->setCurrentIndex(ePageStyle_All);
}


void RegisterObject(QObject *obj)
{
    CSoftKeyboard::GetInstance().registerObject(obj);
}

void ShowKeyboard()
{
	CSoftKeyboard::GetInstance().setDialog();
	QDesktopWidget *pDesktopWidget = QApplication::desktop();
	QPoint movePoint;
	if (QCursor::pos().y() > pDesktopWidget->height() / 2)
		// ¿¿ÉÏ¾ÓÖÐÏÔÊ¾
	{
		movePoint = QPoint(pDesktopWidget->height() / 2 - 300, 0);
	}
	else
	{
		// ¿¿ÏÂ¾ÓÖÐÏÔÊ¾
		movePoint = QPoint(pDesktopWidget->height() / 2 - 300, pDesktopWidget->height() - 400);
	}
	CSoftKeyboard::GetInstance().move(movePoint);
    CSoftKeyboard::GetInstance().show();
}


