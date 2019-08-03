#include "QCCurvePlot.h"

CMyQCPCurveData::CMyQCPCurveData()
    : m_dKey(0)
    , m_dValue(0)
    , m_ScatterStyle(QCPScatterStyle())
{

}

CMyQCPCurveData::CMyQCPCurveData(double dKey, double dValue, QCPScatterStyle ScatterStyle)
    : m_dKey(dKey)
    , m_dValue(dValue)
    , m_ScatterStyle(ScatterStyle)
{

}




CMyQCPCurve::CMyQCPCurve(QCPAxis *keyAxis, QCPAxis *valueAxis)
    : QCPAbstractPlottable1D<CMyQCPCurveData>(keyAxis, valueAxis)
    , m_dPointStyleSize(7)
    , m_AdaptiveSampling(true)
{

}

QSharedPointer<CMyQCPCurveDataContainer> CMyQCPCurve::data()
{
    return mDataContainer;
}


void CMyQCPCurve::setData(QSharedPointer<CMyQCPCurveDataContainer> data)
{
    mDataContainer = data;
}

void CMyQCPCurve::setData(const QVector<double> &keys, const QVector<double> &values, const QVector<QCPScatterStyle> &ScatterStyles)
{
    mDataContainer->clear();
    addData(keys, values, ScatterStyles);
}

void CMyQCPCurve::addData(const QVector<double> &keys, const QVector<double> &values, const QVector<QCPScatterStyle> &ScatterStyles)
{
    // todo: 一些必要的判断
    if (keys.empty() || values.empty())
    {
        qDebug() << Q_FUNC_INFO << "keys or values empty, size = " << keys.size() << " " << values.size();
        return;
    }

    const int isize = qMin(keys.size(), values.size());

    QVector<CMyQCPCurveData> tempData(isize);
    QVector<CMyQCPCurveData>::iterator it = tempData.begin();
    const QVector<CMyQCPCurveData>::iterator itEnd = tempData.end();
    int i = 0;
    while (it != itEnd)
    {
        it->m_dKey = keys[i];
        it->m_dValue = values[i];
        it->m_ScatterStyle = ScatterStyles[i];
        ++it;
        ++i;
    }

    mDataContainer->add(tempData);
}

void CMyQCPCurve::addData(double dKey, double dValue, QCPScatterStyle ScatterStyle)
{
    mDataContainer->add(CMyQCPCurveData(dKey, dValue, ScatterStyle));
}

double CMyQCPCurve::selectTest(const QPointF &pos, bool onlySelectable, QVariant *details) const
{
    if ((onlySelectable && mSelectable == QCP::stNone) || mDataContainer->isEmpty())
        return -1;
    if (!mKeyAxis || !mValueAxis)
        return -1;

    if (mKeyAxis.data()->axisRect()->rect().contains(pos.toPoint()))
    {
        CMyQCPCurveDataContainer::const_iterator closestDataPoint = mDataContainer->constEnd();
        double result = pointDistance(pos, closestDataPoint);
        if (details)
        {
            int pointIndex = closestDataPoint - mDataContainer->constBegin();
            details->setValue(QCPDataSelection(QCPDataRange(pointIndex, pointIndex + 1)));
        }
        return result;
    }
    else
        return -1;
}

/* inherits documentation from base class */
QCPRange CMyQCPCurve::getKeyRange(bool &foundRange, QCP::SignDomain inSignDomain) const
{
    return mDataContainer->keyRange(foundRange, inSignDomain);
}

/* inherits documentation from base class */
QCPRange CMyQCPCurve::getValueRange(bool &foundRange, QCP::SignDomain inSignDomain, const QCPRange &inKeyRange) const
{
    return mDataContainer->valueRange(foundRange, inSignDomain, inKeyRange);
}

void CMyQCPCurve::draw(QCPPainter *painter)
{
    if (mDataContainer->isEmpty())
        return;

    QCPAxis *keyAxis = mKeyAxis.data();
    QCPAxis *valueAxis = mValueAxis.data();
    if (!keyAxis || !valueAxis)
    {
        qDebug() << Q_FUNC_INFO << "invalid key or value axis";
        return;
    }

    //
    CMyQCPCurveDataContainer::const_iterator visibleBegin, visibleEnd;
    getVisibleDataBounds(visibleBegin, visibleEnd, QCPDataRange(0, dataCount()));

    // 有效数据特殊处理
    QVector<CMyQCPCurveData> lineData;
    getOptimizedLineData(&lineData, visibleBegin, visibleEnd);
    if (mKeyAxis->rangeReversed() != (mKeyAxis->orientation() == Qt::Vertical)) // make sure key pixels are sorted ascending in lineData (significantly simplifies following processing)
        std::reverse(lineData.begin(), lineData.end());

    //
    QVector<QPointF> lines;
    lines = dataToLines(lineData);

    //
    QVector<QCPScatterStyle> scatterStyles;
    scatterStyles.resize(lineData.size());
    for (int i = 0; i < lineData.size(); ++i)
        scatterStyles[i] = lineData[i].m_ScatterStyle;

    QVector<QPointF> scatters;
    scatters = dataToScatter(lineData);

    painter->setPen(mPen);
    painter->setBrush(mBrush);
    if (painter->pen().style() != Qt::NoPen && painter->pen().color().alpha() != 0)
    {
        applyDefaultAntialiasingHint(painter);
        // 画线
        drawPolyline(painter, lines);

        // 画点的形状
        drawScatterPlot(painter, scatters, scatterStyles);
    }
}

void CMyQCPCurve::drawLegendIcon(QCPPainter *painter, const QRectF &rect) const
{
    // draw fill:
    if (mBrush.style() != Qt::NoBrush)
    {
        applyFillAntialiasingHint(painter);
        painter->fillRect(QRectF(rect.left(), rect.top() + rect.height() / 2.0, rect.width(), rect.height() / 3.0), mBrush);
    }

    double iScatterSize = 8;
    double dheight = 20;

    QRectF textRect;
    int textHeight = 0;
    applyScattersAntialiasingHint(painter);
    for (int ii = 0; ii < 3; ++ii)
    {
        if (0 == ii)
        {
            textRect = painter->fontMetrics().boundingRect(0, 0, 0, dheight, Qt::TextDontClip, QStringLiteral("在控"));
            textHeight = qMax(textRect.height(), dheight);

            QCPScatterStyle ScatterStyle(QCPScatterStyle::ssCircle, QPen(Qt::green), QBrush(Qt::green), iScatterSize);
            ScatterStyle.applyTo(painter, QPen());
            ScatterStyle.drawShape(painter, QPointF(rect.left() + iScatterSize / 2, QRectF(rect).center().y()));

            painter->setPen(Qt::black);
            painter->drawText(rect.left() + iScatterSize + 5, rect.y(), textRect.width(), textHeight, Qt::TextDontClip, QStringLiteral("在控"));
        }
        else if (2 == ii)
        {
            textRect = painter->fontMetrics().boundingRect(0, 0, 0, dheight, Qt::TextDontClip, QStringLiteral("失控"));
            textHeight = qMax(textRect.height(), dheight);

            QCPScatterStyle ScatterStyle(QCPScatterStyle::ssSquare, QPen(Qt::red), QBrush(Qt::red), iScatterSize);
            ScatterStyle.applyTo(painter, QPen());
            ScatterStyle.drawShape(painter, QPointF(rect.left() + 80 + iScatterSize / 2, QRectF(rect).center().y()));

            painter->setPen(Qt::black);
            painter->drawText(rect.left() + 85 + iScatterSize, rect.y(), textRect.width(), textHeight, Qt::TextDontClip, QStringLiteral("失控"));
        }
        else
        {
            textRect = painter->fontMetrics().boundingRect(0, 0, 0, dheight, Qt::TextDontClip, QStringLiteral("警告"));
            textHeight = qMax(textRect.height(), dheight);

            QCPScatterStyle ScatterStyle(QCPScatterStyle::ssTriangle, QPen(Qt::darkYellow), QBrush(Qt::darkYellow), iScatterSize);
            ScatterStyle.applyTo(painter, QPen());
            ScatterStyle.drawShape(painter, QPointF(rect.left() + 40 + iScatterSize / 2, QRectF(rect).center().y()));

            painter->setPen(Qt::black);
            painter->drawText(rect.left() + 45 + iScatterSize, rect.y(), textRect.width(), textHeight, Qt::TextDontClip, QStringLiteral("警告"));
        }
    }
}

void CMyQCPCurve::drawScatterPlot(QCPPainter *painter, const QVector<QPointF> &scatters, const QVector<QCPScatterStyle> &scatterStyles)
{
    for (int i = 0; i < scatters.size(); ++i)
    {
        QCPScatterStyle style = scatterStyles.at(i);
        style.applyTo(painter, mPen);

        style.drawShape(painter, scatters.at(i).x(), scatters.at(i).y());
    }
}

void CMyQCPCurve::getVisibleDataBounds(CMyQCPCurveDataContainer::const_iterator &begin, CMyQCPCurveDataContainer::const_iterator &end, const QCPDataRange &rangeRestriction) const
{
    if (rangeRestriction.isEmpty())
    {
        end = mDataContainer->constEnd();
        begin = end;
    }
    else
    {
        QCPAxis *keyAxis = mKeyAxis.data();
        QCPAxis *valueAxis = mValueAxis.data();
        if (!keyAxis || !valueAxis)
        {
            qDebug() << Q_FUNC_INFO << "invalid key or value axis";
            return;
        }

        begin = mDataContainer->findBegin(keyAxis->range().lower);
        end = mDataContainer->findEnd(keyAxis->range().upper);
        mDataContainer->limitIteratorsToDataRange(begin, end, rangeRestriction);
    }
}

void CMyQCPCurve::getOptimizedLineData(QVector<CMyQCPCurveData> *lineData, const CMyQCPCurveDataContainer::const_iterator &begin, const CMyQCPCurveDataContainer::const_iterator &end) const
{
    if (!lineData)
        return;

    QCPAxis *keyAxis = mKeyAxis.data();
    QCPAxis *valueAxis = mValueAxis.data();
    if (!keyAxis || !valueAxis)
    {
        qDebug() << Q_FUNC_INFO << "invalid key or value axis";
        return;
    }

    if (begin == end)
        return;

    int dataCount = end - begin;
    int maxCount = (std::numeric_limits<int>::max)();
    if (m_AdaptiveSampling)
    {
        double keyPixelSpan = qAbs(keyAxis->coordToPixel(begin->m_dKey) - keyAxis->coordToPixel((end - 1)->m_dKey));
        if (2 * keyPixelSpan + 2 < static_cast<double>((std::numeric_limits<int>::max)()))
            maxCount = 2 * keyPixelSpan + 2;
    }

    if (false)
    {

    }
    else // don't use adaptive sampling algorithm, transfer points one-to-one from the data container into the output
    {
        lineData->resize(dataCount);
        std::copy(begin, end, lineData->begin());
    }
}

QVector<QPointF> CMyQCPCurve::dataToLines(const QVector<CMyQCPCurveData> &data) const
{
    QVector<QPointF> result;
    QCPAxis *keyAxis = mKeyAxis.data();
    QCPAxis *valueAxis = mValueAxis.data();
    if (!keyAxis || !valueAxis)
    {
        qDebug() << Q_FUNC_INFO << "invalid key or value axis";
        return QVector<QPointF>();
    }

    result.resize(data.size() - 2);

    // transform data points to pixels:
    if (keyAxis->orientation() == Qt::Vertical)
    {
        for (int i = 0; i < data.size() - 2; ++i)
        {
            result[i].setX(valueAxis->coordToPixel(data.at(i + 1).m_dValue));
            result[i].setY(keyAxis->coordToPixel(data.at(i + 1).m_dKey));
        }
    }
    else // key axis is horizontal
    {
        for (int i = 0; i < data.size() - 2; ++i)
        {
            result[i].setX(keyAxis->coordToPixel(data.at(i + 1).m_dKey));
            result[i].setY(valueAxis->coordToPixel(data.at(i + 1).m_dValue));
        }
    }
    return result;
}

QVector<QPointF> CMyQCPCurve::dataToScatter(const QVector<CMyQCPCurveData> &data) const
{
    QVector<QPointF> scatters;
    QCPAxis *keyAxis = mKeyAxis.data();
    QCPAxis *valueAxis = mValueAxis.data();
    if (!keyAxis || !valueAxis)
    {
        qDebug() << Q_FUNC_INFO << "invalid key or value axis";
        return QVector<QPointF>();
    }

    scatters.resize(data.size());
    if (keyAxis->orientation() == Qt::Vertical)
    {
        for (int i = 0; i < data.size(); ++i)
        {
            if (!qIsNaN(data.at(i).m_dValue))
            {
                scatters[i].setX(valueAxis->coordToPixel(data.at(i).m_dValue));
                scatters[i].setY(keyAxis->coordToPixel(data.at(i).m_dKey));
            }
        }
    }
    else
    {
        for (int i = 0; i < data.size(); ++i)
        {
            if (!qIsNaN(data.at(i).m_dValue))
            {
                scatters[i].setX(keyAxis->coordToPixel(data.at(i).m_dKey));
                scatters[i].setY(valueAxis->coordToPixel(data.at(i).m_dValue));
            }
        }
    }

    return scatters;
}

double CMyQCPCurve::pointDistance(const QPointF &pixelPoint, CMyQCPCurveDataContainer::const_iterator &closestData) const
{
    closestData = mDataContainer->constEnd();
    if (mDataContainer->isEmpty())
        return -1.0;

    //      if (mLineStyle == lsNone && mScatterStyle.isNone())
    //        return -1.0;

    // calculate minimum distances to graph data points and find closestData iterator:
    double minDistSqr = (std::numeric_limits<double>::max)();
    // determine which key range comes into question, taking selection tolerance around pos into account:
    double posKeyMin, posKeyMax, dummy;
    pixelsToCoords(pixelPoint - QPointF(mParentPlot->selectionTolerance(), mParentPlot->selectionTolerance()), posKeyMin, dummy);
    pixelsToCoords(pixelPoint + QPointF(mParentPlot->selectionTolerance(), mParentPlot->selectionTolerance()), posKeyMax, dummy);
    if (posKeyMin > posKeyMax)
        qSwap(posKeyMin, posKeyMax);
    // iterate over found data points and then choose the one with the shortest distance to pos:
    CMyQCPCurveDataContainer::const_iterator begin = mDataContainer->findBegin(posKeyMin, true);
    CMyQCPCurveDataContainer::const_iterator end = mDataContainer->findEnd(posKeyMax, true);
    for (CMyQCPCurveDataContainer::const_iterator it = begin; it != end; ++it)
    {
        const double currentDistSqr = QCPVector2D(coordsToPixels(it->m_dKey, it->m_dValue) - pixelPoint).lengthSquared();
        if (currentDistSqr < minDistSqr)
        {
            minDistSqr = currentDistSqr;
            closestData = it;
        }
    }

    // calculate distance to graph line if there is one (if so, will probably be smaller than distance to closest data point):
    //      if (mLineStyle != lsNone)
    //      {
    // line displayed, calculate distance to line segments:

    //getLines(&lineData, QCPDataRange(0, dataCount()));

    CMyQCPCurveDataContainer::const_iterator visibleBegin, visibleEnd;
    getVisibleDataBounds(visibleBegin, visibleEnd, QCPDataRange(0, dataCount()));

    // 有效数据特殊处理
    QVector<CMyQCPCurveData> lineData;
    getOptimizedLineData(&lineData, visibleBegin, visibleEnd);
    if (mKeyAxis->rangeReversed() != (mKeyAxis->orientation() == Qt::Vertical)) // make sure key pixels are sorted ascending in lineData (significantly simplifies following processing)
        std::reverse(lineData.begin(), lineData.end());

    QVector<QPointF> lines;
    lines = dataToLines(lineData);

    QCPVector2D p(pixelPoint);
    const int step = /*mLineStyle==lsImpulse ? 2 :*/ 1; // impulse plot differs from other line styles in that the lineData points are only pairwise connected
    for (int i = 0; i < lines.size() - 1; i += step)
    {
        const double currentDistSqr = p.distanceSquaredToLine(lines.at(i), lines.at(i + 1));
        if (currentDistSqr < minDistSqr)
            minDistSqr = currentDistSqr;
    }
    //      }

    return qSqrt(minDistSqr);
}



const static int st_iXTickCount = 36;
const static int st_iYTickCount = 7;
const static QVector<double> st_vecXTick = QVector<double>{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35};

CQcPlot::CQcPlot(QWidget* parent /*= nullptr*/)
    : QCustomPlot(parent)
{
    m_mapPoint.clear();
    connect(this, SIGNAL(mousePress(QMouseEvent*)), this, SLOT(SlotSelectPoint(QMouseEvent*)));
    InitQcPolt();
}

CQcPlot::~CQcPlot()
{
    disconnect(this, SIGNAL(mousePress(QMouseEvent*)), this, SLOT(SlotSelectPoint(QMouseEvent*)));
//    if(m_pMyQCPCurve) delete m_pMyQCPCurve;
}

void CQcPlot::InitQcPolt()
{
    legend->clear();
    legend->setFont(QFont("Microsoft YaHei", 9));
    legend->setVisible(true);
    legend->setIconSize(120, 18);

    m_pMyQCPCurve = new CMyQCPCurve(this->xAxis, this->yAxis);

    QVector<QString> vecText;
    vecText << "0" << "1SD" << "2SD" << "3SD" << "-1SD" << "-2SD" << "-3SD";
    m_xAxisTick = QSharedPointer<QCPAxisTickerText>(new QCPAxisTickerText);
    m_xAxisTick->addTicks(st_vecXTick, QVector<QString>(36));
    m_yAxisTick = QSharedPointer<QCPAxisTickerText>(new QCPAxisTickerText);
    m_yAxisTick->addTicks(QVector<double>{ 0, 1, 2, 3, -1, -2, -3 }, vecText);
    m_yAxis2Tick = QSharedPointer<QCPAxisTickerText>(new QCPAxisTickerText);
    m_yAxis2Tick->addTicks(QVector<double>{ 0, 1, 2, 3, -1, -2, -3 }, vecText);

    QPen pen;
    pen.setStyle(Qt::DotLine);
    pen.setWidth(2);
    pen.setColor(QColor(0, 89, 157));
    m_pMyQCPCurve->setPen(QPen(QColor(0, 89, 157), 2));

    yAxis->grid()->setPen(pen);
    yAxis->grid()->setZeroLinePen(pen);
    yAxis->setTicker(m_yAxisTick);
    m_yAxisTick->setTickCount(7);
    m_yAxisTick->setTickStepStrategy(QCPAxisTicker::tssMeetTickCount);
    yAxis->setRange(-4, 4);
    yAxis->setTickLabelFont(QFont("Microsoft YaHei", 9));
    yAxis->setLabelFont(QFont("Microsoft YaHei", 12));
    yAxis->setBasePen(QPen(QColor(0, 89, 157)));
    yAxis->setTickPen(QPen(QColor(0, 89, 157)));
    yAxis->setSubTickPen(QPen(QColor(0, 89, 157)));
    yAxis->setLabelColor(QColor(0, 89, 157));
    yAxis->setLabelPadding(0);
    yAxis->setLabel(QStringLiteral("标准差"));

    yAxis2->setVisible(true);
    yAxis2->grid()->setPen(pen);
    yAxis2->grid()->setZeroLinePen(pen);
    yAxis2->setTicker(m_yAxis2Tick);
    m_yAxis2Tick->setTickCount(7);
    yAxis2->setRange(-4, 4);
    yAxis2->setSubTicks(false);
    yAxis2->setTickLabelFont(QFont("Microsoft YaHei", 9));
    yAxis2->setLabelFont(QFont("Microsoft YaHei", 12));
    yAxis2->setBasePen(QPen(QColor(0, 89, 157)));
    yAxis2->setTickPen(QPen(QColor(0, 89, 157)));
    yAxis2->setSubTickPen(QPen(QColor(0, 89, 157)));
    yAxis2->setLabelColor(QColor(0, 89, 157));
    yAxis2->setLabelPadding(0);

    xAxis->setTicker(m_xAxisTick);
    xAxis->setTickLabelRotation(20);
    m_xAxisTick->setTickCount(36);
    xAxis->setRange(0, 35);
    xAxis->setSubTicks(false);
    xAxis->setTickLabelFont(QFont("Microsoft YaHei", 9));
    xAxis->setLabelFont(QFont("Microsoft YaHei", 12));
    xAxis->setBasePen(QPen(QColor(0, 89, 157)));
    xAxis->setTickPen(QPen(QColor(0, 89, 157)));
    xAxis->setLabelColor(QColor(0, 89, 157)); //0,147,211
    xAxis->setLabelPadding(0);
    xAxis->setLabel(QStringLiteral("时间"));
}

void CQcPlot::SetTickText(QCPAxis *Axis, const QVector<QString>& vecText)
{
    if (vecText.size() != Axis->ticker()->tickCount())
        return;

    if (Axis == yAxis2)
        m_yAxis2Tick->setTicks(QVector<double>{0, 1, 2, 3, -1, -2, -3}, vecText);
    else if(Axis == yAxis)
        m_yAxisTick->setTicks(QVector<double>{0, 1, 2, 3, -1, -2, -3}, vecText);
    else if (Axis == xAxis)
        m_xAxisTick->setTicks(st_vecXTick, vecText);
}

void CQcPlot::SetQcPlotData(const QVector<SQcPlotPoint>& vecQcPoint)
{
    ClearQcPlot();
    if (vecQcPoint.empty())
        return;

    QVector<double> vectorKey(vecQcPoint.size() + 2);
    QVector<double> vectorValue(vecQcPoint.size() + 2);
    QVector<QCPScatterStyle> vectorScatterStyle(vecQcPoint.size() + 2);

    QVector<QString> vecXText(xAxis->ticker()->tickCount());

    vectorKey[0] = 0;
    vectorValue[0] = 0;
    vectorScatterStyle[0] = QCPScatterStyle();

    auto it = vecQcPoint.begin();
    for (int ii = 1; it != vecQcPoint.end(); ++it, ++ii)
    {
        double dSD = it->dYData;
        if (qAbs(it->dYData) > 3.5) dSD = (it->dYData > 0) ? 3.5 : (-3.5);

        m_mapPoint[ii] = *it;

        vectorKey[ii] = ii;
        vectorValue[ii] = dSD;
        if (it->iQcRstType == 1)
            vectorScatterStyle[ii] = QCPScatterStyle(QCPScatterStyle::ssCircle, QPen(Qt::green), QBrush(Qt::green), 8);
        else if(it->iQcRstType == 2)
            vectorScatterStyle[ii] = QCPScatterStyle(QCPScatterStyle::ssTriangle, QPen(Qt::darkYellow), QBrush(Qt::darkYellow), 8);
        else
            vectorScatterStyle[ii] = QCPScatterStyle(QCPScatterStyle::ssSquare, QPen(Qt::red), QBrush(Qt::red), 8);

		vecXText[ii] = "1";// VAZConvStrT2Q(bool(it->iQcTimeType) ? VAZTimeToStr(it->dXData) : VAZDateToStr(it->dXData));
    }

    vectorKey[vecQcPoint.size() + 1] = vecQcPoint.size() + 1;
    vectorValue[vecQcPoint.size() + 1] = 0;
    vectorScatterStyle[vecQcPoint.size() + 1] = QCPScatterStyle();

    SetTickText(yAxis2, QVector<QString>() << "0" << QString::number(vecQcPoint.at(0).dSD, 'g', 3) << QString::number(2 * vecQcPoint.at(0).dSD, 'g', 3)
        << QString::number(3 * vecQcPoint.at(0).dSD, 'g', 3) << QString::number(-vecQcPoint.at(0).dSD, 'g', 3) << QString::number(-2 * vecQcPoint.at(0).dSD, 'g', 3) 
        << QString::number(-3 * vecQcPoint.at(0).dSD, 'g', 3));

    SetTickText(xAxis, vecXText);
    m_pMyQCPCurve->setData(vectorKey, vectorValue, vectorScatterStyle);
    rescaleAxes();
    yAxis->setRange(-4, 4);
    replot();
}

void CQcPlot::ClearQcPlot()
{
    m_pMyQCPCurve->clearData();
    m_mapPoint.clear();

    QVector<QString> vecText;
    vecText << "0" << "1SD" << "2SD" << "3SD" << "-1SD" << "-2SD" << "-3SD";
    SetTickText(yAxis2, vecText);
    SetTickText(xAxis, QVector<QString>(36));

    rescaleAxes();
    replot();
}

void CQcPlot::SaveBmp(QImage &image)
{
    QTransform trans;
    trans = trans.rotate(270);
    image = this->toPixmap(width(), 1.3*height(), 1).toImage().transformed(trans);
	replot();
}

void CQcPlot::SlotSelectPoint(QMouseEvent* qEvent)
{
    if (qEvent->button() == Qt::RightButton)
    {
        replot();
        return;
    }

    QPointF SelectedPoint = qEvent->localPos();

    //排除区间范围外的鼠标点
    if (!viewport().contains(qEvent->pos()))
    {
        replot();
        return;
    }

    QPointF Closest(INT_MAX, INT_MAX);
    qreal iDistance(INT_MAX);
    QSharedPointer<CMyQCPCurveDataContainer> qsharePoint = m_pMyQCPCurve->data();
    for (int ii = 0; ii < qsharePoint->size(); ii++)
    {
        int i = qsharePoint->at(ii)->m_dKey;
        qreal dPosX = xAxis->coordToPixel(qsharePoint->at(ii)->m_dKey);
        qreal dPosY = yAxis->coordToPixel(qsharePoint->at(ii)->m_dValue);

        QPointF currentPoint(dPosX, dPosY);
        qreal currentDistance = qSqrt((currentPoint.x() - SelectedPoint.x()) * (currentPoint.x() - SelectedPoint.x()) +
            (currentPoint.y() - SelectedPoint.y()) * (currentPoint.y() - SelectedPoint.y()));

        if (currentDistance < iDistance)
        {
            iDistance = currentDistance;
            Closest = currentPoint;
        }
    }

    if (iDistance < selectionTolerance())
    {
		int iKey = 5;// VAZRound(xAxis->pixelToCoord(Closest.x()));
        emit SignalSelectPoint(m_mapPoint[iKey]);
    }

    return;
}