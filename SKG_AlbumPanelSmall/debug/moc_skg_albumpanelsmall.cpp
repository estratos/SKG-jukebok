/****************************************************************************
** Meta object code from reading C++ file 'skg_albumpanelsmall.h'
**
** Created: Fri Jul 16 22:41:12 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../skg_albumpanelsmall.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'skg_albumpanelsmall.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SKG_AlbumPanelSmall[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      21,   20,   20,   20, 0x05,
      37,   20,   20,   20, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_SKG_AlbumPanelSmall[] = {
    "SKG_AlbumPanelSmall\0\0Album1Clicked()\0"
    "Album2Clicked()\0"
};

const QMetaObject SKG_AlbumPanelSmall::staticMetaObject = {
    { &QFrame::staticMetaObject, qt_meta_stringdata_SKG_AlbumPanelSmall,
      qt_meta_data_SKG_AlbumPanelSmall, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SKG_AlbumPanelSmall::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SKG_AlbumPanelSmall::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SKG_AlbumPanelSmall::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SKG_AlbumPanelSmall))
        return static_cast<void*>(const_cast< SKG_AlbumPanelSmall*>(this));
    return QFrame::qt_metacast(_clname);
}

int SKG_AlbumPanelSmall::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QFrame::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: Album1Clicked(); break;
        case 1: Album2Clicked(); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void SKG_AlbumPanelSmall::Album1Clicked()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void SKG_AlbumPanelSmall::Album2Clicked()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
