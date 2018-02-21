#ifndef SKG_ALBUMPANELFRAME_H
#define SKG_ALBUMPANELFRAME_H

#include <QFrame>
#include <QResizeEvent>
#include "../lib/skglib.h"
#include "../SKG_AlbumWidget/skg_albumwidget.h"

namespace Ui {
    class SKG_AlbumPanelFrame;
}

class SKG_AlbumPanelFrame : public QFrame {
    Q_OBJECT
public:
    SKG_AlbumPanelFrame(QWidget *parent = 0);
    ~SKG_AlbumPanelFrame();
    void LoadAlbum1(SKG_Album *album1,bool largealbumnumbers = false);
    void LoadAlbum2(SKG_Album *album2,bool largealbumnumbers = false);
    void LoadAlbum3(SKG_Album *album3,bool largealbumnumbers = false);
    void LoadAlbum4(SKG_Album *album4,bool largealbumnumbers = false);
    SKG_AlbumWidget *AlbumWidget1();
    SKG_AlbumWidget *AlbumWidget2();
    SKG_AlbumWidget *AlbumWidget3();
    SKG_AlbumWidget *AlbumWidget4();


protected:
    void changeEvent(QEvent *e);

private:
    Ui::SKG_AlbumPanelFrame *ui;
    int OriginalHeight;
    int OriginalWidth;
};

#endif // SKG_ALBUMPANELFRAME_H
