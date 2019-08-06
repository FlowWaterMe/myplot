#ifndef SOFTKEYBOARD_DLL_H
#define SOFTKEYBOARD_DLL_H

#include <QDialog>
#include <QSqlDatabase>
#include <QLineEdit>
#include <QTextEdit>
#include <QPlainTextEdit>
#include <QPoint>
#include "softkeyboard_dll_global.h"
#include <QDeskTopWidget>
namespace Ui {
class SoftKeyboard;
}

class SOFTKEYBOARD_DLLSHARED_EXPORT CSoftKeyboard : public QDialog
{
    Q_OBJECT

public:
    static CSoftKeyboard &GetInstance();
    ~CSoftKeyboard();

    void registerObject(QObject *obj);
	void setDialog();
private:
    enum EKey
    {
        eKey_Symbol1 = 0,  //  ~ `
        eKey_Number1,
        eKey_Number2,
        eKey_Number3,
        eKey_Number4,
        eKey_Number5,
        eKey_Number6,
        eKey_Number7,
        eKey_Number8,
        eKey_Number9,
        eKey_Number0,
        eKey_Symbol2,       //  _ -
        eKey_Symbol3,       //  + =
        eKey_Backspace,

        eKey_Tab,
        eKey_Q,
        eKey_W,
        eKey_E,
        eKey_R,
        eKey_T,
        eKey_Y,
        eKey_U,
        eKey_I,
        eKey_O,
        eKey_P,
        eKey_Symbol4,        // { [
        eKey_Symbol5,        // } ]
        eKey_Symbol6,        // |

        eKey_CapsLock,
        eKey_A,
        eKey_S,
        eKey_D,
        eKey_F,
        eKey_G,
        eKey_H,
        eKey_J,
        eKey_K,
        eKey_L,
        eKey_Symbol7,           //  : ;
        eKey_Symbol8,           //  " '
        eKey_Enter,

        eKey_Shift,
        eKey_Z,
        eKey_X,
        eKey_C,
        eKey_V,
        eKey_B,
        eKey_N,
        eKey_M,
        eKey_Symbol9,           // < ,
        eKey_Symbol10,          // > .
        eKey_Symbol11,          // ? /
        eKey_PgUp,
        eKey_Up,                // ио
        eKey_PgDn,

        eKey_Ctrl,
        eKey_EN_CH,
        eKey_Alt,
        eKey_Space,
        eKey_Left,
        eKey_Down,
        eKey_Right,
    };

    enum ELetterStyle
    {
        eLetterStyle_Capital = 0,
        eLetterStyle_Lowercase,
    };

    enum EInputStyle
    {
        eInputStyle_EN = 0,
        eInputStyle_CH,
    };

	enum EPageStyle
	{
		ePageStyle_All = 0,
		ePageStyle_OnlyNumber,
	};

private:
    void InitKeyboard();

    void InitPinyinDB();
    void UninitPinyinDB();

    void SymbolDealWith(EKey eKey);
    void NumberDealWith(EKey eKey);
    void LetterDealWith(EKey eKey);
    void FunctionKeyDealWith(EKey eKey);

    void BackspaceFunctionKey();
    void TabFunctionKey();
    void CapsLockFunctionKey();
    void EnterFunctionKey();
    void ShiftFunctionKey();
    void CtrlFunctionKey();
    void EN_CHFunctionKey();
    void AltFunctionKey();
    void SpaceFunctionKey();
    void DirFunctionKey();
    void PgFunctionKey(bool bIsUp);

    void QueriedChinese();
    void SelectedChinese(int index);
    void CleanedChinese();
    void ShowedChinese(QStringList strList);
    void HiddenChinese();
    void LastPageChinese();
    void NextPageChinese();

    void WidgetValueInserted(const QString& value);
    void DeletedWidgetValue();

    void SwitchInputStyle();
    void SwitchLetterStyle();
    void SwitchShift();
    void SwitchCtrl();
    void SwitchAlt();

private Q_SLOTS:
    void SlotBtnClicked();

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void showEvent(QShowEvent *event) override;
    void closeEvent(QCloseEvent *event) override;

private:
    Ui::SoftKeyboard *ui;

    static CSoftKeyboard *st_pKeyboard;

    QSqlDatabase    m_DBSql;
    QString         m_DBName;
    QObject*        m_CallObj;

    QStringList m_ListAllPinYin;
    int m_iCurPinYinPage;

    EInputStyle m_eCurInputStyle;
    ELetterStyle m_eCurLetterStyle;
    bool m_bShift;
    bool m_bCtrl;
    bool m_bAlt;

    bool m_bPressed;
    QPoint m_Point;
    explicit CSoftKeyboard(QWidget *parent = 0);
};

extern "C" Q_DECL_EXPORT void RegisterObject(QObject* obj);
extern "C" Q_DECL_EXPORT void ShowKeyboard();


#endif // SOFTKEYBOARD_DLL_H
