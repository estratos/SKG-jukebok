#ifndef CUSTOMALBUMLIST_H
#define CUSTOMALBUMLIST_H

#include <QObject>

class CustomAlbumList
{

private:
    QString Name;
    QList <int> AlbumNumbers;

public:
    explicit CustomAlbumList();
    QString GetName(){return Name;}
    QList <int> GetAlbumNumbers();
    void AddAlbumNumbers(QList <int> albumnums){AlbumNumbers.append(albumnums);}
    void SetName(QString listname){Name = listname;}
    void Clear();
};

#endif // CUSTOMALBUMLIST_H
