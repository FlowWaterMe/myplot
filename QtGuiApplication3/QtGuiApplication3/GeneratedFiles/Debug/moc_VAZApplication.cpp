/****************************************************************************
** Meta object code from reading C++ file 'VAZApplication.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../VAZApplication.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'VAZApplication.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CVAZApplication_t {
    QByteArrayData data[8];
    char stringdata0[115];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CVAZApplication_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CVAZApplication_t qt_meta_stringdata_CVAZApplication = {
    {
QT_MOC_LITERAL(0, 0, 15), // "CVAZApplication"
QT_MOC_LITERAL(1, 16, 25), // "SignalNotifyKeyPressEvent"
QT_MOC_LITERAL(2, 42, 0), // ""
QT_MOC_LITERAL(3, 43, 7), // "iKeyVal"
QT_MOC_LITERAL(4, 51, 8), // "sObjName"
QT_MOC_LITERAL(5, 60, 30), // "SignalNotifyMouseBtnPressEvent"
QT_MOC_LITERAL(6, 91, 9), // "SlotsQuit"
QT_MOC_LITERAL(7, 101, 13) // "bIsQiutWindow"

    },
    "CVAZApplication\0SignalNotifyKeyPressEvent\0"
    "\0iKeyVal\0sObjName\0SignalNotifyMouseBtnPressEvent\0"
    "SlotsQuit\0bIsQiutWindow"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CVAZApplication[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   29,    2, 0x06 /* Public */,
       5,    0,   34,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,   35,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::UInt, QMetaType::QString,    3,    4,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    7,

       0        // eod
};

void CVAZApplication::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CVAZApplication *_t = static_cast<CVAZApplication *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->SignalNotifyKeyPressEvent((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: _t->SignalNotifyMouseBtnPressEvent(); break;
        case 2: _t->SlotsQuit((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CVAZApplication::*_t)(unsigned int , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CVAZApplication::SignalNotifyKeyPressEvent)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (CVAZApplication::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CVAZApplication::SignalNotifyMouseBtnPressEvent)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject CVAZApplication::staticMetaObject = {
    { &QApplication::staticMetaObject, qt_meta_stringdata_CVAZApplication.data,
      qt_meta_data_CVAZApplication,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *CVAZApplication::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CVAZApplication::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CVAZApplication.stringdata0))
        return static_cast<void*>(this);
    return QApplication::qt_metacast(_clname);
}

int CVAZApplication::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QApplication::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void CVAZApplication::SignalNotifyKeyPressEvent(unsigned int _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CVAZApplication::SignalNotifyMouseBtnPressEvent()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
