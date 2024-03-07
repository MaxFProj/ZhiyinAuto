/****************************************************************************
** Meta object code from reading C++ file 'ml_render_gui.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../ml_render_gui.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ml_render_gui.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MLRenderingZeroOrOneActionGroup_t {
    QByteArrayData data[6];
    char stringdata0[66];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MLRenderingZeroOrOneActionGroup_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MLRenderingZeroOrOneActionGroup_t qt_meta_stringdata_MLRenderingZeroOrOneActionGroup = {
    {
QT_MOC_LITERAL(0, 0, 31), // "MLRenderingZeroOrOneActionGroup"
QT_MOC_LITERAL(1, 32, 12), // "setExclusive"
QT_MOC_LITERAL(2, 45, 0), // ""
QT_MOC_LITERAL(3, 46, 6), // "toggle"
QT_MOC_LITERAL(4, 53, 8), // "QAction*"
QT_MOC_LITERAL(5, 62, 3) // "act"

    },
    "MLRenderingZeroOrOneActionGroup\0"
    "setExclusive\0\0toggle\0QAction*\0act"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MLRenderingZeroOrOneActionGroup[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x08 /* Private */,
       3,    1,   27,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, 0x80000000 | 4,    5,

       0        // eod
};

void MLRenderingZeroOrOneActionGroup::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MLRenderingZeroOrOneActionGroup *_t = static_cast<MLRenderingZeroOrOneActionGroup *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setExclusive((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->toggle((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAction* >(); break;
            }
            break;
        }
    }
}

const QMetaObject MLRenderingZeroOrOneActionGroup::staticMetaObject = {
    { &QActionGroup::staticMetaObject, qt_meta_stringdata_MLRenderingZeroOrOneActionGroup.data,
      qt_meta_data_MLRenderingZeroOrOneActionGroup,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MLRenderingZeroOrOneActionGroup::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MLRenderingZeroOrOneActionGroup::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MLRenderingZeroOrOneActionGroup.stringdata0))
        return static_cast<void*>(const_cast< MLRenderingZeroOrOneActionGroup*>(this));
    return QActionGroup::qt_metacast(_clname);
}

int MLRenderingZeroOrOneActionGroup::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QActionGroup::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}
struct qt_meta_stringdata_MLRenderingColorPicker_t {
    QByteArrayData data[5];
    char stringdata0[76];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MLRenderingColorPicker_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MLRenderingColorPicker_t qt_meta_stringdata_MLRenderingColorPicker = {
    {
QT_MOC_LITERAL(0, 0, 22), // "MLRenderingColorPicker"
QT_MOC_LITERAL(1, 23, 22), // "userDefinedColorAction"
QT_MOC_LITERAL(2, 46, 0), // ""
QT_MOC_LITERAL(3, 47, 18), // "MLRenderingAction*"
QT_MOC_LITERAL(4, 66, 9) // "pickColor"

    },
    "MLRenderingColorPicker\0userDefinedColorAction\0"
    "\0MLRenderingAction*\0pickColor"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MLRenderingColorPicker[] = {

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
       1,    2,   24,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   29,    2, 0x09 /* Protected */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, 0x80000000 | 3,    2,    2,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void MLRenderingColorPicker::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MLRenderingColorPicker *_t = static_cast<MLRenderingColorPicker *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->userDefinedColorAction((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< MLRenderingAction*(*)>(_a[2]))); break;
        case 1: _t->pickColor(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< MLRenderingAction* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MLRenderingColorPicker::*_t)(int , MLRenderingAction * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MLRenderingColorPicker::userDefinedColorAction)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject MLRenderingColorPicker::staticMetaObject = {
    { &QPushButton::staticMetaObject, qt_meta_stringdata_MLRenderingColorPicker.data,
      qt_meta_data_MLRenderingColorPicker,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MLRenderingColorPicker::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MLRenderingColorPicker::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MLRenderingColorPicker.stringdata0))
        return static_cast<void*>(const_cast< MLRenderingColorPicker*>(this));
    return QPushButton::qt_metacast(_clname);
}

int MLRenderingColorPicker::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QPushButton::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void MLRenderingColorPicker::userDefinedColorAction(int _t1, MLRenderingAction * _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_MLRenderingFloatSlider_t {
    QByteArrayData data[5];
    char stringdata0[93];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MLRenderingFloatSlider_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MLRenderingFloatSlider_t qt_meta_stringdata_MLRenderingFloatSlider = {
    {
QT_MOC_LITERAL(0, 0, 22), // "MLRenderingFloatSlider"
QT_MOC_LITERAL(1, 23, 36), // "updateRenderingDataAccordingT..."
QT_MOC_LITERAL(2, 60, 0), // ""
QT_MOC_LITERAL(3, 61, 18), // "MLRenderingAction*"
QT_MOC_LITERAL(4, 80, 12) // "valueChanged"

    },
    "MLRenderingFloatSlider\0"
    "updateRenderingDataAccordingToAction\0"
    "\0MLRenderingAction*\0valueChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MLRenderingFloatSlider[] = {

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
       1,    3,   34,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   41,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, 0x80000000 | 3,    2,    2,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 3, QMetaType::Bool,    2,    2,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::Float,    2,

       0        // eod
};

void MLRenderingFloatSlider::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MLRenderingFloatSlider *_t = static_cast<MLRenderingFloatSlider *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->updateRenderingDataAccordingToAction((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< MLRenderingAction*(*)>(_a[2]))); break;
        case 1: _t->updateRenderingDataAccordingToAction((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< MLRenderingAction*(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 2: _t->valueChanged((*reinterpret_cast< float(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< MLRenderingAction* >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< MLRenderingAction* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MLRenderingFloatSlider::*_t)(int , MLRenderingAction * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MLRenderingFloatSlider::updateRenderingDataAccordingToAction)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (MLRenderingFloatSlider::*_t)(int , MLRenderingAction * , bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MLRenderingFloatSlider::updateRenderingDataAccordingToAction)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject MLRenderingFloatSlider::staticMetaObject = {
    { &MLFloatSlider::staticMetaObject, qt_meta_stringdata_MLRenderingFloatSlider.data,
      qt_meta_data_MLRenderingFloatSlider,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MLRenderingFloatSlider::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MLRenderingFloatSlider::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MLRenderingFloatSlider.stringdata0))
        return static_cast<void*>(const_cast< MLRenderingFloatSlider*>(this));
    return MLFloatSlider::qt_metacast(_clname);
}

int MLRenderingFloatSlider::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = MLFloatSlider::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void MLRenderingFloatSlider::updateRenderingDataAccordingToAction(int _t1, MLRenderingAction * _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MLRenderingFloatSlider::updateRenderingDataAccordingToAction(int _t1, MLRenderingAction * _t2, bool _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
struct qt_meta_stringdata_MLRenderingOnOffToolbar_t {
    QByteArrayData data[6];
    char stringdata0[97];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MLRenderingOnOffToolbar_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MLRenderingOnOffToolbar_t qt_meta_stringdata_MLRenderingOnOffToolbar = {
    {
QT_MOC_LITERAL(0, 0, 23), // "MLRenderingOnOffToolbar"
QT_MOC_LITERAL(1, 24, 36), // "updateRenderingDataAccordingT..."
QT_MOC_LITERAL(2, 61, 0), // ""
QT_MOC_LITERAL(3, 62, 18), // "MLRenderingAction*"
QT_MOC_LITERAL(4, 81, 6), // "toggle"
QT_MOC_LITERAL(5, 88, 8) // "QAction*"

    },
    "MLRenderingOnOffToolbar\0"
    "updateRenderingDataAccordingToAction\0"
    "\0MLRenderingAction*\0toggle\0QAction*"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MLRenderingOnOffToolbar[] = {

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
       1,    3,   34,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   41,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, 0x80000000 | 3,    2,    2,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 3, QMetaType::Bool,    2,    2,    2,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 5,    2,

       0        // eod
};

void MLRenderingOnOffToolbar::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MLRenderingOnOffToolbar *_t = static_cast<MLRenderingOnOffToolbar *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->updateRenderingDataAccordingToAction((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< MLRenderingAction*(*)>(_a[2]))); break;
        case 1: _t->updateRenderingDataAccordingToAction((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< MLRenderingAction*(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 2: _t->toggle((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< MLRenderingAction* >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< MLRenderingAction* >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAction* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MLRenderingOnOffToolbar::*_t)(int , MLRenderingAction * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MLRenderingOnOffToolbar::updateRenderingDataAccordingToAction)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (MLRenderingOnOffToolbar::*_t)(int , MLRenderingAction * , bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MLRenderingOnOffToolbar::updateRenderingDataAccordingToAction)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject MLRenderingOnOffToolbar::staticMetaObject = {
    { &QToolBar::staticMetaObject, qt_meta_stringdata_MLRenderingOnOffToolbar.data,
      qt_meta_data_MLRenderingOnOffToolbar,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MLRenderingOnOffToolbar::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MLRenderingOnOffToolbar::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MLRenderingOnOffToolbar.stringdata0))
        return static_cast<void*>(const_cast< MLRenderingOnOffToolbar*>(this));
    return QToolBar::qt_metacast(_clname);
}

int MLRenderingOnOffToolbar::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QToolBar::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void MLRenderingOnOffToolbar::updateRenderingDataAccordingToAction(int _t1, MLRenderingAction * _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MLRenderingOnOffToolbar::updateRenderingDataAccordingToAction(int _t1, MLRenderingAction * _t2, bool _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
struct qt_meta_stringdata_MLRenderingToolbar_t {
    QByteArrayData data[17];
    char stringdata0[347];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MLRenderingToolbar_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MLRenderingToolbar_t qt_meta_stringdata_MLRenderingToolbar = {
    {
QT_MOC_LITERAL(0, 0, 18), // "MLRenderingToolbar"
QT_MOC_LITERAL(1, 19, 37), // "updateRenderingDataAccordingT..."
QT_MOC_LITERAL(2, 57, 0), // ""
QT_MOC_LITERAL(3, 58, 25), // "QList<MLRenderingAction*>"
QT_MOC_LITERAL(4, 84, 18), // "MLRenderingAction*"
QT_MOC_LITERAL(5, 103, 26), // "QList<MLRenderingAction*>&"
QT_MOC_LITERAL(6, 130, 36), // "updateRenderingDataAccordingT..."
QT_MOC_LITERAL(7, 167, 15), // "activatedAction"
QT_MOC_LITERAL(8, 183, 38), // "setColorPickerAccordingToRend..."
QT_MOC_LITERAL(9, 222, 15), // "MLRenderingData"
QT_MOC_LITERAL(10, 238, 2), // "dt"
QT_MOC_LITERAL(11, 241, 48), // "getCurrentRenderingDataAccord..."
QT_MOC_LITERAL(12, 290, 16), // "MLRenderingData&"
QT_MOC_LITERAL(13, 307, 6), // "toggle"
QT_MOC_LITERAL(14, 314, 8), // "QAction*"
QT_MOC_LITERAL(15, 323, 3), // "act"
QT_MOC_LITERAL(16, 327, 19) // "extraUpdateRequired"

    },
    "MLRenderingToolbar\0"
    "updateRenderingDataAccordingToActions\0"
    "\0QList<MLRenderingAction*>\0"
    "MLRenderingAction*\0QList<MLRenderingAction*>&\0"
    "updateRenderingDataAccordingToAction\0"
    "activatedAction\0setColorPickerAccordingToRenderingData\0"
    "MLRenderingData\0dt\0"
    "getCurrentRenderingDataAccordingToColorPickerGUI\0"
    "MLRenderingData&\0toggle\0QAction*\0act\0"
    "extraUpdateRequired"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MLRenderingToolbar[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   54,    2, 0x06 /* Public */,
       1,    3,   59,    2, 0x06 /* Public */,
       6,    2,   66,    2, 0x06 /* Public */,
       7,    1,   71,    2, 0x06 /* Public */,
       8,    1,   74,    2, 0x06 /* Public */,
      11,    1,   77,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      13,    1,   80,    2, 0x09 /* Protected */,
      16,    2,   83,    2, 0x09 /* Protected */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, 0x80000000 | 3,    2,    2,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 4, 0x80000000 | 5,    2,    2,    2,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 4,    2,    2,
    QMetaType::Void, 0x80000000 | 4,    2,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, 0x80000000 | 12,   10,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 14,   15,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 4,    2,    2,

       0        // eod
};

void MLRenderingToolbar::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MLRenderingToolbar *_t = static_cast<MLRenderingToolbar *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->updateRenderingDataAccordingToActions((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QList<MLRenderingAction*>(*)>(_a[2]))); break;
        case 1: _t->updateRenderingDataAccordingToActions((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< MLRenderingAction*(*)>(_a[2])),(*reinterpret_cast< QList<MLRenderingAction*>(*)>(_a[3]))); break;
        case 2: _t->updateRenderingDataAccordingToAction((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< MLRenderingAction*(*)>(_a[2]))); break;
        case 3: _t->activatedAction((*reinterpret_cast< MLRenderingAction*(*)>(_a[1]))); break;
        case 4: _t->setColorPickerAccordingToRenderingData((*reinterpret_cast< const MLRenderingData(*)>(_a[1]))); break;
        case 5: _t->getCurrentRenderingDataAccordingToColorPickerGUI((*reinterpret_cast< MLRenderingData(*)>(_a[1]))); break;
        case 6: _t->toggle((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 7: _t->extraUpdateRequired((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< MLRenderingAction*(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<MLRenderingAction*> >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< MLRenderingAction* >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< MLRenderingAction* >(); break;
            }
            break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< MLRenderingAction* >(); break;
            }
            break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAction* >(); break;
            }
            break;
        case 7:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< MLRenderingAction* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MLRenderingToolbar::*_t)(int , const QList<MLRenderingAction*> & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MLRenderingToolbar::updateRenderingDataAccordingToActions)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (MLRenderingToolbar::*_t)(int , MLRenderingAction * , QList<MLRenderingAction*> & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MLRenderingToolbar::updateRenderingDataAccordingToActions)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (MLRenderingToolbar::*_t)(int , MLRenderingAction * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MLRenderingToolbar::updateRenderingDataAccordingToAction)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (MLRenderingToolbar::*_t)(MLRenderingAction * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MLRenderingToolbar::activatedAction)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (MLRenderingToolbar::*_t)(const MLRenderingData & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MLRenderingToolbar::setColorPickerAccordingToRenderingData)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (MLRenderingToolbar::*_t)(MLRenderingData & ) const;
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MLRenderingToolbar::getCurrentRenderingDataAccordingToColorPickerGUI)) {
                *result = 5;
                return;
            }
        }
    }
}

const QMetaObject MLRenderingToolbar::staticMetaObject = {
    { &QToolBar::staticMetaObject, qt_meta_stringdata_MLRenderingToolbar.data,
      qt_meta_data_MLRenderingToolbar,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MLRenderingToolbar::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MLRenderingToolbar::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MLRenderingToolbar.stringdata0))
        return static_cast<void*>(const_cast< MLRenderingToolbar*>(this));
    return QToolBar::qt_metacast(_clname);
}

int MLRenderingToolbar::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QToolBar::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void MLRenderingToolbar::updateRenderingDataAccordingToActions(int _t1, const QList<MLRenderingAction*> & _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MLRenderingToolbar::updateRenderingDataAccordingToActions(int _t1, MLRenderingAction * _t2, QList<MLRenderingAction*> & _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MLRenderingToolbar::updateRenderingDataAccordingToAction(int _t1, MLRenderingAction * _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MLRenderingToolbar::activatedAction(MLRenderingAction * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void MLRenderingToolbar::setColorPickerAccordingToRenderingData(const MLRenderingData & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void MLRenderingToolbar::getCurrentRenderingDataAccordingToColorPickerGUI(MLRenderingData & _t1)const
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(const_cast< MLRenderingToolbar *>(this), &staticMetaObject, 5, _a);
}
struct qt_meta_stringdata_MLRenderingSideToolbar_t {
    QByteArrayData data[5];
    char stringdata0[44];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MLRenderingSideToolbar_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MLRenderingSideToolbar_t qt_meta_stringdata_MLRenderingSideToolbar = {
    {
QT_MOC_LITERAL(0, 0, 22), // "MLRenderingSideToolbar"
QT_MOC_LITERAL(1, 23, 6), // "toggle"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 8), // "QAction*"
QT_MOC_LITERAL(4, 40, 3) // "act"

    },
    "MLRenderingSideToolbar\0toggle\0\0QAction*\0"
    "act"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MLRenderingSideToolbar[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   19,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

       0        // eod
};

void MLRenderingSideToolbar::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MLRenderingSideToolbar *_t = static_cast<MLRenderingSideToolbar *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->toggle((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAction* >(); break;
            }
            break;
        }
    }
}

const QMetaObject MLRenderingSideToolbar::staticMetaObject = {
    { &MLRenderingToolbar::staticMetaObject, qt_meta_stringdata_MLRenderingSideToolbar.data,
      qt_meta_data_MLRenderingSideToolbar,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MLRenderingSideToolbar::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MLRenderingSideToolbar::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MLRenderingSideToolbar.stringdata0))
        return static_cast<void*>(const_cast< MLRenderingSideToolbar*>(this));
    return MLRenderingToolbar::qt_metacast(_clname);
}

int MLRenderingSideToolbar::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = MLRenderingToolbar::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}
struct qt_meta_stringdata_MLRenderingParametersFrame_t {
    QByteArrayData data[7];
    char stringdata0[175];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MLRenderingParametersFrame_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MLRenderingParametersFrame_t qt_meta_stringdata_MLRenderingParametersFrame = {
    {
QT_MOC_LITERAL(0, 0, 26), // "MLRenderingParametersFrame"
QT_MOC_LITERAL(1, 27, 37), // "updateRenderingDataAccordingT..."
QT_MOC_LITERAL(2, 65, 0), // ""
QT_MOC_LITERAL(3, 66, 25), // "QList<MLRenderingAction*>"
QT_MOC_LITERAL(4, 92, 18), // "MLRenderingAction*"
QT_MOC_LITERAL(5, 111, 26), // "QList<MLRenderingAction*>&"
QT_MOC_LITERAL(6, 138, 36) // "updateRenderingDataAccordingT..."

    },
    "MLRenderingParametersFrame\0"
    "updateRenderingDataAccordingToActions\0"
    "\0QList<MLRenderingAction*>\0"
    "MLRenderingAction*\0QList<MLRenderingAction*>&\0"
    "updateRenderingDataAccordingToAction"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MLRenderingParametersFrame[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   34,    2, 0x06 /* Public */,
       1,    3,   39,    2, 0x06 /* Public */,
       6,    2,   46,    2, 0x06 /* Public */,
       6,    3,   51,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, 0x80000000 | 3,    2,    2,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 4, 0x80000000 | 5,    2,    2,    2,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 4,    2,    2,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 4, QMetaType::Bool,    2,    2,    2,

       0        // eod
};

void MLRenderingParametersFrame::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MLRenderingParametersFrame *_t = static_cast<MLRenderingParametersFrame *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->updateRenderingDataAccordingToActions((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QList<MLRenderingAction*>(*)>(_a[2]))); break;
        case 1: _t->updateRenderingDataAccordingToActions((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< MLRenderingAction*(*)>(_a[2])),(*reinterpret_cast< QList<MLRenderingAction*>(*)>(_a[3]))); break;
        case 2: _t->updateRenderingDataAccordingToAction((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< MLRenderingAction*(*)>(_a[2]))); break;
        case 3: _t->updateRenderingDataAccordingToAction((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< MLRenderingAction*(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<MLRenderingAction*> >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< MLRenderingAction* >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< MLRenderingAction* >(); break;
            }
            break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< MLRenderingAction* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MLRenderingParametersFrame::*_t)(int , const QList<MLRenderingAction*> & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MLRenderingParametersFrame::updateRenderingDataAccordingToActions)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (MLRenderingParametersFrame::*_t)(int , MLRenderingAction * , QList<MLRenderingAction*> & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MLRenderingParametersFrame::updateRenderingDataAccordingToActions)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (MLRenderingParametersFrame::*_t)(int , MLRenderingAction * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MLRenderingParametersFrame::updateRenderingDataAccordingToAction)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (MLRenderingParametersFrame::*_t)(int , MLRenderingAction * , bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MLRenderingParametersFrame::updateRenderingDataAccordingToAction)) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject MLRenderingParametersFrame::staticMetaObject = {
    { &QFrame::staticMetaObject, qt_meta_stringdata_MLRenderingParametersFrame.data,
      qt_meta_data_MLRenderingParametersFrame,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MLRenderingParametersFrame::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MLRenderingParametersFrame::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MLRenderingParametersFrame.stringdata0))
        return static_cast<void*>(const_cast< MLRenderingParametersFrame*>(this));
    return QFrame::qt_metacast(_clname);
}

int MLRenderingParametersFrame::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QFrame::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void MLRenderingParametersFrame::updateRenderingDataAccordingToActions(int _t1, const QList<MLRenderingAction*> & _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MLRenderingParametersFrame::updateRenderingDataAccordingToActions(int _t1, MLRenderingAction * _t2, QList<MLRenderingAction*> & _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MLRenderingParametersFrame::updateRenderingDataAccordingToAction(int _t1, MLRenderingAction * _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MLRenderingParametersFrame::updateRenderingDataAccordingToAction(int _t1, MLRenderingAction * _t2, bool _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
struct qt_meta_stringdata_MLRenderingGlobalToolbar_t {
    QByteArrayData data[10];
    char stringdata0[194];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MLRenderingGlobalToolbar_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MLRenderingGlobalToolbar_t qt_meta_stringdata_MLRenderingGlobalToolbar = {
    {
QT_MOC_LITERAL(0, 0, 24), // "MLRenderingGlobalToolbar"
QT_MOC_LITERAL(1, 25, 37), // "updateRenderingDataAccordingT..."
QT_MOC_LITERAL(2, 63, 0), // ""
QT_MOC_LITERAL(3, 64, 31), // "QList<MLRenderingGlobalAction*>"
QT_MOC_LITERAL(4, 96, 22), // "statusConsistencyCheck"
QT_MOC_LITERAL(5, 119, 51), // "MLSceneGLSharedDataContext::P..."
QT_MOC_LITERAL(6, 171, 2), // "mp"
QT_MOC_LITERAL(7, 174, 6), // "toggle"
QT_MOC_LITERAL(8, 181, 8), // "QAction*"
QT_MOC_LITERAL(9, 190, 3) // "act"

    },
    "MLRenderingGlobalToolbar\0"
    "updateRenderingDataAccordingToActions\0"
    "\0QList<MLRenderingGlobalAction*>\0"
    "statusConsistencyCheck\0"
    "MLSceneGLSharedDataContext::PerMeshRenderingDataMap\0"
    "mp\0toggle\0QAction*\0act"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MLRenderingGlobalToolbar[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   32,    2, 0x0a /* Public */,
       7,    1,   35,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, 0x80000000 | 8,    9,

       0        // eod
};

void MLRenderingGlobalToolbar::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MLRenderingGlobalToolbar *_t = static_cast<MLRenderingGlobalToolbar *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->updateRenderingDataAccordingToActions((*reinterpret_cast< QList<MLRenderingGlobalAction*>(*)>(_a[1]))); break;
        case 1: _t->statusConsistencyCheck((*reinterpret_cast< const MLSceneGLSharedDataContext::PerMeshRenderingDataMap(*)>(_a[1]))); break;
        case 2: _t->toggle((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<MLRenderingGlobalAction*> >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAction* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MLRenderingGlobalToolbar::*_t)(QList<MLRenderingGlobalAction*> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MLRenderingGlobalToolbar::updateRenderingDataAccordingToActions)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject MLRenderingGlobalToolbar::staticMetaObject = {
    { &QToolBar::staticMetaObject, qt_meta_stringdata_MLRenderingGlobalToolbar.data,
      qt_meta_data_MLRenderingGlobalToolbar,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MLRenderingGlobalToolbar::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MLRenderingGlobalToolbar::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MLRenderingGlobalToolbar.stringdata0))
        return static_cast<void*>(const_cast< MLRenderingGlobalToolbar*>(this));
    return QToolBar::qt_metacast(_clname);
}

int MLRenderingGlobalToolbar::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QToolBar::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void MLRenderingGlobalToolbar::updateRenderingDataAccordingToActions(QList<MLRenderingGlobalAction*> _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_MLRenderingSolidParametersFrame_t {
    QByteArrayData data[1];
    char stringdata0[32];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MLRenderingSolidParametersFrame_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MLRenderingSolidParametersFrame_t qt_meta_stringdata_MLRenderingSolidParametersFrame = {
    {
QT_MOC_LITERAL(0, 0, 31) // "MLRenderingSolidParametersFrame"

    },
    "MLRenderingSolidParametersFrame"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MLRenderingSolidParametersFrame[] = {

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

void MLRenderingSolidParametersFrame::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject MLRenderingSolidParametersFrame::staticMetaObject = {
    { &MLRenderingParametersFrame::staticMetaObject, qt_meta_stringdata_MLRenderingSolidParametersFrame.data,
      qt_meta_data_MLRenderingSolidParametersFrame,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MLRenderingSolidParametersFrame::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MLRenderingSolidParametersFrame::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MLRenderingSolidParametersFrame.stringdata0))
        return static_cast<void*>(const_cast< MLRenderingSolidParametersFrame*>(this));
    return MLRenderingParametersFrame::qt_metacast(_clname);
}

int MLRenderingSolidParametersFrame::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = MLRenderingParametersFrame::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
struct qt_meta_stringdata_MLRenderingWireParametersFrame_t {
    QByteArrayData data[4];
    char stringdata0[70];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MLRenderingWireParametersFrame_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MLRenderingWireParametersFrame_t qt_meta_stringdata_MLRenderingWireParametersFrame = {
    {
QT_MOC_LITERAL(0, 0, 30), // "MLRenderingWireParametersFrame"
QT_MOC_LITERAL(1, 31, 18), // "switchWireModality"
QT_MOC_LITERAL(2, 50, 0), // ""
QT_MOC_LITERAL(3, 51, 18) // "MLRenderingAction*"

    },
    "MLRenderingWireParametersFrame\0"
    "switchWireModality\0\0MLRenderingAction*"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MLRenderingWireParametersFrame[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   19,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, 0x80000000 | 3,    2,    2,

       0        // eod
};

void MLRenderingWireParametersFrame::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MLRenderingWireParametersFrame *_t = static_cast<MLRenderingWireParametersFrame *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->switchWireModality((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< MLRenderingAction*(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< MLRenderingAction* >(); break;
            }
            break;
        }
    }
}

const QMetaObject MLRenderingWireParametersFrame::staticMetaObject = {
    { &MLRenderingParametersFrame::staticMetaObject, qt_meta_stringdata_MLRenderingWireParametersFrame.data,
      qt_meta_data_MLRenderingWireParametersFrame,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MLRenderingWireParametersFrame::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MLRenderingWireParametersFrame::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MLRenderingWireParametersFrame.stringdata0))
        return static_cast<void*>(const_cast< MLRenderingWireParametersFrame*>(this));
    return MLRenderingParametersFrame::qt_metacast(_clname);
}

int MLRenderingWireParametersFrame::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = MLRenderingParametersFrame::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}
struct qt_meta_stringdata_MLRenderingPointsParametersFrame_t {
    QByteArrayData data[1];
    char stringdata0[33];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MLRenderingPointsParametersFrame_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MLRenderingPointsParametersFrame_t qt_meta_stringdata_MLRenderingPointsParametersFrame = {
    {
QT_MOC_LITERAL(0, 0, 32) // "MLRenderingPointsParametersFrame"

    },
    "MLRenderingPointsParametersFrame"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MLRenderingPointsParametersFrame[] = {

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

void MLRenderingPointsParametersFrame::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject MLRenderingPointsParametersFrame::staticMetaObject = {
    { &MLRenderingParametersFrame::staticMetaObject, qt_meta_stringdata_MLRenderingPointsParametersFrame.data,
      qt_meta_data_MLRenderingPointsParametersFrame,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MLRenderingPointsParametersFrame::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MLRenderingPointsParametersFrame::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MLRenderingPointsParametersFrame.stringdata0))
        return static_cast<void*>(const_cast< MLRenderingPointsParametersFrame*>(this));
    return MLRenderingParametersFrame::qt_metacast(_clname);
}

int MLRenderingPointsParametersFrame::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = MLRenderingParametersFrame::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
struct qt_meta_stringdata_MLRenderingSelectionParametersFrame_t {
    QByteArrayData data[1];
    char stringdata0[36];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MLRenderingSelectionParametersFrame_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MLRenderingSelectionParametersFrame_t qt_meta_stringdata_MLRenderingSelectionParametersFrame = {
    {
QT_MOC_LITERAL(0, 0, 35) // "MLRenderingSelectionParameter..."

    },
    "MLRenderingSelectionParametersFrame"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MLRenderingSelectionParametersFrame[] = {

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

void MLRenderingSelectionParametersFrame::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject MLRenderingSelectionParametersFrame::staticMetaObject = {
    { &MLRenderingParametersFrame::staticMetaObject, qt_meta_stringdata_MLRenderingSelectionParametersFrame.data,
      qt_meta_data_MLRenderingSelectionParametersFrame,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MLRenderingSelectionParametersFrame::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MLRenderingSelectionParametersFrame::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MLRenderingSelectionParametersFrame.stringdata0))
        return static_cast<void*>(const_cast< MLRenderingSelectionParametersFrame*>(this));
    return MLRenderingParametersFrame::qt_metacast(_clname);
}

int MLRenderingSelectionParametersFrame::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = MLRenderingParametersFrame::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
struct qt_meta_stringdata_MLRenderingDefaultDecoratorParametersFrame_t {
    QByteArrayData data[1];
    char stringdata0[43];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MLRenderingDefaultDecoratorParametersFrame_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MLRenderingDefaultDecoratorParametersFrame_t qt_meta_stringdata_MLRenderingDefaultDecoratorParametersFrame = {
    {
QT_MOC_LITERAL(0, 0, 42) // "MLRenderingDefaultDecoratorPa..."

    },
    "MLRenderingDefaultDecoratorParametersFrame"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MLRenderingDefaultDecoratorParametersFrame[] = {

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

void MLRenderingDefaultDecoratorParametersFrame::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject MLRenderingDefaultDecoratorParametersFrame::staticMetaObject = {
    { &MLRenderingParametersFrame::staticMetaObject, qt_meta_stringdata_MLRenderingDefaultDecoratorParametersFrame.data,
      qt_meta_data_MLRenderingDefaultDecoratorParametersFrame,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MLRenderingDefaultDecoratorParametersFrame::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MLRenderingDefaultDecoratorParametersFrame::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MLRenderingDefaultDecoratorParametersFrame.stringdata0))
        return static_cast<void*>(const_cast< MLRenderingDefaultDecoratorParametersFrame*>(this));
    return MLRenderingParametersFrame::qt_metacast(_clname);
}

int MLRenderingDefaultDecoratorParametersFrame::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = MLRenderingParametersFrame::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
struct qt_meta_stringdata_MLRenderingBBoxParametersFrame_t {
    QByteArrayData data[1];
    char stringdata0[31];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MLRenderingBBoxParametersFrame_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MLRenderingBBoxParametersFrame_t qt_meta_stringdata_MLRenderingBBoxParametersFrame = {
    {
QT_MOC_LITERAL(0, 0, 30) // "MLRenderingBBoxParametersFrame"

    },
    "MLRenderingBBoxParametersFrame"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MLRenderingBBoxParametersFrame[] = {

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

void MLRenderingBBoxParametersFrame::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject MLRenderingBBoxParametersFrame::staticMetaObject = {
    { &MLRenderingParametersFrame::staticMetaObject, qt_meta_stringdata_MLRenderingBBoxParametersFrame.data,
      qt_meta_data_MLRenderingBBoxParametersFrame,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MLRenderingBBoxParametersFrame::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MLRenderingBBoxParametersFrame::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MLRenderingBBoxParametersFrame.stringdata0))
        return static_cast<void*>(const_cast< MLRenderingBBoxParametersFrame*>(this));
    return MLRenderingParametersFrame::qt_metacast(_clname);
}

int MLRenderingBBoxParametersFrame::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = MLRenderingParametersFrame::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
struct qt_meta_stringdata_MLRenderingParametersTab_t {
    QByteArrayData data[13];
    char stringdata0[245];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MLRenderingParametersTab_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MLRenderingParametersTab_t qt_meta_stringdata_MLRenderingParametersTab = {
    {
QT_MOC_LITERAL(0, 0, 24), // "MLRenderingParametersTab"
QT_MOC_LITERAL(1, 25, 37), // "updateRenderingDataAccordingT..."
QT_MOC_LITERAL(2, 63, 0), // ""
QT_MOC_LITERAL(3, 64, 25), // "QList<MLRenderingAction*>"
QT_MOC_LITERAL(4, 90, 36), // "updateRenderingDataAccordingT..."
QT_MOC_LITERAL(5, 127, 18), // "MLRenderingAction*"
QT_MOC_LITERAL(6, 146, 25), // "updateLayerTableRequested"
QT_MOC_LITERAL(7, 172, 9), // "switchTab"
QT_MOC_LITERAL(8, 182, 6), // "meshid"
QT_MOC_LITERAL(9, 189, 7), // "tabname"
QT_MOC_LITERAL(10, 197, 19), // "setAssociatedMeshId"
QT_MOC_LITERAL(11, 217, 21), // "activateRenderingMode"
QT_MOC_LITERAL(12, 239, 5) // "index"

    },
    "MLRenderingParametersTab\0"
    "updateRenderingDataAccordingToActions\0"
    "\0QList<MLRenderingAction*>\0"
    "updateRenderingDataAccordingToAction\0"
    "MLRenderingAction*\0updateLayerTableRequested\0"
    "switchTab\0meshid\0tabname\0setAssociatedMeshId\0"
    "activateRenderingMode\0index"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MLRenderingParametersTab[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   44,    2, 0x06 /* Public */,
       4,    2,   49,    2, 0x06 /* Public */,
       6,    0,   54,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    2,   55,    2, 0x0a /* Public */,
      10,    1,   60,    2, 0x0a /* Public */,
      11,    1,   63,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, 0x80000000 | 3,    2,    2,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 5,    2,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    8,    9,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Int,   12,

       0        // eod
};

void MLRenderingParametersTab::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MLRenderingParametersTab *_t = static_cast<MLRenderingParametersTab *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->updateRenderingDataAccordingToActions((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QList<MLRenderingAction*>(*)>(_a[2]))); break;
        case 1: _t->updateRenderingDataAccordingToAction((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< MLRenderingAction*(*)>(_a[2]))); break;
        case 2: _t->updateLayerTableRequested(); break;
        case 3: _t->switchTab((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 4: _t->setAssociatedMeshId((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->activateRenderingMode((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<MLRenderingAction*> >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< MLRenderingAction* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MLRenderingParametersTab::*_t)(int , const QList<MLRenderingAction*> & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MLRenderingParametersTab::updateRenderingDataAccordingToActions)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (MLRenderingParametersTab::*_t)(int , MLRenderingAction * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MLRenderingParametersTab::updateRenderingDataAccordingToAction)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (MLRenderingParametersTab::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MLRenderingParametersTab::updateLayerTableRequested)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject MLRenderingParametersTab::staticMetaObject = {
    { &QTabWidget::staticMetaObject, qt_meta_stringdata_MLRenderingParametersTab.data,
      qt_meta_data_MLRenderingParametersTab,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MLRenderingParametersTab::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MLRenderingParametersTab::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MLRenderingParametersTab.stringdata0))
        return static_cast<void*>(const_cast< MLRenderingParametersTab*>(this));
    return QTabWidget::qt_metacast(_clname);
}

int MLRenderingParametersTab::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTabWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void MLRenderingParametersTab::updateRenderingDataAccordingToActions(int _t1, const QList<MLRenderingAction*> & _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MLRenderingParametersTab::updateRenderingDataAccordingToAction(int _t1, MLRenderingAction * _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MLRenderingParametersTab::updateLayerTableRequested()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
