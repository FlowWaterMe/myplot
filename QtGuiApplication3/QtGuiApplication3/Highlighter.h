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
	void highlightBlock(const QString &text) override;//重写父类这个函数 自动调用
private:

	struct HighlightingRule//语法规则结构体，包含正则表达式模式串和匹配的样式  
	{
		QRegularExpression pattern;
		QTextCharFormat format;
	};
	QVector<HighlightingRule> highlightingRules;//规则的集合，可以定义多个高亮规则

	QRegularExpression commentStartExpression; //注释的高亮，使用highliangBlock()匹配，下文提到
	QRegularExpression commentEndExpression;

	QTextCharFormat keywordFormat;//高亮样式，关键词，一下顾名思义
	QTextCharFormat classFormat;
	QTextCharFormat singleLineCommentFormat;
	QTextCharFormat multiLineCommentFormat;
	QTextCharFormat quotationFormat;
	QTextCharFormat functionFormat;

};
