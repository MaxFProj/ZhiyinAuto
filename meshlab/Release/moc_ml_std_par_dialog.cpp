/****************************************************************************
** Meta object code from reading C++ file 'ml_std_par_dialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../ml_std_par_dialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ml_std_par_dialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MeshlabStdDialog_t {
    QByteArrayData data[10];
    char stringdata0[116];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MeshlabStdDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MeshlabStdDialog_t qt_meta_stringdata_MeshlabStdDialog = {
    {
QT_MOC_LITERAL(0, 0, 16), // "MeshlabStdDialog"
QT_MOC_LITERAL(1, 17, 10), // "closeClick"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 10), // "applyClick"
QT_MOC_LITERAL(4, 40, 11), // "resetValues"
QT_MOC_LITERAL(5, 52, 10), // "toggleHelp"
QT_MOC_LITERAL(6, 63, 13), // "togglePreview"
QT_MOC_LITERAL(7, 77, 12), // "applyDynamic"
QT_MOC_LITERAL(8, 90, 17), // "changeCurrentMesh"
QT_MOC_LITERAL(9, 108, 7) // "meshInd"

    },
    "MeshlabStdDialog\0closeClick\0\0applyClick\0"
    "resetValues\0toggleHelp\0togglePreview\0"
    "applyDynamic\0changeCurrentMesh\0meshInd"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MeshlabStdDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x0a /* Public */,
       3,    0,   50,    2, 0x08 /* Private */,
       4,    0,   51,    2, 0x08 /* Private */,
       5,    0,   52,    2, 0x08 /* Private */,
       6,    0,   53,    2, 0x08 /* Private */,
       7,    0,   54,    2, 0x08 /* Private */,
       8,    1,   55,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    9,

       0        // eod
};

void MeshlabStdDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MeshlabStdDialog *_t = static_cast<MeshlabStdDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->closeClick(); break;
        case 1: _t->applyClick(); break;
        case 2: _t->resetValues(); break;
        case 3: _t->toggleHelp(); break;
        case 4: _t->togglePreview(); break;
        case 5: _t->applyDynamic(); break;
        case 6: _t->changeCurrentMesh((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject MeshlabStdDialog::staticMetaObject = {
    { &QDockWidget::staticMetaObject, qt_meta_stringdata_MeshlabStdDialog.data,
      qt_meta_data_MeshlabStdDialog,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MeshlabStdDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MeshlabStdDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MeshlabStdDialog.stringdata0))
        return static_cast<void*>(const_cast< MeshlabStdDialog*>(this));
    return QDockWidget::qt_metacast(_clname);
}

int MeshlabStdDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDockWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
