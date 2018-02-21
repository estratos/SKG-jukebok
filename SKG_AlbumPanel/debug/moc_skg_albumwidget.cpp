/****************************************************************************
** Meta object code from reading C++ file 'skg_albumwidget.h'
**
** Created: Fri Jul 16 22:45:27 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../SKG_AlbumWidget/skg_albumwidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'skg_albumwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SKG_AlbumWidget[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      17,   16,   16,   16, 0x05,
      27,   16,   16,   16, 0x05,
      45,   16,   16,   16, 0x05,

 // slots: signature, parameters, type, tag, flags
      74,   68,   16,   16, 0x0a,
     130,   96,   16,   16, 0x0a,
     154,   96,   16,   16, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_SKG_AlbumWidget[] = {
    "SKG_AlbumWidget\0\0clicked()\0AlbumArtClicked()\0"
    "SelectedTrackChanged()\0album\0"
    "LoadAlbum(SKG_Album*)\0"
    "newtop,newleft,newwidth,newheight\0"
    "Expand(int,int,int,int)\0"
    "Contract(int,int,int,int)\0"
};

const QMetaObject SKG_AlbumWidget::staticMetaObject = {
    { &QFrame::staticMetaObject, qt_meta_stringdata_SKG_AlbumWidget,
      qt_meta_data_SKG_AlbumWidget, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SKG_AlbumWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SKG_AlbumWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SKG_AlbumWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SKG_AlbumWidget))
        return static_cast<void*>(const_cast< SKG_AlbumWidget*>(this));
    return QFrame::qt_metacast(_clname);
}

int SKG_AlbumWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QFrame::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: clicked(); break;
        case 1: AlbumArtClicked(); break;
        case 2: SelectedTrackChanged(); break;
        case 3: LoadAlbum((*reinterpret_cast< SKG_Album*(*)>(_a[1]))); break;
        case 4: Expand((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 5: Contract((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        default: ;
        }
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void SKG_AlbumWidget::clicked()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void SKG_AlbumWidget::AlbumArtClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void SKG_AlbumWidget::SelectedTrackChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}
QT_END_MOC_NAMESPACE
