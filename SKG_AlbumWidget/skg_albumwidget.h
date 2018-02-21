#ifndef SKG_ALBUMWIDGET_H
#define SKG_ALBUMWIDGET_H

//#include <QtGui/QWidget>
#include <QtGui/QFrame>
#include "skg_albumframe.h"

class SKG_AlbumWidget : public QFrame
{
    Q_OBJECT

friend class SKG_AlbumPanelSmall;
friend class SKG_AlbumPanel;

private:
    SKG_AlbumFrame *albumframe;
    SKG_Album *LoadedAlbum;
    void DisableControls();

protected:
    void resizeEvent(QResizeEvent *event);
    void mousePressEvent(QMouseEvent *event);

public slots:
    void LoadAlbum(SKG_Album *album, bool largealbumnumbers = false);
    void Expand(int newtop,int newleft,int newwidth,int newheight);
    void Contract(int newtop,int newleft,int newwidth,int newheight);

signals:
    void clicked();
    void AlbumArtClicked();
    void SelectedTrackChanged();
    void DoubleClicked();

public:
    SKG_AlbumWidget(QWidget *parent = 0);
    QString AlbumName();
    QString ArtistName();
    QString AlbumArt();
    SKG_Track *GetSelectedTrack();
    QString SelectedTrackID();
    void Clear();
    void SetSelectedTrack(int tracknum);
    void SetFontSize(int fontsize);
};

#endif
