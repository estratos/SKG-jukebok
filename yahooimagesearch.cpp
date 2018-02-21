#include "yahooimagesearch.h"
#include <QApplication>
#include <QImage>

YahooImageSearch::YahooImageSearch(QObject *parent) :  QObject(parent)
{
    NumResults = 5;
    manager = new QNetworkAccessManager(this);
    PicsDownloaded = 0;
}

void YahooImageSearch::Search(QString Artist, QString Album, int numResults)
{
    PicsDownloaded = 0;
    NumResults = numResults;
    QObject::disconnect(manager,0,0,0);
    QObject::connect(manager,SIGNAL(finished(QNetworkReply*)),this,SLOT(FinishedSearch(QNetworkReply*)));
    QString querystring("\"" + Artist + " " + Album + "\"");
    QUrl url("http://boss.yahooapis.com/ysearch/images/v1/" + querystring);
    url.addQueryItem("appid","FPHXzMPV34GumBNIRUffRJm.yjhmrGg_FfmNhP9f5Rf6HNG.6wTSD17Ikn3jFzy41ug7UA--");
    url.addQueryItem("format","xml");
    url.addQueryItem("count",QString::number(numResults));
    manager->get(QNetworkRequest(url));
}

void YahooImageSearch::FinishedSearch(QNetworkReply *reply)
{
    QDomNodeList urlnodelist;
    QVariant result;
    int i;

    UrlList.clear();
    result = reply->readAll();
    //ui->txtSearchResults->setText(result.toString());
    SearchResults.setContent(result.toByteArray(),true);
    urlnodelist = SearchResults.elementsByTagName("url");
    for (i = 0;i<urlnodelist.count();i++)
        UrlList.append(urlnodelist.at(i).toElement().text());

    Lookup();
}

void YahooImageSearch::Lookup()
{
    int i;
    QNetworkReply *reply;

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

void YahooImageSearch::FinishedLookup(QNetworkReply *reply)
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

int YahooImageSearch::PercentageComplete()
{
    float percentageperpic;

    percentageperpic = 100.0 / float(NumResults);
    return int(percentageperpic) * PicsDownloaded;
}
