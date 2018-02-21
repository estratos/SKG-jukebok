/****************************************************************************
** Meta object code from reading C++ file 'skg_albumpanel.h'
**
** Created: Fri Jul 16 22:45:24 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../skg_albumpanel.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'skg_albumpanel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SKG_AlbumPanel[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: signature, parameters, type, tag, flags
      16,   15,   15,   15, 0x05,
      32,   15,   15,   15, 0x05,
      48,   15,   15,   15, 0x05,
      64,   15,   15,   15, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_SKG_AlbumPanel[] = {
    "SKG_AlbumPanel\0\0Album1Clicked()\0"
    "Album2Clicked()\0Album3Clicked()\0"
    "Album4Clicked()\0"
};

const QMetaObject SKG_AlbumPanel::staticMetaObject = {
    { &QFrame::staticMetaObject, qt_meta_stringdata_SKG_AlbumPanel,
      qt_meta_data_SKG_AlbumPanel, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SKG_AlbumPanel::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SKG_AlbumPanel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SKG_AlbumPanel::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SKG_AlbumPanel))
        return static_cast<void*>(const_cast< SKG_AlbumPanel*>(this));
    return QFrame::qt_metacast(_clname);
}

int SKG_AlbumPanel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QFrame::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: Album1Clicked(); break;
        case 1: Album2Clicked(); break;
        case 2: Album3Clicked(); break;
        case 3: Album4Clicked(); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void SKG_AlbumPanel::Album1Clicked()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void SKG_AlbumPanel::Album2Clicked()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void SKG_AlbumPanel::Album3Clicked()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void SKG_AlbumPanel::Album4Clicked()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}
QT_END_MOC_NAMESPACE
