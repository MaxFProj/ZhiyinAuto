/****************************************************************************
** Meta object code from reading C++ file 'interfaces.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../common/interfaces.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'interfaces.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MeshLabFilterInterface_t {
    QByteArrayData data[5];
    char stringdata0[66];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MeshLabFilterInterface_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MeshLabFilterInterface_t qt_meta_stringdata_MeshLabFilterInterface = {
    {
QT_MOC_LITERAL(0, 0, 22), // "MeshLabFilterInterface"
QT_MOC_LITERAL(1, 23, 22), // "renderingDataRequested"
QT_MOC_LITERAL(2, 46, 0), // ""
QT_MOC_LITERAL(3, 47, 12), // "setInterrupt"
QT_MOC_LITERAL(4, 60, 5) // "inter"

    },
    "MeshLabFilterInterface\0renderingDataRequested\0"
    "\0setInterrupt\0inter"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MeshLabFilterInterface[] = {

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
       3,    1,   27,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    4,

       0        // eod
};

void MeshLabFilterInterface::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MeshLabFilterInterface *_t = static_cast<MeshLabFilterInterface *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->renderingDataRequested((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->setInterrupt((*reinterpret_cast< const bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MeshLabFilterInterface::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MeshLabFilterInterface::renderingDataRequested)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject MeshLabFilterInterface::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_MeshLabFilterInterface.data,
      qt_meta_data_MeshLabFilterInterface,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MeshLabFilterInterface::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MeshLabFilterInterface::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MeshLabFilterInterface.stringdata0))
        return static_cast<void*>(const_cast< MeshLabFilterInterface*>(this));
    if (!strcmp(_clname, "MeshLabInterface"))
        return static_cast< MeshLabInterface*>(const_cast< MeshLabFilterInterface*>(this));
    return QObject::qt_metacast(_clname);
}

int MeshLabFilterInterface::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
void MeshLabFilterInterface::renderingDataRequested(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
