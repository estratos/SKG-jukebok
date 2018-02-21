#include "playlist.h"
#include <time.h>

Playlist::Playlist(QObject *parent) :
    QObject(parent)
{
    Name = "";
    CustomListName = "";
    //TrackNumbers->clear();
    TrackNumbers = new QList<int>;
}

QList<int>* Playlist::GetTrackNumbers(bool random)
{
    QList <int> *list;
    list = TrackNumbers;
    if (random)
    {
        RandomizeList(list);
    }
    return list;
}

void Playlist::Clear()
{
    Name = "";
    TrackNumbers->clear();
}

void Playlist::RandomizeList(QList <int> *list)
{
    int numtimes = 0;
    int rnd;
    qsrand(time(NULL));
    while (numtimes < 5)
    {
        for (int i = 0;i < list->count();i++)
        {
            rnd = qrand() % list->count();
            list->swap(i,rnd);
        }
        numtimes++;
    }
}

void Playlist::Swap(int i,int j)
{
    TrackNumbers->swap(i,j);
}
