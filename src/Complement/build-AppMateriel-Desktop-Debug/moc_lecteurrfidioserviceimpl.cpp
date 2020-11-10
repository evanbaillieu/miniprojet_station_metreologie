/****************************************************************************
** Meta object code from reading C++ file 'lecteurrfidioserviceimpl.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../AppMaterielV2/physiqueIO/lecteurrfidioserviceimpl.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'lecteurrfidioserviceimpl.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_PhysiqueIO__LecteurRFIDIOServiceImpl_t {
    QByteArrayData data[7];
    char stringdata[97];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PhysiqueIO__LecteurRFIDIOServiceImpl_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PhysiqueIO__LecteurRFIDIOServiceImpl_t qt_meta_stringdata_PhysiqueIO__LecteurRFIDIOServiceImpl = {
    {
QT_MOC_LITERAL(0, 0, 36), // "PhysiqueIO::LecteurRFIDIOServ..."
QT_MOC_LITERAL(1, 37, 6), // "dataOk"
QT_MOC_LITERAL(2, 44, 0), // ""
QT_MOC_LITERAL(3, 45, 13), // "deconnexionOK"
QT_MOC_LITERAL(4, 59, 11), // "connexionOK"
QT_MOC_LITERAL(5, 71, 12), // "readDatagram"
QT_MOC_LITERAL(6, 84, 12) // "detectErreur"

    },
    "PhysiqueIO::LecteurRFIDIOServiceImpl\0"
    "dataOk\0\0deconnexionOK\0connexionOK\0"
    "readDatagram\0detectErreur"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PhysiqueIO__LecteurRFIDIOServiceImpl[] = {

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
       1,    1,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   42,    2, 0x0a /* Public */,
       4,    0,   43,    2, 0x0a /* Public */,
       5,    0,   44,    2, 0x0a /* Public */,
       6,    0,   45,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void PhysiqueIO::LecteurRFIDIOServiceImpl::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        LecteurRFIDIOServiceImpl *_t = static_cast<LecteurRFIDIOServiceImpl *>(_o);
        switch (_id) {
        case 0: _t->dataOk((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->deconnexionOK(); break;
        case 2: _t->connexionOK(); break;
        case 3: _t->readDatagram(); break;
        case 4: _t->detectErreur(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (LecteurRFIDIOServiceImpl::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&LecteurRFIDIOServiceImpl::dataOk)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject PhysiqueIO::LecteurRFIDIOServiceImpl::staticMetaObject = {
    { &LecteurRFIDIOService::staticMetaObject, qt_meta_stringdata_PhysiqueIO__LecteurRFIDIOServiceImpl.data,
      qt_meta_data_PhysiqueIO__LecteurRFIDIOServiceImpl,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *PhysiqueIO::LecteurRFIDIOServiceImpl::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PhysiqueIO::LecteurRFIDIOServiceImpl::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_PhysiqueIO__LecteurRFIDIOServiceImpl.stringdata))
        return static_cast<void*>(const_cast< LecteurRFIDIOServiceImpl*>(this));
    return LecteurRFIDIOService::qt_metacast(_clname);
}

int PhysiqueIO::LecteurRFIDIOServiceImpl::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = LecteurRFIDIOService::qt_metacall(_c, _id, _a);
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
void PhysiqueIO::LecteurRFIDIOServiceImpl::dataOk(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
