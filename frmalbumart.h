#ifndef FRMALBUMART_H
#define FRMALBUMART_H

#include <QDialog>
#include <QTimer>
#include "googleimagesearch.h"
#include "yahooimagesearch.h"
#include "lib/skglib.h"

namespace Ui {
    class frmAlbumArt;
}

class frmAlbumArt : public QDialog {
    Q_OBJECT
public:
    frmAlbumArt(QWidget *parent = 0);
    ~frmAlbumArt();
    void Search(SKG_Album *album);

protected:
    void changeEvent(QEvent *e);

private:
    Ui::frmAlbumArt *ui;
    QList <QPixmap> PicList;
    int PicIndex;
    GoogleImageSearch *Google;
    YahooImageSearch *Yahoo;
    QTimer *timer;
    SKG_Album *Album;
    bool boolGoogleFinished;
    bool boolYahooFinished;
    void Finished();
    void DisplayPicture();
    int PercentComplete();

private slots:
    void GoogleFinished(){boolGoogleFinished = true;}
    void YahooFinished(){boolYahooFinished = true;}
    void Tick();
    void Previous();
    void Next();
    void Save();
};

#endif // FRMALBUMART_H
