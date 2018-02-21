#ifndef CUSTOMLISTMANAGER_H
#define CUSTOMLISTMANAGER_H

#include "customalbumlist.h"
#include "lib/skglib.h"
#include <QDomDocument>
#include <QDomElement>

class CustomListManager
{
public:
    CustomListManager();

    QList <CustomAlbumList*> GetCustomLists();

    void AddList(CustomAlbumList *list){CustomLists.append(list);}
    void RemoveList(int listindex);
    void SaveCustomListFile();
    void SetLibrary(SKG_MusicLibrary *lib);
    CustomAlbumList* RetrieveListByName(QString listname);
    int ListCount(){return CustomLists.count();}

private:
   QList <CustomAlbumList*> CustomLists;
   QString CustomListFile;
   SKG_MusicLibrary *Library;

   void LoadCustomListFile();
   void Sort();
   void CreateTestList();
};

#endif // CUSTOMLISTMANAGER_H
