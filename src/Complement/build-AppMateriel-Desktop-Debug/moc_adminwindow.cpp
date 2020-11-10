/****************************************************************************
** Meta object code from reading C++ file 'adminwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../AppMaterielV2/client/adminwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'adminwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_AdminWindow_t {
    QByteArrayData data[13];
    char stringdata[342];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AdminWindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AdminWindow_t qt_meta_stringdata_AdminWindow = {
    {
QT_MOC_LITERAL(0, 0, 11), // "AdminWindow"
QT_MOC_LITERAL(1, 12, 28), // "on_pushButtonAddUser_clicked"
QT_MOC_LITERAL(2, 41, 0), // ""
QT_MOC_LITERAL(3, 42, 25), // "on_pushButtonEdit_clicked"
QT_MOC_LITERAL(4, 68, 27), // "on_pushButtonDelete_clicked"
QT_MOC_LITERAL(5, 96, 27), // "on_pushButtonGetAll_clicked"
QT_MOC_LITERAL(6, 124, 27), // "on_pushButtonSearch_clicked"
QT_MOC_LITERAL(7, 152, 32), // "on_pushButtonValid_Seach_clicked"
QT_MOC_LITERAL(8, 185, 33), // "on_pushButtonValid_GetAll_cli..."
QT_MOC_LITERAL(9, 219, 34), // "on_pushButtonValid_AddUser_cl..."
QT_MOC_LITERAL(10, 254, 31), // "on_pushButtonValid_Edit_clicked"
QT_MOC_LITERAL(11, 286, 33), // "on_pushButtonValid_Delete_cli..."
QT_MOC_LITERAL(12, 320, 21) // "on_listWidget_clicked"

    },
    "AdminWindow\0on_pushButtonAddUser_clicked\0"
    "\0on_pushButtonEdit_clicked\0"
    "on_pushButtonDelete_clicked\0"
    "on_pushButtonGetAll_clicked\0"
    "on_pushButtonSearch_clicked\0"
    "on_pushButtonValid_Seach_clicked\0"
    "on_pushButtonValid_GetAll_clicked\0"
    "on_pushButtonValid_AddUser_clicked\0"
    "on_pushButtonValid_Edit_clicked\0"
    "on_pushButtonValid_Delete_clicked\0"
    "on_listWidget_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AdminWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x08 /* Private */,
       3,    0,   70,    2, 0x08 /* Private */,
       4,    0,   71,    2, 0x08 /* Private */,
       5,    0,   72,    2, 0x08 /* Private */,
       6,    0,   73,    2, 0x08 /* Private */,
       7,    0,   74,    2, 0x08 /* Private */,
       8,    0,   75,    2, 0x08 /* Private */,
       9,    0,   76,    2, 0x08 /* Private */,
      10,    0,   77,    2, 0x08 /* Private */,
      11,    0,   78,    2, 0x08 /* Private */,
      12,    0,   79,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
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

void AdminWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AdminWindow *_t = static_cast<AdminWindow *>(_o);
        switch (_id) {
        case 0: _t->on_pushButtonAddUser_clicked(); break;
        case 1: _t->on_pushButtonEdit_clicked(); break;
        case 2: _t->on_pushButtonDelete_clicked(); break;
        case 3: _t->on_pushButtonGetAll_clicked(); break;
        case 4: _t->on_pushButtonSearch_clicked(); break;
        case 5: _t->on_pushButtonValid_Seach_clicked(); break;
        case 6: _t->on_pushButtonValid_GetAll_clicked(); break;
        case 7: _t->on_pushButtonValid_AddUser_clicked(); break;
        case 8: _t->on_pushButtonValid_Edit_clicked(); break;
        case 9: _t->on_pushButtonValid_Delete_clicked(); break;
        case 10: _t->on_listWidget_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject AdminWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_AdminWindow.data,
      qt_meta_data_AdminWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *AdminWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AdminWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_AdminWindow.stringdata))
        return static_cast<void*>(const_cast< AdminWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int AdminWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE
