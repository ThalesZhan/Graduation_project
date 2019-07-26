/****************************************************************************
** Meta object code from reading C++ file 'pro_rec.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Rec_GUI/pro_rec.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'pro_rec.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Pro_Rec_t {
    QByteArrayData data[14];
    char stringdata0[252];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Pro_Rec_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Pro_Rec_t qt_meta_stringdata_Pro_Rec = {
    {
QT_MOC_LITERAL(0, 0, 7), // "Pro_Rec"
QT_MOC_LITERAL(1, 8, 12), // "get_Filename"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 10), // "initialize"
QT_MOC_LITERAL(4, 33, 28), // "on_radioButton_shape_clicked"
QT_MOC_LITERAL(5, 62, 7), // "checked"
QT_MOC_LITERAL(6, 70, 29), // "on_radioButton_chalky_clicked"
QT_MOC_LITERAL(7, 100, 18), // "on_convert_clicked"
QT_MOC_LITERAL(8, 119, 20), // "on_denoising_clicked"
QT_MOC_LITERAL(9, 140, 20), // "on_splitback_clicked"
QT_MOC_LITERAL(10, 161, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(11, 183, 20), // "on_histogram_clicked"
QT_MOC_LITERAL(12, 204, 22), // "on_gparameters_clicked"
QT_MOC_LITERAL(13, 227, 24) // "on_recgonization_clicked"

    },
    "Pro_Rec\0get_Filename\0\0initialize\0"
    "on_radioButton_shape_clicked\0checked\0"
    "on_radioButton_chalky_clicked\0"
    "on_convert_clicked\0on_denoising_clicked\0"
    "on_splitback_clicked\0on_pushButton_clicked\0"
    "on_histogram_clicked\0on_gparameters_clicked\0"
    "on_recgonization_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Pro_Rec[] = {

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
       1,    0,   69,    2, 0x0a /* Public */,
       3,    0,   70,    2, 0x0a /* Public */,
       4,    1,   71,    2, 0x08 /* Private */,
       6,    1,   74,    2, 0x08 /* Private */,
       7,    0,   77,    2, 0x08 /* Private */,
       8,    0,   78,    2, 0x08 /* Private */,
       9,    0,   79,    2, 0x08 /* Private */,
      10,    0,   80,    2, 0x08 /* Private */,
      11,    0,   81,    2, 0x08 /* Private */,
      12,    0,   82,    2, 0x08 /* Private */,
      13,    0,   83,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Pro_Rec::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Pro_Rec *_t = static_cast<Pro_Rec *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->get_Filename(); break;
        case 1: _t->initialize(); break;
        case 2: _t->on_radioButton_shape_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->on_radioButton_chalky_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->on_convert_clicked(); break;
        case 5: _t->on_denoising_clicked(); break;
        case 6: _t->on_splitback_clicked(); break;
        case 7: _t->on_pushButton_clicked(); break;
        case 8: _t->on_histogram_clicked(); break;
        case 9: _t->on_gparameters_clicked(); break;
        case 10: _t->on_recgonization_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject Pro_Rec::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_Pro_Rec.data,
      qt_meta_data_Pro_Rec,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Pro_Rec::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Pro_Rec::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Pro_Rec.stringdata0))
        return static_cast<void*>(const_cast< Pro_Rec*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int Pro_Rec::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
