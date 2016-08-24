/****************************************************************************
** Meta object code from reading C++ file 'setmap.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "setmap.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'setmap.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SetMap[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       8,    7,    7,    7, 0x0a,
      16,    7,    7,    7, 0x0a,
      26,    7,    7,    7, 0x0a,
      34,    7,    7,    7, 0x0a,
      42,    7,    7,    7, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_SetMap[] = {
    "SetMap\0\0start()\0restart()\0reset()\0"
    "check()\0quit()\0"
};

void SetMap::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        SetMap *_t = static_cast<SetMap *>(_o);
        switch (_id) {
        case 0: _t->start(); break;
        case 1: _t->restart(); break;
        case 2: _t->reset(); break;
        case 3: _t->check(); break;
        case 4: _t->quit(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData SetMap::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject SetMap::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_SetMap,
      qt_meta_data_SetMap, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SetMap::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SetMap::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SetMap::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SetMap))
        return static_cast<void*>(const_cast< SetMap*>(this));
    return QDialog::qt_metacast(_clname);
}

int SetMap::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
