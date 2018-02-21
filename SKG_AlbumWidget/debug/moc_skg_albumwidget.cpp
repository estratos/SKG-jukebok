/****************************************************************************
** Meta object code from reading C++ file 'skg_albumwidget.h'
**
** Created: Sat Oct 16 13:04:05 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../skg_albumwidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'skg_albumwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SKG_AlbumWidget[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: signature, parameters, type, tag, flags
      17,   16,   16,   16, 0x05,
      27,   16,   16,   16, 0x05,
      45,   16,   16,   16, 0x05,
      68,   16,   16,   16, 0x05,

 // slots: signature, parameters, type, tag, flags
      90,   84,   16,   16, 0x0a,
     146,  112,   16,   16, 0x0a,
     170,  112,   16,   16, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_SKG_AlbumWidget[] = {
    "SKG_AlbumWidget\0\0clicked()\0AlbumArtClicked()\0"
    "SelectedTrackChanged()\0doubleclicked()\0"
    "album\0LoadAlbum(SKG_Album*)\0"
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
        case 3: doubleclicked(); break;
        case 4: LoadAlbum((*reinterpret_cast< SKG_Album*(*)>(_a[1]))); break;
        case 5: Expand((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 6: Contract((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        default: ;
        }
        _id -= 7;
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

// SIGNAL 3
void SKG_AlbumWidget::doubleclicked()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}
QT_END_MOC_NAMESPACE
