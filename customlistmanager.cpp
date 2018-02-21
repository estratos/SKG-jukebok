#include "customlistmanager.h"
#include "lib/skglib.h"
#include "jukeboxconfig.h"
#include <time.h>
#include <QTextStream>
#include <stdlib.h>
#include <QMessageBox>

CustomListManager::CustomListManager()
{
    CustomListFile = ResourcesDirectory() + "/lists.xml";
}

QList <CustomAlbumList*> CustomListManager::GetCustomLists()
{
    Sort();
    return CustomLists;
}

void CustomListManager::RemoveList(int listindex)
{
    if (listindex < CustomLists.count())
        CustomLists.removeAt(listindex);
}

void CustomListManager::SaveCustomListFile()
{
    SKG_Album *curralbum;
    CustomAlbumList *currlist;
    int i,j;
    QDomDocument doc;
    QDomElement mainelement;
    QDomElement countelement;
    QDomElement listelement;
    QDomElement nameelement;
    QDomElement albumelement;

    if(QFile::exists(CustomListFile))
        QFile::remove(CustomListFile);

    QFile listfile(CustomListFile);
    listfile.open(QIODevice::WriteOnly);

    mainelement = doc.createElement("CustomLists");
    countelement = doc.createElement("count");
    countelement.setAttribute("count",CustomLists.count());
    mainelement.appendChild(countelement);

    for (i = 0; i < CustomLists.count(); i++)
    {
        listelement = doc.createElement("list");
        currlist = CustomLists.at(i);
        nameelement = doc.createElement("name");
        nameelement.setAttribute("name",currlist->GetName());
        listelement.appendChild(nameelement);

        for(j = 0; j < currlist->GetAlbumNumbers().count(); j++)
        {
            curralbum = Library->GetAlbumByNumber(currlist->GetAlbumNumbers().at(j));
            albumelement = doc.createElement("album");
            albumelement.setAttribute("artist",curralbum->GetArtistName());
            albumelement.setAttribute("albumname",curralbum->GetAlbumName());
            listelement.appendChild(albumelement);
        }
        //doc.appendChild(listelement);
        mainelement.appendChild(listelement);
    }
    doc.appendChild(mainelement);
    listfile.write(doc.toByteArray());
    listfile.close();
}

void CustomListManager::LoadCustomListFile()
{
    QDomDocument doc;
    QDomNodeList listnodes;
    QDomElement listelement;
    QDomElement nameelement;
    QDomNodeList albumnodes;
    QDomElement albumelement;
    QString artistname;
    QString albumname;

    bool x;
    QString errmsg;
    int errline;
    CustomAlbumList *currlist;
    SKG_Album *curralbum;
    int i,j;

    if (!QFile::exists(CustomListFile))
        return;

    QFile listfile(CustomListFile);
    listfile.open(QIODevice::ReadOnly);
    x = doc.setContent(listfile.readAll(),&errmsg,&errline);
    listnodes = doc.elementsByTagName("list");

    for (i = 0; i < listnodes.count(); i++)
    {
        listelement = listnodes.at(i).toElement();
        currlist = new CustomAlbumList;
        nameelement = listelement.firstChildElement("");
        currlist->SetName(nameelement.attribute("name",""));
        QList <int> albumnums;
        albumnodes = listelement.elementsByTagName("album");
        for (j = 0; j< albumnodes.length(); j++)
        {
            albumelement = albumnodes.at(j).toElement();
            artistname = albumelement.attribute("artist","");
            albumname = albumelement.attribute("albumname");
            curralbum = Library->GetAlbumByName(artistname,albumname);
            if (curralbum != NULL)
                albumnums.append(curralbum->GetAlbumNumber());
        }
        currlist->AddAlbumNumbers(albumnums);
        CustomLists.append(currlist);
    }
    listfile.close();
}

CustomAlbumList* CustomListManager::RetrieveListByName(QString listname)
{
    foreach (CustomAlbumList *list,CustomLists)
    {
        if (list->GetName() == listname)
        {
            return list;
            break;
        }
    }
    return NULL;
}

void CustomListManager::SetLibrary(SKG_MusicLibrary *lib)
{
    Library = lib;
    LoadCustomListFile();
}

void CustomListManager::CreateTestList()
{
    int i;
    int albumnum;
    bool exists;
    CustomAlbumList *customlist;
    QList<int> list;

    srand(time(0));
    customlist = new CustomAlbumList;
    customlist->SetName("Test");
    while(list.count() < 50)
    {
        albumnum = (rand() % Library->GetAlbums().count());
        exists = false;
        for(i = 0; i < list.count(); i++)
        {
            if (list.at(i) == albumnum)
                exists = true;
        }
        if (!exists)
            list.append(albumnum);
    }
    customlist->AddAlbumNumbers(list);
    CustomLists.append(customlist);
}

void CustomListManager::Sort()
{
    int i,j;

    for (i = 0; i < CustomLists.count() - 1; i++)
    {
        for (j = i + 1; j < CustomLists.count(); j++)
            if (CustomLists.at(i)->GetName() < CustomLists.at(j)->GetName())
                CustomLists.swap(i,j);
    }
}
