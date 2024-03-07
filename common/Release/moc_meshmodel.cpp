/****************************************************************************
** Meta object code from reading C++ file 'meshmodel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../meshmodel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'meshmodel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MeshDocument_t {
    QByteArrayData data[13];
    char stringdata0[175];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MeshDocument_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MeshDocument_t qt_meta_stringdata_MeshDocument = {
    {
QT_MOC_LITERAL(0, 0, 12), // "MeshDocument"
QT_MOC_LITERAL(1, 13, 18), // "currentMeshChanged"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 5), // "index"
QT_MOC_LITERAL(4, 39, 20), // "meshDocumentModified"
QT_MOC_LITERAL(5, 60, 14), // "meshSetChanged"
QT_MOC_LITERAL(6, 75, 9), // "meshAdded"
QT_MOC_LITERAL(7, 85, 11), // "meshRemoved"
QT_MOC_LITERAL(8, 97, 16), // "rasterSetChanged"
QT_MOC_LITERAL(9, 114, 15), // "documentUpdated"
QT_MOC_LITERAL(10, 130, 14), // "resetTrackball"
QT_MOC_LITERAL(11, 145, 16), // "addNewDockWidget"
QT_MOC_LITERAL(12, 162, 12) // "QDockWidget*"

    },
    "MeshDocument\0currentMeshChanged\0\0index\0"
    "meshDocumentModified\0meshSetChanged\0"
    "meshAdded\0meshRemoved\0rasterSetChanged\0"
    "documentUpdated\0resetTrackball\0"
    "addNewDockWidget\0QDockWidget*"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MeshDocument[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       9,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x06 /* Public */,
       4,    0,   62,    2, 0x06 /* Public */,
       5,    0,   63,    2, 0x06 /* Public */,
       6,    1,   64,    2, 0x06 /* Public */,
       7,    1,   67,    2, 0x06 /* Public */,
       8,    0,   70,    2, 0x06 /* Public */,
       9,    0,   71,    2, 0x06 /* Public */,
      10,    0,   72,    2, 0x06 /* Public */,
      11,    2,   73,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 12, QMetaType::Bool,    2,    2,

       0        // eod
};

void MeshDocument::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MeshDocument *_t = static_cast<MeshDocument *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->currentMeshChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->meshDocumentModified(); break;
        case 2: _t->meshSetChanged(); break;
        case 3: _t->meshAdded((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->meshRemoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->rasterSetChanged(); break;
        case 6: _t->documentUpdated(); break;
        case 7: _t->resetTrackball(); break;
        case 8: _t->addNewDockWidget((*reinterpret_cast< QDockWidget*(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 8:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QDockWidget* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MeshDocument::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MeshDocument::currentMeshChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (MeshDocument::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MeshDocument::meshDocumentModified)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (MeshDocument::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MeshDocument::meshSetChanged)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (MeshDocument::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MeshDocument::meshAdded)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (MeshDocument::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MeshDocument::meshRemoved)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (MeshDocument::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MeshDocument::rasterSetChanged)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (MeshDocument::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MeshDocument::documentUpdated)) {
                *result = 6;
                return;
            }
        }
        {
            typedef void (MeshDocument::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MeshDocument::resetTrackball)) {
                *result = 7;
                return;
            }
        }
        {
            typedef void (MeshDocument::*_t)(QDockWidget * , bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MeshDocument::addNewDockWidget)) {
                *result = 8;
                return;
            }
        }
    }
}

const QMetaObject MeshDocument::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_MeshDocument.data,
      qt_meta_data_MeshDocument,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MeshDocument::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MeshDocument::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MeshDocument.stringdata0))
        return static_cast<void*>(const_cast< MeshDocument*>(this));
    return QObject::qt_metacast(_clname);
}

int MeshDocument::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void MeshDocument::currentMeshChanged(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MeshDocument::meshDocumentModified()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void MeshDocument::meshSetChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void MeshDocument::meshAdded(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void MeshDocument::meshRemoved(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void MeshDocument::rasterSetChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, Q_NULLPTR);
}

// SIGNAL 6
void MeshDocument::documentUpdated()
{
    QMetaObject::activate(this, &staticMetaObject, 6, Q_NULLPTR);
}

// SIGNAL 7
void MeshDocument::resetTrackball()
{
    QMetaObject::activate(this, &staticMetaObject, 7, Q_NULLPTR);
}

// SIGNAL 8
void MeshDocument::addNewDockWidget(QDockWidget * _t1, bool _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}
QT_END_MOC_NAMESPACE
