/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      21,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      38,   11,   11,   11, 0x08,
      64,   11,   11,   11, 0x08,
      91,   11,   11,   11, 0x08,
     117,   11,   11,   11, 0x08,
     144,   11,   11,   11, 0x08,
     170,   11,   11,   11, 0x08,
     197,   11,   11,   11, 0x08,
     223,   11,   11,   11, 0x08,
     250,   11,   11,   11, 0x08,
     276,   11,   11,   11, 0x08,
     302,   11,   11,   11, 0x08,
     328,   11,   11,   11, 0x08,
     352,   11,   11,   11, 0x08,
     377,   11,   11,   11, 0x08,
     403,   11,   11,   11, 0x08,
     430,   11,   11,   11, 0x08,
     457,   11,   11,   11, 0x08,
     483,   11,   11,   11, 0x08,
     499,   11,   11,   11, 0x08,
     528,  520,  516,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0on_pushButton_4_clicked()\0"
    "on_pushButton_4_pressed()\0"
    "on_pushButton_4_released()\0"
    "on_pushButton_5_pressed()\0"
    "on_pushButton_5_released()\0"
    "on_pushButton_6_pressed()\0"
    "on_pushButton_6_released()\0"
    "on_pushButton_7_pressed()\0"
    "on_pushButton_7_released()\0"
    "on_pushButton_6_clicked()\0"
    "on_pushButton_2_clicked()\0"
    "on_pushButton_3_clicked()\0"
    "on_pushButton_pressed()\0"
    "on_pushButton_released()\0"
    "on_pushButton_2_pressed()\0"
    "on_pushButton_2_released()\0"
    "on_pushButton_3_released()\0"
    "on_pushButton_3_pressed()\0updateBattery()\0"
    "updateLiveData()\0int\0min,max\0"
    "random(int,int)\0"
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->on_pushButton_4_clicked(); break;
        case 1: _t->on_pushButton_4_pressed(); break;
        case 2: _t->on_pushButton_4_released(); break;
        case 3: _t->on_pushButton_5_pressed(); break;
        case 4: _t->on_pushButton_5_released(); break;
        case 5: _t->on_pushButton_6_pressed(); break;
        case 6: _t->on_pushButton_6_released(); break;
        case 7: _t->on_pushButton_7_pressed(); break;
        case 8: _t->on_pushButton_7_released(); break;
        case 9: _t->on_pushButton_6_clicked(); break;
        case 10: _t->on_pushButton_2_clicked(); break;
        case 11: _t->on_pushButton_3_clicked(); break;
        case 12: _t->on_pushButton_pressed(); break;
        case 13: _t->on_pushButton_released(); break;
        case 14: _t->on_pushButton_2_pressed(); break;
        case 15: _t->on_pushButton_2_released(); break;
        case 16: _t->on_pushButton_3_released(); break;
        case 17: _t->on_pushButton_3_pressed(); break;
        case 18: _t->updateBattery(); break;
        case 19: _t->updateLiveData(); break;
        case 20: { int _r = _t->random((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MainWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 21)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 21;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
