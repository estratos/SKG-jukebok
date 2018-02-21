#ifndef SKG_ALBUMPANEL_H
#define SKG_ALBUMPANEL_H

#include <QtGui/QFrame>
#include "../lib/skglib.h"
#include "skg_albumpanelframe.h"

class SKG_AlbumPanel : public QFrame
{
    Q_OBJECT

private:
    SKG_AlbumPanelFrame *panelframe;

protected:
    void mousePressEvent(QMouseEvent *event);
    void resizeEvent(QResizeEvent *event);

signals:
    void Album1Clicked();
    void Album2Clicked();
    void Album3Clicked();
    void Album4Clicked();

public:
    SKG_AlbumPanel(QWidget *parent = 0);
    void LoadAlbums(SKG_Album *album1,
                    SKG_Album *album2,
                    SKG_Album *album3,
                    SKG_Album *album4,
                    bool largealbumnumbers = false);
    SKG_AlbumPanel* operator = (const SKG_AlbumPanel* other);
    SKG_Album *Album1();
    SKG_Album *Album2();
    SKG_Album *Album3();
    SKG_Album *Album4();
    void Clear();

};

#endif
