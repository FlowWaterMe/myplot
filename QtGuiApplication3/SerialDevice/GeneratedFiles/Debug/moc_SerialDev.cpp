/****************************************************************************
** Meta object code from reading C++ file 'SerialDev.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../SerialDev.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SerialDev.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CSerialDev_t {
    QByteArrayData data[15];
    char stringdata0[179];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CSerialDev_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CSerialDev_t qt_meta_stringdata_CSerialDev = {
    {
QT_MOC_LITERAL(0, 0, 10), // "CSerialDev"
QT_MOC_LITERAL(1, 11, 17), // "SignalReceiveData"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 18), // "SignalConnectState"
QT_MOC_LITERAL(4, 49, 10), // "bIsConnect"
QT_MOC_LITERAL(5, 60, 11), // "SignalClose"
QT_MOC_LITERAL(6, 72, 15), // "SignalWriteData"
QT_MOC_LITERAL(7, 88, 13), // "SignalOpenDev"
QT_MOC_LITERAL(8, 102, 13), // "SlotReadyData"
QT_MOC_LITERAL(9, 116, 9), // "SlotClose"
QT_MOC_LITERAL(10, 126, 13), // "SlotWriteData"
QT_MOC_LITERAL(11, 140, 5), // "sData"
QT_MOC_LITERAL(12, 146, 8), // "byteData"
QT_MOC_LITERAL(13, 155, 11), // "SlotOpenDev"
QT_MOC_LITERAL(14, 167, 11) // "SerialParam"

    },
    "CSerialDev\0SignalReceiveData\0\0"
    "SignalConnectState\0bIsConnect\0SignalClose\0"
    "SignalWriteData\0SignalOpenDev\0"
    "SlotReadyData\0SlotClose\0SlotWriteData\0"
    "sData\0byteData\0SlotOpenDev\0SerialParam"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CSerialDev[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x06 /* Public */,
       3,    1,   70,    2, 0x06 /* Public */,
       5,    0,   73,    2, 0x06 /* Public */,
       6,    1,   74,    2, 0x06 /* Public */,
       6,    1,   77,    2, 0x06 /* Public */,
       7,    1,   80,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,   83,    2, 0x08 /* Private */,
       9,    0,   84,    2, 0x08 /* Private */,
      10,    1,   85,    2, 0x08 /* Private */,
      10,    1,   88,    2, 0x08 /* Private */,
      13,    1,   91,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QByteArray,    2,
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void, QMetaType::QByteArray,   12,
    QMetaType::Void, QMetaType::QString,   14,

       0        // eod
};

void CSerialDev::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CSerialDev *_t = static_cast<CSerialDev *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->SignalReceiveData(); break;
        case 1: _t->SignalConnectState((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->SignalClose(); break;
        case 3: _t->SignalWriteData((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->SignalWriteData((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 5: _t->SignalOpenDev((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->SlotReadyData(); break;
        case 7: _t->SlotClose(); break;
        case 8: _t->SlotWriteData((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: _t->SlotWriteData((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 10: _t->SlotOpenDev((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CSerialDev::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CSerialDev::SignalReceiveData)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (CSerialDev::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CSerialDev::SignalConnectState)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (CSerialDev::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CSerialDev::SignalClose)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (CSerialDev::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CSerialDev::SignalWriteData)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (CSerialDev::*_t)(QByteArray );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CSerialDev::SignalWriteData)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (CSerialDev::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CSerialDev::SignalOpenDev)) {
                *result = 5;
                return;
            }
        }
    }
}

const QMetaObject CSerialDev::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_CSerialDev.data,
      qt_meta_data_CSerialDev,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *CSerialDev::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CSerialDev::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CSerialDev.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int CSerialDev::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void CSerialDev::SignalReceiveData()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void CSerialDev::SignalConnectState(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void CSerialDev::SignalClose()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void CSerialDev::SignalWriteData(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void CSerialDev::SignalWriteData(QByteArray _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void CSerialDev::SignalOpenDev(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
