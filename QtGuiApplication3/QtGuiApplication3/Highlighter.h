#pragma once

#include <QObject>
#include <QSyntaxHighlighter>
#include <QTextCharFormat>
#include <QRegularExpression>
class Highlighter : public QSyntaxHighlighter
{
	Q_OBJECT

public:
	Highlighter(QTextDocument  *parent = 0);
	~Highlighter();
protected:
	void highlightBlock(const QString &text) override;//��д����������� �Զ�����
private:

	struct HighlightingRule//�﷨����ṹ�壬����������ʽģʽ����ƥ�����ʽ  
	{
		QRegularExpression pattern;
		QTextCharFormat format;
	};
	QVector<HighlightingRule> highlightingRules;//����ļ��ϣ����Զ�������������

	QRegularExpression commentStartExpression; //ע�͵ĸ�����ʹ��highliangBlock()ƥ�䣬�����ᵽ
	QRegularExpression commentEndExpression;

	QTextCharFormat keywordFormat;//������ʽ���ؼ��ʣ�һ�¹���˼��
	QTextCharFormat classFormat;
	QTextCharFormat singleLineCommentFormat;
	QTextCharFormat multiLineCommentFormat;
	QTextCharFormat quotationFormat;
	QTextCharFormat functionFormat;

};
