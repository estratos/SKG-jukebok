#ifndef SKG_ALBUMFRAME_H
#define SKG_ALBUMFRAME_H

#include <QFrame>
#include <QListWidget>
#include <QResizeEvent>
#include "../lib/skglib.h"

//class SKG_Album;

namespace Ui {
    class SKG_AlbumFrame;
}

class SKG_AlbumFrame : public QFrame {
    Q_OBJECT

public:
    SKG_AlbumFrame(QWidget *parent = 0);
    ~SKG_AlbumFrame();
    QListWidget *listTracks();
    bool AlbumArtClicked(QMouseEvent *event);
    void Clear();

public slots:
    void LoadAlbum(SKG_Album *album,bool largealbumnumbers = false);
    void EnableControls();
    void DisableControls();
    void ResizeFrame(QSize newsize);

private:
    Ui::SKG_AlbumFrame *ui;
    bool AlbumNumbersNecessary(SKG_Album *album);

protected:
    void changeEvent(QEvent *e);
    void resizeEvent(QResizeEvent *e);
    //void mousePressEvent(QMouseEvent *event);

};

#endif // SKG_ALBUMFRAME_H
