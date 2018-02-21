#include "customalbumlist.h"
#include <QSet>
#include <QtAlgorithms>

CustomAlbumList::CustomAlbumList()
{
    Name = "";
    AlbumNumbers.clear();
}

QList<int> CustomAlbumList::GetAlbumNumbers()
{
    QSet <int> set;
    QList <int> list;

    // Convert Album Numbers list to a set to get rid of duplicates, then back to
    // a list again
    set = AlbumNumbers.toSet();
    list = set.toList();
    qSort(list);
    return list;
}

void CustomAlbumList::Clear()
{
    Name = "";
    AlbumNumbers.clear();
}
