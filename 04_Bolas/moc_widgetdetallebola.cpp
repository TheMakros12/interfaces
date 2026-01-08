/****************************************************************************
** Meta object code from reading C++ file 'widgetdetallebola.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.13)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "widgetdetallebola.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'widgetdetallebola.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.13. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_WidgetDetalleBola_t {
    QByteArrayData data[6];
    char stringdata0[92];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_WidgetDetalleBola_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_WidgetDetalleBola_t qt_meta_stringdata_WidgetDetalleBola = {
    {
QT_MOC_LITERAL(0, 0, 17), // "WidgetDetalleBola"
QT_MOC_LITERAL(1, 18, 15), // "slotCambiarRojo"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 16), // "slotCambiarVerde"
QT_MOC_LITERAL(4, 52, 15), // "slotCambiarAzul"
QT_MOC_LITERAL(5, 68, 23) // "on_btnPararBola_clicked"

    },
    "WidgetDetalleBola\0slotCambiarRojo\0\0"
    "slotCambiarVerde\0slotCambiarAzul\0"
    "on_btnPararBola_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WidgetDetalleBola[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x0a /* Public */,
       3,    1,   37,    2, 0x0a /* Public */,
       4,    1,   40,    2, 0x0a /* Public */,
       5,    0,   43,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,

       0        // eod
};

void WidgetDetalleBola::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<WidgetDetalleBola *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->slotCambiarRojo((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->slotCambiarVerde((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->slotCambiarAzul((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->on_btnPararBola_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject WidgetDetalleBola::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_WidgetDetalleBola.data,
    qt_meta_data_WidgetDetalleBola,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *WidgetDetalleBola::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WidgetDetalleBola::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_WidgetDetalleBola.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "Ui::WidgetDetalleBola"))
        return static_cast< Ui::WidgetDetalleBola*>(this);
    return QWidget::qt_metacast(_clname);
}

int WidgetDetalleBola::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
