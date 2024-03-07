/****************************************************************************
** Meta object code from reading C++ file 'xmlgeneratorgui.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../xmlgeneratorgui.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'xmlgeneratorgui.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ParamGeneratorGUI_t {
    QByteArrayData data[23];
    char stringdata0[313];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ParamGeneratorGUI_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ParamGeneratorGUI_t qt_meta_stringdata_ParamGeneratorGUI = {
    {
QT_MOC_LITERAL(0, 0, 17), // "ParamGeneratorGUI"
QT_MOC_LITERAL(1, 18, 26), // "paramNameValidationRequest"
QT_MOC_LITERAL(2, 45, 0), // ""
QT_MOC_LITERAL(3, 46, 16), // "QTreeWidgetItem*"
QT_MOC_LITERAL(4, 63, 6), // "parent"
QT_MOC_LITERAL(5, 70, 7), // "newname"
QT_MOC_LITERAL(6, 78, 22), // "itemLabelUpdateRequest"
QT_MOC_LITERAL(7, 101, 4), // "text"
QT_MOC_LITERAL(8, 106, 13), // "updateGUIType"
QT_MOC_LITERAL(9, 120, 9), // "paramtype"
QT_MOC_LITERAL(10, 130, 14), // "updateGUILabel"
QT_MOC_LITERAL(11, 145, 3), // "lab"
QT_MOC_LITERAL(12, 149, 30), // "updateOptionalWidgetVisibility"
QT_MOC_LITERAL(13, 180, 24), // "updateGUIWidgetInterface"
QT_MOC_LITERAL(14, 205, 7), // "guitype"
QT_MOC_LITERAL(15, 213, 12), // "validateName"
QT_MOC_LITERAL(16, 226, 15), // "updateItemLabel"
QT_MOC_LITERAL(17, 242, 11), // "collectInfo"
QT_MOC_LITERAL(18, 254, 18), // "MLXMLParamSubTree&"
QT_MOC_LITERAL(19, 273, 5), // "param"
QT_MOC_LITERAL(20, 279, 10), // "importInfo"
QT_MOC_LITERAL(21, 290, 17), // "MLXMLParamSubTree"
QT_MOC_LITERAL(22, 308, 4) // "tree"

    },
    "ParamGeneratorGUI\0paramNameValidationRequest\0"
    "\0QTreeWidgetItem*\0parent\0newname\0"
    "itemLabelUpdateRequest\0text\0updateGUIType\0"
    "paramtype\0updateGUILabel\0lab\0"
    "updateOptionalWidgetVisibility\0"
    "updateGUIWidgetInterface\0guitype\0"
    "validateName\0updateItemLabel\0collectInfo\0"
    "MLXMLParamSubTree&\0param\0importInfo\0"
    "MLXMLParamSubTree\0tree"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ParamGeneratorGUI[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   64,    2, 0x06 /* Public */,
       6,    2,   69,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    1,   74,    2, 0x08 /* Private */,
      10,    1,   77,    2, 0x08 /* Private */,
      12,    1,   80,    2, 0x08 /* Private */,
      13,    1,   83,    2, 0x08 /* Private */,
      15,    0,   86,    2, 0x08 /* Private */,
      16,    1,   87,    2, 0x08 /* Private */,
      17,    1,   90,    2, 0x0a /* Public */,
      20,    1,   93,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::QString,    4,    5,
    QMetaType::Void, 0x80000000 | 3, QMetaType::QString,    4,    7,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,   14,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, 0x80000000 | 18,   19,
    QMetaType::Void, 0x80000000 | 21,   22,

       0        // eod
};

void ParamGeneratorGUI::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ParamGeneratorGUI *_t = static_cast<ParamGeneratorGUI *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->paramNameValidationRequest((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 1: _t->itemLabelUpdateRequest((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 2: _t->updateGUIType((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->updateGUILabel((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->updateOptionalWidgetVisibility((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->updateGUIWidgetInterface((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->validateName(); break;
        case 7: _t->updateItemLabel((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: _t->collectInfo((*reinterpret_cast< MLXMLParamSubTree(*)>(_a[1]))); break;
        case 9: _t->importInfo((*reinterpret_cast< const MLXMLParamSubTree(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ParamGeneratorGUI::*_t)(QTreeWidgetItem * , const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ParamGeneratorGUI::paramNameValidationRequest)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (ParamGeneratorGUI::*_t)(QTreeWidgetItem * , const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ParamGeneratorGUI::itemLabelUpdateRequest)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject ParamGeneratorGUI::staticMetaObject = {
    { &QFrame::staticMetaObject, qt_meta_stringdata_ParamGeneratorGUI.data,
      qt_meta_data_ParamGeneratorGUI,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ParamGeneratorGUI::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ParamGeneratorGUI::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ParamGeneratorGUI.stringdata0))
        return static_cast<void*>(const_cast< ParamGeneratorGUI*>(this));
    return QFrame::qt_metacast(_clname);
}

int ParamGeneratorGUI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QFrame::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void ParamGeneratorGUI::paramNameValidationRequest(QTreeWidgetItem * _t1, const QString & _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ParamGeneratorGUI::itemLabelUpdateRequest(QTreeWidgetItem * _t1, const QString & _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
struct qt_meta_stringdata_FilterGeneratorGUI_t {
    QByteArrayData data[29];
    char stringdata0[365];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FilterGeneratorGUI_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FilterGeneratorGUI_t qt_meta_stringdata_FilterGeneratorGUI = {
    {
QT_MOC_LITERAL(0, 0, 18), // "FilterGeneratorGUI"
QT_MOC_LITERAL(1, 19, 20), // "validateFunctionName"
QT_MOC_LITERAL(2, 40, 0), // ""
QT_MOC_LITERAL(3, 41, 4), // "name"
QT_MOC_LITERAL(4, 46, 17), // "filterNameUpdated"
QT_MOC_LITERAL(5, 64, 8), // "QWidget*"
QT_MOC_LITERAL(6, 73, 3), // "wid"
QT_MOC_LITERAL(7, 77, 18), // "validateFilterName"
QT_MOC_LITERAL(8, 96, 19), // "FilterGeneratorGUI*"
QT_MOC_LITERAL(9, 116, 7), // "thiswid"
QT_MOC_LITERAL(10, 124, 11), // "collectInfo"
QT_MOC_LITERAL(11, 136, 19), // "MLXMLFilterSubTree&"
QT_MOC_LITERAL(12, 156, 6), // "filter"
QT_MOC_LITERAL(13, 163, 10), // "importInfo"
QT_MOC_LITERAL(14, 174, 18), // "MLXMLFilterSubTree"
QT_MOC_LITERAL(15, 193, 4), // "tree"
QT_MOC_LITERAL(16, 198, 13), // "setFilterName"
QT_MOC_LITERAL(17, 212, 7), // "newname"
QT_MOC_LITERAL(18, 220, 13), // "menuSelection"
QT_MOC_LITERAL(19, 234, 8), // "QAction*"
QT_MOC_LITERAL(20, 243, 3), // "act"
QT_MOC_LITERAL(21, 247, 22), // "validateAndSetItemName"
QT_MOC_LITERAL(22, 270, 16), // "QTreeWidgetItem*"
QT_MOC_LITERAL(23, 287, 6), // "parent"
QT_MOC_LITERAL(24, 294, 14), // "updateItemText"
QT_MOC_LITERAL(25, 309, 4), // "text"
QT_MOC_LITERAL(26, 314, 27), // "filterNameValidationRequest"
QT_MOC_LITERAL(27, 342, 18), // "updateFunctionName"
QT_MOC_LITERAL(28, 361, 3) // "fun"

    },
    "FilterGeneratorGUI\0validateFunctionName\0"
    "\0name\0filterNameUpdated\0QWidget*\0wid\0"
    "validateFilterName\0FilterGeneratorGUI*\0"
    "thiswid\0collectInfo\0MLXMLFilterSubTree&\0"
    "filter\0importInfo\0MLXMLFilterSubTree\0"
    "tree\0setFilterName\0newname\0menuSelection\0"
    "QAction*\0act\0validateAndSetItemName\0"
    "QTreeWidgetItem*\0parent\0updateItemText\0"
    "text\0filterNameValidationRequest\0"
    "updateFunctionName\0fun"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FilterGeneratorGUI[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   74,    2, 0x06 /* Public */,
       4,    2,   77,    2, 0x06 /* Public */,
       7,    2,   82,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    1,   87,    2, 0x0a /* Public */,
      13,    1,   90,    2, 0x0a /* Public */,
      16,    1,   93,    2, 0x0a /* Public */,
      18,    1,   96,    2, 0x08 /* Private */,
      21,    2,   99,    2, 0x08 /* Private */,
      24,    2,  104,    2, 0x08 /* Private */,
      26,    0,  109,    2, 0x08 /* Private */,
      27,    1,  110,    2, 0x08 /* Private */,
       4,    1,  113,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 5,    3,    6,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 8,    3,    9,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void, 0x80000000 | 14,   15,
    QMetaType::Void, QMetaType::QString,   17,
    QMetaType::Void, 0x80000000 | 19,   20,
    QMetaType::Void, 0x80000000 | 22, QMetaType::QString,   23,   17,
    QMetaType::Void, 0x80000000 | 22, QMetaType::QString,   23,   25,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   28,
    QMetaType::Void, QMetaType::QString,    3,

       0        // eod
};

void FilterGeneratorGUI::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        FilterGeneratorGUI *_t = static_cast<FilterGeneratorGUI *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->validateFunctionName((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->filterNameUpdated((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< QWidget*(*)>(_a[2]))); break;
        case 2: _t->validateFilterName((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< FilterGeneratorGUI*(*)>(_a[2]))); break;
        case 3: _t->collectInfo((*reinterpret_cast< MLXMLFilterSubTree(*)>(_a[1]))); break;
        case 4: _t->importInfo((*reinterpret_cast< const MLXMLFilterSubTree(*)>(_a[1]))); break;
        case 5: _t->setFilterName((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->menuSelection((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 7: _t->validateAndSetItemName((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 8: _t->updateItemText((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 9: _t->filterNameValidationRequest(); break;
        case 10: _t->updateFunctionName((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 11: _t->filterNameUpdated((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QWidget* >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< FilterGeneratorGUI* >(); break;
            }
            break;
        case 6:
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
            typedef void (FilterGeneratorGUI::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&FilterGeneratorGUI::validateFunctionName)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (FilterGeneratorGUI::*_t)(const QString & , QWidget * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&FilterGeneratorGUI::filterNameUpdated)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (FilterGeneratorGUI::*_t)(const QString & , FilterGeneratorGUI * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&FilterGeneratorGUI::validateFilterName)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject FilterGeneratorGUI::staticMetaObject = {
    { &QFrame::staticMetaObject, qt_meta_stringdata_FilterGeneratorGUI.data,
      qt_meta_data_FilterGeneratorGUI,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *FilterGeneratorGUI::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FilterGeneratorGUI::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_FilterGeneratorGUI.stringdata0))
        return static_cast<void*>(const_cast< FilterGeneratorGUI*>(this));
    return QFrame::qt_metacast(_clname);
}

int FilterGeneratorGUI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QFrame::qt_metacall(_c, _id, _a);
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
void FilterGeneratorGUI::validateFunctionName(const QString & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void FilterGeneratorGUI::filterNameUpdated(const QString & _t1, QWidget * _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void FilterGeneratorGUI::validateFilterName(const QString & _t1, FilterGeneratorGUI * _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
struct qt_meta_stringdata_FilterGeneratorTab_t {
    QByteArrayData data[10];
    char stringdata0[129];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FilterGeneratorTab_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FilterGeneratorTab_t qt_meta_stringdata_FilterGeneratorTab = {
    {
QT_MOC_LITERAL(0, 0, 18), // "FilterGeneratorTab"
QT_MOC_LITERAL(1, 19, 17), // "filterNameUpdated"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 5), // "fname"
QT_MOC_LITERAL(4, 44, 8), // "QWidget*"
QT_MOC_LITERAL(5, 53, 3), // "wid"
QT_MOC_LITERAL(6, 57, 18), // "validateFilterName"
QT_MOC_LITERAL(7, 76, 19), // "FilterGeneratorGUI*"
QT_MOC_LITERAL(8, 96, 15), // "jsButtonClicked"
QT_MOC_LITERAL(9, 112, 16) // "guiButtonClicked"

    },
    "FilterGeneratorTab\0filterNameUpdated\0"
    "\0fname\0QWidget*\0wid\0validateFilterName\0"
    "FilterGeneratorGUI*\0jsButtonClicked\0"
    "guiButtonClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FilterGeneratorTab[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   34,    2, 0x06 /* Public */,
       6,    2,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,   44,    2, 0x08 /* Private */,
       9,    0,   45,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, 0x80000000 | 4,    3,    5,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 7,    3,    5,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void FilterGeneratorTab::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        FilterGeneratorTab *_t = static_cast<FilterGeneratorTab *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->filterNameUpdated((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< QWidget*(*)>(_a[2]))); break;
        case 1: _t->validateFilterName((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< FilterGeneratorGUI*(*)>(_a[2]))); break;
        case 2: _t->jsButtonClicked(); break;
        case 3: _t->guiButtonClicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QWidget* >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< FilterGeneratorGUI* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (FilterGeneratorTab::*_t)(const QString & , QWidget * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&FilterGeneratorTab::filterNameUpdated)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (FilterGeneratorTab::*_t)(const QString & , FilterGeneratorGUI * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&FilterGeneratorTab::validateFilterName)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject FilterGeneratorTab::staticMetaObject = {
    { &QFrame::staticMetaObject, qt_meta_stringdata_FilterGeneratorTab.data,
      qt_meta_data_FilterGeneratorTab,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *FilterGeneratorTab::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FilterGeneratorTab::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_FilterGeneratorTab.stringdata0))
        return static_cast<void*>(const_cast< FilterGeneratorTab*>(this));
    return QFrame::qt_metacast(_clname);
}

int FilterGeneratorTab::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void FilterGeneratorTab::filterNameUpdated(const QString & _t1, QWidget * _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void FilterGeneratorTab::validateFilterName(const QString & _t1, FilterGeneratorGUI * _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
struct qt_meta_stringdata_PluginGeneratorGUI_t {
    QByteArrayData data[23];
    char stringdata0[280];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PluginGeneratorGUI_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PluginGeneratorGUI_t qt_meta_stringdata_PluginGeneratorGUI = {
    {
QT_MOC_LITERAL(0, 0, 18), // "PluginGeneratorGUI"
QT_MOC_LITERAL(1, 19, 18), // "scriptCodeExecuted"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 12), // "QScriptValue"
QT_MOC_LITERAL(4, 52, 3), // "val"
QT_MOC_LITERAL(5, 56, 4), // "time"
QT_MOC_LITERAL(6, 61, 24), // "insertXMLPluginRequested"
QT_MOC_LITERAL(7, 86, 8), // "filename"
QT_MOC_LITERAL(8, 95, 14), // "plugscriptname"
QT_MOC_LITERAL(9, 110, 14), // "historyRequest"
QT_MOC_LITERAL(10, 125, 10), // "getHistory"
QT_MOC_LITERAL(11, 136, 4), // "hist"
QT_MOC_LITERAL(12, 141, 13), // "menuSelection"
QT_MOC_LITERAL(13, 155, 8), // "QAction*"
QT_MOC_LITERAL(14, 164, 12), // "addNewFilter"
QT_MOC_LITERAL(15, 177, 23), // "MLXMLPluginInfo::XMLMap"
QT_MOC_LITERAL(16, 201, 6), // "filter"
QT_MOC_LITERAL(17, 208, 14), // "updateTabTitle"
QT_MOC_LITERAL(18, 223, 4), // "name"
QT_MOC_LITERAL(19, 228, 8), // "QWidget*"
QT_MOC_LITERAL(20, 237, 3), // "wid"
QT_MOC_LITERAL(21, 241, 18), // "validateFilterName"
QT_MOC_LITERAL(22, 260, 19) // "FilterGeneratorGUI*"

    },
    "PluginGeneratorGUI\0scriptCodeExecuted\0"
    "\0QScriptValue\0val\0time\0insertXMLPluginRequested\0"
    "filename\0plugscriptname\0historyRequest\0"
    "getHistory\0hist\0menuSelection\0QAction*\0"
    "addNewFilter\0MLXMLPluginInfo::XMLMap\0"
    "filter\0updateTabTitle\0name\0QWidget*\0"
    "wid\0validateFilterName\0FilterGeneratorGUI*"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PluginGeneratorGUI[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   54,    2, 0x06 /* Public */,
       6,    2,   61,    2, 0x06 /* Public */,
       9,    0,   66,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    1,   67,    2, 0x0a /* Public */,
      12,    1,   70,    2, 0x08 /* Private */,
      14,    1,   73,    2, 0x08 /* Private */,
      17,    2,   76,    2, 0x08 /* Private */,
      21,    2,   81,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int, QMetaType::QString,    4,    5,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    7,    8,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QStringList,   11,
    QMetaType::Void, 0x80000000 | 13,    2,
    QMetaType::Void, 0x80000000 | 15,   16,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 19,   18,   20,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 22,   18,   20,

       0        // eod
};

void PluginGeneratorGUI::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PluginGeneratorGUI *_t = static_cast<PluginGeneratorGUI *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->scriptCodeExecuted((*reinterpret_cast< const QScriptValue(*)>(_a[1])),(*reinterpret_cast< const int(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 1: _t->insertXMLPluginRequested((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 2: _t->historyRequest(); break;
        case 3: _t->getHistory((*reinterpret_cast< const QStringList(*)>(_a[1]))); break;
        case 4: _t->menuSelection((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 5: _t->addNewFilter((*reinterpret_cast< const MLXMLPluginInfo::XMLMap(*)>(_a[1]))); break;
        case 6: _t->updateTabTitle((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< QWidget*(*)>(_a[2]))); break;
        case 7: _t->validateFilterName((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< FilterGeneratorGUI*(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAction* >(); break;
            }
            break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QWidget* >(); break;
            }
            break;
        case 7:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< FilterGeneratorGUI* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (PluginGeneratorGUI::*_t)(const QScriptValue & , const int , const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&PluginGeneratorGUI::scriptCodeExecuted)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (PluginGeneratorGUI::*_t)(const QString & , const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&PluginGeneratorGUI::insertXMLPluginRequested)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (PluginGeneratorGUI::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&PluginGeneratorGUI::historyRequest)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject PluginGeneratorGUI::staticMetaObject = {
    { &QDockWidget::staticMetaObject, qt_meta_stringdata_PluginGeneratorGUI.data,
      qt_meta_data_PluginGeneratorGUI,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *PluginGeneratorGUI::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PluginGeneratorGUI::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_PluginGeneratorGUI.stringdata0))
        return static_cast<void*>(const_cast< PluginGeneratorGUI*>(this));
    return QDockWidget::qt_metacast(_clname);
}

int PluginGeneratorGUI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDockWidget::qt_metacall(_c, _id, _a);
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
void PluginGeneratorGUI::scriptCodeExecuted(const QScriptValue & _t1, const int _t2, const QString & _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void PluginGeneratorGUI::insertXMLPluginRequested(const QString & _t1, const QString & _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void PluginGeneratorGUI::historyRequest()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
