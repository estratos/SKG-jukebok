#include "googleimagesearch.h"
#include <qjson/parser.h>
#include <QApplication>
#include <QImage>

GoogleImageSearch::GoogleImageSearch(QObject *parent) :
    QObject(parent)
{
    NumResults = 5;
    manager = new QNetworkAccessManager(this);
    PicsDownloaded = 0;
}

void GoogleImageSearch::Search(QString Artist, QString Album, int numResults)
{
    PicsDownloaded = 0;
    NumResults = numResults;
    QObject::disconnect(manager,0,0,0);
    QObject::connect(manager,SIGNAL(finished(QNetworkReply*)),this,SLOT(FinishedSearch(QNetworkReply*)));
    QString querystring(Artist + " " + Album);
    QUrl url("http://ajax.googleapis.com/ajax/services/search/images");
    url.addQueryItem("q",querystring);
    url.addQueryItem("v","1.0");
    url.addQueryItem("rsz?",QString::number(numResults));
    manager->get(QNetworkRequest(url));
}

void GoogleImageSearch::FinishedSearch(QNetworkReply *reply)
{
    QJson::Parser parser;
    QVariant result;
    bool ok;
    QString str;
    QVariantMap vmap;
    QVariant responsedata;
    QVariantMap respdatamap;
    QList<QVariant> resultlist;

    UrlList.clear();
    result = parser.parse(reply->readAll(),&ok);
    str = result.toString();
    SearchResults = result.toMap();
    responsedata =SearchResults["responseData"];
    respdatamap = responsedata.toMap();
    resultlist = respdatamap["results"].toList();
    foreach(QVariant v,resultlist)
    {
        vmap = v.toMap();
        QVariant url = vmap["url"];
        UrlList.append(url.toString());
    }

    Lookup();
}

void GoogleImageSearch::Lookup()
{
    int i;
    QNetworkReply *reply;

    Progress = 0;
    QObject::disconnect(manager,0,0,0);
    PicList.clear();
    QObject::connect(manager,SIGNAL(finished(QNetworkReply*)),this,SLOT(FinishedLookup(QNetworkReply*)));
    for (i = 0;i < UrlList.count();i++)
    {
        LookingUp = true;
        QUrl url(UrlList.at(i));
        reply = manager->get(QNetworkRequest(url));
        while (LookingUp)
            QApplication::processEvents();
    }
    Finished();
}

void GoogleImageSearch::FinishedLookup(QNetworkReply *reply)
{
    QPixmap pixmap;
    QImage image;

    if (!(reply->error()))
    {
        if (image.loadFromData(reply->readAll()))
        //if (pixmap.loadFromData(reply->readAll()))
        {
            pixmap = QPixmap::fromImage(image);
            PicList.append(pixmap);
            PicsDownloaded++;
        }
    }
    LookingUp = false;
}

int GoogleImageSearch::PercentageComplete()
{
    float percentageperpic;

    percentageperpic = 100.0 / float(NumResults);
    return int(percentageperpic) * PicsDownloaded;
}
