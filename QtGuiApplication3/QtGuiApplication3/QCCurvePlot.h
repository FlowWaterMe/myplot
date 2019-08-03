#pragma once

#include <QObject>
#include "qcustomplot.h"
#include <QFont>
#include <QPen>
#include <QBrush>
#include "AppParam.h"
#include <map>
class CMyQCPCurveData
{
public:
    CMyQCPCurveData();
    CMyQCPCurveData(double dKey, double dValue, QCPScatterStyle ScatterStyle = QCPScatterStyle());

public:
    inline double sortKey() const { return m_dKey; }
    inline static CMyQCPCurveData fromSortKey(double dKey) { return CMyQCPCurveData(dKey, 0); }
    inline static bool sortKeyIsMainKey() { return true; }

    inline double mainKey() const { return m_dKey; }
    inline double mainValue() const { return m_dValue; }

    inline QCPRange valueRange() const { return QCPRange(m_dValue, m_dValue); }

    double m_dKey, m_dValue;
    QCPScatterStyle m_ScatterStyle;
};
//Q_DECLARE_TYPEINFO(CMyQCPCurveData, Q_MOVABLE_TYPE);


typedef QCPDataContainer<CMyQCPCurveData> CMyQCPCurveDataContainer;

class CMyQCPCurve : public QCPAbstractPlottable1D<CMyQCPCurveData>
{
    Q_OBJECT

public:
    explicit CMyQCPCurve(QCPAxis *keyAxis, QCPAxis *valueAxis);

public:
    // getters:
    QSharedPointer<CMyQCPCurveDataContainer> data();
    bool adaptiveSampling() const { return m_AdaptiveSampling; }

    // setters:
    void setAdaptiveSampling(bool enabled) { m_AdaptiveSampling = enabled; }
    void setPointStyleSize(double size) { m_dPointStyleSize = size; }

    void clearData() { mDataContainer->clear(); }
    void setData(QSharedPointer<CMyQCPCurveDataContainer> data);
    void setData(const QVector<double>& keys, const QVector<double>& values, const QVector<QCPScatterStyle>& ScatterStyles = QVector<QCPScatterStyle>());


    void addData(const QVector<double>& keys, const QVector<double>& values, const QVector<QCPScatterStyle>& ScatterStyles = QVector<QCPScatterStyle>());
    void addData(double dKey, double dValue, QCPScatterStyle ScatterStyle = QCPScatterStyle());


    // reimplemented virtual methods:
    virtual double selectTest(const QPointF &pos, bool onlySelectable, QVariant *details = 0) const Q_DECL_OVERRIDE;
    virtual QCPRange getKeyRange(bool &foundRange, QCP::SignDomain inSignDomain = QCP::sdBoth) const Q_DECL_OVERRIDE;
    virtual QCPRange getValueRange(bool &foundRange, QCP::SignDomain inSignDomain = QCP::sdBoth, const QCPRange &inKeyRange = QCPRange()) const Q_DECL_OVERRIDE;

protected:
    double m_dPointStyleSize;
    bool m_AdaptiveSampling;

    void draw(QCPPainter *painter) Q_DECL_OVERRIDE;
    void drawLegendIcon(QCPPainter *painter, const QRectF &rect) const Q_DECL_OVERRIDE;

    void drawScatterPlot(QCPPainter *painter, const QVector<QPointF>& scatters, const QVector<QCPScatterStyle>& scatterStyles);

    // 获取有效数据
    void getVisibleDataBounds(CMyQCPCurveDataContainer::const_iterator& begin, CMyQCPCurveDataContainer::const_iterator& end, const QCPDataRange &rangeRestriction) const;
    void getOptimizedLineData(QVector<CMyQCPCurveData> *lineData, const CMyQCPCurveDataContainer::const_iterator &begin, const CMyQCPCurveDataContainer::const_iterator &end) const;
    QVector<QPointF> dataToLines(const QVector<CMyQCPCurveData> &data) const;
    QVector<QPointF> dataToScatter(const QVector<CMyQCPCurveData> &data) const;

    double pointDistance(const QPointF &pixelPoint, CMyQCPCurveDataContainer::const_iterator &closestData) const;

    friend class QCustomPlot;
    friend class QCPLegend;
};







struct SQcPlotPoint
{
    SQcPlotPoint(int iOrderID = 0, int iTestID = 0, double rx = 0, double ry = 0, int iQcRstType = 0, int iTimeType = 0, double dsd = 0)
        : iOrderID(iOrderID), iTestID(iTestID), dYData(ry), dXData(rx), iQcRstType(iQcRstType), iQcTimeType(iTimeType), dSD(dsd) {};

    int    iOrderID;
    int    iTestID;                         // 
    int    iQcRstType;                      // 0不知道；1在控；2警告；3失控
    int    iQcTimeType;                     // 质控时间类型0: 天间，1：实时
    double dXData;
    double dYData;
    double dSD;
};

class CQcPlot : public QCustomPlot
{
    Q_OBJECT
public:
    CQcPlot(QWidget* parent = nullptr);
    ~CQcPlot();

public:
    void SetQcPlotData(const QVector<SQcPlotPoint>& vecQcPoint);
    void ClearQcPlot();
    void SaveBmp(QImage &m_image);

private slots:
    void SlotSelectPoint(QMouseEvent*);

signals:
    void SignalSelectPoint(SQcPlotPoint);

private:
    CMyQCPCurve *m_pMyQCPCurve;
    QMap<int, SQcPlotPoint> m_mapPoint;
    QSharedPointer<QCPAxisTickerText> m_xAxisTick;
    QSharedPointer<QCPAxisTickerText> m_yAxisTick;
    QSharedPointer<QCPAxisTickerText> m_yAxis2Tick;

    void InitQcPolt();
    void SetTickText(QCPAxis *Axis, const QVector<QString>& vecText);
};