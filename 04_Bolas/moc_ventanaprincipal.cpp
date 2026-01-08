/****************************************************************************
** Meta object code from reading C++ file 'ventanaprincipal.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.13)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "ventanaprincipal.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ventanaprincipal.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.13. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_VentanaPrincipal_t {
    QByteArrayData data[11];
    char stringdata0[180];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_VentanaPrincipal_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_VentanaPrincipal_t qt_meta_stringdata_VentanaPrincipal = {
    {
QT_MOC_LITERAL(0, 0, 16), // "VentanaPrincipal"
QT_MOC_LITERAL(1, 17, 16), // "slotTemporizador"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 16), // "slotDInformacion"
QT_MOC_LITERAL(4, 52, 15), // "slotDListaBolas"
QT_MOC_LITERAL(5, 68, 15), // "slotDTablaBolas"
QT_MOC_LITERAL(6, 84, 17), // "slotDTablaRebotes"
QT_MOC_LITERAL(7, 102, 18), // "slotGuardarPartida"
QT_MOC_LITERAL(8, 121, 17), // "slotCargarPartida"
QT_MOC_LITERAL(9, 139, 16), // "slotDDetalleBola"
QT_MOC_LITERAL(10, 156, 23) // "slotDDConfiguracionBola"

    },
    "VentanaPrincipal\0slotTemporizador\0\0"
    "slotDInformacion\0slotDListaBolas\0"
    "slotDTablaBolas\0slotDTablaRebotes\0"
    "slotGuardarPartida\0slotCargarPartida\0"
    "slotDDetalleBola\0slotDDConfiguracionBola"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_VentanaPrincipal[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x0a /* Public */,
       3,    0,   60,    2, 0x0a /* Public */,
       4,    0,   61,    2, 0x0a /* Public */,
       5,    0,   62,    2, 0x0a /* Public */,
       6,    0,   63,    2, 0x0a /* Public */,
       7,    0,   64,    2, 0x0a /* Public */,
       8,    0,   65,    2, 0x0a /* Public */,
       9,    0,   66,    2, 0x0a /* Public */,
      10,    0,   67,    2, 0x0a /* Public */,

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

       0        // eod
};

void VentanaPrincipal::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<VentanaPrincipal *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->slotTemporizador(); break;
        case 1: _t->slotDInformacion(); break;
        case 2: _t->slotDListaBolas(); break;
        case 3: _t->slotDTablaBolas(); break;
        case 4: _t->slotDTablaRebotes(); break;
        case 5: _t->slotGuardarPartida(); break;
        case 6: _t->slotCargarPartida(); break;
        case 7: _t->slotDDetalleBola(); break;
        case 8: _t->slotDDConfiguracionBola(); break;
        default: ;
        }
    }
    (void)_a;
}

QT_INIT_METAOBJECT const QMetaObject VentanaPrincipal::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_VentanaPrincipal.data,
    qt_meta_data_VentanaPrincipal,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *VentanaPrincipal::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *VentanaPrincipal::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_VentanaPrincipal.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int VentanaPrincipal::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
