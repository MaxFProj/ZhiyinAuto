/****************************************************************************
** Meta object code from reading C++ file 'additionalgui.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../additionalgui.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'additionalgui.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CheckBoxListItemDelegate_t {
    QByteArrayData data[1];
    char stringdata0[25];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CheckBoxListItemDelegate_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CheckBoxListItemDelegate_t qt_meta_stringdata_CheckBoxListItemDelegate = {
    {
QT_MOC_LITERAL(0, 0, 24) // "CheckBoxListItemDelegate"

    },
    "CheckBoxListItemDelegate"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CheckBoxListItemDelegate[] = {

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

void CheckBoxListItemDelegate::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject CheckBoxListItemDelegate::staticMetaObject = {
    { &QStyledItemDelegate::staticMetaObject, qt_meta_stringdata_CheckBoxListItemDelegate.data,
      qt_meta_data_CheckBoxListItemDelegate,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CheckBoxListItemDelegate::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CheckBoxListItemDelegate::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CheckBoxListItemDelegate.stringdata0))
        return static_cast<void*>(const_cast< CheckBoxListItemDelegate*>(this));
    return QStyledItemDelegate::qt_metacast(_clname);
}

int CheckBoxListItemDelegate::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QStyledItemDelegate::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
struct qt_meta_stringdata_CheckBoxList_t {
    QByteArrayData data[6];
    char stringdata0[57];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CheckBoxList_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CheckBoxList_t qt_meta_stringdata_CheckBoxList = {
    {
QT_MOC_LITERAL(0, 0, 12), // "CheckBoxList"
QT_MOC_LITERAL(1, 13, 18), // "currentHighlighted"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 4), // "high"
QT_MOC_LITERAL(4, 38, 15), // "setCurrentValue"
QT_MOC_LITERAL(5, 54, 2) // "st"

    },
    "CheckBoxList\0currentHighlighted\0\0high\0"
    "setCurrentValue\0st"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CheckBoxList[] = {

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
       4,    1,   27,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::QStringList,    5,

       0        // eod
};

void CheckBoxList::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CheckBoxList *_t = static_cast<CheckBoxList *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->currentHighlighted((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->setCurrentValue((*reinterpret_cast< const QStringList(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject CheckBoxList::staticMetaObject = {
    { &QComboBox::staticMetaObject, qt_meta_stringdata_CheckBoxList.data,
      qt_meta_data_CheckBoxList,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CheckBoxList::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CheckBoxList::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CheckBoxList.stringdata0))
        return static_cast<void*>(const_cast< CheckBoxList*>(this));
    return QComboBox::qt_metacast(_clname);
}

int CheckBoxList::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QComboBox::qt_metacall(_c, _id, _a);
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
struct qt_meta_stringdata_PrimitiveButton_t {
    QByteArrayData data[1];
    char stringdata0[16];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PrimitiveButton_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PrimitiveButton_t qt_meta_stringdata_PrimitiveButton = {
    {
QT_MOC_LITERAL(0, 0, 15) // "PrimitiveButton"

    },
    "PrimitiveButton"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PrimitiveButton[] = {

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

void PrimitiveButton::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject PrimitiveButton::staticMetaObject = {
    { &QPushButton::staticMetaObject, qt_meta_stringdata_PrimitiveButton.data,
      qt_meta_data_PrimitiveButton,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *PrimitiveButton::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PrimitiveButton::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_PrimitiveButton.stringdata0))
        return static_cast<void*>(const_cast< PrimitiveButton*>(this));
    return QPushButton::qt_metacast(_clname);
}

int PrimitiveButton::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QPushButton::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
struct qt_meta_stringdata_ExpandButtonWidget_t {
    QByteArrayData data[5];
    char stringdata0[46];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ExpandButtonWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ExpandButtonWidget_t qt_meta_stringdata_ExpandButtonWidget = {
    {
QT_MOC_LITERAL(0, 0, 18), // "ExpandButtonWidget"
QT_MOC_LITERAL(1, 19, 10), // "expandView"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 3), // "exp"
QT_MOC_LITERAL(4, 35, 10) // "changeIcon"

    },
    "ExpandButtonWidget\0expandView\0\0exp\0"
    "changeIcon"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ExpandButtonWidget[] = {

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
       4,    0,   27,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    3,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void ExpandButtonWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ExpandButtonWidget *_t = static_cast<ExpandButtonWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->expandView((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->changeIcon(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ExpandButtonWidget::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ExpandButtonWidget::expandView)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject ExpandButtonWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ExpandButtonWidget.data,
      qt_meta_data_ExpandButtonWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ExpandButtonWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ExpandButtonWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ExpandButtonWidget.stringdata0))
        return static_cast<void*>(const_cast< ExpandButtonWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int ExpandButtonWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
void ExpandButtonWidget::expandView(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_TreeWidgetWithMenu_t {
    QByteArrayData data[5];
    char stringdata0[48];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TreeWidgetWithMenu_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TreeWidgetWithMenu_t qt_meta_stringdata_TreeWidgetWithMenu = {
    {
QT_MOC_LITERAL(0, 0, 18), // "TreeWidgetWithMenu"
QT_MOC_LITERAL(1, 19, 14), // "selectedAction"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 8), // "QAction*"
QT_MOC_LITERAL(4, 44, 3) // "act"

    },
    "TreeWidgetWithMenu\0selectedAction\0\0"
    "QAction*\0act"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TreeWidgetWithMenu[] = {

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
       1,    1,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

       0        // eod
};

void TreeWidgetWithMenu::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TreeWidgetWithMenu *_t = static_cast<TreeWidgetWithMenu *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->selectedAction((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
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
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (TreeWidgetWithMenu::*_t)(QAction * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TreeWidgetWithMenu::selectedAction)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject TreeWidgetWithMenu::staticMetaObject = {
    { &QTreeWidget::staticMetaObject, qt_meta_stringdata_TreeWidgetWithMenu.data,
      qt_meta_data_TreeWidgetWithMenu,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *TreeWidgetWithMenu::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TreeWidgetWithMenu::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_TreeWidgetWithMenu.stringdata0))
        return static_cast<void*>(const_cast< TreeWidgetWithMenu*>(this));
    return QTreeWidget::qt_metacast(_clname);
}

int TreeWidgetWithMenu::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTreeWidget::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void TreeWidgetWithMenu::selectedAction(QAction * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_MLSyntaxHighlighter_t {
    QByteArrayData data[1];
    char stringdata0[20];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MLSyntaxHighlighter_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MLSyntaxHighlighter_t qt_meta_stringdata_MLSyntaxHighlighter = {
    {
QT_MOC_LITERAL(0, 0, 19) // "MLSyntaxHighlighter"

    },
    "MLSyntaxHighlighter"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MLSyntaxHighlighter[] = {

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

void MLSyntaxHighlighter::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject MLSyntaxHighlighter::staticMetaObject = {
    { &QSyntaxHighlighter::staticMetaObject, qt_meta_stringdata_MLSyntaxHighlighter.data,
      qt_meta_data_MLSyntaxHighlighter,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MLSyntaxHighlighter::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MLSyntaxHighlighter::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MLSyntaxHighlighter.stringdata0))
        return static_cast<void*>(const_cast< MLSyntaxHighlighter*>(this));
    return QSyntaxHighlighter::qt_metacast(_clname);
}

int MLSyntaxHighlighter::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QSyntaxHighlighter::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
struct qt_meta_stringdata_MLAutoCompleterPopUp_t {
    QByteArrayData data[1];
    char stringdata0[21];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MLAutoCompleterPopUp_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MLAutoCompleterPopUp_t qt_meta_stringdata_MLAutoCompleterPopUp = {
    {
QT_MOC_LITERAL(0, 0, 20) // "MLAutoCompleterPopUp"

    },
    "MLAutoCompleterPopUp"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MLAutoCompleterPopUp[] = {

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

void MLAutoCompleterPopUp::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject MLAutoCompleterPopUp::staticMetaObject = {
    { &QListView::staticMetaObject, qt_meta_stringdata_MLAutoCompleterPopUp.data,
      qt_meta_data_MLAutoCompleterPopUp,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MLAutoCompleterPopUp::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MLAutoCompleterPopUp::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MLAutoCompleterPopUp.stringdata0))
        return static_cast<void*>(const_cast< MLAutoCompleterPopUp*>(this));
    return QListView::qt_metacast(_clname);
}

int MLAutoCompleterPopUp::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QListView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
struct qt_meta_stringdata_MLAutoCompleter_t {
    QByteArrayData data[4];
    char stringdata0[35];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MLAutoCompleter_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MLAutoCompleter_t qt_meta_stringdata_MLAutoCompleter = {
    {
QT_MOC_LITERAL(0, 0, 15), // "MLAutoCompleter"
QT_MOC_LITERAL(1, 16, 13), // "changeCurrent"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 3) // "ind"

    },
    "MLAutoCompleter\0changeCurrent\0\0ind"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MLAutoCompleter[] = {

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
       1,    1,   19,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QModelIndex,    3,

       0        // eod
};

void MLAutoCompleter::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MLAutoCompleter *_t = static_cast<MLAutoCompleter *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->changeCurrent((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject MLAutoCompleter::staticMetaObject = {
    { &QCompleter::staticMetaObject, qt_meta_stringdata_MLAutoCompleter.data,
      qt_meta_data_MLAutoCompleter,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MLAutoCompleter::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MLAutoCompleter::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MLAutoCompleter.stringdata0))
        return static_cast<void*>(const_cast< MLAutoCompleter*>(this));
    return QCompleter::qt_metacast(_clname);
}

int MLAutoCompleter::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QCompleter::qt_metacall(_c, _id, _a);
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
struct qt_meta_stringdata_MLScriptEditor_t {
    QByteArrayData data[13];
    char stringdata0[156];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MLScriptEditor_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MLScriptEditor_t qt_meta_stringdata_MLScriptEditor = {
    {
QT_MOC_LITERAL(0, 0, 14), // "MLScriptEditor"
QT_MOC_LITERAL(1, 15, 25), // "updateLineNumberAreaWidth"
QT_MOC_LITERAL(2, 41, 0), // ""
QT_MOC_LITERAL(3, 42, 13), // "newBlockCount"
QT_MOC_LITERAL(4, 56, 20), // "highlightCurrentLine"
QT_MOC_LITERAL(5, 77, 20), // "updateLineNumberArea"
QT_MOC_LITERAL(6, 98, 1), // "r"
QT_MOC_LITERAL(7, 100, 2), // "dy"
QT_MOC_LITERAL(8, 103, 16), // "showAutoComplete"
QT_MOC_LITERAL(9, 120, 10), // "QKeyEvent*"
QT_MOC_LITERAL(10, 131, 1), // "e"
QT_MOC_LITERAL(11, 133, 19), // "insertSuggestedWord"
QT_MOC_LITERAL(12, 153, 2) // "st"

    },
    "MLScriptEditor\0updateLineNumberAreaWidth\0"
    "\0newBlockCount\0highlightCurrentLine\0"
    "updateLineNumberArea\0r\0dy\0showAutoComplete\0"
    "QKeyEvent*\0e\0insertSuggestedWord\0st"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MLScriptEditor[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x08 /* Private */,
       4,    0,   42,    2, 0x08 /* Private */,
       5,    2,   43,    2, 0x08 /* Private */,
       8,    1,   48,    2, 0x08 /* Private */,
      11,    1,   51,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QRect, QMetaType::Int,    6,    7,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, QMetaType::QString,   12,

       0        // eod
};

void MLScriptEditor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MLScriptEditor *_t = static_cast<MLScriptEditor *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->updateLineNumberAreaWidth((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->highlightCurrentLine(); break;
        case 2: _t->updateLineNumberArea((*reinterpret_cast< const QRect(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->showAutoComplete((*reinterpret_cast< QKeyEvent*(*)>(_a[1]))); break;
        case 4: _t->insertSuggestedWord((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject MLScriptEditor::staticMetaObject = {
    { &QPlainTextEdit::staticMetaObject, qt_meta_stringdata_MLScriptEditor.data,
      qt_meta_data_MLScriptEditor,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MLScriptEditor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MLScriptEditor::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MLScriptEditor.stringdata0))
        return static_cast<void*>(const_cast< MLScriptEditor*>(this));
    return QPlainTextEdit::qt_metacast(_clname);
}

int MLScriptEditor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QPlainTextEdit::qt_metacall(_c, _id, _a);
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
struct qt_meta_stringdata_MyToolButton_t {
    QByteArrayData data[3];
    char stringdata0[23];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MyToolButton_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MyToolButton_t qt_meta_stringdata_MyToolButton = {
    {
QT_MOC_LITERAL(0, 0, 12), // "MyToolButton"
QT_MOC_LITERAL(1, 13, 8), // "openMenu"
QT_MOC_LITERAL(2, 22, 0) // ""

    },
    "MyToolButton\0openMenu\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MyToolButton[] = {

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
       1,    0,   19,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void MyToolButton::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MyToolButton *_t = static_cast<MyToolButton *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->openMenu(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject MyToolButton::staticMetaObject = {
    { &QToolButton::staticMetaObject, qt_meta_stringdata_MyToolButton.data,
      qt_meta_data_MyToolButton,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MyToolButton::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MyToolButton::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MyToolButton.stringdata0))
        return static_cast<void*>(const_cast< MyToolButton*>(this));
    return QToolButton::qt_metacast(_clname);
}

int MyToolButton::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QToolButton::qt_metacall(_c, _id, _a);
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
struct qt_meta_stringdata_MenuLineEdit_t {
    QByteArrayData data[4];
    char stringdata0[29];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MenuLineEdit_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MenuLineEdit_t qt_meta_stringdata_MenuLineEdit = {
    {
QT_MOC_LITERAL(0, 0, 12), // "MenuLineEdit"
QT_MOC_LITERAL(1, 13, 12), // "arrowPressed"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 1) // "k"

    },
    "MenuLineEdit\0arrowPressed\0\0k"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MenuLineEdit[] = {

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
       1,    1,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,

       0        // eod
};

void MenuLineEdit::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MenuLineEdit *_t = static_cast<MenuLineEdit *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->arrowPressed((*reinterpret_cast< const int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MenuLineEdit::*_t)(const int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MenuLineEdit::arrowPressed)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject MenuLineEdit::staticMetaObject = {
    { &QLineEdit::staticMetaObject, qt_meta_stringdata_MenuLineEdit.data,
      qt_meta_data_MenuLineEdit,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MenuLineEdit::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MenuLineEdit::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MenuLineEdit.stringdata0))
        return static_cast<void*>(const_cast< MenuLineEdit*>(this));
    return QLineEdit::qt_metacast(_clname);
}

int MenuLineEdit::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QLineEdit::qt_metacall(_c, _id, _a);
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
void MenuLineEdit::arrowPressed(const int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_MenuWithToolTip_t {
    QByteArrayData data[1];
    char stringdata0[16];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MenuWithToolTip_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MenuWithToolTip_t qt_meta_stringdata_MenuWithToolTip = {
    {
QT_MOC_LITERAL(0, 0, 15) // "MenuWithToolTip"

    },
    "MenuWithToolTip"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MenuWithToolTip[] = {

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

void MenuWithToolTip::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject MenuWithToolTip::staticMetaObject = {
    { &QMenu::staticMetaObject, qt_meta_stringdata_MenuWithToolTip.data,
      qt_meta_data_MenuWithToolTip,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MenuWithToolTip::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MenuWithToolTip::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MenuWithToolTip.stringdata0))
        return static_cast<void*>(const_cast< MenuWithToolTip*>(this));
    return QMenu::qt_metacast(_clname);
}

int MenuWithToolTip::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMenu::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
struct qt_meta_stringdata_SearchMenu_t {
    QByteArrayData data[8];
    char stringdata0[74];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SearchMenu_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SearchMenu_t qt_meta_stringdata_SearchMenu = {
    {
QT_MOC_LITERAL(0, 0, 10), // "SearchMenu"
QT_MOC_LITERAL(1, 11, 6), // "edited"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 4), // "text"
QT_MOC_LITERAL(4, 24, 16), // "setLineEditFocus"
QT_MOC_LITERAL(5, 41, 18), // "onAboutToShowEvent"
QT_MOC_LITERAL(6, 60, 11), // "changeFocus"
QT_MOC_LITERAL(7, 72, 1) // "k"

    },
    "SearchMenu\0edited\0\0text\0setLineEditFocus\0"
    "onAboutToShowEvent\0changeFocus\0k"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SearchMenu[] = {

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
       1,    1,   34,    2, 0x08 /* Private */,
       4,    0,   37,    2, 0x08 /* Private */,
       5,    0,   38,    2, 0x08 /* Private */,
       6,    1,   39,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    7,

       0        // eod
};

void SearchMenu::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SearchMenu *_t = static_cast<SearchMenu *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->edited((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->setLineEditFocus(); break;
        case 2: _t->onAboutToShowEvent(); break;
        case 3: _t->changeFocus((*reinterpret_cast< const int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject SearchMenu::staticMetaObject = {
    { &MenuWithToolTip::staticMetaObject, qt_meta_stringdata_SearchMenu.data,
      qt_meta_data_SearchMenu,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *SearchMenu::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SearchMenu::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_SearchMenu.stringdata0))
        return static_cast<void*>(const_cast< SearchMenu*>(this));
    return MenuWithToolTip::qt_metacast(_clname);
}

int SearchMenu::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = MenuWithToolTip::qt_metacall(_c, _id, _a);
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
struct qt_meta_stringdata_MLFloatSlider_t {
    QByteArrayData data[5];
    char stringdata0[58];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MLFloatSlider_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MLFloatSlider_t qt_meta_stringdata_MLFloatSlider = {
    {
QT_MOC_LITERAL(0, 0, 13), // "MLFloatSlider"
QT_MOC_LITERAL(1, 14, 17), // "floatValueChanged"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 5), // "value"
QT_MOC_LITERAL(4, 39, 18) // "notifyValueChanged"

    },
    "MLFloatSlider\0floatValueChanged\0\0value\0"
    "notifyValueChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MLFloatSlider[] = {

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
       4,    1,   27,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Float,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,

       0        // eod
};

void MLFloatSlider::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MLFloatSlider *_t = static_cast<MLFloatSlider *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->floatValueChanged((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 1: _t->notifyValueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MLFloatSlider::*_t)(float );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MLFloatSlider::floatValueChanged)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject MLFloatSlider::staticMetaObject = {
    { &QSlider::staticMetaObject, qt_meta_stringdata_MLFloatSlider.data,
      qt_meta_data_MLFloatSlider,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MLFloatSlider::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MLFloatSlider::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MLFloatSlider.stringdata0))
        return static_cast<void*>(const_cast< MLFloatSlider*>(this));
    return QSlider::qt_metacast(_clname);
}

int MLFloatSlider::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QSlider::qt_metacall(_c, _id, _a);
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
void MLFloatSlider::floatValueChanged(float _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
