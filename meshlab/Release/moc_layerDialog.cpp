/****************************************************************************
** Meta object code from reading C++ file 'layerDialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../layerDialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'layerDialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_DecoratorParamsTreeWidget_t {
    QByteArrayData data[6];
    char stringdata0[49];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DecoratorParamsTreeWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DecoratorParamsTreeWidget_t qt_meta_stringdata_DecoratorParamsTreeWidget = {
    {
QT_MOC_LITERAL(0, 0, 25), // "DecoratorParamsTreeWidget"
QT_MOC_LITERAL(1, 26, 4), // "save"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 5), // "reset"
QT_MOC_LITERAL(4, 38, 5), // "apply"
QT_MOC_LITERAL(5, 44, 4) // "load"

    },
    "DecoratorParamsTreeWidget\0save\0\0reset\0"
    "apply\0load"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DecoratorParamsTreeWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x0a /* Public */,
       3,    0,   35,    2, 0x0a /* Public */,
       4,    0,   36,    2, 0x0a /* Public */,
       5,    0,   37,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void DecoratorParamsTreeWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DecoratorParamsTreeWidget *_t = static_cast<DecoratorParamsTreeWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->save(); break;
        case 1: _t->reset(); break;
        case 2: _t->apply(); break;
        case 3: _t->load(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject DecoratorParamsTreeWidget::staticMetaObject = {
    { &QFrame::staticMetaObject, qt_meta_stringdata_DecoratorParamsTreeWidget.data,
      qt_meta_data_DecoratorParamsTreeWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *DecoratorParamsTreeWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DecoratorParamsTreeWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_DecoratorParamsTreeWidget.stringdata0))
        return static_cast<void*>(const_cast< DecoratorParamsTreeWidget*>(this));
    return QFrame::qt_metacast(_clname);
}

int DecoratorParamsTreeWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
struct qt_meta_stringdata_LayerDialog_t {
    QByteArrayData data[25];
    char stringdata0[388];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_LayerDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_LayerDialog_t qt_meta_stringdata_LayerDialog = {
    {
QT_MOC_LITERAL(0, 0, 11), // "LayerDialog"
QT_MOC_LITERAL(1, 12, 24), // "removeDecoratorRequested"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 8), // "QAction*"
QT_MOC_LITERAL(4, 47, 8), // "toBeShow"
QT_MOC_LITERAL(5, 56, 11), // "updateTable"
QT_MOC_LITERAL(6, 68, 51), // "MLSceneGLSharedDataContext::P..."
QT_MOC_LITERAL(7, 120, 3), // "dtf"
QT_MOC_LITERAL(8, 124, 17), // "rasterItemClicked"
QT_MOC_LITERAL(9, 142, 16), // "QTreeWidgetItem*"
QT_MOC_LITERAL(10, 159, 15), // "meshItemClicked"
QT_MOC_LITERAL(11, 175, 9), // "showEvent"
QT_MOC_LITERAL(12, 185, 11), // "QShowEvent*"
QT_MOC_LITERAL(13, 197, 5), // "event"
QT_MOC_LITERAL(14, 203, 15), // "showContextMenu"
QT_MOC_LITERAL(15, 219, 3), // "pos"
QT_MOC_LITERAL(16, 223, 11), // "adaptLayout"
QT_MOC_LITERAL(17, 235, 4), // "item"
QT_MOC_LITERAL(18, 240, 37), // "updateRenderingDataAccordingT..."
QT_MOC_LITERAL(19, 278, 6), // "meshid"
QT_MOC_LITERAL(20, 285, 25), // "QList<MLRenderingAction*>"
QT_MOC_LITERAL(21, 311, 36), // "updateRenderingDataAccordingT..."
QT_MOC_LITERAL(22, 348, 18), // "MLRenderingAction*"
QT_MOC_LITERAL(23, 367, 15), // "actionActivated"
QT_MOC_LITERAL(24, 383, 4) // "ract"

    },
    "LayerDialog\0removeDecoratorRequested\0"
    "\0QAction*\0toBeShow\0updateTable\0"
    "MLSceneGLSharedDataContext::PerMeshRenderingDataMap\0"
    "dtf\0rasterItemClicked\0QTreeWidgetItem*\0"
    "meshItemClicked\0showEvent\0QShowEvent*\0"
    "event\0showContextMenu\0pos\0adaptLayout\0"
    "item\0updateRenderingDataAccordingToActions\0"
    "meshid\0QList<MLRenderingAction*>\0"
    "updateRenderingDataAccordingToAction\0"
    "MLRenderingAction*\0actionActivated\0"
    "ract"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LayerDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   74,    2, 0x06 /* Public */,
       4,    0,   77,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   78,    2, 0x0a /* Public */,
       8,    2,   81,    2, 0x0a /* Public */,
      10,    2,   86,    2, 0x0a /* Public */,
      11,    1,   91,    2, 0x0a /* Public */,
      14,    1,   94,    2, 0x0a /* Public */,
      16,    1,   97,    2, 0x0a /* Public */,
      18,    2,  100,    2, 0x0a /* Public */,
      21,    2,  105,    2, 0x0a /* Public */,
      23,    1,  110,    2, 0x0a /* Public */,
       5,    0,  113,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, 0x80000000 | 9, QMetaType::Int,    2,    2,
    QMetaType::Void, 0x80000000 | 9, QMetaType::Int,    2,    2,
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::Void, QMetaType::QPoint,   15,
    QMetaType::Void, 0x80000000 | 9,   17,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 20,   19,    2,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 22,   19,    2,
    QMetaType::Void, 0x80000000 | 22,   24,
    QMetaType::Void,

       0        // eod
};

void LayerDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        LayerDialog *_t = static_cast<LayerDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->removeDecoratorRequested((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 1: _t->toBeShow(); break;
        case 2: _t->updateTable((*reinterpret_cast< const MLSceneGLSharedDataContext::PerMeshRenderingDataMap(*)>(_a[1]))); break;
        case 3: _t->rasterItemClicked((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->meshItemClicked((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 5: _t->showEvent((*reinterpret_cast< QShowEvent*(*)>(_a[1]))); break;
        case 6: _t->showContextMenu((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 7: _t->adaptLayout((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1]))); break;
        case 8: _t->updateRenderingDataAccordingToActions((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QList<MLRenderingAction*>(*)>(_a[2]))); break;
        case 9: _t->updateRenderingDataAccordingToAction((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< MLRenderingAction*(*)>(_a[2]))); break;
        case 10: _t->actionActivated((*reinterpret_cast< MLRenderingAction*(*)>(_a[1]))); break;
        case 11: _t->updateTable(); break;
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
        case 8:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<MLRenderingAction*> >(); break;
            }
            break;
        case 9:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< MLRenderingAction* >(); break;
            }
            break;
        case 10:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< MLRenderingAction* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (LayerDialog::*_t)(QAction * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&LayerDialog::removeDecoratorRequested)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (LayerDialog::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&LayerDialog::toBeShow)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject LayerDialog::staticMetaObject = {
    { &QDockWidget::staticMetaObject, qt_meta_stringdata_LayerDialog.data,
      qt_meta_data_LayerDialog,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *LayerDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LayerDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_LayerDialog.stringdata0))
        return static_cast<void*>(const_cast< LayerDialog*>(this));
    return QDockWidget::qt_metacast(_clname);
}

int LayerDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDockWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void LayerDialog::removeDecoratorRequested(QAction * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void LayerDialog::toBeShow()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
