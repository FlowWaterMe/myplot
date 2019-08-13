/********************************************************************************
** Form generated from reading UI file 'SoftKeyboard.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SOFTKEYBOARD_H
#define UI_SOFTKEYBOARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SoftKeyboard
{
public:
    QGridLayout *gridLayout;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QGridLayout *gridLayout_2;
    QGridLayout *keyboardPanel;
    QPushButton *symbol_BarBackslash;
    QPushButton *control_CapsLock;
    QPushButton *symbol_BraceLeftBracketLeft;
    QPushButton *letter_P;
    QPushButton *letter_D;
    QPushButton *letter_S;
    QPushButton *letter_A;
    QPushButton *letter_F;
    QPushButton *letter_J;
    QPushButton *letter_G;
    QPushButton *letter_H;
    QPushButton *symbol_AsciiTildeQuote;
    QPushButton *number_1;
    QPushButton *number_2;
    QPushButton *number_5;
    QPushButton *number_6;
    QPushButton *number_4;
    QPushButton *number_3;
    QPushButton *number_8;
    QPushButton *number_0;
    QPushButton *number_9;
    QPushButton *number_7;
    QPushButton *symbol_PlusEqual;
    QPushButton *symbol_MinusUnderscore;
    QPushButton *control_Tab;
    QPushButton *letter_Q;
    QPushButton *letter_W;
    QPushButton *letter_E;
    QPushButton *letter_R;
    QPushButton *letter_U;
    QPushButton *letter_T;
    QPushButton *letter_Y;
    QPushButton *letter_I;
    QPushButton *letter_O;
    QPushButton *symbol_ColonSemicolon;
    QPushButton *symbol_QuoteDblApostrophe;
    QPushButton *letter_L;
    QPushButton *letter_K;
    QPushButton *control_LeftShift;
    QPushButton *letter_Z;
    QPushButton *control_Enter;
    QPushButton *letter_X;
    QPushButton *letter_C;
    QPushButton *letter_V;
    QPushButton *letter_B;
    QPushButton *letter_N;
    QPushButton *symbol_LessComma;
    QPushButton *letter_M;
    QPushButton *symbol_GreaterPeriod;
    QPushButton *control_ArrowUp;
    QPushButton *symbol_QuestionSlash;
    QPushButton *control_PageUp;
    QPushButton *control_LeftCtrl;
    QPushButton *control_Language;
    QPushButton *control_PageDown;
    QPushButton *control_ArrowDown;
    QPushButton *control_ArrowLeft;
    QPushButton *control_LeftAlt;
    QPushButton *control_Space;
    QPushButton *symbol_BraceRightBracketRight;
    QPushButton *control_ArrowRight;
    QPushButton *control_Backspace;
    QPushButton *control_Disable;
    QLabel *language_Pinyin;
    QLabel *language_CH1;
    QLabel *language_CH2;
    QLabel *language_CH3;
    QLabel *language_CH4;
    QLabel *language_CH5;
    QLabel *language_CH6;
    QLabel *language_CH7;
    QLabel *language_CH8;
    QLabel *language_CH9;
    QWidget *page_num;
    QGridLayout *gridLayout_3;
    QGridLayout *keyboardPanel_number;
    QPushButton *control_Enter_num;
    QPushButton *number_D3;
    QPushButton *number_D6;
    QPushButton *number_D7;
    QPushButton *number_D4;
    QPushButton *number_D8;
    QPushButton *number_D1;
    QPushButton *number_D9;
    QPushButton *number_D5;
    QPushButton *number_D0;
    QPushButton *number_D2;
    QPushButton *symbol_GreaterPeriod_num;
    QPushButton *control_Backspace_num;

    void setupUi(QDialog *SoftKeyboard)
    {
        if (SoftKeyboard->objectName().isEmpty())
            SoftKeyboard->setObjectName(QStringLiteral("SoftKeyboard"));
        SoftKeyboard->resize(825, 385);
        SoftKeyboard->setMinimumSize(QSize(800, 280));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(12);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        SoftKeyboard->setFont(font);
        SoftKeyboard->setFocusPolicy(Qt::ClickFocus);
        SoftKeyboard->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	\n"
"	font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"	background-color: rgb(38, 35, 33);\n"
"	color: white;\n"
"}\n"
"\n"
"QLabel\n"
"{\n"
"	color: rgb(38, 35, 33);\n"
"}\n"
"\n"
"QDialog\n"
"{\n"
"	border: 1px solid gray;\n"
"}\n"
""));
        SoftKeyboard->setSizeGripEnabled(true);
        SoftKeyboard->setModal(false);
        gridLayout = new QGridLayout(SoftKeyboard);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        stackedWidget = new QStackedWidget(SoftKeyboard);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setAcceptDrops(false);
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        gridLayout_2 = new QGridLayout(page);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(9, 20, 9, 20);
        keyboardPanel = new QGridLayout();
        keyboardPanel->setSpacing(2);
        keyboardPanel->setObjectName(QStringLiteral("keyboardPanel"));
        keyboardPanel->setContentsMargins(-1, 0, -1, -1);
        symbol_BarBackslash = new QPushButton(page);
        symbol_BarBackslash->setObjectName(QStringLiteral("symbol_BarBackslash"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(symbol_BarBackslash->sizePolicy().hasHeightForWidth());
        symbol_BarBackslash->setSizePolicy(sizePolicy);
        symbol_BarBackslash->setMinimumSize(QSize(50, 32));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(10);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(50);
        symbol_BarBackslash->setFont(font1);
        symbol_BarBackslash->setFocusPolicy(Qt::NoFocus);
        symbol_BarBackslash->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	text-align: center;\n"
"}"));
        symbol_BarBackslash->setAutoDefault(false);

        keyboardPanel->addWidget(symbol_BarBackslash, 1, 38, 1, 2);

        control_CapsLock = new QPushButton(page);
        control_CapsLock->setObjectName(QStringLiteral("control_CapsLock"));
        sizePolicy.setHeightForWidth(control_CapsLock->sizePolicy().hasHeightForWidth());
        control_CapsLock->setSizePolicy(sizePolicy);
        control_CapsLock->setMinimumSize(QSize(75, 32));
        control_CapsLock->setFont(font1);
        control_CapsLock->setFocusPolicy(Qt::NoFocus);
        control_CapsLock->setCheckable(true);
        control_CapsLock->setAutoDefault(false);

        keyboardPanel->addWidget(control_CapsLock, 2, 0, 1, 3);

        symbol_BraceLeftBracketLeft = new QPushButton(page);
        symbol_BraceLeftBracketLeft->setObjectName(QStringLiteral("symbol_BraceLeftBracketLeft"));
        sizePolicy.setHeightForWidth(symbol_BraceLeftBracketLeft->sizePolicy().hasHeightForWidth());
        symbol_BraceLeftBracketLeft->setSizePolicy(sizePolicy);
        symbol_BraceLeftBracketLeft->setMinimumSize(QSize(36, 32));
        symbol_BraceLeftBracketLeft->setFont(font1);
        symbol_BraceLeftBracketLeft->setFocusPolicy(Qt::NoFocus);
        symbol_BraceLeftBracketLeft->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	text-align: center;\n"
"}"));
        symbol_BraceLeftBracketLeft->setAutoDefault(false);

        keyboardPanel->addWidget(symbol_BraceLeftBracketLeft, 1, 32, 1, 3);

        letter_P = new QPushButton(page);
        letter_P->setObjectName(QStringLiteral("letter_P"));
        sizePolicy.setHeightForWidth(letter_P->sizePolicy().hasHeightForWidth());
        letter_P->setSizePolicy(sizePolicy);
        letter_P->setMinimumSize(QSize(36, 32));
        letter_P->setFont(font1);
        letter_P->setFocusPolicy(Qt::NoFocus);
        letter_P->setAutoDefault(false);

        keyboardPanel->addWidget(letter_P, 1, 29, 1, 3);

        letter_D = new QPushButton(page);
        letter_D->setObjectName(QStringLiteral("letter_D"));
        sizePolicy.setHeightForWidth(letter_D->sizePolicy().hasHeightForWidth());
        letter_D->setSizePolicy(sizePolicy);
        letter_D->setMinimumSize(QSize(36, 32));
        letter_D->setFont(font1);
        letter_D->setFocusPolicy(Qt::NoFocus);
        letter_D->setAutoDefault(false);

        keyboardPanel->addWidget(letter_D, 2, 9, 1, 3);

        letter_S = new QPushButton(page);
        letter_S->setObjectName(QStringLiteral("letter_S"));
        sizePolicy.setHeightForWidth(letter_S->sizePolicy().hasHeightForWidth());
        letter_S->setSizePolicy(sizePolicy);
        letter_S->setMinimumSize(QSize(36, 32));
        letter_S->setFont(font1);
        letter_S->setFocusPolicy(Qt::NoFocus);
        letter_S->setAutoDefault(false);

        keyboardPanel->addWidget(letter_S, 2, 6, 1, 3);

        letter_A = new QPushButton(page);
        letter_A->setObjectName(QStringLiteral("letter_A"));
        sizePolicy.setHeightForWidth(letter_A->sizePolicy().hasHeightForWidth());
        letter_A->setSizePolicy(sizePolicy);
        letter_A->setMinimumSize(QSize(36, 32));
        letter_A->setFont(font1);
        letter_A->setFocusPolicy(Qt::NoFocus);
        letter_A->setAutoDefault(false);

        keyboardPanel->addWidget(letter_A, 2, 3, 1, 3);

        letter_F = new QPushButton(page);
        letter_F->setObjectName(QStringLiteral("letter_F"));
        sizePolicy.setHeightForWidth(letter_F->sizePolicy().hasHeightForWidth());
        letter_F->setSizePolicy(sizePolicy);
        letter_F->setMinimumSize(QSize(36, 32));
        letter_F->setFont(font1);
        letter_F->setFocusPolicy(Qt::NoFocus);
        letter_F->setAutoDefault(false);

        keyboardPanel->addWidget(letter_F, 2, 12, 1, 3);

        letter_J = new QPushButton(page);
        letter_J->setObjectName(QStringLiteral("letter_J"));
        sizePolicy.setHeightForWidth(letter_J->sizePolicy().hasHeightForWidth());
        letter_J->setSizePolicy(sizePolicy);
        letter_J->setMinimumSize(QSize(36, 32));
        letter_J->setFont(font1);
        letter_J->setFocusPolicy(Qt::NoFocus);
        letter_J->setAutoDefault(false);

        keyboardPanel->addWidget(letter_J, 2, 21, 1, 3);

        letter_G = new QPushButton(page);
        letter_G->setObjectName(QStringLiteral("letter_G"));
        sizePolicy.setHeightForWidth(letter_G->sizePolicy().hasHeightForWidth());
        letter_G->setSizePolicy(sizePolicy);
        letter_G->setMinimumSize(QSize(36, 32));
        letter_G->setFont(font1);
        letter_G->setFocusPolicy(Qt::NoFocus);
        letter_G->setAutoDefault(false);

        keyboardPanel->addWidget(letter_G, 2, 15, 1, 3);

        letter_H = new QPushButton(page);
        letter_H->setObjectName(QStringLiteral("letter_H"));
        sizePolicy.setHeightForWidth(letter_H->sizePolicy().hasHeightForWidth());
        letter_H->setSizePolicy(sizePolicy);
        letter_H->setMinimumSize(QSize(36, 32));
        letter_H->setFont(font1);
        letter_H->setFocusPolicy(Qt::NoFocus);
        letter_H->setAutoDefault(false);

        keyboardPanel->addWidget(letter_H, 2, 18, 1, 3);

        symbol_AsciiTildeQuote = new QPushButton(page);
        symbol_AsciiTildeQuote->setObjectName(QStringLiteral("symbol_AsciiTildeQuote"));
        sizePolicy.setHeightForWidth(symbol_AsciiTildeQuote->sizePolicy().hasHeightForWidth());
        symbol_AsciiTildeQuote->setSizePolicy(sizePolicy);
        symbol_AsciiTildeQuote->setMinimumSize(QSize(36, 32));
        symbol_AsciiTildeQuote->setFont(font1);
        symbol_AsciiTildeQuote->setFocusPolicy(Qt::NoFocus);
        symbol_AsciiTildeQuote->setLayoutDirection(Qt::LeftToRight);
        symbol_AsciiTildeQuote->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	text-align: center;\n"
"}"));
        symbol_AsciiTildeQuote->setAutoDefault(false);

        keyboardPanel->addWidget(symbol_AsciiTildeQuote, 0, 0, 1, 1);

        number_1 = new QPushButton(page);
        number_1->setObjectName(QStringLiteral("number_1"));
        sizePolicy.setHeightForWidth(number_1->sizePolicy().hasHeightForWidth());
        number_1->setSizePolicy(sizePolicy);
        number_1->setMinimumSize(QSize(36, 32));
        number_1->setFont(font1);
        number_1->setFocusPolicy(Qt::NoFocus);
        number_1->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	text-align: center;\n"
"}"));
        number_1->setAutoDefault(false);

        keyboardPanel->addWidget(number_1, 0, 1, 1, 3);

        number_2 = new QPushButton(page);
        number_2->setObjectName(QStringLiteral("number_2"));
        sizePolicy.setHeightForWidth(number_2->sizePolicy().hasHeightForWidth());
        number_2->setSizePolicy(sizePolicy);
        number_2->setMinimumSize(QSize(36, 32));
        number_2->setFont(font1);
        number_2->setFocusPolicy(Qt::NoFocus);
        number_2->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	text-align: center;\n"
"}"));
        number_2->setAutoDefault(false);

        keyboardPanel->addWidget(number_2, 0, 4, 1, 3);

        number_5 = new QPushButton(page);
        number_5->setObjectName(QStringLiteral("number_5"));
        sizePolicy.setHeightForWidth(number_5->sizePolicy().hasHeightForWidth());
        number_5->setSizePolicy(sizePolicy);
        number_5->setMinimumSize(QSize(36, 32));
        number_5->setFont(font1);
        number_5->setFocusPolicy(Qt::NoFocus);
        number_5->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	text-align: center;\n"
"}"));
        number_5->setAutoDefault(false);

        keyboardPanel->addWidget(number_5, 0, 13, 1, 3);

        number_6 = new QPushButton(page);
        number_6->setObjectName(QStringLiteral("number_6"));
        sizePolicy.setHeightForWidth(number_6->sizePolicy().hasHeightForWidth());
        number_6->setSizePolicy(sizePolicy);
        number_6->setMinimumSize(QSize(36, 32));
        number_6->setFont(font1);
        number_6->setFocusPolicy(Qt::NoFocus);
        number_6->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	text-align: center;\n"
"}"));
        number_6->setAutoDefault(false);

        keyboardPanel->addWidget(number_6, 0, 16, 1, 3);

        number_4 = new QPushButton(page);
        number_4->setObjectName(QStringLiteral("number_4"));
        sizePolicy.setHeightForWidth(number_4->sizePolicy().hasHeightForWidth());
        number_4->setSizePolicy(sizePolicy);
        number_4->setMinimumSize(QSize(36, 32));
        number_4->setFont(font1);
        number_4->setFocusPolicy(Qt::NoFocus);
        number_4->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	text-align: center;\n"
"}"));
        number_4->setAutoDefault(false);

        keyboardPanel->addWidget(number_4, 0, 10, 1, 3);

        number_3 = new QPushButton(page);
        number_3->setObjectName(QStringLiteral("number_3"));
        sizePolicy.setHeightForWidth(number_3->sizePolicy().hasHeightForWidth());
        number_3->setSizePolicy(sizePolicy);
        number_3->setMinimumSize(QSize(36, 32));
        number_3->setFont(font1);
        number_3->setFocusPolicy(Qt::NoFocus);
        number_3->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	text-align: center;\n"
"}"));
        number_3->setAutoDefault(false);

        keyboardPanel->addWidget(number_3, 0, 7, 1, 3);

        number_8 = new QPushButton(page);
        number_8->setObjectName(QStringLiteral("number_8"));
        sizePolicy.setHeightForWidth(number_8->sizePolicy().hasHeightForWidth());
        number_8->setSizePolicy(sizePolicy);
        number_8->setMinimumSize(QSize(36, 32));
        number_8->setFont(font1);
        number_8->setFocusPolicy(Qt::NoFocus);
        number_8->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	text-align: center;\n"
"}"));
        number_8->setAutoDefault(false);

        keyboardPanel->addWidget(number_8, 0, 22, 1, 3);

        number_0 = new QPushButton(page);
        number_0->setObjectName(QStringLiteral("number_0"));
        sizePolicy.setHeightForWidth(number_0->sizePolicy().hasHeightForWidth());
        number_0->setSizePolicy(sizePolicy);
        number_0->setMinimumSize(QSize(36, 32));
        number_0->setFont(font1);
        number_0->setFocusPolicy(Qt::NoFocus);
        number_0->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	text-align: center;\n"
"}"));
        number_0->setAutoDefault(false);

        keyboardPanel->addWidget(number_0, 0, 28, 1, 3);

        number_9 = new QPushButton(page);
        number_9->setObjectName(QStringLiteral("number_9"));
        sizePolicy.setHeightForWidth(number_9->sizePolicy().hasHeightForWidth());
        number_9->setSizePolicy(sizePolicy);
        number_9->setMinimumSize(QSize(36, 32));
        number_9->setFont(font1);
        number_9->setFocusPolicy(Qt::NoFocus);
        number_9->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	text-align: center;\n"
"}"));
        number_9->setAutoDefault(false);

        keyboardPanel->addWidget(number_9, 0, 25, 1, 3);

        number_7 = new QPushButton(page);
        number_7->setObjectName(QStringLiteral("number_7"));
        sizePolicy.setHeightForWidth(number_7->sizePolicy().hasHeightForWidth());
        number_7->setSizePolicy(sizePolicy);
        number_7->setMinimumSize(QSize(36, 32));
        number_7->setFont(font1);
        number_7->setFocusPolicy(Qt::NoFocus);
        number_7->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	text-align: center;\n"
"}"));
        number_7->setAutoDefault(false);

        keyboardPanel->addWidget(number_7, 0, 19, 1, 3);

        symbol_PlusEqual = new QPushButton(page);
        symbol_PlusEqual->setObjectName(QStringLiteral("symbol_PlusEqual"));
        sizePolicy.setHeightForWidth(symbol_PlusEqual->sizePolicy().hasHeightForWidth());
        symbol_PlusEqual->setSizePolicy(sizePolicy);
        symbol_PlusEqual->setMinimumSize(QSize(36, 32));
        symbol_PlusEqual->setFont(font1);
        symbol_PlusEqual->setFocusPolicy(Qt::NoFocus);
        symbol_PlusEqual->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	text-align: center;\n"
"}"));
        symbol_PlusEqual->setAutoDefault(false);

        keyboardPanel->addWidget(symbol_PlusEqual, 0, 34, 1, 3);

        symbol_MinusUnderscore = new QPushButton(page);
        symbol_MinusUnderscore->setObjectName(QStringLiteral("symbol_MinusUnderscore"));
        sizePolicy.setHeightForWidth(symbol_MinusUnderscore->sizePolicy().hasHeightForWidth());
        symbol_MinusUnderscore->setSizePolicy(sizePolicy);
        symbol_MinusUnderscore->setMinimumSize(QSize(36, 32));
        symbol_MinusUnderscore->setFont(font1);
        symbol_MinusUnderscore->setFocusPolicy(Qt::NoFocus);
        symbol_MinusUnderscore->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	text-align: center;\n"
"}"));
        symbol_MinusUnderscore->setAutoDefault(false);

        keyboardPanel->addWidget(symbol_MinusUnderscore, 0, 31, 1, 3);

        control_Tab = new QPushButton(page);
        control_Tab->setObjectName(QStringLiteral("control_Tab"));
        sizePolicy.setHeightForWidth(control_Tab->sizePolicy().hasHeightForWidth());
        control_Tab->setSizePolicy(sizePolicy);
        control_Tab->setMinimumSize(QSize(60, 32));
        control_Tab->setFont(font1);
        control_Tab->setFocusPolicy(Qt::NoFocus);
        control_Tab->setAutoDefault(false);

        keyboardPanel->addWidget(control_Tab, 1, 0, 1, 2);

        letter_Q = new QPushButton(page);
        letter_Q->setObjectName(QStringLiteral("letter_Q"));
        sizePolicy.setHeightForWidth(letter_Q->sizePolicy().hasHeightForWidth());
        letter_Q->setSizePolicy(sizePolicy);
        letter_Q->setMinimumSize(QSize(36, 32));
        letter_Q->setFont(font1);
        letter_Q->setFocusPolicy(Qt::NoFocus);
        letter_Q->setAutoDefault(false);

        keyboardPanel->addWidget(letter_Q, 1, 2, 1, 3);

        letter_W = new QPushButton(page);
        letter_W->setObjectName(QStringLiteral("letter_W"));
        sizePolicy.setHeightForWidth(letter_W->sizePolicy().hasHeightForWidth());
        letter_W->setSizePolicy(sizePolicy);
        letter_W->setMinimumSize(QSize(36, 32));
        letter_W->setFont(font1);
        letter_W->setFocusPolicy(Qt::NoFocus);
        letter_W->setAutoDefault(false);

        keyboardPanel->addWidget(letter_W, 1, 5, 1, 3);

        letter_E = new QPushButton(page);
        letter_E->setObjectName(QStringLiteral("letter_E"));
        sizePolicy.setHeightForWidth(letter_E->sizePolicy().hasHeightForWidth());
        letter_E->setSizePolicy(sizePolicy);
        letter_E->setMinimumSize(QSize(36, 32));
        letter_E->setFont(font1);
        letter_E->setFocusPolicy(Qt::NoFocus);
        letter_E->setAutoDefault(false);

        keyboardPanel->addWidget(letter_E, 1, 8, 1, 3);

        letter_R = new QPushButton(page);
        letter_R->setObjectName(QStringLiteral("letter_R"));
        sizePolicy.setHeightForWidth(letter_R->sizePolicy().hasHeightForWidth());
        letter_R->setSizePolicy(sizePolicy);
        letter_R->setMinimumSize(QSize(36, 32));
        letter_R->setFont(font1);
        letter_R->setFocusPolicy(Qt::NoFocus);
        letter_R->setAutoDefault(false);

        keyboardPanel->addWidget(letter_R, 1, 11, 1, 3);

        letter_U = new QPushButton(page);
        letter_U->setObjectName(QStringLiteral("letter_U"));
        sizePolicy.setHeightForWidth(letter_U->sizePolicy().hasHeightForWidth());
        letter_U->setSizePolicy(sizePolicy);
        letter_U->setMinimumSize(QSize(36, 32));
        letter_U->setFont(font1);
        letter_U->setFocusPolicy(Qt::NoFocus);
        letter_U->setAutoDefault(false);

        keyboardPanel->addWidget(letter_U, 1, 20, 1, 3);

        letter_T = new QPushButton(page);
        letter_T->setObjectName(QStringLiteral("letter_T"));
        sizePolicy.setHeightForWidth(letter_T->sizePolicy().hasHeightForWidth());
        letter_T->setSizePolicy(sizePolicy);
        letter_T->setMinimumSize(QSize(36, 32));
        letter_T->setFont(font1);
        letter_T->setFocusPolicy(Qt::NoFocus);
        letter_T->setAutoDefault(false);

        keyboardPanel->addWidget(letter_T, 1, 14, 1, 3);

        letter_Y = new QPushButton(page);
        letter_Y->setObjectName(QStringLiteral("letter_Y"));
        sizePolicy.setHeightForWidth(letter_Y->sizePolicy().hasHeightForWidth());
        letter_Y->setSizePolicy(sizePolicy);
        letter_Y->setMinimumSize(QSize(36, 32));
        letter_Y->setFont(font1);
        letter_Y->setFocusPolicy(Qt::NoFocus);
        letter_Y->setAutoDefault(false);

        keyboardPanel->addWidget(letter_Y, 1, 17, 1, 3);

        letter_I = new QPushButton(page);
        letter_I->setObjectName(QStringLiteral("letter_I"));
        sizePolicy.setHeightForWidth(letter_I->sizePolicy().hasHeightForWidth());
        letter_I->setSizePolicy(sizePolicy);
        letter_I->setMinimumSize(QSize(36, 32));
        letter_I->setFont(font1);
        letter_I->setFocusPolicy(Qt::NoFocus);
        letter_I->setAutoDefault(false);

        keyboardPanel->addWidget(letter_I, 1, 23, 1, 3);

        letter_O = new QPushButton(page);
        letter_O->setObjectName(QStringLiteral("letter_O"));
        sizePolicy.setHeightForWidth(letter_O->sizePolicy().hasHeightForWidth());
        letter_O->setSizePolicy(sizePolicy);
        letter_O->setMinimumSize(QSize(36, 32));
        letter_O->setFont(font1);
        letter_O->setFocusPolicy(Qt::NoFocus);
        letter_O->setAutoDefault(false);

        keyboardPanel->addWidget(letter_O, 1, 26, 1, 3);

        symbol_ColonSemicolon = new QPushButton(page);
        symbol_ColonSemicolon->setObjectName(QStringLiteral("symbol_ColonSemicolon"));
        sizePolicy.setHeightForWidth(symbol_ColonSemicolon->sizePolicy().hasHeightForWidth());
        symbol_ColonSemicolon->setSizePolicy(sizePolicy);
        symbol_ColonSemicolon->setMinimumSize(QSize(36, 32));
        symbol_ColonSemicolon->setFont(font1);
        symbol_ColonSemicolon->setFocusPolicy(Qt::NoFocus);
        symbol_ColonSemicolon->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	text-align: center;\n"
"}"));
        symbol_ColonSemicolon->setAutoDefault(false);

        keyboardPanel->addWidget(symbol_ColonSemicolon, 2, 30, 1, 3);

        symbol_QuoteDblApostrophe = new QPushButton(page);
        symbol_QuoteDblApostrophe->setObjectName(QStringLiteral("symbol_QuoteDblApostrophe"));
        sizePolicy.setHeightForWidth(symbol_QuoteDblApostrophe->sizePolicy().hasHeightForWidth());
        symbol_QuoteDblApostrophe->setSizePolicy(sizePolicy);
        symbol_QuoteDblApostrophe->setMinimumSize(QSize(36, 32));
        symbol_QuoteDblApostrophe->setFont(font1);
        symbol_QuoteDblApostrophe->setFocusPolicy(Qt::NoFocus);
        symbol_QuoteDblApostrophe->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	text-align: center;\n"
"}"));
        symbol_QuoteDblApostrophe->setAutoDefault(false);

        keyboardPanel->addWidget(symbol_QuoteDblApostrophe, 2, 33, 1, 3);

        letter_L = new QPushButton(page);
        letter_L->setObjectName(QStringLiteral("letter_L"));
        sizePolicy.setHeightForWidth(letter_L->sizePolicy().hasHeightForWidth());
        letter_L->setSizePolicy(sizePolicy);
        letter_L->setMinimumSize(QSize(36, 32));
        letter_L->setFont(font1);
        letter_L->setFocusPolicy(Qt::NoFocus);
        letter_L->setAutoDefault(false);

        keyboardPanel->addWidget(letter_L, 2, 27, 1, 3);

        letter_K = new QPushButton(page);
        letter_K->setObjectName(QStringLiteral("letter_K"));
        sizePolicy.setHeightForWidth(letter_K->sizePolicy().hasHeightForWidth());
        letter_K->setSizePolicy(sizePolicy);
        letter_K->setMinimumSize(QSize(36, 32));
        letter_K->setFont(font1);
        letter_K->setFocusPolicy(Qt::NoFocus);
        letter_K->setAutoDefault(false);

        keyboardPanel->addWidget(letter_K, 2, 24, 1, 3);

        control_LeftShift = new QPushButton(page);
        control_LeftShift->setObjectName(QStringLiteral("control_LeftShift"));
        sizePolicy.setHeightForWidth(control_LeftShift->sizePolicy().hasHeightForWidth());
        control_LeftShift->setSizePolicy(sizePolicy);
        control_LeftShift->setMinimumSize(QSize(60, 32));
        control_LeftShift->setFont(font1);
        control_LeftShift->setFocusPolicy(Qt::NoFocus);
        control_LeftShift->setCheckable(true);
        control_LeftShift->setAutoDefault(false);

        keyboardPanel->addWidget(control_LeftShift, 3, 0, 1, 4);

        letter_Z = new QPushButton(page);
        letter_Z->setObjectName(QStringLiteral("letter_Z"));
        sizePolicy.setHeightForWidth(letter_Z->sizePolicy().hasHeightForWidth());
        letter_Z->setSizePolicy(sizePolicy);
        letter_Z->setMinimumSize(QSize(36, 32));
        letter_Z->setFont(font1);
        letter_Z->setFocusPolicy(Qt::NoFocus);
        letter_Z->setCheckable(false);
        letter_Z->setAutoDefault(false);

        keyboardPanel->addWidget(letter_Z, 3, 4, 1, 3);

        control_Enter = new QPushButton(page);
        control_Enter->setObjectName(QStringLiteral("control_Enter"));
        sizePolicy.setHeightForWidth(control_Enter->sizePolicy().hasHeightForWidth());
        control_Enter->setSizePolicy(sizePolicy);
        control_Enter->setMinimumSize(QSize(80, 32));
        control_Enter->setFont(font1);
        control_Enter->setFocusPolicy(Qt::NoFocus);
        control_Enter->setAutoDefault(false);

        keyboardPanel->addWidget(control_Enter, 2, 36, 1, 4);

        letter_X = new QPushButton(page);
        letter_X->setObjectName(QStringLiteral("letter_X"));
        sizePolicy.setHeightForWidth(letter_X->sizePolicy().hasHeightForWidth());
        letter_X->setSizePolicy(sizePolicy);
        letter_X->setMinimumSize(QSize(36, 32));
        letter_X->setFont(font1);
        letter_X->setFocusPolicy(Qt::NoFocus);
        letter_X->setAutoDefault(false);

        keyboardPanel->addWidget(letter_X, 3, 7, 1, 3);

        letter_C = new QPushButton(page);
        letter_C->setObjectName(QStringLiteral("letter_C"));
        sizePolicy.setHeightForWidth(letter_C->sizePolicy().hasHeightForWidth());
        letter_C->setSizePolicy(sizePolicy);
        letter_C->setMinimumSize(QSize(36, 32));
        letter_C->setFont(font1);
        letter_C->setFocusPolicy(Qt::NoFocus);
        letter_C->setAutoDefault(false);

        keyboardPanel->addWidget(letter_C, 3, 10, 1, 3);

        letter_V = new QPushButton(page);
        letter_V->setObjectName(QStringLiteral("letter_V"));
        sizePolicy.setHeightForWidth(letter_V->sizePolicy().hasHeightForWidth());
        letter_V->setSizePolicy(sizePolicy);
        letter_V->setMinimumSize(QSize(36, 32));
        letter_V->setFont(font1);
        letter_V->setFocusPolicy(Qt::NoFocus);
        letter_V->setAutoDefault(false);

        keyboardPanel->addWidget(letter_V, 3, 13, 1, 3);

        letter_B = new QPushButton(page);
        letter_B->setObjectName(QStringLiteral("letter_B"));
        sizePolicy.setHeightForWidth(letter_B->sizePolicy().hasHeightForWidth());
        letter_B->setSizePolicy(sizePolicy);
        letter_B->setMinimumSize(QSize(36, 32));
        letter_B->setFont(font1);
        letter_B->setFocusPolicy(Qt::NoFocus);
        letter_B->setAutoDefault(false);

        keyboardPanel->addWidget(letter_B, 3, 16, 1, 3);

        letter_N = new QPushButton(page);
        letter_N->setObjectName(QStringLiteral("letter_N"));
        sizePolicy.setHeightForWidth(letter_N->sizePolicy().hasHeightForWidth());
        letter_N->setSizePolicy(sizePolicy);
        letter_N->setMinimumSize(QSize(36, 32));
        letter_N->setFont(font1);
        letter_N->setFocusPolicy(Qt::NoFocus);
        letter_N->setAutoDefault(false);

        keyboardPanel->addWidget(letter_N, 3, 19, 1, 3);

        symbol_LessComma = new QPushButton(page);
        symbol_LessComma->setObjectName(QStringLiteral("symbol_LessComma"));
        sizePolicy.setHeightForWidth(symbol_LessComma->sizePolicy().hasHeightForWidth());
        symbol_LessComma->setSizePolicy(sizePolicy);
        symbol_LessComma->setMinimumSize(QSize(36, 32));
        symbol_LessComma->setFont(font1);
        symbol_LessComma->setFocusPolicy(Qt::NoFocus);
        symbol_LessComma->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	text-align: center;\n"
"}"));
        symbol_LessComma->setAutoDefault(false);

        keyboardPanel->addWidget(symbol_LessComma, 3, 25, 1, 3);

        letter_M = new QPushButton(page);
        letter_M->setObjectName(QStringLiteral("letter_M"));
        sizePolicy.setHeightForWidth(letter_M->sizePolicy().hasHeightForWidth());
        letter_M->setSizePolicy(sizePolicy);
        letter_M->setMinimumSize(QSize(36, 32));
        letter_M->setFont(font1);
        letter_M->setFocusPolicy(Qt::NoFocus);
        letter_M->setAutoDefault(false);

        keyboardPanel->addWidget(letter_M, 3, 22, 1, 3);

        symbol_GreaterPeriod = new QPushButton(page);
        symbol_GreaterPeriod->setObjectName(QStringLiteral("symbol_GreaterPeriod"));
        sizePolicy.setHeightForWidth(symbol_GreaterPeriod->sizePolicy().hasHeightForWidth());
        symbol_GreaterPeriod->setSizePolicy(sizePolicy);
        symbol_GreaterPeriod->setMinimumSize(QSize(36, 32));
        symbol_GreaterPeriod->setFont(font1);
        symbol_GreaterPeriod->setFocusPolicy(Qt::NoFocus);
        symbol_GreaterPeriod->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	text-align: center;\n"
"}"));
        symbol_GreaterPeriod->setAutoDefault(false);

        keyboardPanel->addWidget(symbol_GreaterPeriod, 3, 28, 1, 3);

        control_ArrowUp = new QPushButton(page);
        control_ArrowUp->setObjectName(QStringLiteral("control_ArrowUp"));
        sizePolicy.setHeightForWidth(control_ArrowUp->sizePolicy().hasHeightForWidth());
        control_ArrowUp->setSizePolicy(sizePolicy);
        control_ArrowUp->setMinimumSize(QSize(36, 32));
        control_ArrowUp->setFont(font1);
        control_ArrowUp->setFocusPolicy(Qt::NoFocus);
        control_ArrowUp->setAutoDefault(false);

        keyboardPanel->addWidget(control_ArrowUp, 3, 37, 1, 2);

        symbol_QuestionSlash = new QPushButton(page);
        symbol_QuestionSlash->setObjectName(QStringLiteral("symbol_QuestionSlash"));
        sizePolicy.setHeightForWidth(symbol_QuestionSlash->sizePolicy().hasHeightForWidth());
        symbol_QuestionSlash->setSizePolicy(sizePolicy);
        symbol_QuestionSlash->setMinimumSize(QSize(36, 32));
        symbol_QuestionSlash->setFont(font1);
        symbol_QuestionSlash->setFocusPolicy(Qt::NoFocus);
        symbol_QuestionSlash->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	text-align: center;\n"
"}"));
        symbol_QuestionSlash->setAutoDefault(false);

        keyboardPanel->addWidget(symbol_QuestionSlash, 3, 31, 1, 3);

        control_PageUp = new QPushButton(page);
        control_PageUp->setObjectName(QStringLiteral("control_PageUp"));
        sizePolicy.setHeightForWidth(control_PageUp->sizePolicy().hasHeightForWidth());
        control_PageUp->setSizePolicy(sizePolicy);
        control_PageUp->setMinimumSize(QSize(50, 32));
        control_PageUp->setFont(font1);
        control_PageUp->setFocusPolicy(Qt::NoFocus);
        control_PageUp->setAutoDefault(false);

        keyboardPanel->addWidget(control_PageUp, 3, 34, 1, 3);

        control_LeftCtrl = new QPushButton(page);
        control_LeftCtrl->setObjectName(QStringLiteral("control_LeftCtrl"));
        sizePolicy.setHeightForWidth(control_LeftCtrl->sizePolicy().hasHeightForWidth());
        control_LeftCtrl->setSizePolicy(sizePolicy);
        control_LeftCtrl->setMinimumSize(QSize(50, 32));
        control_LeftCtrl->setFont(font1);
        control_LeftCtrl->setFocusPolicy(Qt::NoFocus);
        control_LeftCtrl->setCheckable(true);
        control_LeftCtrl->setAutoDefault(false);

        keyboardPanel->addWidget(control_LeftCtrl, 4, 0, 1, 2);

        control_Language = new QPushButton(page);
        control_Language->setObjectName(QStringLiteral("control_Language"));
        sizePolicy.setHeightForWidth(control_Language->sizePolicy().hasHeightForWidth());
        control_Language->setSizePolicy(sizePolicy);
        control_Language->setMinimumSize(QSize(56, 32));
        control_Language->setFont(font1);
        control_Language->setFocusPolicy(Qt::NoFocus);
        control_Language->setIconSize(QSize(24, 24));
        control_Language->setAutoRepeatDelay(300);
        control_Language->setAutoDefault(false);

        keyboardPanel->addWidget(control_Language, 4, 2, 1, 5);

        control_PageDown = new QPushButton(page);
        control_PageDown->setObjectName(QStringLiteral("control_PageDown"));
        sizePolicy.setHeightForWidth(control_PageDown->sizePolicy().hasHeightForWidth());
        control_PageDown->setSizePolicy(sizePolicy);
        control_PageDown->setMinimumSize(QSize(50, 32));
        control_PageDown->setFont(font1);
        control_PageDown->setFocusPolicy(Qt::NoFocus);
        control_PageDown->setAutoDefault(false);

        keyboardPanel->addWidget(control_PageDown, 3, 39, 1, 1);

        control_ArrowDown = new QPushButton(page);
        control_ArrowDown->setObjectName(QStringLiteral("control_ArrowDown"));
        sizePolicy.setHeightForWidth(control_ArrowDown->sizePolicy().hasHeightForWidth());
        control_ArrowDown->setSizePolicy(sizePolicy);
        control_ArrowDown->setMinimumSize(QSize(36, 32));
        control_ArrowDown->setFont(font1);
        control_ArrowDown->setFocusPolicy(Qt::NoFocus);
        control_ArrowDown->setAutoDefault(false);

        keyboardPanel->addWidget(control_ArrowDown, 4, 37, 1, 2);

        control_ArrowLeft = new QPushButton(page);
        control_ArrowLeft->setObjectName(QStringLiteral("control_ArrowLeft"));
        sizePolicy.setHeightForWidth(control_ArrowLeft->sizePolicy().hasHeightForWidth());
        control_ArrowLeft->setSizePolicy(sizePolicy);
        control_ArrowLeft->setMinimumSize(QSize(36, 32));
        control_ArrowLeft->setFont(font1);
        control_ArrowLeft->setFocusPolicy(Qt::NoFocus);
        control_ArrowLeft->setAutoDefault(false);

        keyboardPanel->addWidget(control_ArrowLeft, 4, 34, 1, 3);

        control_LeftAlt = new QPushButton(page);
        control_LeftAlt->setObjectName(QStringLiteral("control_LeftAlt"));
        sizePolicy.setHeightForWidth(control_LeftAlt->sizePolicy().hasHeightForWidth());
        control_LeftAlt->setSizePolicy(sizePolicy);
        control_LeftAlt->setMinimumSize(QSize(56, 32));
        control_LeftAlt->setFont(font1);
        control_LeftAlt->setFocusPolicy(Qt::NoFocus);
        control_LeftAlt->setCheckable(true);
        control_LeftAlt->setAutoDefault(false);

        keyboardPanel->addWidget(control_LeftAlt, 4, 7, 1, 4);

        control_Space = new QPushButton(page);
        control_Space->setObjectName(QStringLiteral("control_Space"));
        sizePolicy.setHeightForWidth(control_Space->sizePolicy().hasHeightForWidth());
        control_Space->setSizePolicy(sizePolicy);
        control_Space->setFont(font1);
        control_Space->setFocusPolicy(Qt::NoFocus);
        control_Space->setAutoDefault(false);

        keyboardPanel->addWidget(control_Space, 4, 11, 1, 23);

        symbol_BraceRightBracketRight = new QPushButton(page);
        symbol_BraceRightBracketRight->setObjectName(QStringLiteral("symbol_BraceRightBracketRight"));
        sizePolicy.setHeightForWidth(symbol_BraceRightBracketRight->sizePolicy().hasHeightForWidth());
        symbol_BraceRightBracketRight->setSizePolicy(sizePolicy);
        symbol_BraceRightBracketRight->setMinimumSize(QSize(36, 21));
        symbol_BraceRightBracketRight->setFont(font1);
        symbol_BraceRightBracketRight->setFocusPolicy(Qt::NoFocus);
        symbol_BraceRightBracketRight->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	text-align: center;\n"
"}"));
        symbol_BraceRightBracketRight->setAutoDefault(false);

        keyboardPanel->addWidget(symbol_BraceRightBracketRight, 1, 35, 1, 3);

        control_ArrowRight = new QPushButton(page);
        control_ArrowRight->setObjectName(QStringLiteral("control_ArrowRight"));
        sizePolicy.setHeightForWidth(control_ArrowRight->sizePolicy().hasHeightForWidth());
        control_ArrowRight->setSizePolicy(sizePolicy);
        control_ArrowRight->setMinimumSize(QSize(36, 32));
        control_ArrowRight->setFont(font1);
        control_ArrowRight->setFocusPolicy(Qt::NoFocus);
        control_ArrowRight->setAutoDefault(false);

        keyboardPanel->addWidget(control_ArrowRight, 4, 39, 1, 1);

        control_Backspace = new QPushButton(page);
        control_Backspace->setObjectName(QStringLiteral("control_Backspace"));
        sizePolicy.setHeightForWidth(control_Backspace->sizePolicy().hasHeightForWidth());
        control_Backspace->setSizePolicy(sizePolicy);
        control_Backspace->setMinimumSize(QSize(75, 32));
        control_Backspace->setFont(font1);
        control_Backspace->setFocusPolicy(Qt::NoFocus);
        control_Backspace->setAutoDefault(false);

        keyboardPanel->addWidget(control_Backspace, 0, 37, 1, 2);

        control_Disable = new QPushButton(page);
        control_Disable->setObjectName(QStringLiteral("control_Disable"));
        sizePolicy.setHeightForWidth(control_Disable->sizePolicy().hasHeightForWidth());
        control_Disable->setSizePolicy(sizePolicy);
        control_Disable->setMinimumSize(QSize(75, 32));
        control_Disable->setFont(font1);
        control_Disable->setFocusPolicy(Qt::NoFocus);
        control_Disable->setAutoDefault(false);

        keyboardPanel->addWidget(control_Disable, 0, 39, 1, 1);


        gridLayout_2->addLayout(keyboardPanel, 0, 0, 1, 9);

        language_Pinyin = new QLabel(page);
        language_Pinyin->setObjectName(QStringLiteral("language_Pinyin"));
        language_Pinyin->setMinimumSize(QSize(0, 24));
        language_Pinyin->setMaximumSize(QSize(2000, 24));
        language_Pinyin->setFont(font);
        language_Pinyin->setStyleSheet(QStringLiteral(""));

        gridLayout_2->addWidget(language_Pinyin, 1, 0, 1, 9);

        language_CH1 = new QLabel(page);
        language_CH1->setObjectName(QStringLiteral("language_CH1"));
        language_CH1->setMinimumSize(QSize(0, 24));
        language_CH1->setMaximumSize(QSize(16777215, 24));
        language_CH1->setFont(font);

        gridLayout_2->addWidget(language_CH1, 2, 0, 1, 1);

        language_CH2 = new QLabel(page);
        language_CH2->setObjectName(QStringLiteral("language_CH2"));
        language_CH2->setMinimumSize(QSize(0, 24));
        language_CH2->setMaximumSize(QSize(16777215, 24));
        language_CH2->setFont(font);

        gridLayout_2->addWidget(language_CH2, 2, 1, 1, 1);

        language_CH3 = new QLabel(page);
        language_CH3->setObjectName(QStringLiteral("language_CH3"));
        language_CH3->setMinimumSize(QSize(0, 24));
        language_CH3->setMaximumSize(QSize(16777215, 24));
        language_CH3->setFont(font);

        gridLayout_2->addWidget(language_CH3, 2, 2, 1, 1);

        language_CH4 = new QLabel(page);
        language_CH4->setObjectName(QStringLiteral("language_CH4"));
        language_CH4->setMinimumSize(QSize(0, 24));
        language_CH4->setMaximumSize(QSize(16777215, 24));
        language_CH4->setFont(font);

        gridLayout_2->addWidget(language_CH4, 2, 3, 1, 1);

        language_CH5 = new QLabel(page);
        language_CH5->setObjectName(QStringLiteral("language_CH5"));
        language_CH5->setMinimumSize(QSize(0, 24));
        language_CH5->setMaximumSize(QSize(16777215, 24));
        language_CH5->setFont(font);

        gridLayout_2->addWidget(language_CH5, 2, 4, 1, 1);

        language_CH6 = new QLabel(page);
        language_CH6->setObjectName(QStringLiteral("language_CH6"));
        language_CH6->setMinimumSize(QSize(0, 24));
        language_CH6->setMaximumSize(QSize(16777215, 24));
        language_CH6->setFont(font);

        gridLayout_2->addWidget(language_CH6, 2, 5, 1, 1);

        language_CH7 = new QLabel(page);
        language_CH7->setObjectName(QStringLiteral("language_CH7"));
        language_CH7->setMinimumSize(QSize(0, 24));
        language_CH7->setMaximumSize(QSize(16777215, 24));
        language_CH7->setFont(font);

        gridLayout_2->addWidget(language_CH7, 2, 6, 1, 1);

        language_CH8 = new QLabel(page);
        language_CH8->setObjectName(QStringLiteral("language_CH8"));
        language_CH8->setMinimumSize(QSize(0, 24));
        language_CH8->setMaximumSize(QSize(16777215, 24));
        language_CH8->setFont(font);

        gridLayout_2->addWidget(language_CH8, 2, 7, 1, 1);

        language_CH9 = new QLabel(page);
        language_CH9->setObjectName(QStringLiteral("language_CH9"));
        language_CH9->setMinimumSize(QSize(0, 24));
        language_CH9->setMaximumSize(QSize(16777215, 24));
        language_CH9->setFont(font);

        gridLayout_2->addWidget(language_CH9, 2, 8, 1, 1);

        stackedWidget->addWidget(page);
        page_num = new QWidget();
        page_num->setObjectName(QStringLiteral("page_num"));
        gridLayout_3 = new QGridLayout(page_num);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(-1, 20, -1, 20);
        keyboardPanel_number = new QGridLayout();
        keyboardPanel_number->setSpacing(2);
        keyboardPanel_number->setObjectName(QStringLiteral("keyboardPanel_number"));
        control_Enter_num = new QPushButton(page_num);
        control_Enter_num->setObjectName(QStringLiteral("control_Enter_num"));
        sizePolicy.setHeightForWidth(control_Enter_num->sizePolicy().hasHeightForWidth());
        control_Enter_num->setSizePolicy(sizePolicy);
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setBold(false);
        font2.setItalic(false);
        font2.setWeight(50);
        control_Enter_num->setFont(font2);
        control_Enter_num->setFocusPolicy(Qt::NoFocus);
        control_Enter_num->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	text-align: center;\n"
"	font:20px\n"
"}"));
        control_Enter_num->setAutoDefault(false);

        keyboardPanel_number->addWidget(control_Enter_num, 5, 3, 2, 1);

        number_D3 = new QPushButton(page_num);
        number_D3->setObjectName(QStringLiteral("number_D3"));
        sizePolicy.setHeightForWidth(number_D3->sizePolicy().hasHeightForWidth());
        number_D3->setSizePolicy(sizePolicy);
        number_D3->setMinimumSize(QSize(36, 32));
        number_D3->setFont(font2);
        number_D3->setFocusPolicy(Qt::NoFocus);
        number_D3->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	text-align: center;\n"
"	font:20px\n"
"}"));
        number_D3->setAutoDefault(false);

        keyboardPanel_number->addWidget(number_D3, 3, 3, 1, 1);

        number_D6 = new QPushButton(page_num);
        number_D6->setObjectName(QStringLiteral("number_D6"));
        sizePolicy.setHeightForWidth(number_D6->sizePolicy().hasHeightForWidth());
        number_D6->setSizePolicy(sizePolicy);
        number_D6->setMinimumSize(QSize(36, 32));
        number_D6->setFont(font2);
        number_D6->setFocusPolicy(Qt::NoFocus);
        number_D6->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	text-align: center;\n"
"	font:20px\n"
"}"));
        number_D6->setAutoDefault(false);

        keyboardPanel_number->addWidget(number_D6, 2, 3, 1, 1);

        number_D7 = new QPushButton(page_num);
        number_D7->setObjectName(QStringLiteral("number_D7"));
        sizePolicy.setHeightForWidth(number_D7->sizePolicy().hasHeightForWidth());
        number_D7->setSizePolicy(sizePolicy);
        number_D7->setMinimumSize(QSize(36, 32));
        number_D7->setFont(font2);
        number_D7->setFocusPolicy(Qt::NoFocus);
        number_D7->setLayoutDirection(Qt::LeftToRight);
        number_D7->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	text-align: center;\n"
"	font:20px\n"
"}"));
        number_D7->setAutoDefault(false);

        keyboardPanel_number->addWidget(number_D7, 0, 0, 1, 1);

        number_D4 = new QPushButton(page_num);
        number_D4->setObjectName(QStringLiteral("number_D4"));
        sizePolicy.setHeightForWidth(number_D4->sizePolicy().hasHeightForWidth());
        number_D4->setSizePolicy(sizePolicy);
        number_D4->setMinimumSize(QSize(36, 32));
        number_D4->setFont(font2);
        number_D4->setFocusPolicy(Qt::NoFocus);
        number_D4->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	text-align: center;\n"
"	font:20px\n"
"}"));
        number_D4->setAutoDefault(false);

        keyboardPanel_number->addWidget(number_D4, 2, 0, 1, 1);

        number_D8 = new QPushButton(page_num);
        number_D8->setObjectName(QStringLiteral("number_D8"));
        sizePolicy.setHeightForWidth(number_D8->sizePolicy().hasHeightForWidth());
        number_D8->setSizePolicy(sizePolicy);
        number_D8->setMinimumSize(QSize(36, 32));
        number_D8->setFont(font2);
        number_D8->setFocusPolicy(Qt::NoFocus);
        number_D8->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	text-align: center;\n"
"	font:20px\n"
"}"));
        number_D8->setAutoDefault(false);

        keyboardPanel_number->addWidget(number_D8, 0, 2, 1, 1);

        number_D1 = new QPushButton(page_num);
        number_D1->setObjectName(QStringLiteral("number_D1"));
        sizePolicy.setHeightForWidth(number_D1->sizePolicy().hasHeightForWidth());
        number_D1->setSizePolicy(sizePolicy);
        number_D1->setMinimumSize(QSize(36, 32));
        number_D1->setFont(font2);
        number_D1->setFocusPolicy(Qt::NoFocus);
        number_D1->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	text-align: center;\n"
"	font:20px\n"
"}"));
        number_D1->setAutoDefault(false);

        keyboardPanel_number->addWidget(number_D1, 3, 0, 1, 1);

        number_D9 = new QPushButton(page_num);
        number_D9->setObjectName(QStringLiteral("number_D9"));
        sizePolicy.setHeightForWidth(number_D9->sizePolicy().hasHeightForWidth());
        number_D9->setSizePolicy(sizePolicy);
        number_D9->setMinimumSize(QSize(36, 32));
        number_D9->setFont(font2);
        number_D9->setFocusPolicy(Qt::NoFocus);
        number_D9->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	text-align: center;\n"
"	font:20px\n"
"}"));
        number_D9->setAutoDefault(false);

        keyboardPanel_number->addWidget(number_D9, 0, 3, 1, 1);

        number_D5 = new QPushButton(page_num);
        number_D5->setObjectName(QStringLiteral("number_D5"));
        sizePolicy.setHeightForWidth(number_D5->sizePolicy().hasHeightForWidth());
        number_D5->setSizePolicy(sizePolicy);
        number_D5->setMinimumSize(QSize(36, 32));
        number_D5->setFont(font2);
        number_D5->setFocusPolicy(Qt::NoFocus);
        number_D5->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	text-align: center;\n"
"	font:20px\n"
"}"));
        number_D5->setAutoDefault(false);

        keyboardPanel_number->addWidget(number_D5, 2, 2, 1, 1);

        number_D0 = new QPushButton(page_num);
        number_D0->setObjectName(QStringLiteral("number_D0"));
        sizePolicy.setHeightForWidth(number_D0->sizePolicy().hasHeightForWidth());
        number_D0->setSizePolicy(sizePolicy);
        number_D0->setMinimumSize(QSize(36, 32));
        number_D0->setFont(font2);
        number_D0->setFocusPolicy(Qt::NoFocus);
        number_D0->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	text-align: center;\n"
"	font:20px\n"
"}"));
        number_D0->setAutoDefault(false);

        keyboardPanel_number->addWidget(number_D0, 5, 0, 1, 1);

        number_D2 = new QPushButton(page_num);
        number_D2->setObjectName(QStringLiteral("number_D2"));
        sizePolicy.setHeightForWidth(number_D2->sizePolicy().hasHeightForWidth());
        number_D2->setSizePolicy(sizePolicy);
        number_D2->setMinimumSize(QSize(36, 32));
        number_D2->setFont(font2);
        number_D2->setFocusPolicy(Qt::NoFocus);
        number_D2->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	text-align: center;\n"
"	font:20px\n"
"}"));
        number_D2->setAutoDefault(false);

        keyboardPanel_number->addWidget(number_D2, 3, 2, 1, 1);

        symbol_GreaterPeriod_num = new QPushButton(page_num);
        symbol_GreaterPeriod_num->setObjectName(QStringLiteral("symbol_GreaterPeriod_num"));
        sizePolicy.setHeightForWidth(symbol_GreaterPeriod_num->sizePolicy().hasHeightForWidth());
        symbol_GreaterPeriod_num->setSizePolicy(sizePolicy);
        symbol_GreaterPeriod_num->setMinimumSize(QSize(36, 32));
        symbol_GreaterPeriod_num->setFont(font2);
        symbol_GreaterPeriod_num->setFocusPolicy(Qt::NoFocus);
        symbol_GreaterPeriod_num->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	text-align: center;\n"
"	font:20px\n"
"}"));
        symbol_GreaterPeriod_num->setAutoDefault(false);

        keyboardPanel_number->addWidget(symbol_GreaterPeriod_num, 6, 0, 1, 1);

        control_Backspace_num = new QPushButton(page_num);
        control_Backspace_num->setObjectName(QStringLiteral("control_Backspace_num"));
        sizePolicy.setHeightForWidth(control_Backspace_num->sizePolicy().hasHeightForWidth());
        control_Backspace_num->setSizePolicy(sizePolicy);
        control_Backspace_num->setMinimumSize(QSize(75, 32));
        control_Backspace_num->setFont(font2);
        control_Backspace_num->setFocusPolicy(Qt::NoFocus);
        control_Backspace_num->setLayoutDirection(Qt::LeftToRight);
        control_Backspace_num->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	text-align: center;\n"
"	font:20px\n"
"}"));
        control_Backspace_num->setAutoDefault(false);

        keyboardPanel_number->addWidget(control_Backspace_num, 5, 2, 2, 1);


        gridLayout_3->addLayout(keyboardPanel_number, 0, 0, 1, 1);

        stackedWidget->addWidget(page_num);

        gridLayout->addWidget(stackedWidget, 0, 0, 1, 1);


        retranslateUi(SoftKeyboard);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(SoftKeyboard);
    } // setupUi

    void retranslateUi(QDialog *SoftKeyboard)
    {
        SoftKeyboard->setWindowTitle(QApplication::translate("SoftKeyboard", "Vazyme KEY", Q_NULLPTR));
#ifndef QT_NO_WHATSTHIS
        symbol_BarBackslash->setWhatsThis(QApplication::translate("SoftKeyboard", "27", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        symbol_BarBackslash->setText(QApplication::translate("SoftKeyboard", " |\n"
" \\", Q_NULLPTR));
#ifndef QT_NO_WHATSTHIS
        control_CapsLock->setWhatsThis(QApplication::translate("SoftKeyboard", "28", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        control_CapsLock->setText(QApplication::translate("SoftKeyboard", "CapsLock", Q_NULLPTR));
#ifndef QT_NO_WHATSTHIS
        symbol_BraceLeftBracketLeft->setWhatsThis(QApplication::translate("SoftKeyboard", "25", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        symbol_BraceLeftBracketLeft->setText(QApplication::translate("SoftKeyboard", " {\n"
" [", Q_NULLPTR));
#ifndef QT_NO_WHATSTHIS
        letter_P->setWhatsThis(QApplication::translate("SoftKeyboard", "24", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        letter_P->setText(QApplication::translate("SoftKeyboard", "p", Q_NULLPTR));
#ifndef QT_NO_WHATSTHIS
        letter_D->setWhatsThis(QApplication::translate("SoftKeyboard", "31", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        letter_D->setText(QApplication::translate("SoftKeyboard", "d", Q_NULLPTR));
#ifndef QT_NO_WHATSTHIS
        letter_S->setWhatsThis(QApplication::translate("SoftKeyboard", "30", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        letter_S->setText(QApplication::translate("SoftKeyboard", "s", Q_NULLPTR));
#ifndef QT_NO_WHATSTHIS
        letter_A->setWhatsThis(QApplication::translate("SoftKeyboard", "29", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        letter_A->setText(QApplication::translate("SoftKeyboard", "a", Q_NULLPTR));
#ifndef QT_NO_WHATSTHIS
        letter_F->setWhatsThis(QApplication::translate("SoftKeyboard", "32", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        letter_F->setText(QApplication::translate("SoftKeyboard", "f", Q_NULLPTR));
#ifndef QT_NO_WHATSTHIS
        letter_J->setWhatsThis(QApplication::translate("SoftKeyboard", "35", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        letter_J->setText(QApplication::translate("SoftKeyboard", "j", Q_NULLPTR));
#ifndef QT_NO_WHATSTHIS
        letter_G->setWhatsThis(QApplication::translate("SoftKeyboard", "33", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        letter_G->setText(QApplication::translate("SoftKeyboard", "g", Q_NULLPTR));
#ifndef QT_NO_WHATSTHIS
        letter_H->setWhatsThis(QApplication::translate("SoftKeyboard", "34", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        letter_H->setText(QApplication::translate("SoftKeyboard", "h", Q_NULLPTR));
#ifndef QT_NO_WHATSTHIS
        symbol_AsciiTildeQuote->setWhatsThis(QApplication::translate("SoftKeyboard", "0", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        symbol_AsciiTildeQuote->setText(QApplication::translate("SoftKeyboard", " ~\n"
" `", Q_NULLPTR));
#ifndef QT_NO_WHATSTHIS
        number_1->setWhatsThis(QApplication::translate("SoftKeyboard", "1", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        number_1->setText(QApplication::translate("SoftKeyboard", " !\n"
" 1", Q_NULLPTR));
#ifndef QT_NO_WHATSTHIS
        number_2->setWhatsThis(QApplication::translate("SoftKeyboard", "2", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        number_2->setText(QApplication::translate("SoftKeyboard", " @\n"
" 2", Q_NULLPTR));
#ifndef QT_NO_WHATSTHIS
        number_5->setWhatsThis(QApplication::translate("SoftKeyboard", "5", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        number_5->setText(QApplication::translate("SoftKeyboard", " %\n"
" 5", Q_NULLPTR));
#ifndef QT_NO_WHATSTHIS
        number_6->setWhatsThis(QApplication::translate("SoftKeyboard", "6", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        number_6->setText(QApplication::translate("SoftKeyboard", " ^\n"
" 6", Q_NULLPTR));
#ifndef QT_NO_WHATSTHIS
        number_4->setWhatsThis(QApplication::translate("SoftKeyboard", "4", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        number_4->setText(QApplication::translate("SoftKeyboard", " $\n"
" 4", Q_NULLPTR));
#ifndef QT_NO_WHATSTHIS
        number_3->setWhatsThis(QApplication::translate("SoftKeyboard", "3", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        number_3->setText(QApplication::translate("SoftKeyboard", " #\n"
" 3", Q_NULLPTR));
#ifndef QT_NO_WHATSTHIS
        number_8->setWhatsThis(QApplication::translate("SoftKeyboard", "8", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        number_8->setText(QApplication::translate("SoftKeyboard", " *\n"
" 8", Q_NULLPTR));
#ifndef QT_NO_WHATSTHIS
        number_0->setWhatsThis(QApplication::translate("SoftKeyboard", "10", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        number_0->setText(QApplication::translate("SoftKeyboard", " )\n"
" 0", Q_NULLPTR));
#ifndef QT_NO_WHATSTHIS
        number_9->setWhatsThis(QApplication::translate("SoftKeyboard", "9", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        number_9->setText(QApplication::translate("SoftKeyboard", " (\n"
" 9", Q_NULLPTR));
#ifndef QT_NO_WHATSTHIS
        number_7->setWhatsThis(QApplication::translate("SoftKeyboard", "7", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        number_7->setText(QApplication::translate("SoftKeyboard", "&&\n"
" 7", Q_NULLPTR));
#ifndef QT_NO_WHATSTHIS
        symbol_PlusEqual->setWhatsThis(QApplication::translate("SoftKeyboard", "12", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        symbol_PlusEqual->setText(QApplication::translate("SoftKeyboard", " +\n"
" =", Q_NULLPTR));
#ifndef QT_NO_WHATSTHIS
        symbol_MinusUnderscore->setWhatsThis(QApplication::translate("SoftKeyboard", "11", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        symbol_MinusUnderscore->setText(QApplication::translate("SoftKeyboard", " _\n"
" -", Q_NULLPTR));
#ifndef QT_NO_WHATSTHIS
        control_Tab->setWhatsThis(QApplication::translate("SoftKeyboard", "14", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        control_Tab->setText(QApplication::translate("SoftKeyboard", "Tab", Q_NULLPTR));
#ifndef QT_NO_WHATSTHIS
        letter_Q->setWhatsThis(QApplication::translate("SoftKeyboard", "15", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        letter_Q->setText(QApplication::translate("SoftKeyboard", "q", Q_NULLPTR));
#ifndef QT_NO_WHATSTHIS
        letter_W->setWhatsThis(QApplication::translate("SoftKeyboard", "16", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        letter_W->setText(QApplication::translate("SoftKeyboard", "w", Q_NULLPTR));
#ifndef QT_NO_WHATSTHIS
        letter_E->setWhatsThis(QApplication::translate("SoftKeyboard", "17", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        letter_E->setText(QApplication::translate("SoftKeyboard", "e", Q_NULLPTR));
#ifndef QT_NO_WHATSTHIS
        letter_R->setWhatsThis(QApplication::translate("SoftKeyboard", "18", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        letter_R->setText(QApplication::translate("SoftKeyboard", "r", Q_NULLPTR));
#ifndef QT_NO_WHATSTHIS
        letter_U->setWhatsThis(QApplication::translate("SoftKeyboard", "21", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        letter_U->setText(QApplication::translate("SoftKeyboard", "u", Q_NULLPTR));
#ifndef QT_NO_WHATSTHIS
        letter_T->setWhatsThis(QApplication::translate("SoftKeyboard", "19", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        letter_T->setText(QApplication::translate("SoftKeyboard", "t", Q_NULLPTR));
#ifndef QT_NO_WHATSTHIS
        letter_Y->setWhatsThis(QApplication::translate("SoftKeyboard", "20", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        letter_Y->setText(QApplication::translate("SoftKeyboard", "y", Q_NULLPTR));
#ifndef QT_NO_WHATSTHIS
        letter_I->setWhatsThis(QApplication::translate("SoftKeyboard", "22", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        letter_I->setText(QApplication::translate("SoftKeyboard", "i", Q_NULLPTR));
#ifndef QT_NO_WHATSTHIS
        letter_O->setWhatsThis(QApplication::translate("SoftKeyboard", "23", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        letter_O->setText(QApplication::translate("SoftKeyboard", "o", Q_NULLPTR));
#ifndef QT_NO_WHATSTHIS
        symbol_ColonSemicolon->setWhatsThis(QApplication::translate("SoftKeyboard", "38", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        symbol_ColonSemicolon->setText(QApplication::translate("SoftKeyboard", " :\n"
" ;", Q_NULLPTR));
#ifndef QT_NO_WHATSTHIS
        symbol_QuoteDblApostrophe->setWhatsThis(QApplication::translate("SoftKeyboard", "39", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        symbol_QuoteDblApostrophe->setText(QApplication::translate("SoftKeyboard", " \"\n"
" '", Q_NULLPTR));
#ifndef QT_NO_WHATSTHIS
        letter_L->setWhatsThis(QApplication::translate("SoftKeyboard", "37", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        letter_L->setText(QApplication::translate("SoftKeyboard", "l", Q_NULLPTR));
#ifndef QT_NO_WHATSTHIS
        letter_K->setWhatsThis(QApplication::translate("SoftKeyboard", "36", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        letter_K->setText(QApplication::translate("SoftKeyboard", "k", Q_NULLPTR));
#ifndef QT_NO_WHATSTHIS
        control_LeftShift->setWhatsThis(QApplication::translate("SoftKeyboard", "41", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        control_LeftShift->setText(QApplication::translate("SoftKeyboard", "Shift", Q_NULLPTR));
#ifndef QT_NO_WHATSTHIS
        letter_Z->setWhatsThis(QApplication::translate("SoftKeyboard", "42", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        letter_Z->setText(QApplication::translate("SoftKeyboard", "z", Q_NULLPTR));
#ifndef QT_NO_WHATSTHIS
        control_Enter->setWhatsThis(QApplication::translate("SoftKeyboard", "40", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        control_Enter->setText(QApplication::translate("SoftKeyboard", "Enter", Q_NULLPTR));
#ifndef QT_NO_WHATSTHIS
        letter_X->setWhatsThis(QApplication::translate("SoftKeyboard", "43", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        letter_X->setText(QApplication::translate("SoftKeyboard", "x", Q_NULLPTR));
#ifndef QT_NO_WHATSTHIS
        letter_C->setWhatsThis(QApplication::translate("SoftKeyboard", "44", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        letter_C->setText(QApplication::translate("SoftKeyboard", "c", Q_NULLPTR));
#ifndef QT_NO_WHATSTHIS
        letter_V->setWhatsThis(QApplication::translate("SoftKeyboard", "45", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        letter_V->setText(QApplication::translate("SoftKeyboard", "v", Q_NULLPTR));
#ifndef QT_NO_WHATSTHIS
        letter_B->setWhatsThis(QApplication::translate("SoftKeyboard", "46", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        letter_B->setText(QApplication::translate("SoftKeyboard", "b", Q_NULLPTR));
#ifndef QT_NO_WHATSTHIS
        letter_N->setWhatsThis(QApplication::translate("SoftKeyboard", "47", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        letter_N->setText(QApplication::translate("SoftKeyboard", "n", Q_NULLPTR));
#ifndef QT_NO_WHATSTHIS
        symbol_LessComma->setWhatsThis(QApplication::translate("SoftKeyboard", "49", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        symbol_LessComma->setText(QApplication::translate("SoftKeyboard", " <\n"
" ,", Q_NULLPTR));
#ifndef QT_NO_WHATSTHIS
        letter_M->setWhatsThis(QApplication::translate("SoftKeyboard", "48", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        letter_M->setText(QApplication::translate("SoftKeyboard", "m", Q_NULLPTR));
#ifndef QT_NO_WHATSTHIS
        symbol_GreaterPeriod->setWhatsThis(QApplication::translate("SoftKeyboard", "50", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        symbol_GreaterPeriod->setText(QApplication::translate("SoftKeyboard", " >\n"
" .", Q_NULLPTR));
#ifndef QT_NO_WHATSTHIS
        control_ArrowUp->setWhatsThis(QApplication::translate("SoftKeyboard", "53", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        control_ArrowUp->setText(QApplication::translate("SoftKeyboard", "\342\206\221", Q_NULLPTR));
#ifndef QT_NO_WHATSTHIS
        symbol_QuestionSlash->setWhatsThis(QApplication::translate("SoftKeyboard", "51", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        symbol_QuestionSlash->setText(QApplication::translate("SoftKeyboard", " ?\n"
" /", Q_NULLPTR));
#ifndef QT_NO_WHATSTHIS
        control_PageUp->setWhatsThis(QApplication::translate("SoftKeyboard", "52", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        control_PageUp->setText(QApplication::translate("SoftKeyboard", "PgUp", Q_NULLPTR));
#ifndef QT_NO_WHATSTHIS
        control_LeftCtrl->setWhatsThis(QApplication::translate("SoftKeyboard", "55", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        control_LeftCtrl->setText(QApplication::translate("SoftKeyboard", "Ctrl", Q_NULLPTR));
#ifndef QT_NO_WHATSTHIS
        control_Language->setWhatsThis(QApplication::translate("SoftKeyboard", "56", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        control_Language->setText(QApplication::translate("SoftKeyboard", "EN", Q_NULLPTR));
#ifndef QT_NO_WHATSTHIS
        control_PageDown->setWhatsThis(QApplication::translate("SoftKeyboard", "54", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        control_PageDown->setText(QApplication::translate("SoftKeyboard", "PgDn", Q_NULLPTR));
#ifndef QT_NO_WHATSTHIS
        control_ArrowDown->setWhatsThis(QApplication::translate("SoftKeyboard", "60", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        control_ArrowDown->setText(QApplication::translate("SoftKeyboard", "\342\206\223", Q_NULLPTR));
#ifndef QT_NO_WHATSTHIS
        control_ArrowLeft->setWhatsThis(QApplication::translate("SoftKeyboard", "59", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        control_ArrowLeft->setText(QApplication::translate("SoftKeyboard", "\342\206\220", Q_NULLPTR));
#ifndef QT_NO_WHATSTHIS
        control_LeftAlt->setWhatsThis(QApplication::translate("SoftKeyboard", "57", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        control_LeftAlt->setText(QApplication::translate("SoftKeyboard", "Alt", Q_NULLPTR));
#ifndef QT_NO_WHATSTHIS
        control_Space->setWhatsThis(QApplication::translate("SoftKeyboard", "58", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        control_Space->setText(QString());
#ifndef QT_NO_WHATSTHIS
        symbol_BraceRightBracketRight->setWhatsThis(QApplication::translate("SoftKeyboard", "26", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        symbol_BraceRightBracketRight->setText(QApplication::translate("SoftKeyboard", " }\n"
" ]", Q_NULLPTR));
#ifndef QT_NO_WHATSTHIS
        control_ArrowRight->setWhatsThis(QApplication::translate("SoftKeyboard", "61", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        control_ArrowRight->setText(QApplication::translate("SoftKeyboard", "\342\206\222", Q_NULLPTR));
#ifndef QT_NO_WHATSTHIS
        control_Backspace->setWhatsThis(QApplication::translate("SoftKeyboard", "13", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        control_Backspace->setText(QApplication::translate("SoftKeyboard", "Backspace", Q_NULLPTR));
#ifndef QT_NO_WHATSTHIS
        control_Disable->setWhatsThis(QApplication::translate("SoftKeyboard", "62", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        control_Disable->setText(QApplication::translate("SoftKeyboard", "\342\226\274", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        language_Pinyin->setToolTip(QApplication::translate("SoftKeyboard", "1.\345\217\214\345\207\273\346\216\245\346\224\266\347\273\223\346\236\234\345\271\266\351\200\200\345\207\272\n"
"2.\345\217\263\345\207\273\347\233\264\346\216\245\351\200\200\345\207\272\351\224\256\347\233\230", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        language_Pinyin->setText(QString());
        language_CH1->setText(QString());
        language_CH2->setText(QString());
        language_CH3->setText(QString());
        language_CH4->setText(QString());
        language_CH5->setText(QString());
        language_CH6->setText(QString());
        language_CH7->setText(QString());
        language_CH8->setText(QString());
        language_CH9->setText(QString());
#ifndef QT_NO_WHATSTHIS
        control_Enter_num->setWhatsThis(QApplication::translate("SoftKeyboard", "40", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        control_Enter_num->setText(QApplication::translate("SoftKeyboard", "Enter\n"
"\342\226\274", Q_NULLPTR));
#ifndef QT_NO_WHATSTHIS
        number_D3->setWhatsThis(QApplication::translate("SoftKeyboard", "3", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        number_D3->setText(QApplication::translate("SoftKeyboard", "3", Q_NULLPTR));
#ifndef QT_NO_WHATSTHIS
        number_D6->setWhatsThis(QApplication::translate("SoftKeyboard", "6", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        number_D6->setText(QApplication::translate("SoftKeyboard", "6", Q_NULLPTR));
#ifndef QT_NO_WHATSTHIS
        number_D7->setWhatsThis(QApplication::translate("SoftKeyboard", "7", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        number_D7->setText(QApplication::translate("SoftKeyboard", "7", Q_NULLPTR));
#ifndef QT_NO_WHATSTHIS
        number_D4->setWhatsThis(QApplication::translate("SoftKeyboard", "4", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        number_D4->setText(QApplication::translate("SoftKeyboard", "4", Q_NULLPTR));
#ifndef QT_NO_WHATSTHIS
        number_D8->setWhatsThis(QApplication::translate("SoftKeyboard", "8", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        number_D8->setText(QApplication::translate("SoftKeyboard", " 8", Q_NULLPTR));
#ifndef QT_NO_WHATSTHIS
        number_D1->setWhatsThis(QApplication::translate("SoftKeyboard", "1", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        number_D1->setText(QApplication::translate("SoftKeyboard", "1", Q_NULLPTR));
#ifndef QT_NO_WHATSTHIS
        number_D9->setWhatsThis(QApplication::translate("SoftKeyboard", "9", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        number_D9->setText(QApplication::translate("SoftKeyboard", " 9", Q_NULLPTR));
#ifndef QT_NO_WHATSTHIS
        number_D5->setWhatsThis(QApplication::translate("SoftKeyboard", "5", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        number_D5->setText(QApplication::translate("SoftKeyboard", "5", Q_NULLPTR));
#ifndef QT_NO_WHATSTHIS
        number_D0->setWhatsThis(QApplication::translate("SoftKeyboard", "10", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        number_D0->setText(QApplication::translate("SoftKeyboard", "0", Q_NULLPTR));
#ifndef QT_NO_WHATSTHIS
        number_D2->setWhatsThis(QApplication::translate("SoftKeyboard", "2", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        number_D2->setText(QApplication::translate("SoftKeyboard", "2", Q_NULLPTR));
#ifndef QT_NO_WHATSTHIS
        symbol_GreaterPeriod_num->setWhatsThis(QApplication::translate("SoftKeyboard", "50", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        symbol_GreaterPeriod_num->setText(QApplication::translate("SoftKeyboard", ".", Q_NULLPTR));
#ifndef QT_NO_WHATSTHIS
        control_Backspace_num->setWhatsThis(QApplication::translate("SoftKeyboard", "13", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        control_Backspace_num->setText(QApplication::translate("SoftKeyboard", "Backspace", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SoftKeyboard: public Ui_SoftKeyboard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SOFTKEYBOARD_H
