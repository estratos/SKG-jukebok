/****************************************************************************
** Meta object code from reading C++ file 'skg_albumframe.h'
**
** Created: Fri Jul 16 22:41:19 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../SKG_AlbumWidget/skg_albumframe.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'skg_albumframe.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SKG_AlbumFrame[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      22,   16,   15,   15, 0x0a,
      44,   15,   15,   15, 0x0a,
      61,   15,   15,   15, 0x0a,
      87,   79,   15,   15, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_SKG_AlbumFrame[] = {
    "SKG_AlbumFrame\0\0album\0LoadAlbum(SKG_Album*)\0"
    "EnableControls()\0DisableControls()\0"
    "newsize\0ResizeFrame(QSize)\0"
};

const QMetaObject SKG_AlbumFrame::staticMetaObject = {
    { &QFrame::staticMetaObject, qt_meta_stringdata_SKG_AlbumFrame,
      qt_meta_data_SKG_AlbumFrame, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SKG_AlbumFrame::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SKG_AlbumFrame::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SKG_AlbumFrame::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SKG_AlbumFrame))
        return static_cast<void*>(const_cast< SKG_AlbumFrame*>(this));
    return QFrame::qt_metacast(_clname);
}

int SKG_AlbumFrame::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QFrame::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: LoadAlbum((*reinterpret_cast< SKG_Album*(*)>(_a[1]))); break;
        case 1: EnableControls(); break;
        case 2: DisableControls(); break;
        case 3: ResizeFrame((*reinterpret_cast< QSize(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
