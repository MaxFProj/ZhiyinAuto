/****************************************************************************
** Meta object code from reading C++ file 'filterScriptDialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../filterScriptDialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'filterScriptDialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_FilterScriptDialog_t {
    QByteArrayData data[10];
    char stringdata0[160];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FilterScriptDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FilterScriptDialog_t qt_meta_stringdata_FilterScriptDialog = {
    {
QT_MOC_LITERAL(0, 0, 18), // "FilterScriptDialog"
QT_MOC_LITERAL(1, 19, 11), // "applyScript"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 11), // "clearScript"
QT_MOC_LITERAL(4, 44, 10), // "saveScript"
QT_MOC_LITERAL(5, 55, 10), // "openScript"
QT_MOC_LITERAL(6, 66, 20), // "moveSelectedFilterUp"
QT_MOC_LITERAL(7, 87, 22), // "moveSelectedFilterDown"
QT_MOC_LITERAL(8, 110, 20), // "removeSelectedFilter"
QT_MOC_LITERAL(9, 131, 28) // "editSelectedFilterParameters"

    },
    "FilterScriptDialog\0applyScript\0\0"
    "clearScript\0saveScript\0openScript\0"
    "moveSelectedFilterUp\0moveSelectedFilterDown\0"
    "removeSelectedFilter\0editSelectedFilterParameters"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FilterScriptDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x08 /* Private */,
       3,    0,   55,    2, 0x08 /* Private */,
       4,    0,   56,    2, 0x08 /* Private */,
       5,    0,   57,    2, 0x08 /* Private */,
       6,    0,   58,    2, 0x08 /* Private */,
       7,    0,   59,    2, 0x08 /* Private */,
       8,    0,   60,    2, 0x08 /* Private */,
       9,    0,   61,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void FilterScriptDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        FilterScriptDialog *_t = static_cast<FilterScriptDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->applyScript(); break;
        case 1: _t->clearScript(); break;
        case 2: _t->saveScript(); break;
        case 3: _t->openScript(); break;
        case 4: _t->moveSelectedFilterUp(); break;
        case 5: _t->moveSelectedFilterDown(); break;
        case 6: _t->removeSelectedFilter(); break;
        case 7: _t->editSelectedFilterParameters(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject FilterScriptDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_FilterScriptDialog.data,
      qt_meta_data_FilterScriptDialog,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *FilterScriptDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FilterScriptDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_FilterScriptDialog.stringdata0))
        return static_cast<void*>(const_cast< FilterScriptDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int FilterScriptDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE