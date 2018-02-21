#ifndef GOOGLEIMAGESEARCH_H
#define GOOGLEIMAGESEARCH_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QStringList>
#include <QPixmap>

class GoogleImageSearch : public QObject
{
Q_OBJECT
public:
    explicit GoogleImageSearch(QObject *parent = 0);
    QList<QPixmap> GetPicList(){return PicList;}
    void Search(QString Artist, QString Album,int numResults = 5);
    int PercentageComplete();

private:
    QNetworkAccessManager *manager;
    QStringList UrlList;
    QList<QPixmap> PicList;
    QVariantMap SearchResults;
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

#endif // GOOGLEIMAGESEARCH_H
