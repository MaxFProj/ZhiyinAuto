/****************************************************************************
** Meta object code from reading C++ file 'xmlstdpardialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../xmlstdpardialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'xmlstdpardialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_XMLMeshLabWidget_t {
    QByteArrayData data[3];
    char stringdata0[35];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_XMLMeshLabWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_XMLMeshLabWidget_t qt_meta_stringdata_XMLMeshLabWidget = {
    {
QT_MOC_LITERAL(0, 0, 16), // "XMLMeshLabWidget"
QT_MOC_LITERAL(1, 17, 16), // "parameterChanged"
QT_MOC_LITERAL(2, 34, 0) // ""

    },
    "XMLMeshLabWidget\0parameterChanged\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_XMLMeshLabWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,

       0        // eod
};

void XMLMeshLabWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        XMLMeshLabWidget *_t = static_cast<XMLMeshLabWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->parameterChanged(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (XMLMeshLabWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&XMLMeshLabWidget::parameterChanged)) {
                *result = 0;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject XMLMeshLabWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_XMLMeshLabWidget.data,
      qt_meta_data_XMLMeshLabWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *XMLMeshLabWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *XMLMeshLabWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_XMLMeshLabWidget.stringdata0))
        return static_cast<void*>(const_cast< XMLMeshLabWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int XMLMeshLabWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void XMLMeshLabWidget::parameterChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
struct qt_meta_stringdata_XMLCheckBoxWidget_t {
    QByteArrayData data[1];
    char stringdata0[18];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_XMLCheckBoxWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_XMLCheckBoxWidget_t qt_meta_stringdata_XMLCheckBoxWidget = {
    {
QT_MOC_LITERAL(0, 0, 17) // "XMLCheckBoxWidget"

    },
    "XMLCheckBoxWidget"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_XMLCheckBoxWidget[] = {

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

void XMLCheckBoxWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject XMLCheckBoxWidget::staticMetaObject = {
    { &XMLMeshLabWidget::staticMetaObject, qt_meta_stringdata_XMLCheckBoxWidget.data,
      qt_meta_data_XMLCheckBoxWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *XMLCheckBoxWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *XMLCheckBoxWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_XMLCheckBoxWidget.stringdata0))
        return static_cast<void*>(const_cast< XMLCheckBoxWidget*>(this));
    return XMLMeshLabWidget::qt_metacast(_clname);
}

int XMLCheckBoxWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = XMLMeshLabWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
struct qt_meta_stringdata_XMLEditWidget_t {
    QByteArrayData data[1];
    char stringdata0[14];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_XMLEditWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_XMLEditWidget_t qt_meta_stringdata_XMLEditWidget = {
    {
QT_MOC_LITERAL(0, 0, 13) // "XMLEditWidget"

    },
    "XMLEditWidget"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_XMLEditWidget[] = {

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

void XMLEditWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject XMLEditWidget::staticMetaObject = {
    { &XMLMeshLabWidget::staticMetaObject, qt_meta_stringdata_XMLEditWidget.data,
      qt_meta_data_XMLEditWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *XMLEditWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *XMLEditWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_XMLEditWidget.stringdata0))
        return static_cast<void*>(const_cast< XMLEditWidget*>(this));
    return XMLMeshLabWidget::qt_metacast(_clname);
}

int XMLEditWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = XMLMeshLabWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
struct qt_meta_stringdata_XMLStringWidget_t {
    QByteArrayData data[1];
    char stringdata0[16];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_XMLStringWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_XMLStringWidget_t qt_meta_stringdata_XMLStringWidget = {
    {
QT_MOC_LITERAL(0, 0, 15) // "XMLStringWidget"

    },
    "XMLStringWidget"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_XMLStringWidget[] = {

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

void XMLStringWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject XMLStringWidget::staticMetaObject = {
    { &XMLMeshLabWidget::staticMetaObject, qt_meta_stringdata_XMLStringWidget.data,
      qt_meta_data_XMLStringWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *XMLStringWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *XMLStringWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_XMLStringWidget.stringdata0))
        return static_cast<void*>(const_cast< XMLStringWidget*>(this));
    return XMLMeshLabWidget::qt_metacast(_clname);
}

int XMLStringWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = XMLMeshLabWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
struct qt_meta_stringdata_XMLAbsWidget_t {
    QByteArrayData data[6];
    char stringdata0[83];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_XMLAbsWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_XMLAbsWidget_t qt_meta_stringdata_XMLAbsWidget = {
    {
QT_MOC_LITERAL(0, 0, 12), // "XMLAbsWidget"
QT_MOC_LITERAL(1, 13, 18), // "dialogParamChanged"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 21), // "on_absSB_valueChanged"
QT_MOC_LITERAL(4, 55, 4), // "newv"
QT_MOC_LITERAL(5, 60, 22) // "on_percSB_valueChanged"

    },
    "XMLAbsWidget\0dialogParamChanged\0\0"
    "on_absSB_valueChanged\0newv\0"
    "on_percSB_valueChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_XMLAbsWidget[] = {

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
       1,    0,   29,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,   30,    2, 0x0a /* Public */,
       5,    1,   33,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Double,    4,
    QMetaType::Void, QMetaType::Double,    4,

       0        // eod
};

void XMLAbsWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        XMLAbsWidget *_t = static_cast<XMLAbsWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->dialogParamChanged(); break;
        case 1: _t->on_absSB_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 2: _t->on_percSB_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (XMLAbsWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&XMLAbsWidget::dialogParamChanged)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject XMLAbsWidget::staticMetaObject = {
    { &XMLMeshLabWidget::staticMetaObject, qt_meta_stringdata_XMLAbsWidget.data,
      qt_meta_data_XMLAbsWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *XMLAbsWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *XMLAbsWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_XMLAbsWidget.stringdata0))
        return static_cast<void*>(const_cast< XMLAbsWidget*>(this));
    return XMLMeshLabWidget::qt_metacast(_clname);
}

int XMLAbsWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = XMLMeshLabWidget::qt_metacall(_c, _id, _a);
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
void XMLAbsWidget::dialogParamChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
struct qt_meta_stringdata_XMLVec3Widget_t {
    QByteArrayData data[17];
    char stringdata0[152];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_XMLVec3Widget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_XMLVec3Widget_t qt_meta_stringdata_XMLVec3Widget = {
    {
QT_MOC_LITERAL(0, 0, 13), // "XMLVec3Widget"
QT_MOC_LITERAL(1, 14, 10), // "askViewDir"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 10), // "askViewPos"
QT_MOC_LITERAL(4, 37, 13), // "askSurfacePos"
QT_MOC_LITERAL(5, 51, 12), // "askCameraPos"
QT_MOC_LITERAL(6, 64, 15), // "askTrackballPos"
QT_MOC_LITERAL(7, 80, 6), // "setExp"
QT_MOC_LITERAL(8, 87, 4), // "name"
QT_MOC_LITERAL(9, 92, 3), // "exp"
QT_MOC_LITERAL(10, 96, 8), // "getPoint"
QT_MOC_LITERAL(11, 105, 8), // "setPoint"
QT_MOC_LITERAL(12, 114, 12), // "vcg::Point3f"
QT_MOC_LITERAL(13, 127, 1), // "p"
QT_MOC_LITERAL(14, 129, 7), // "setShot"
QT_MOC_LITERAL(15, 137, 10), // "vcg::Shotf"
QT_MOC_LITERAL(16, 148, 3) // "val"

    },
    "XMLVec3Widget\0askViewDir\0\0askViewPos\0"
    "askSurfacePos\0askCameraPos\0askTrackballPos\0"
    "setExp\0name\0exp\0getPoint\0setPoint\0"
    "vcg::Point3f\0p\0setShot\0vcg::Shotf\0val"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_XMLVec3Widget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x06 /* Public */,
       3,    1,   62,    2, 0x06 /* Public */,
       4,    1,   65,    2, 0x06 /* Public */,
       5,    1,   68,    2, 0x06 /* Public */,
       6,    1,   71,    2, 0x06 /* Public */,
       7,    2,   74,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    0,   79,    2, 0x0a /* Public */,
      11,    2,   80,    2, 0x0a /* Public */,
      14,    2,   85,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    8,    9,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 12,    8,   13,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 15,    8,   16,

       0        // eod
};

void XMLVec3Widget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        XMLVec3Widget *_t = static_cast<XMLVec3Widget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->askViewDir((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->askViewPos((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->askSurfacePos((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->askCameraPos((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->askTrackballPos((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->setExp((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 6: _t->getPoint(); break;
        case 7: _t->setPoint((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const vcg::Point3f(*)>(_a[2]))); break;
        case 8: _t->setShot((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const vcg::Shotf(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (XMLVec3Widget::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&XMLVec3Widget::askViewDir)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (XMLVec3Widget::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&XMLVec3Widget::askViewPos)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (XMLVec3Widget::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&XMLVec3Widget::askSurfacePos)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (XMLVec3Widget::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&XMLVec3Widget::askCameraPos)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (XMLVec3Widget::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&XMLVec3Widget::askTrackballPos)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (XMLVec3Widget::*_t)(const QString & , const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&XMLVec3Widget::setExp)) {
                *result = 5;
                return;
            }
        }
    }
}

const QMetaObject XMLVec3Widget::staticMetaObject = {
    { &XMLMeshLabWidget::staticMetaObject, qt_meta_stringdata_XMLVec3Widget.data,
      qt_meta_data_XMLVec3Widget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *XMLVec3Widget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *XMLVec3Widget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_XMLVec3Widget.stringdata0))
        return static_cast<void*>(const_cast< XMLVec3Widget*>(this));
    return XMLMeshLabWidget::qt_metacast(_clname);
}

int XMLVec3Widget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = XMLMeshLabWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void XMLVec3Widget::askViewDir(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void XMLVec3Widget::askViewPos(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void XMLVec3Widget::askSurfacePos(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void XMLVec3Widget::askCameraPos(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void XMLVec3Widget::askTrackballPos(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void XMLVec3Widget::setExp(const QString & _t1, const QString & _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
struct qt_meta_stringdata_XMLColorWidget_t {
    QByteArrayData data[4];
    char stringdata0[45];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_XMLColorWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_XMLColorWidget_t qt_meta_stringdata_XMLColorWidget = {
    {
QT_MOC_LITERAL(0, 0, 14), // "XMLColorWidget"
QT_MOC_LITERAL(1, 15, 18), // "dialogParamChanged"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 9) // "pickColor"

    },
    "XMLColorWidget\0dialogParamChanged\0\0"
    "pickColor"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_XMLColorWidget[] = {

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
       1,    0,   24,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   25,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void XMLColorWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        XMLColorWidget *_t = static_cast<XMLColorWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->dialogParamChanged(); break;
        case 1: _t->pickColor(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (XMLColorWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&XMLColorWidget::dialogParamChanged)) {
                *result = 0;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject XMLColorWidget::staticMetaObject = {
    { &XMLMeshLabWidget::staticMetaObject, qt_meta_stringdata_XMLColorWidget.data,
      qt_meta_data_XMLColorWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *XMLColorWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *XMLColorWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_XMLColorWidget.stringdata0))
        return static_cast<void*>(const_cast< XMLColorWidget*>(this));
    return XMLMeshLabWidget::qt_metacast(_clname);
}

int XMLColorWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = XMLMeshLabWidget::qt_metacall(_c, _id, _a);
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
void XMLColorWidget::dialogParamChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
struct qt_meta_stringdata_XMLSliderWidget_t {
    QByteArrayData data[6];
    char stringdata0[59];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_XMLSliderWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_XMLSliderWidget_t qt_meta_stringdata_XMLSliderWidget = {
    {
QT_MOC_LITERAL(0, 0, 15), // "XMLSliderWidget"
QT_MOC_LITERAL(1, 16, 18), // "dialogParamChanged"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 8), // "setValue"
QT_MOC_LITERAL(4, 45, 4), // "newv"
QT_MOC_LITERAL(5, 50, 8) // "newValue"

    },
    "XMLSliderWidget\0dialogParamChanged\0\0"
    "setValue\0newv\0newValue"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_XMLSliderWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,   35,    2, 0x0a /* Public */,
       3,    0,   38,    2, 0x0a /* Public */,
       3,    1,   39,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Float,    5,

       0        // eod
};

void XMLSliderWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        XMLSliderWidget *_t = static_cast<XMLSliderWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->dialogParamChanged(); break;
        case 1: _t->setValue((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->setValue(); break;
        case 3: _t->setValue((*reinterpret_cast< float(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (XMLSliderWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&XMLSliderWidget::dialogParamChanged)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject XMLSliderWidget::staticMetaObject = {
    { &XMLMeshLabWidget::staticMetaObject, qt_meta_stringdata_XMLSliderWidget.data,
      qt_meta_data_XMLSliderWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *XMLSliderWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *XMLSliderWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_XMLSliderWidget.stringdata0))
        return static_cast<void*>(const_cast< XMLSliderWidget*>(this));
    return XMLMeshLabWidget::qt_metacast(_clname);
}

int XMLSliderWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = XMLMeshLabWidget::qt_metacall(_c, _id, _a);
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
void XMLSliderWidget::dialogParamChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
struct qt_meta_stringdata_XMLComboWidget_t {
    QByteArrayData data[3];
    char stringdata0[35];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_XMLComboWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_XMLComboWidget_t qt_meta_stringdata_XMLComboWidget = {
    {
QT_MOC_LITERAL(0, 0, 14), // "XMLComboWidget"
QT_MOC_LITERAL(1, 15, 18), // "dialogParamChanged"
QT_MOC_LITERAL(2, 34, 0) // ""

    },
    "XMLComboWidget\0dialogParamChanged\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_XMLComboWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,

       0        // eod
};

void XMLComboWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        XMLComboWidget *_t = static_cast<XMLComboWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->dialogParamChanged(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (XMLComboWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&XMLComboWidget::dialogParamChanged)) {
                *result = 0;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject XMLComboWidget::staticMetaObject = {
    { &XMLMeshLabWidget::staticMetaObject, qt_meta_stringdata_XMLComboWidget.data,
      qt_meta_data_XMLComboWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *XMLComboWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *XMLComboWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_XMLComboWidget.stringdata0))
        return static_cast<void*>(const_cast< XMLComboWidget*>(this));
    return XMLMeshLabWidget::qt_metacast(_clname);
}

int XMLComboWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = XMLMeshLabWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void XMLComboWidget::dialogParamChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
struct qt_meta_stringdata_XMLEnumWidget_t {
    QByteArrayData data[1];
    char stringdata0[14];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_XMLEnumWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_XMLEnumWidget_t qt_meta_stringdata_XMLEnumWidget = {
    {
QT_MOC_LITERAL(0, 0, 13) // "XMLEnumWidget"

    },
    "XMLEnumWidget"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_XMLEnumWidget[] = {

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

void XMLEnumWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject XMLEnumWidget::staticMetaObject = {
    { &XMLComboWidget::staticMetaObject, qt_meta_stringdata_XMLEnumWidget.data,
      qt_meta_data_XMLEnumWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *XMLEnumWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *XMLEnumWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_XMLEnumWidget.stringdata0))
        return static_cast<void*>(const_cast< XMLEnumWidget*>(this));
    return XMLComboWidget::qt_metacast(_clname);
}

int XMLEnumWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = XMLComboWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
struct qt_meta_stringdata_XMLMeshWidget_t {
    QByteArrayData data[1];
    char stringdata0[14];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_XMLMeshWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_XMLMeshWidget_t qt_meta_stringdata_XMLMeshWidget = {
    {
QT_MOC_LITERAL(0, 0, 13) // "XMLMeshWidget"

    },
    "XMLMeshWidget"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_XMLMeshWidget[] = {

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

void XMLMeshWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject XMLMeshWidget::staticMetaObject = {
    { &XMLEnumWidget::staticMetaObject, qt_meta_stringdata_XMLMeshWidget.data,
      qt_meta_data_XMLMeshWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *XMLMeshWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *XMLMeshWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_XMLMeshWidget.stringdata0))
        return static_cast<void*>(const_cast< XMLMeshWidget*>(this));
    return XMLEnumWidget::qt_metacast(_clname);
}

int XMLMeshWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = XMLEnumWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
struct qt_meta_stringdata_XMLShotWidget_t {
    QByteArrayData data[11];
    char stringdata0[110];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_XMLShotWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_XMLShotWidget_t qt_meta_stringdata_XMLShotWidget = {
    {
QT_MOC_LITERAL(0, 0, 13), // "XMLShotWidget"
QT_MOC_LITERAL(1, 14, 13), // "askRasterShot"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 11), // "askMeshShot"
QT_MOC_LITERAL(4, 41, 13), // "askViewerShot"
QT_MOC_LITERAL(5, 55, 18), // "dialogParamChanged"
QT_MOC_LITERAL(6, 74, 7), // "getShot"
QT_MOC_LITERAL(7, 82, 12), // "setShotValue"
QT_MOC_LITERAL(8, 95, 4), // "name"
QT_MOC_LITERAL(9, 100, 5), // "Shotm"
QT_MOC_LITERAL(10, 106, 3) // "val"

    },
    "XMLShotWidget\0askRasterShot\0\0askMeshShot\0"
    "askViewerShot\0dialogParamChanged\0"
    "getShot\0setShotValue\0name\0Shotm\0val"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_XMLShotWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,
       3,    1,   47,    2, 0x06 /* Public */,
       4,    1,   50,    2, 0x06 /* Public */,
       5,    0,   53,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   54,    2, 0x0a /* Public */,
       7,    2,   55,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 9,    8,   10,

       0        // eod
};

void XMLShotWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        XMLShotWidget *_t = static_cast<XMLShotWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->askRasterShot((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->askMeshShot((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->askViewerShot((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->dialogParamChanged(); break;
        case 4: _t->getShot(); break;
        case 5: _t->setShotValue((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< Shotm(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (XMLShotWidget::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&XMLShotWidget::askRasterShot)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (XMLShotWidget::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&XMLShotWidget::askMeshShot)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (XMLShotWidget::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&XMLShotWidget::askViewerShot)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (XMLShotWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&XMLShotWidget::dialogParamChanged)) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject XMLShotWidget::staticMetaObject = {
    { &XMLMeshLabWidget::staticMetaObject, qt_meta_stringdata_XMLShotWidget.data,
      qt_meta_data_XMLShotWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *XMLShotWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *XMLShotWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_XMLShotWidget.stringdata0))
        return static_cast<void*>(const_cast< XMLShotWidget*>(this));
    return XMLMeshLabWidget::qt_metacast(_clname);
}

int XMLShotWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = XMLMeshLabWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void XMLShotWidget::askRasterShot(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void XMLShotWidget::askMeshShot(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void XMLShotWidget::askViewerShot(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void XMLShotWidget::dialogParamChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}
struct qt_meta_stringdata_XMLStdParFrame_t {
    QByteArrayData data[3];
    char stringdata0[33];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_XMLStdParFrame_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_XMLStdParFrame_t qt_meta_stringdata_XMLStdParFrame = {
    {
QT_MOC_LITERAL(0, 0, 14), // "XMLStdParFrame"
QT_MOC_LITERAL(1, 15, 16), // "parameterChanged"
QT_MOC_LITERAL(2, 32, 0) // ""

    },
    "XMLStdParFrame\0parameterChanged\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_XMLStdParFrame[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,

       0        // eod
};

void XMLStdParFrame::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        XMLStdParFrame *_t = static_cast<XMLStdParFrame *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->parameterChanged(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (XMLStdParFrame::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&XMLStdParFrame::parameterChanged)) {
                *result = 0;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject XMLStdParFrame::staticMetaObject = {
    { &QFrame::staticMetaObject, qt_meta_stringdata_XMLStdParFrame.data,
      qt_meta_data_XMLStdParFrame,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *XMLStdParFrame::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *XMLStdParFrame::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_XMLStdParFrame.stringdata0))
        return static_cast<void*>(const_cast< XMLStdParFrame*>(this));
    return QFrame::qt_metacast(_clname);
}

int XMLStdParFrame::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QFrame::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void XMLStdParFrame::parameterChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
struct qt_meta_stringdata_MeshLabXMLStdDialog_t {
    QByteArrayData data[19];
    char stringdata0[262];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MeshLabXMLStdDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MeshLabXMLStdDialog_t qt_meta_stringdata_MeshLabXMLStdDialog = {
    {
QT_MOC_LITERAL(0, 0, 19), // "MeshLabXMLStdDialog"
QT_MOC_LITERAL(1, 20, 15), // "filterInterrupt"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 20), // "isinterruptrequested"
QT_MOC_LITERAL(4, 58, 25), // "filterParametersEvaluated"
QT_MOC_LITERAL(5, 84, 6), // "fnmame"
QT_MOC_LITERAL(6, 91, 21), // "QMap<QString,QString>"
QT_MOC_LITERAL(7, 113, 8), // "parvalue"
QT_MOC_LITERAL(8, 122, 10), // "applyClick"
QT_MOC_LITERAL(9, 133, 10), // "closeClick"
QT_MOC_LITERAL(10, 144, 16), // "resetExpressions"
QT_MOC_LITERAL(11, 161, 10), // "toggleHelp"
QT_MOC_LITERAL(12, 172, 13), // "togglePreview"
QT_MOC_LITERAL(13, 186, 12), // "applyDynamic"
QT_MOC_LITERAL(14, 199, 17), // "changeCurrentMesh"
QT_MOC_LITERAL(15, 217, 7), // "meshInd"
QT_MOC_LITERAL(16, 225, 12), // "extendedView"
QT_MOC_LITERAL(17, 238, 3), // "ext"
QT_MOC_LITERAL(18, 242, 19) // "postFilterExecution"

    },
    "MeshLabXMLStdDialog\0filterInterrupt\0"
    "\0isinterruptrequested\0filterParametersEvaluated\0"
    "fnmame\0QMap<QString,QString>\0parvalue\0"
    "applyClick\0closeClick\0resetExpressions\0"
    "toggleHelp\0togglePreview\0applyDynamic\0"
    "changeCurrentMesh\0meshInd\0extendedView\0"
    "ext\0postFilterExecution"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MeshLabXMLStdDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   69,    2, 0x06 /* Public */,
       4,    2,   72,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,   77,    2, 0x08 /* Private */,
       9,    0,   78,    2, 0x08 /* Private */,
      10,    0,   79,    2, 0x08 /* Private */,
      11,    0,   80,    2, 0x08 /* Private */,
      12,    0,   81,    2, 0x08 /* Private */,
      13,    0,   82,    2, 0x08 /* Private */,
      14,    1,   83,    2, 0x08 /* Private */,
      16,    1,   86,    2, 0x08 /* Private */,
      18,    0,   89,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 6,    5,    7,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   15,
    QMetaType::Void, QMetaType::Bool,   17,
    QMetaType::Void,

       0        // eod
};

void MeshLabXMLStdDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MeshLabXMLStdDialog *_t = static_cast<MeshLabXMLStdDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->filterInterrupt((*reinterpret_cast< const bool(*)>(_a[1]))); break;
        case 1: _t->filterParametersEvaluated((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QMap<QString,QString>(*)>(_a[2]))); break;
        case 2: _t->applyClick(); break;
        case 3: _t->closeClick(); break;
        case 4: _t->resetExpressions(); break;
        case 5: _t->toggleHelp(); break;
        case 6: _t->togglePreview(); break;
        case 7: _t->applyDynamic(); break;
        case 8: _t->changeCurrentMesh((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->extendedView((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: _t->postFilterExecution(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MeshLabXMLStdDialog::*_t)(const bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MeshLabXMLStdDialog::filterInterrupt)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (MeshLabXMLStdDialog::*_t)(const QString & , const QMap<QString,QString> & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MeshLabXMLStdDialog::filterParametersEvaluated)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject MeshLabXMLStdDialog::staticMetaObject = {
    { &QDockWidget::staticMetaObject, qt_meta_stringdata_MeshLabXMLStdDialog.data,
      qt_meta_data_MeshLabXMLStdDialog,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MeshLabXMLStdDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MeshLabXMLStdDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MeshLabXMLStdDialog.stringdata0))
        return static_cast<void*>(const_cast< MeshLabXMLStdDialog*>(this));
    return QDockWidget::qt_metacast(_clname);
}

int MeshLabXMLStdDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDockWidget::qt_metacall(_c, _id, _a);
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
void MeshLabXMLStdDialog::filterInterrupt(const bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MeshLabXMLStdDialog::filterParametersEvaluated(const QString & _t1, const QMap<QString,QString> & _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
struct qt_meta_stringdata_OldScriptingSystemXMLParamDialog_t {
    QByteArrayData data[5];
    char stringdata0[67];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_OldScriptingSystemXMLParamDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_OldScriptingSystemXMLParamDialog_t qt_meta_stringdata_OldScriptingSystemXMLParamDialog = {
    {
QT_MOC_LITERAL(0, 0, 32), // "OldScriptingSystemXMLParamDialog"
QT_MOC_LITERAL(1, 33, 9), // "getAccept"
QT_MOC_LITERAL(2, 43, 0), // ""
QT_MOC_LITERAL(3, 44, 10), // "toggleHelp"
QT_MOC_LITERAL(4, 55, 11) // "resetValues"

    },
    "OldScriptingSystemXMLParamDialog\0"
    "getAccept\0\0toggleHelp\0resetValues"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_OldScriptingSystemXMLParamDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x0a /* Public */,
       3,    0,   30,    2, 0x0a /* Public */,
       4,    0,   31,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void OldScriptingSystemXMLParamDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        OldScriptingSystemXMLParamDialog *_t = static_cast<OldScriptingSystemXMLParamDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->getAccept(); break;
        case 1: _t->toggleHelp(); break;
        case 2: _t->resetValues(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject OldScriptingSystemXMLParamDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_OldScriptingSystemXMLParamDialog.data,
      qt_meta_data_OldScriptingSystemXMLParamDialog,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *OldScriptingSystemXMLParamDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *OldScriptingSystemXMLParamDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_OldScriptingSystemXMLParamDialog.stringdata0))
        return static_cast<void*>(const_cast< OldScriptingSystemXMLParamDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int OldScriptingSystemXMLParamDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE
