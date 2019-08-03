/****************************************************************************
** Meta object code from reading C++ file 'QCCurvePlot.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../QCCurvePlot.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QCCurvePlot.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CMyQCPCurve_t {
    QByteArrayData data[1];
    char stringdata0[12];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CMyQCPCurve_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CMyQCPCurve_t qt_meta_stringdata_CMyQCPCurve = {
    {
QT_MOC_LITERAL(0, 0, 11) // "CMyQCPCurve"

    },
    "CMyQCPCurve"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CMyQCPCurve[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void CMyQCPCurve::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject CMyQCPCurve::staticMetaObject = {
    { &QCPAbstractPlottable1D<CMyQCPCurveData>::staticMetaObject, qt_meta_stringdata_CMyQCPCurve.data,
      qt_meta_data_CMyQCPCurve,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *CMyQCPCurve::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CMyQCPCurve::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CMyQCPCurve.stringdata0))
        return static_cast<void*>(this);
    return QCPAbstractPlottable1D<CMyQCPCurveData>::qt_metacast(_clname);
}

int CMyQCPCurve::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QCPAbstractPlottable1D<CMyQCPCurveData>::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_CQcPlot_t {
    QByteArrayData data[6];
    char stringdata0[69];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CQcPlot_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CQcPlot_t qt_meta_stringdata_CQcPlot = {
    {
QT_MOC_LITERAL(0, 0, 7), // "CQcPlot"
QT_MOC_LITERAL(1, 8, 17), // "SignalSelectPoint"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 12), // "SQcPlotPoint"
QT_MOC_LITERAL(4, 40, 15), // "SlotSelectPoint"
QT_MOC_LITERAL(5, 56, 12) // "QMouseEvent*"

    },
    "CQcPlot\0SignalSelectPoint\0\0SQcPlotPoint\0"
    "SlotSelectPoint\0QMouseEvent*"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CQcPlot[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   27,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 5,    2,

       0        // eod
};

void CQcPlot::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CQcPlot *_t = static_cast<CQcPlot *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->SignalSelectPoint((*reinterpret_cast< SQcPlotPoint(*)>(_a[1]))); break;
        case 1: _t->SlotSelectPoint((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CQcPlot::*_t)(SQcPlotPoint );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CQcPlot::SignalSelectPoint)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject CQcPlot::staticMetaObject = {
    { &QCustomPlot::staticMetaObject, qt_meta_stringdata_CQcPlot.data,
      qt_meta_data_CQcPlot,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *CQcPlot::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CQcPlot::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CQcPlot.stringdata0))
        return static_cast<void*>(this);
    return QCustomPlot::qt_metacast(_clname);
}

int CQcPlot::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QCustomPlot::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void CQcPlot::SignalSelectPoint(SQcPlotPoint _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
