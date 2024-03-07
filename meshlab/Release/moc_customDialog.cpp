/****************************************************************************
** Meta object code from reading C++ file 'customDialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../customDialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'customDialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_SettingDialog_t {
    QByteArrayData data[7];
    char stringdata0[56];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SettingDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SettingDialog_t qt_meta_stringdata_SettingDialog = {
    {
QT_MOC_LITERAL(0, 0, 13), // "SettingDialog"
QT_MOC_LITERAL(1, 14, 18), // "applySettingSignal"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 4), // "save"
QT_MOC_LITERAL(4, 39, 5), // "reset"
QT_MOC_LITERAL(5, 45, 5), // "apply"
QT_MOC_LITERAL(6, 51, 4) // "load"

    },
    "SettingDialog\0applySettingSignal\0\0"
    "save\0reset\0apply\0load"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SettingDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   40,    2, 0x0a /* Public */,
       4,    0,   41,    2, 0x0a /* Public */,
       5,    0,   42,    2, 0x0a /* Public */,
       6,    0,   43,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void SettingDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SettingDialog *_t = static_cast<SettingDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->applySettingSignal(); break;
        case 1: _t->save(); break;
        case 2: _t->reset(); break;
        case 3: _t->apply(); break;
        case 4: _t->load(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (SettingDialog::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SettingDialog::applySettingSignal)) {
                *result = 0;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject SettingDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_SettingDialog.data,
      qt_meta_data_SettingDialog,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *SettingDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SettingDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_SettingDialog.stringdata0))
        return static_cast<void*>(const_cast< SettingDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int SettingDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
void SettingDialog::applySettingSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
struct qt_meta_stringdata_CustomDialog_t {
    QByteArrayData data[7];
    char stringdata0[84];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CustomDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CustomDialog_t qt_meta_stringdata_CustomDialog = {
    {
QT_MOC_LITERAL(0, 0, 12), // "CustomDialog"
QT_MOC_LITERAL(1, 13, 18), // "applyCustomSetting"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 13), // "openSubDialog"
QT_MOC_LITERAL(4, 47, 17), // "QTableWidgetItem*"
QT_MOC_LITERAL(5, 65, 3), // "itm"
QT_MOC_LITERAL(6, 69, 14) // "updateSettings"

    },
    "CustomDialog\0applyCustomSetting\0\0"
    "openSubDialog\0QTableWidgetItem*\0itm\0"
    "updateSettings"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CustomDialog[] = {

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
       6,    0,   33,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void,

       0        // eod
};

void CustomDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CustomDialog *_t = static_cast<CustomDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->applyCustomSetting(); break;
        case 1: _t->openSubDialog((*reinterpret_cast< QTableWidgetItem*(*)>(_a[1]))); break;
        case 2: _t->updateSettings(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CustomDialog::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CustomDialog::applyCustomSetting)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject CustomDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_CustomDialog.data,
      qt_meta_data_CustomDialog,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CustomDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CustomDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CustomDialog.stringdata0))
        return static_cast<void*>(const_cast< CustomDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int CustomDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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

// SIGNAL 0
void CustomDialog::applyCustomSetting()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
