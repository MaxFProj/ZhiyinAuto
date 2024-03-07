/****************************************************************************
** Meta object code from reading C++ file 'multiViewer_Container.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../multiViewer_Container.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'multiViewer_Container.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Splitter_t {
    QByteArrayData data[1];
    char stringdata0[9];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Splitter_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Splitter_t qt_meta_stringdata_Splitter = {
    {
QT_MOC_LITERAL(0, 0, 8) // "Splitter"

    },
    "Splitter"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Splitter[] = {

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

void Splitter::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject Splitter::staticMetaObject = {
    { &QSplitter::staticMetaObject, qt_meta_stringdata_Splitter.data,
      qt_meta_data_Splitter,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Splitter::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Splitter::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Splitter.stringdata0))
        return static_cast<void*>(const_cast< Splitter*>(this));
    return QSplitter::qt_metacast(_clname);
}

int Splitter::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QSplitter::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
struct qt_meta_stringdata_SplitterHandle_t {
    QByteArrayData data[1];
    char stringdata0[15];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SplitterHandle_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SplitterHandle_t qt_meta_stringdata_SplitterHandle = {
    {
QT_MOC_LITERAL(0, 0, 14) // "SplitterHandle"

    },
    "SplitterHandle"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SplitterHandle[] = {

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

void SplitterHandle::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject SplitterHandle::staticMetaObject = {
    { &QSplitterHandle::staticMetaObject, qt_meta_stringdata_SplitterHandle.data,
      qt_meta_data_SplitterHandle,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *SplitterHandle::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SplitterHandle::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_SplitterHandle.stringdata0))
        return static_cast<void*>(const_cast< SplitterHandle*>(this));
    return QSplitterHandle::qt_metacast(_clname);
}

int SplitterHandle::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QSplitterHandle::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
struct qt_meta_stringdata_MultiViewer_Container_t {
    QByteArrayData data[7];
    char stringdata0[116];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MultiViewer_Container_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MultiViewer_Container_t qt_meta_stringdata_MultiViewer_Container = {
    {
QT_MOC_LITERAL(0, 0, 21), // "MultiViewer_Container"
QT_MOC_LITERAL(1, 22, 21), // "updateMainWindowMenus"
QT_MOC_LITERAL(2, 44, 0), // ""
QT_MOC_LITERAL(3, 45, 20), // "updateDocumentViewer"
QT_MOC_LITERAL(4, 66, 27), // "closingMultiViewerContainer"
QT_MOC_LITERAL(5, 94, 13), // "updateCurrent"
QT_MOC_LITERAL(6, 108, 7) // "current"

    },
    "MultiViewer_Container\0updateMainWindowMenus\0"
    "\0updateDocumentViewer\0closingMultiViewerContainer\0"
    "updateCurrent\0current"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MultiViewer_Container[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x06 /* Public */,
       3,    0,   35,    2, 0x06 /* Public */,
       4,    0,   36,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   37,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    6,

       0        // eod
};

void MultiViewer_Container::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MultiViewer_Container *_t = static_cast<MultiViewer_Container *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->updateMainWindowMenus(); break;
        case 1: _t->updateDocumentViewer(); break;
        case 2: _t->closingMultiViewerContainer(); break;
        case 3: _t->updateCurrent((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MultiViewer_Container::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MultiViewer_Container::updateMainWindowMenus)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (MultiViewer_Container::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MultiViewer_Container::updateDocumentViewer)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (MultiViewer_Container::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MultiViewer_Container::closingMultiViewerContainer)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject MultiViewer_Container::staticMetaObject = {
    { &Splitter::staticMetaObject, qt_meta_stringdata_MultiViewer_Container.data,
      qt_meta_data_MultiViewer_Container,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MultiViewer_Container::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MultiViewer_Container::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MultiViewer_Container.stringdata0))
        return static_cast<void*>(const_cast< MultiViewer_Container*>(this));
    return Splitter::qt_metacast(_clname);
}

int MultiViewer_Container::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Splitter::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void MultiViewer_Container::updateMainWindowMenus()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void MultiViewer_Container::updateDocumentViewer()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void MultiViewer_Container::closingMultiViewerContainer()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
