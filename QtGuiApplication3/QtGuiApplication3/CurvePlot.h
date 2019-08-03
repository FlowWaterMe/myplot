#pragma once

#include "qcustomplot.h"
#include <QFont>
#include <QPen>
#include <QBrush>
#include "AppParam.h"


class CCurvePlot : public QCustomPlot
{
    Q_OBJECT
public:
    CCurvePlot(QWidget* parent = nullptr);
    ~CCurvePlot();

public:
    void InitCurvePlot(const SCurveParam& CurveParam);
    void ClearCurvePlot();

    void SetData(const QVector<SCurvePoint>& vecData);
    void AppendData(const QVector<SCurvePoint>& vecData);

    void SaveBmp(QImage &m_image);

    void SetXName(QString sXName);
    void SetYName(QString sYName);

private:
    EClickRule m_eClickRule;
    QCPItemText* m_pPointText;
    QCPItemTracer* m_pPointHint;

private slots:
    void SlotSelectPoint(QMouseEvent*); 
};