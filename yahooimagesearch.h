#ifndef YAHOOIMAGESEARCH_H
#define YAHOOIMAGESEARCH_H

#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QDomDocument>
#include <QStringList>
#include <QPixmap>

class YahooImageSearch : public QObject
{
    Q_OBJECT

public:
    YahooImageSearch(QObject *parent = 0);
    QList<QPixmap> GetPicList(){return PicList;}
    void Search(QString Artist, QString Album,int numResults = 5);
    int PercentageComplete();

private:
    QNetworkAccessManager *manager;
    QStringList UrlList;
    QList<QPixmap> PicList;
    QDomDocument SearchResults;
    bool LookingUp;
    int PicsDownloaded;
    int NumResults;
    int Progress;

    void Lookup();

private slots:
    void FinishedSearch(QNetworkReply *reply);
    void FinishedLookup(QNetworkReply *reply);

signals:
    void Finished();
};

#endif // YAHOOIMAGESEARCH_H
