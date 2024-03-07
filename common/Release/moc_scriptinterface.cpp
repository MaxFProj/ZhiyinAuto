/****************************************************************************
** Meta object code from reading C++ file 'scriptinterface.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../scriptinterface.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'scriptinterface.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_VCGVertexSI_t {
    QByteArrayData data[18];
    char stringdata0[122];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_VCGVertexSI_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_VCGVertexSI_t qt_meta_stringdata_VCGVertexSI = {
    {
QT_MOC_LITERAL(0, 0, 11), // "VCGVertexSI"
QT_MOC_LITERAL(1, 12, 4), // "getP"
QT_MOC_LITERAL(2, 17, 16), // "QVector<Scalarm>"
QT_MOC_LITERAL(3, 34, 0), // ""
QT_MOC_LITERAL(4, 35, 8), // "getPoint"
QT_MOC_LITERAL(5, 44, 11), // "VCGPoint3SI"
QT_MOC_LITERAL(6, 56, 5), // "setPC"
QT_MOC_LITERAL(7, 62, 7), // "Scalarm"
QT_MOC_LITERAL(8, 70, 1), // "x"
QT_MOC_LITERAL(9, 72, 1), // "y"
QT_MOC_LITERAL(10, 74, 1), // "z"
QT_MOC_LITERAL(11, 76, 4), // "setP"
QT_MOC_LITERAL(12, 81, 1), // "p"
QT_MOC_LITERAL(13, 83, 8), // "setPoint"
QT_MOC_LITERAL(14, 92, 4), // "getN"
QT_MOC_LITERAL(15, 97, 9), // "getNormal"
QT_MOC_LITERAL(16, 107, 9), // "setNormal"
QT_MOC_LITERAL(17, 117, 4) // "setN"

    },
    "VCGVertexSI\0getP\0QVector<Scalarm>\0\0"
    "getPoint\0VCGPoint3SI\0setPC\0Scalarm\0x\0"
    "y\0z\0setP\0p\0setPoint\0getN\0getNormal\0"
    "setNormal\0setN"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_VCGVertexSI[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // methods: name, argc, parameters, tag, flags
       1,    0,   59,    3, 0x02 /* Public */,
       4,    0,   60,    3, 0x02 /* Public */,
       6,    3,   61,    3, 0x02 /* Public */,
      11,    1,   68,    3, 0x02 /* Public */,
      13,    1,   71,    3, 0x02 /* Public */,
      14,    0,   74,    3, 0x02 /* Public */,
      15,    0,   75,    3, 0x02 /* Public */,
      16,    1,   76,    3, 0x02 /* Public */,
      17,    3,   79,    3, 0x02 /* Public */,

 // methods: parameters
    0x80000000 | 2,
    0x80000000 | 5,
    QMetaType::Void, 0x80000000 | 7, 0x80000000 | 7, 0x80000000 | 7,    8,    9,   10,
    QMetaType::Void, 0x80000000 | 2,   12,
    QMetaType::Void, 0x80000000 | 5,   12,
    0x80000000 | 2,
    0x80000000 | 5,
    QMetaType::Void, 0x80000000 | 5,   12,
    QMetaType::Void, 0x80000000 | 7, 0x80000000 | 7, 0x80000000 | 7,    8,    9,   10,

       0        // eod
};

void VCGVertexSI::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        VCGVertexSI *_t = static_cast<VCGVertexSI *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { QVector<Scalarm> _r = _t->getP();
            if (_a[0]) *reinterpret_cast< QVector<Scalarm>*>(_a[0]) = _r; }  break;
        case 1: { VCGPoint3SI _r = _t->getPoint();
            if (_a[0]) *reinterpret_cast< VCGPoint3SI*>(_a[0]) = _r; }  break;
        case 2: _t->setPC((*reinterpret_cast< const Scalarm(*)>(_a[1])),(*reinterpret_cast< const Scalarm(*)>(_a[2])),(*reinterpret_cast< const Scalarm(*)>(_a[3]))); break;
        case 3: _t->setP((*reinterpret_cast< const QVector<Scalarm>(*)>(_a[1]))); break;
        case 4: _t->setPoint((*reinterpret_cast< const VCGPoint3SI(*)>(_a[1]))); break;
        case 5: { QVector<Scalarm> _r = _t->getN();
            if (_a[0]) *reinterpret_cast< QVector<Scalarm>*>(_a[0]) = _r; }  break;
        case 6: { VCGPoint3SI _r = _t->getNormal();
            if (_a[0]) *reinterpret_cast< VCGPoint3SI*>(_a[0]) = _r; }  break;
        case 7: _t->setNormal((*reinterpret_cast< const VCGPoint3SI(*)>(_a[1]))); break;
        case 8: _t->setN((*reinterpret_cast< const Scalarm(*)>(_a[1])),(*reinterpret_cast< const Scalarm(*)>(_a[2])),(*reinterpret_cast< const Scalarm(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<Scalarm> >(); break;
            }
            break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< VCGPoint3SI >(); break;
            }
            break;
        case 7:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< VCGPoint3SI >(); break;
            }
            break;
        }
    }
}

const QMetaObject VCGVertexSI::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_VCGVertexSI.data,
      qt_meta_data_VCGVertexSI,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *VCGVertexSI::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *VCGVertexSI::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_VCGVertexSI.stringdata0))
        return static_cast<void*>(const_cast< VCGVertexSI*>(this));
    return QObject::qt_metacast(_clname);
}

int VCGVertexSI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
struct qt_meta_stringdata_MeshDocumentSI_t {
    QByteArrayData data[10];
    char stringdata0[92];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MeshDocumentSI_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MeshDocumentSI_t qt_meta_stringdata_MeshDocumentSI = {
    {
QT_MOC_LITERAL(0, 0, 14), // "MeshDocumentSI"
QT_MOC_LITERAL(1, 15, 7), // "getMesh"
QT_MOC_LITERAL(2, 23, 12), // "MeshModelSI*"
QT_MOC_LITERAL(3, 36, 0), // ""
QT_MOC_LITERAL(4, 37, 6), // "meshId"
QT_MOC_LITERAL(5, 44, 13), // "getMeshByName"
QT_MOC_LITERAL(6, 58, 4), // "name"
QT_MOC_LITERAL(7, 63, 7), // "current"
QT_MOC_LITERAL(8, 71, 9), // "currentId"
QT_MOC_LITERAL(9, 81, 10) // "setCurrent"

    },
    "MeshDocumentSI\0getMesh\0MeshModelSI*\0"
    "\0meshId\0getMeshByName\0name\0current\0"
    "currentId\0setCurrent"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MeshDocumentSI[] = {

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

 // methods: name, argc, parameters, tag, flags
       1,    1,   39,    3, 0x02 /* Public */,
       5,    1,   42,    3, 0x02 /* Public */,
       7,    0,   45,    3, 0x02 /* Public */,
       8,    0,   46,    3, 0x02 /* Public */,
       9,    1,   47,    3, 0x02 /* Public */,

 // methods: parameters
    0x80000000 | 2, QMetaType::Int,    4,
    0x80000000 | 2, QMetaType::QString,    6,
    0x80000000 | 2,
    QMetaType::Int,
    QMetaType::Int, QMetaType::Int,    4,

       0        // eod
};

void MeshDocumentSI::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MeshDocumentSI *_t = static_cast<MeshDocumentSI *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { MeshModelSI* _r = _t->getMesh((*reinterpret_cast< const int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< MeshModelSI**>(_a[0]) = _r; }  break;
        case 1: { MeshModelSI* _r = _t->getMeshByName((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< MeshModelSI**>(_a[0]) = _r; }  break;
        case 2: { MeshModelSI* _r = _t->current();
            if (_a[0]) *reinterpret_cast< MeshModelSI**>(_a[0]) = _r; }  break;
        case 3: { int _r = _t->currentId();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 4: { int _r = _t->setCurrent((*reinterpret_cast< const int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObject MeshDocumentSI::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_MeshDocumentSI.data,
      qt_meta_data_MeshDocumentSI,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MeshDocumentSI::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MeshDocumentSI::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MeshDocumentSI.stringdata0))
        return static_cast<void*>(const_cast< MeshDocumentSI*>(this));
    return QObject::qt_metacast(_clname);
}

int MeshDocumentSI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
struct qt_meta_stringdata_MeshModelSI_t {
    QByteArrayData data[29];
    char stringdata0[274];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MeshModelSI_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MeshModelSI_t qt_meta_stringdata_MeshModelSI = {
    {
QT_MOC_LITERAL(0, 0, 11), // "MeshModelSI"
QT_MOC_LITERAL(1, 12, 2), // "id"
QT_MOC_LITERAL(2, 15, 0), // ""
QT_MOC_LITERAL(3, 16, 8), // "bboxDiag"
QT_MOC_LITERAL(4, 25, 7), // "Scalarm"
QT_MOC_LITERAL(5, 33, 7), // "bboxMin"
QT_MOC_LITERAL(6, 41, 16), // "QVector<Scalarm>"
QT_MOC_LITERAL(7, 58, 7), // "bboxMax"
QT_MOC_LITERAL(8, 66, 12), // "computeMinVQ"
QT_MOC_LITERAL(9, 79, 12), // "computeMaxVQ"
QT_MOC_LITERAL(10, 92, 12), // "computeMinFQ"
QT_MOC_LITERAL(11, 105, 12), // "computeMaxFQ"
QT_MOC_LITERAL(12, 118, 4), // "vert"
QT_MOC_LITERAL(13, 123, 21), // "QVector<VCGVertexSI*>"
QT_MOC_LITERAL(14, 145, 15), // "getVertPosArray"
QT_MOC_LITERAL(15, 161, 12), // "Point3Vector"
QT_MOC_LITERAL(16, 174, 16), // "getVertNormArray"
QT_MOC_LITERAL(17, 191, 15), // "setVertPosArray"
QT_MOC_LITERAL(18, 207, 2), // "pa"
QT_MOC_LITERAL(19, 210, 16), // "setVertNormArray"
QT_MOC_LITERAL(20, 227, 2), // "na"
QT_MOC_LITERAL(21, 230, 5), // "label"
QT_MOC_LITERAL(22, 236, 2), // "vn"
QT_MOC_LITERAL(23, 239, 2), // "fn"
QT_MOC_LITERAL(24, 242, 1), // "v"
QT_MOC_LITERAL(25, 244, 12), // "VCGVertexSI*"
QT_MOC_LITERAL(26, 257, 3), // "ind"
QT_MOC_LITERAL(27, 261, 4), // "shot"
QT_MOC_LITERAL(28, 266, 7) // "ShotSI*"

    },
    "MeshModelSI\0id\0\0bboxDiag\0Scalarm\0"
    "bboxMin\0QVector<Scalarm>\0bboxMax\0"
    "computeMinVQ\0computeMaxVQ\0computeMinFQ\0"
    "computeMaxFQ\0vert\0QVector<VCGVertexSI*>\0"
    "getVertPosArray\0Point3Vector\0"
    "getVertNormArray\0setVertPosArray\0pa\0"
    "setVertNormArray\0na\0label\0vn\0fn\0v\0"
    "VCGVertexSI*\0ind\0shot\0ShotSI*"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MeshModelSI[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // methods: name, argc, parameters, tag, flags
       1,    0,  104,    2, 0x02 /* Public */,
       3,    0,  105,    2, 0x02 /* Public */,
       5,    0,  106,    2, 0x02 /* Public */,
       7,    0,  107,    2, 0x02 /* Public */,
       8,    0,  108,    2, 0x02 /* Public */,
       9,    0,  109,    2, 0x02 /* Public */,
      10,    0,  110,    2, 0x02 /* Public */,
      11,    0,  111,    2, 0x02 /* Public */,
      12,    0,  112,    2, 0x02 /* Public */,
      14,    0,  113,    2, 0x02 /* Public */,
      16,    0,  114,    2, 0x02 /* Public */,
      17,    1,  115,    2, 0x02 /* Public */,
      19,    1,  118,    2, 0x02 /* Public */,
      21,    0,  121,    2, 0x02 /* Public */,
      22,    0,  122,    2, 0x02 /* Public */,
      23,    0,  123,    2, 0x02 /* Public */,
      24,    1,  124,    2, 0x02 /* Public */,
      27,    0,  127,    2, 0x02 /* Public */,

 // methods: parameters
    QMetaType::Int,
    0x80000000 | 4,
    0x80000000 | 6,
    0x80000000 | 6,
    0x80000000 | 4,
    0x80000000 | 4,
    0x80000000 | 4,
    0x80000000 | 4,
    0x80000000 | 13,
    0x80000000 | 15,
    0x80000000 | 15,
    QMetaType::Void, 0x80000000 | 15,   18,
    QMetaType::Void, 0x80000000 | 15,   20,
    QMetaType::QString,
    QMetaType::Int,
    QMetaType::Int,
    0x80000000 | 25, QMetaType::Int,   26,
    0x80000000 | 28,

       0        // eod
};

void MeshModelSI::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MeshModelSI *_t = static_cast<MeshModelSI *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { int _r = _t->id();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 1: { Scalarm _r = _t->bboxDiag();
            if (_a[0]) *reinterpret_cast< Scalarm*>(_a[0]) = _r; }  break;
        case 2: { QVector<Scalarm> _r = _t->bboxMin();
            if (_a[0]) *reinterpret_cast< QVector<Scalarm>*>(_a[0]) = _r; }  break;
        case 3: { QVector<Scalarm> _r = _t->bboxMax();
            if (_a[0]) *reinterpret_cast< QVector<Scalarm>*>(_a[0]) = _r; }  break;
        case 4: { Scalarm _r = _t->computeMinVQ();
            if (_a[0]) *reinterpret_cast< Scalarm*>(_a[0]) = _r; }  break;
        case 5: { Scalarm _r = _t->computeMaxVQ();
            if (_a[0]) *reinterpret_cast< Scalarm*>(_a[0]) = _r; }  break;
        case 6: { Scalarm _r = _t->computeMinFQ();
            if (_a[0]) *reinterpret_cast< Scalarm*>(_a[0]) = _r; }  break;
        case 7: { Scalarm _r = _t->computeMaxFQ();
            if (_a[0]) *reinterpret_cast< Scalarm*>(_a[0]) = _r; }  break;
        case 8: { QVector<VCGVertexSI*> _r = _t->vert();
            if (_a[0]) *reinterpret_cast< QVector<VCGVertexSI*>*>(_a[0]) = _r; }  break;
        case 9: { Point3Vector _r = _t->getVertPosArray();
            if (_a[0]) *reinterpret_cast< Point3Vector*>(_a[0]) = _r; }  break;
        case 10: { Point3Vector _r = _t->getVertNormArray();
            if (_a[0]) *reinterpret_cast< Point3Vector*>(_a[0]) = _r; }  break;
        case 11: _t->setVertPosArray((*reinterpret_cast< const Point3Vector(*)>(_a[1]))); break;
        case 12: _t->setVertNormArray((*reinterpret_cast< const Point3Vector(*)>(_a[1]))); break;
        case 13: { QString _r = _t->label();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 14: { int _r = _t->vn();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 15: { int _r = _t->fn();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 16: { VCGVertexSI* _r = _t->v((*reinterpret_cast< const int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< VCGVertexSI**>(_a[0]) = _r; }  break;
        case 17: { ShotSI* _r = _t->shot();
            if (_a[0]) *reinterpret_cast< ShotSI**>(_a[0]) = _r; }  break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 11:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Point3Vector >(); break;
            }
            break;
        case 12:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Point3Vector >(); break;
            }
            break;
        }
    }
}

const QMetaObject MeshModelSI::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_MeshModelSI.data,
      qt_meta_data_MeshModelSI,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MeshModelSI::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MeshModelSI::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MeshModelSI.stringdata0))
        return static_cast<void*>(const_cast< MeshModelSI*>(this));
    return QObject::qt_metacast(_clname);
}

int MeshModelSI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    }
    return _id;
}
struct qt_meta_stringdata_Env_t {
    QByteArrayData data[5];
    char stringdata0[36];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Env_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Env_t qt_meta_stringdata_Env = {
    {
QT_MOC_LITERAL(0, 0, 3), // "Env"
QT_MOC_LITERAL(1, 4, 23), // "insertExpressionBinding"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 2), // "nm"
QT_MOC_LITERAL(4, 32, 3) // "exp"

    },
    "Env\0insertExpressionBinding\0\0nm\0exp"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Env[] = {

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

 // methods: name, argc, parameters, tag, flags
       1,    2,   19,    2, 0x02 /* Public */,

 // methods: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    3,    4,

       0        // eod
};

void Env::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Env *_t = static_cast<Env *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->insertExpressionBinding((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObject Env::staticMetaObject = {
    { &QScriptEngine::staticMetaObject, qt_meta_stringdata_Env.data,
      qt_meta_data_Env,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Env::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Env::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Env.stringdata0))
        return static_cast<void*>(const_cast< Env*>(this));
    return QScriptEngine::qt_metacast(_clname);
}

int Env::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QScriptEngine::qt_metacall(_c, _id, _a);
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
struct qt_meta_stringdata_ShotSI_t {
    QByteArrayData data[4];
    char stringdata0[23];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ShotSI_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ShotSI_t qt_meta_stringdata_ShotSI = {
    {
QT_MOC_LITERAL(0, 0, 6), // "ShotSI"
QT_MOC_LITERAL(1, 7, 6), // "itSelf"
QT_MOC_LITERAL(2, 14, 7), // "ShotSI*"
QT_MOC_LITERAL(3, 22, 0) // ""

    },
    "ShotSI\0itSelf\0ShotSI*\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ShotSI[] = {

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

 // methods: name, argc, parameters, tag, flags
       1,    0,   19,    3, 0x02 /* Public */,

 // methods: parameters
    0x80000000 | 2,

       0        // eod
};

void ShotSI::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ShotSI *_t = static_cast<ShotSI *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { ShotSI* _r = _t->itSelf();
            if (_a[0]) *reinterpret_cast< ShotSI**>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObject ShotSI::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ShotSI.data,
      qt_meta_data_ShotSI,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ShotSI::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ShotSI::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ShotSI.stringdata0))
        return static_cast<void*>(const_cast< ShotSI*>(this));
    return QObject::qt_metacast(_clname);
}

int ShotSI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE
