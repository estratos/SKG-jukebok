#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <QObject>

class Playlist : public QObject
{
Q_OBJECT

private:
    QString Name;
    QString CustomListName;
    QList <int> *TrackNumbers;
    void RandomizeList(QList <int> *list);

public:
    explicit Playlist(QObject *parent = 0);
    QString GetName(){return Name;}
    QString GetCustomListName(){return CustomListName;}
    QList <int> *GetTrackNumbers(bool random);
    void AddTrackNumber(int tracknum){TrackNumbers->append(tracknum);}
    void RemoveTrackNumber(int tracknum){TrackNumbers->removeAll(tracknum);}
    void SetName(QString listname){Name = listname;}
    void SetCustomListName(QString customlistname){CustomListName = customlistname;}
    void Clear();
    void Swap(int i,int j);
    int Count(){return TrackNumbers->count();}
};

#endif // PLAYLIST_H
