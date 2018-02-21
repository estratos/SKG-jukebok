#ifndef SKG_ALBUMPANELFRAMESMALL_H
#define SKG_ALBUMPANELFRAMESMALL_H

#include <QFrame>
#include <QResizeEvent>
#include "../lib/skglib.h"
#include "../SKG_AlbumWidget/skg_albumwidget.h"

namespace Ui {
    class SKG_AlbumPanelFrameSmall;
}

class SKG_AlbumPanelFrameSmall : public QFrame {
    Q_OBJECT

public:
    SKG_AlbumPanelFrameSmall(QWidget *parent = 0);
    ~SKG_AlbumPanelFrameSmall();
    void LoadAlbum1(SKG_Album *album1,bool largealbumnumbers = false);
    void LoadAlbum2(SKG_Album *album2,bool largealbumnumbers = false);
    SKG_AlbumWidget *AlbumWidget1();
    SKG_AlbumWidget *AlbumWidget2();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::SKG_AlbumPanelFrameSmall *ui;
    int OriginalHeight;
    int OriginalWidth;
};

#endif // SKG_ALBUMPANELFRAMESMALL_H
