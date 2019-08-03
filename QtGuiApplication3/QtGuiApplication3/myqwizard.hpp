#pragma once
#include <QWizard>
#include <QFile>
#include <QMessageBox>
#include <QLabel>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QCheckBox>
#include <QGroupBox>
#include <QRadioButton>
#include <QDir>
#include <QRegularExpression>
QT_BEGIN_NAMESPACE
class QCheckBox;
class QGroupBox;
class QLabel;
class QLineEdit;
class QRadioButton;
QT_END_NAMESPACE
class MyQwizard : public QWizard {
	Q_OBJECT

public:
	MyQwizard(QWidget * parent = Q_NULLPTR);
	~MyQwizard();
	void accept() override;
private:
	
};
class IntroPage : public QWizardPage
{
	Q_OBJECT

public:
	IntroPage(QWidget *parent = 0);

private:
	QLabel *label;
};
class ClassInfoPage : public QWizardPage
{
	Q_OBJECT

public:
	ClassInfoPage(QWidget *parent = 0);

private:
	QLabel *classNameLabel;
	QLabel *baseClassLabel;
	QLineEdit *classNameLineEdit;
	QLineEdit *baseClassLineEdit;
	QCheckBox *qobjectMacroCheckBox;
	QGroupBox *groupBox;
	QRadioButton *qobjectCtorRadioButton;
	QRadioButton *qwidgetCtorRadioButton;
	QRadioButton *defaultCtorRadioButton;
	QCheckBox *copyCtorCheckBox;
};

class CodeStylePage : public QWizardPage
{
	Q_OBJECT

public:
	CodeStylePage(QWidget *parent = 0);

protected:
	void initializePage() override;

private:
	QCheckBox *commentCheckBox;
	QCheckBox *protectCheckBox;
	QCheckBox *includeBaseCheckBox;
	QLabel *macroNameLabel;
	QLabel *baseIncludeLabel;
	QLineEdit *macroNameLineEdit;
	QLineEdit *baseIncludeLineEdit;
};

class OutputFilesPage : public QWizardPage
{
	Q_OBJECT

public:
	OutputFilesPage(QWidget *parent = 0);

protected:
	void initializePage() override;

private:
	QLabel *outputDirLabel;
	QLabel *headerLabel;
	QLabel *implementationLabel;
	QLineEdit *outputDirLineEdit;
	QLineEdit *headerLineEdit;
	QLineEdit *implementationLineEdit;
};

class ConclusionPage : public QWizardPage
{
	Q_OBJECT

public:
	ConclusionPage(QWidget *parent = 0);

protected:
	void initializePage() override;

private:
	QLabel *label;
};