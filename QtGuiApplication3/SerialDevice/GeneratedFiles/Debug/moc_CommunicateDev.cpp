/****************************************************************************
** Meta object code from reading C++ file 'CommunicateDev.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../CommunicateDev.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CommunicateDev.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CCommunicateDev_t {
    QByteArrayData data[10];
    char stringdata0[118];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CCommunicateDev_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CCommunicateDev_t qt_meta_stringdata_CCommunicateDev = {
    {
QT_MOC_LITERAL(0, 0, 15), // "CCommunicateDev"
QT_MOC_LITERAL(1, 16, 17), // "SiganlReceiveData"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 3), // "iNo"
QT_MOC_LITERAL(4, 39, 5), // "sData"
QT_MOC_LITERAL(5, 45, 18), // "SignalConnectState"
QT_MOC_LITERAL(6, 64, 10), // "bIsConnect"
QT_MOC_LITERAL(7, 75, 11), // "SignalClose"
QT_MOC_LITERAL(8, 87, 15), // "SignalWriteData"
QT_MOC_LITERAL(9, 103, 14) // "SignalStartDev"

    },
    "CCommunicateDev\0SiganlReceiveData\0\0"
    "iNo\0sData\0SignalConnectState\0bIsConnect\0"
    "SignalClose\0SignalWriteData\0SignalStartDev"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CCommunicateDev[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   39,    2, 0x06 /* Public */,
       5,    2,   44,    2, 0x06 /* Public */,
       7,    0,   49,    2, 0x06 /* Public */,
       8,    1,   50,    2, 0x06 /* Public */,
       9,    1,   53,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    3,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,    3,    6,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,

       0        // eod
};

void CCommunicateDev::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CCommunicateDev *_t = static_cast<CCommunicateDev *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->SiganlReceiveData((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: _t->SignalConnectState((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 2: _t->SignalClose(); break;
        case 3: _t->SignalWriteData((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->SignalStartDev((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CCommunicateDev::*_t)(int , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CCommunicateDev::SiganlReceiveData)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (CCommunicateDev::*_t)(int , bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CCommunicateDev::SignalConnectState)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (CCommunicateDev::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CCommunicateDev::SignalClose)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (CCommunicateDev::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CCommunicateDev::SignalWriteData)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (CCommunicateDev::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CCommunicateDev::SignalStartDev)) {
                *result = 4;
                return;
            }
        }
    }
}

const QMetaObject CCommunicateDev::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_CCommunicateDev.data,
      qt_meta_data_CCommunicateDev,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *CCommunicateDev::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CCommunicateDev::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CCommunicateDev.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int CCommunicateDev::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void CCommunicateDev::SiganlReceiveData(int _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CCommunicateDev::SignalConnectState(int _t1, bool _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void CCommunicateDev::SignalClose()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void CCommunicateDev::SignalWriteData(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void CCommunicateDev::SignalStartDev(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
