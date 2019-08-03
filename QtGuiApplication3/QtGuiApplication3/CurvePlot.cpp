#include "CurvePlot.h"
#include <QVector>

CCurvePlot::CCurvePlot(QWidget* parent /*= nullptr*/)
    :QCustomPlot(parent)
    , m_eClickRule(eClickRule_Not)
{
    setBackground(QBrush(Qt::transparent));
    setStyleSheet("background-color: transparent;");
    connect(this, SIGNAL(mousePress(QMouseEvent*)), this, SLOT(SlotSelectPoint(QMouseEvent*)));

    m_pPointText = new QCPItemText(this);
    registerItem(m_pPointText);
    m_pPointText->position->setType(QCPItemPosition::ptAxisRectRatio);      // 设置文本坐标解析方式，前文中有提到QCPItemPosition类的PositionType枚举
    m_pPointText->setPositionAlignment(Qt::AlignRight | Qt::AlignBottom);   // 设置位置在矩形区域的位置
    m_pPointText->position->setCoords(1.0, 0.95);                           // 设置位置，注意第三行代码的枚举类型和这儿的值解析方式有关系
    m_pPointText->setText("");
    m_pPointText->setTextAlignment(Qt::AlignLeft);                          // 设置文本在矩形区域的位置
    m_pPointText->setFont(QFont(font().family(), 9));                       // 设置文本的字体
    m_pPointText->setPadding(QMargins(8, 0, 0, 0));                         // 设置文本所在矩形的margins

    m_pPointHint = new QCPItemTracer(this);
    m_pPointHint->setStyle(QCPItemTracer::tsCircle);
    m_pPointHint->setBrush(Qt::SolidPattern);
    registerItem(m_pPointHint);
    m_pPointHint->position->setPixelPosition(QPointF());

    xAxis->grid()->setSubGridVisible(true);
    xAxis->grid()->setPen(QPen(QColor(Qt::lightGray), 0, Qt::DotLine));
    xAxis->setUpperEnding(QCPLineEnding(QCPLineEnding::esSpikeArrow));
    yAxis->setUpperEnding(QCPLineEnding(QCPLineEnding::esSpikeArrow));
    xAxis->setTickLabelFont(QFont("Microsoft YaHei", 9));
    xAxis->setLabelFont(QFont("Microsoft YaHei", 12));
    yAxis->setTickLabelFont(QFont("Microsoft YaHei", 9));
    yAxis->setLabelFont(QFont("Microsoft YaHei", 12));
    xAxis->setBasePen(QPen(QColor(0, 89, 157)));
    xAxis->setTickPen(QPen(QColor(0, 89, 157)));
    xAxis->setSubTickPen(QPen(QColor(0, 89, 157)));
    yAxis->setBasePen(QPen(QColor(0, 89, 157)));
    yAxis->setTickPen(QPen(QColor(0, 89, 157)));
    yAxis->setSubTickPen(QPen(QColor(0, 89, 157)));

    xAxis->setLabelColor(QColor(0, 89, 157)); //0,147,211
    yAxis->setLabelColor(QColor(0, 89, 157));

    xAxis->setSubTicks(false);
    yAxis->grid()->setPen(QPen(QColor(Qt::lightGray), 0, Qt::DotLine));
    yAxis->setLabelPadding(0);
    xAxis->setLabelPadding(0);

    addGraph();
 }

CCurvePlot::~CCurvePlot()
{
    disconnect(this, SIGNAL(mousePress(QMouseEvent*)), this, SLOT(SlotSelectPoint(QMouseEvent*)));
}

void CCurvePlot::InitCurvePlot(const SCurveParam& CurveParam)
{
    legend->clear();
    legend->setFont(CurveParam.Plotfont);
    legend->setVisible(CurveParam.bIsDisplayLegend);

    xAxis->setLabel(CurveParam.sXName);
    yAxis->setLabel(CurveParam.sYName);
    xAxis->ticker()->setTickCount(CurveParam.XTickerNum);
    yAxis->ticker()->setTickCount(CurveParam.YTickerNum);
    xAxis->setTickLabelRotation(CurveParam.XLabelRotation);
    graph()->setPen(CurveParam.CurveStylePen);

    m_eClickRule = CurveParam.eClickRule;
    m_pPointHint->position->setPixelPosition(QPointF());
}


void CCurvePlot::ClearCurvePlot()
{
    graph()->setData(QVector<double>(), QVector<double>());
    rescaleAxes();
    replot();
}

void CCurvePlot::SetData(const QVector<SCurvePoint>& vecData)
{
    QVector<double> vecXValue;
    QVector<double> vecYValue;
    for (SCurvePoint PointData : vecData)
    {
        vecXValue.push_back(PointData.dXData);
        vecYValue.push_back(PointData.dYData);
    }

    graph()->setData(vecXValue, vecYValue);
    rescaleAxes();
    replot();
}


void CCurvePlot::AppendData(const QVector<SCurvePoint>& vecData)
{
    QVector<double> vecXValue;
    QVector<double> vecYValue;
    for (SCurvePoint PointData : vecData)
    {
        vecXValue.push_back(PointData.dXData);
        vecYValue.push_back(PointData.dYData);
    }

    graph()->addData(vecXValue, vecYValue);
    rescaleAxes();
    replot();
}

void CCurvePlot::SaveBmp(QImage &image)
{
    QTransform trans;
    trans = trans.rotate(270);
    image = toPixmap(width(), 1.1*height(), 0.6).toImage().transformed(trans);
}

void CCurvePlot::SetXName(QString sXName)
{
    xAxis->setLabel(sXName);
    replot();
}

void CCurvePlot::SetYName(QString sYName)
{
    yAxis->setLabel(sYName);
    replot();
}


void CCurvePlot::SlotSelectPoint(QMouseEvent* qEvent)
{
    m_pPointText->setText("");
    m_pPointHint->position->setPixelPosition(QPointF(0, 0));
    if (qEvent->button() == Qt::RightButton)
    {
        replot();
        return;
    }

    QPointF SelectedPoint = qEvent->localPos();

    //排除区间范围内的鼠标点
    if (!viewport().contains(qEvent->pos()))
    {
        replot();
        return;
    }

    QPointF Closest(INT_MAX, INT_MAX);
    qreal iDistance(INT_MAX);
    QSharedPointer<QCPGraphDataContainer> qsharePoint = graph(0)->data();
    int iSize = qsharePoint->size();
    for (int ii = 0; ii < qsharePoint->size(); ii++)
    {
        qreal dPosX = xAxis->coordToPixel(qsharePoint->at(ii)->key);
        qreal dPosY = yAxis->coordToPixel(qsharePoint->at(ii)->value);

        QPointF currentPoint(dPosX, dPosY);
        qreal currentDistance(INT_MAX);
        switch (m_eClickRule)
        {
        case eClickRule_Precise:
            currentDistance = qSqrt((currentPoint.x() - SelectedPoint.x()) * (currentPoint.x() - SelectedPoint.x()) +
                (currentPoint.y() - SelectedPoint.y()) * (currentPoint.y() - SelectedPoint.y()));
            break;
        case eClickRule_Round:
            currentDistance = qAbs(dPosX - SelectedPoint.x());
            break;
        default: return;
        }

        if (currentDistance < iDistance)
        {
            iDistance = currentDistance;
            Closest = currentPoint;
        }
    }

    if (iDistance < selectionTolerance())
    {
        double dKey = xAxis->pixelToCoord(Closest.x());
        double dValue = yAxis->pixelToCoord(Closest.y());
        m_pPointText->setText(QString("X: %1, Y: %2").arg(dKey).arg(dValue));
        m_pPointHint->position->setPixelPosition(QPointF(Closest.x(), Closest.y()));
    }

    replot();
    return;
}