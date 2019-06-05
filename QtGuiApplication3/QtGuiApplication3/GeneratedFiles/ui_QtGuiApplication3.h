/********************************************************************************
** Form generated from reading UI file 'QtGuiApplication3.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTGUIAPPLICATION3_H
#define UI_QTGUIAPPLICATION3_H

#include <../control/MySlideSwitch.h>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "CurvePlot.h"
#include "QCCurvePlot.h"
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_QtGuiApplication3Class
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_4;
    QGridLayout *gridLayout_3;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_6;
    QLineEdit *lineEdit;
    CMySlideSwitch *label;
    QTableWidget *tableWidget;
    QGridLayout *gridLayout_5;
    QPushButton *pushButton_zhuxing;
    QPushButton *pushButton_zhexian;
    QPushButton *pushButton_yb;
    QPushButton *pushButton_zk;
    QPushButton *pushButton_dq;
    QPushButton *pushButton_fn;
    QTextEdit *textEdit;
    QTabWidget *tabWidget;
    QWidget *t1;
    QGridLayout *gridLayout_2;
    CCurvePlot *widget;
    QWidget *t2;
    QGridLayout *gridLayout;
    QCustomPlot *widget_com;
    QWidget *t3;
    QGridLayout *gridLayout_7;
    CQcPlot *widget_QC;
    QWidget *t4;
    QGridLayout *gridLayout_9;
    CCurvePlot *widget_DB;
    QWidget *t5;
    QGridLayout *gridLayout_8;
    CCurvePlot *widget_FN;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QtGuiApplication3Class)
    {
        if (QtGuiApplication3Class->objectName().isEmpty())
            QtGuiApplication3Class->setObjectName(QStringLiteral("QtGuiApplication3Class"));
        QtGuiApplication3Class->resize(871, 735);
        centralWidget = new QWidget(QtGuiApplication3Class);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_4 = new QGridLayout(centralWidget);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout_6 = new QGridLayout(groupBox);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        gridLayout_6->addWidget(lineEdit, 0, 0, 1, 1);

        label = new CMySlideSwitch(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(80, 40));

        gridLayout_6->addWidget(label, 0, 1, 1, 1);

        tableWidget = new QTableWidget(groupBox);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));

        gridLayout_6->addWidget(tableWidget, 1, 0, 1, 2);

        gridLayout_5 = new QGridLayout();
        gridLayout_5->setSpacing(6);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        pushButton_zhuxing = new QPushButton(groupBox);
        pushButton_zhuxing->setObjectName(QStringLiteral("pushButton_zhuxing"));
        pushButton_zhuxing->setIconSize(QSize(30, 30));

        gridLayout_5->addWidget(pushButton_zhuxing, 0, 0, 1, 1);

        pushButton_zhexian = new QPushButton(groupBox);
        pushButton_zhexian->setObjectName(QStringLiteral("pushButton_zhexian"));
        pushButton_zhexian->setAutoFillBackground(false);
        pushButton_zhexian->setIconSize(QSize(30, 30));

        gridLayout_5->addWidget(pushButton_zhexian, 0, 1, 1, 1);

        pushButton_yb = new QPushButton(groupBox);
        pushButton_yb->setObjectName(QStringLiteral("pushButton_yb"));

        gridLayout_5->addWidget(pushButton_yb, 1, 0, 1, 1);

        pushButton_zk = new QPushButton(groupBox);
        pushButton_zk->setObjectName(QStringLiteral("pushButton_zk"));

        gridLayout_5->addWidget(pushButton_zk, 1, 1, 1, 1);

        pushButton_dq = new QPushButton(groupBox);
        pushButton_dq->setObjectName(QStringLiteral("pushButton_dq"));

        gridLayout_5->addWidget(pushButton_dq, 2, 0, 1, 1);

        pushButton_fn = new QPushButton(groupBox);
        pushButton_fn->setObjectName(QStringLiteral("pushButton_fn"));

        gridLayout_5->addWidget(pushButton_fn, 2, 1, 1, 1);


        gridLayout_6->addLayout(gridLayout_5, 2, 0, 1, 2);

        textEdit = new QTextEdit(groupBox);
        textEdit->setObjectName(QStringLiteral("textEdit"));

        gridLayout_6->addWidget(textEdit, 3, 0, 1, 2);


        gridLayout_3->addWidget(groupBox, 0, 0, 1, 1);

        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        t1 = new QWidget();
        t1->setObjectName(QStringLiteral("t1"));
        gridLayout_2 = new QGridLayout(t1);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        widget = new CCurvePlot(t1);
        widget->setObjectName(QStringLiteral("widget"));

        gridLayout_2->addWidget(widget, 0, 0, 1, 1);

        tabWidget->addTab(t1, QString());
        t2 = new QWidget();
        t2->setObjectName(QStringLiteral("t2"));
        gridLayout = new QGridLayout(t2);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        widget_com = new QCustomPlot(t2);
        widget_com->setObjectName(QStringLiteral("widget_com"));

        gridLayout->addWidget(widget_com, 0, 0, 1, 1);

        tabWidget->addTab(t2, QString());
        t3 = new QWidget();
        t3->setObjectName(QStringLiteral("t3"));
        gridLayout_7 = new QGridLayout(t3);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        widget_QC = new CQcPlot(t3);
        widget_QC->setObjectName(QStringLiteral("widget_QC"));

        gridLayout_7->addWidget(widget_QC, 0, 0, 1, 1);

        tabWidget->addTab(t3, QString());
        t4 = new QWidget();
        t4->setObjectName(QStringLiteral("t4"));
        gridLayout_9 = new QGridLayout(t4);
        gridLayout_9->setSpacing(6);
        gridLayout_9->setContentsMargins(11, 11, 11, 11);
        gridLayout_9->setObjectName(QStringLiteral("gridLayout_9"));
        widget_DB = new CCurvePlot(t4);
        widget_DB->setObjectName(QStringLiteral("widget_DB"));

        gridLayout_9->addWidget(widget_DB, 0, 0, 1, 1);

        tabWidget->addTab(t4, QString());
        t5 = new QWidget();
        t5->setObjectName(QStringLiteral("t5"));
        gridLayout_8 = new QGridLayout(t5);
        gridLayout_8->setSpacing(6);
        gridLayout_8->setContentsMargins(11, 11, 11, 11);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        widget_FN = new CCurvePlot(t5);
        widget_FN->setObjectName(QStringLiteral("widget_FN"));

        gridLayout_8->addWidget(widget_FN, 0, 0, 1, 1);

        tabWidget->addTab(t5, QString());

        gridLayout_3->addWidget(tabWidget, 0, 1, 1, 1);

        gridLayout_3->setColumnStretch(0, 1);
        gridLayout_3->setColumnStretch(1, 2);
        gridLayout_3->setColumnMinimumWidth(0, 1);
        gridLayout_3->setColumnMinimumWidth(1, 1);

        gridLayout_4->addLayout(gridLayout_3, 0, 0, 1, 1);

        QtGuiApplication3Class->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(QtGuiApplication3Class);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 871, 23));
        QtGuiApplication3Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QtGuiApplication3Class);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        QtGuiApplication3Class->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(QtGuiApplication3Class);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        QtGuiApplication3Class->setStatusBar(statusBar);

        retranslateUi(QtGuiApplication3Class);

        tabWidget->setCurrentIndex(4);


        QMetaObject::connectSlotsByName(QtGuiApplication3Class);
    } // setupUi

    void retranslateUi(QMainWindow *QtGuiApplication3Class)
    {
        QtGuiApplication3Class->setWindowTitle(QApplication::translate("QtGuiApplication3Class", "QtGuiApplication3", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("QtGuiApplication3Class", "GroupBox", Q_NULLPTR));
        lineEdit->setText(QApplication::translate("QtGuiApplication3Class", "\346\254\242\350\277\216\346\235\245\345\210\260\344\270\215\344\272\214\344\270\226\347\225\214", Q_NULLPTR));
        label->setText(QApplication::translate("QtGuiApplication3Class", "TextLabel", Q_NULLPTR));
        pushButton_zhuxing->setText(QApplication::translate("QtGuiApplication3Class", "\346\237\261\345\275\242", Q_NULLPTR));
        pushButton_zhexian->setText(QApplication::translate("QtGuiApplication3Class", "\346\212\230\347\272\277", Q_NULLPTR));
        pushButton_yb->setText(QApplication::translate("QtGuiApplication3Class", "\346\240\267\346\234\254\345\233\276\345\275\242", Q_NULLPTR));
        pushButton_zk->setText(QApplication::translate("QtGuiApplication3Class", "\350\264\250\346\216\247\345\233\276", Q_NULLPTR));
        pushButton_dq->setText(QApplication::translate("QtGuiApplication3Class", "\345\256\232\346\240\207\346\233\262\347\272\277", Q_NULLPTR));
        pushButton_fn->setText(QApplication::translate("QtGuiApplication3Class", "\345\217\215\345\272\224\346\265\223\345\272\246\345\233\276", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(t1), QApplication::translate("QtGuiApplication3Class", "\346\240\267\346\234\254\345\233\276", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(t2), QApplication::translate("QtGuiApplication3Class", "\345\270\270\350\247\204\345\233\276", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(t3), QApplication::translate("QtGuiApplication3Class", "\350\264\250\346\216\247\345\233\276", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(t4), QApplication::translate("QtGuiApplication3Class", "\345\256\232\346\240\207\346\233\262\347\272\277", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(t5), QApplication::translate("QtGuiApplication3Class", "\345\217\215\345\272\224\346\265\223\345\272\246\345\233\276", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class QtGuiApplication3Class: public Ui_QtGuiApplication3Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTGUIAPPLICATION3_H
