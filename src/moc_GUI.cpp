/****************************************************************************
** Meta object code from reading C++ file 'GUI.h'
**
** Created: Thu Dec 20 23:54:00 2007
**      by: The Qt Meta Object Compiler version 59 (Qt 4.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "gui/GUI.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GUI.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 59
#error "This file was generated using the moc from 4.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

static const uint qt_meta_data_GUI[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   10, // methods
       0,    0, // properties
       0,    0, // enums/sets

 // slots: signature, parameters, type, tag, flags
      11,    5,    4,    4, 0x0a,
      33,    5,    4,    4, 0x0a,
      51,    4,    4,    4, 0x0a,
      61,    4,    4,    4, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_GUI[] = {
    "GUI\0\0index\0setDirectoryInit(int)\0"
    "setDirectory(int)\0getPath()\0run()\0"
};

const QMetaObject GUI::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_GUI,
      qt_meta_data_GUI, 0 }
};

const QMetaObject *GUI::metaObject() const
{
    return &staticMetaObject;
}

void *GUI::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GUI))
	return static_cast<void*>(const_cast< GUI*>(this));
    return QWidget::qt_metacast(_clname);
}

int GUI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: setDirectoryInit((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: setDirectory((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: getPath(); break;
        case 3: run(); break;
        }
        _id -= 4;
    }
    return _id;
}
