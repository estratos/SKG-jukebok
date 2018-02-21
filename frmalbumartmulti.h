#ifndef FRMALBUMARTMULTI_H
#define FRMALBUMARTMULTI_H

#include <QDialog>
#include <QPixmap>
#include <QListWidgetItem>
#include <QTimer>
#include "lib/skglib.h"
#include "googleimagesearch.h"
#include "yahooimagesearch.h"

namespace Ui {
    class frmAlbumArtMulti;
}

class frmAlbumArtMulti : public QDialog {
    Q_OBJECT
public:
    frmAlbumArtMulti(QWidget *parent = 0);
    ~frmAlbumArtMulti();

    void Initialize(SKG_MusicLibrary *lib);

protected:
    void changeEvent(QEvent *e);

private:
    Ui::frmAlbumArtMulti *ui;
    SKG_MusicLibrary *Library;
    SKG_Album *CurrentAlbum;
    QList <SKG_Album*> Albums;
    QList <QPixmap> PicList;
    QTimer *timer;
    GoogleImageSearch *Google;
    YahooImageSearch *Yahoo;
    bool Searching;
    bool boolGoogleFinished;
    bool boolYahooFinished;
    int PicIndex;
    int AlbumIndex;

    QList <SKG_Album*> AlbumsWithoutArt();
    void Search(SKG_Album *album);
    void Finished();
    void DisplayPicture();
    void DisplayAlbumList();
    int PercentComplete();

private slots:
    void GoogleFinished(){boolGoogleFinished = true;}
    void YahooFinished(){boolYahooFinished = true;}
    void Tick();
    void Previous();
    void Next();
    void Save();
    void Up();
    void Down();
    void Toggle();
    void Toggle(QListWidgetItem *item);
    void DownloadNow();
    void DisplayAlbumsWithoutArt();
    void DisplayAllAlbums();
    void NextAlbum();
    void ItemChanged(QListWidgetItem * current, QListWidgetItem * previous);
    void ItemClicked(QListWidgetItem *item);
};

#endif // FRMALBUMARTMULTI_H
