#ifndef SKG_ALBUMPANELSMALL_H
#define SKG_ALBUMPANELSMALL_H

#include <QtGui/QFrame>
#include "skg_albumpanelframesmall.h"

class SKG_AlbumPanelSmall : public QFrame
{
    Q_OBJECT

private:
    SKG_AlbumPanelFrameSmall *panelframe;

protected:
    void mousePressEvent(QMouseEvent *event);

signals:
    void Album1Clicked();
    void Album2Clicked();

public:
    SKG_AlbumPanelSmall(QWidget *parent = 0);
    void LoadAlbums(SKG_Album *album1,SKG_Album *album2,bool largealbumnumbers = false);
    SKG_AlbumPanelSmall* operator = (const SKG_AlbumPanelSmall* other);
    SKG_Album *Album1();
    SKG_Album *Album2();
    void Clear();
};

#endif
