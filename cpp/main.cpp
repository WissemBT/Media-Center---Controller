/**
 * @file main.cpp
 * @author wissem BEN BETTAIEB
 * @brief this is the main file where several 
 * steps are tested
 * @version 0.1
 * @date 2022-11-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "multimedia.h"
#include "photo.h"
#include "video.h"
#include "film.h"
#include "group.h"
#include "database.h"
#include "server.h"

#define ETAPE2 0
#define ETAPE4 0
#define ETAPE5 0
#define ETAPE6 0
#define ETAPE7 0
#define ETAPE8_9 0
#define ETAPE10 0
#define ETAPE11 1



int main(int argc, const char* argv[])
{
    #if ETAPE2
    Multimedia * firstObj = new Multimedia();
    Multimedia * secondObj = new Multimedia("PhotoNumberOne","Photo.jpg");

    string objName = secondObj->getObjName();
    string pathName = secondObj->getPathName();
    
    firstObj->setObjName(objName);
    firstObj->setPathName(pathName);
    
    firstObj->afficher(cout);
    secondObj->afficher(cout);

    delete firstObj;
    delete secondObj;
    #endif

    #if ETAPE4
    Photo* firstPhoto = new Photo();
    Photo* secondPhoto = new Photo("Image","image.png",5.0,5.0);

    Video* video = new Video("VIDEO","vid.mp4",200);

    string _photoName = secondPhoto->getObjName();
    double _latitude = secondPhoto->getLatitude();
    double _longitude = secondPhoto->getLongitude();
    string _pathName=secondPhoto->getPathName();

    firstPhoto->setPathName(_pathName);
    firstPhoto->setObjName(_photoName);
    firstPhoto->setLatitude(_latitude);
    firstPhoto->setLongitude(_longitude);

    firstPhoto->afficher(cout);
    secondPhoto->afficher(cout);
    video->afficher(cout);

    secondPhoto->lire();
    video->lire();

    delete firstPhoto;
    delete secondPhoto;
    delete video;
    #endif

    #if ETAPE5
    vector<Multimedia*> mediaVector;

    mediaVector.push_back((new Photo("PHOTO N 1 ","image.png",10,10)));
    mediaVector.push_back((new Photo("PHOTO N 2 ","2.png",20,20)));
    mediaVector.push_back((new Video("VIDEO N 1 ","vid.mp4",200)));

    for (auto & media : mediaVector){
        media->afficher(cout);
        media->lire();
    }
    for (auto & media : mediaVector){
        delete media;
    }

    #endif

    #if ETAPE6
    int* chapters1 = new int[5];
    chapters1[0]=1;
    for (int i=1;i<5;i++)
        chapters1[i]=chapters1[i-1]+1;
    int* chapters2 = new int[5];
    chapters2[0]=10;
    for (int i=1;i<5;i++)
        chapters2[i]=chapters2[i-1]+1;
    
    Film* firstFilm = new Film("FILM N 1","vid.mp4",200,5,chapters1);
    firstFilm->afficher(cout);

    chapters1[0]=10000;
    firstFilm->afficher(cout);
    delete[] chapters1;
    firstFilm->afficher(cout);
    
    firstFilm->setChapters(chapters2,5);
    chapters2[0]=52222;
    delete[] chapters2;
    firstFilm->afficher(cout);

    const int * chapters = firstFilm->getChapters();
    delete firstFilm;

    #endif

    #if ETAPE7
    int* chapters1 = new int[5];
    chapters1[0]=1;
    for (int i=1;i<5;i++)
        chapters1[i]=chapters1[i-1]+1;
    int* chapters2 = new int[5];
        chapters2[0]=10;
    for (int i=1;i<5;i++)
        chapters2[i]=chapters2[i-1]+1;
    Film firstFilm("FIRST FILM","vid.mp4",200,5,chapters1);
    Film secondFilm(firstFilm);
    Film thirdFilm("THIRD FILM","vid.mp4",200,5,chapters2);
    firstFilm.afficher(cout);
    secondFilm.afficher(cout);
    thirdFilm.afficher(cout);
    thirdFilm=firstFilm;
    firstFilm.setChapters(chapters2,5);
    firstFilm.setObjName("VERSION TWO");
    secondFilm.afficher(cout);
    thirdFilm.afficher(cout);

    #endif

    #if ETAPE8_9
    Group * photosGroup = new Group("Photos "); 
    Group * videosGroup = new Group("Videos ");
    Group * VerifGroup = new Group("Verification");
    for (int i=1;i<6;i++)
    {   
        string cpt=to_string(i);
        ptrMultimedia _Photo (new Photo("PHOTO N "+cpt,cpt+".png",10*i,10*i));
        ptrMultimedia _Video (new Video("VIDEO N "+cpt,cpt+".mp4",10*i));
        photosGroup->push_back(_Photo);
        photosGroup->push_back(_Video);
        if(i<3) VerifGroup->push_back(_Photo);
        else VerifGroup->push_back(_Video);
    }
    photosGroup->show(cout);
    videosGroup->show(cout);
    delete photosGroup;
    delete videosGroup;
    
    VerifGroup->show(cout);
    VerifGroup->erase(VerifGroup->begin());
    VerifGroup->show(cout);

    #endif

    #if ETAPE10
    Database * firstBase = new Database();

    ptrPhoto firstPhoto = firstBase->createPhoto("FIRST_PHOTO","image.png",10,10);
    ptrPhoto secondPhoto = firstBase->createPhoto("SECOND_PHOTO","2.png",10,10);
    ptrVideo firstVideo = firstBase->createVideo("FIRST_VIDEO","vid.mp4",200);
    ptrFilm firstFilm = firstBase->createFilm("FIRST_FILM","vid.mp4",250,4,new int[4]);
    ptrGroup firstGroup = firstBase->createGroup("FIRST_GROUP");
    firstGroup->push_back(firstPhoto);
    firstGroup->push_back(secondPhoto);
    firstGroup->push_back(firstVideo);
    firstBase->findANDShow("FIRST_GROUP",cout);
    firstBase->findANDShow("FIRST_PHOTO",cout);
    firstBase->findANDShow("KOURA",cout);
    firstBase->findANDPlay("SECOND_PHOTO");
    firstBase->findANDPlay("NEYMAR");
    #endif

    #if ETAPE11
    Database * firstBase = new Database();

    ptrPhoto firstPhoto = firstBase->createPhoto("FIRST_PHOTO","image.png",10,10);
    ptrPhoto secondPhoto = firstBase->createPhoto("SECOND_PHOTO","2.png",10,10);
    ptrVideo firstVideo = firstBase->createVideo("FIRST_VIDEO","vid.mp4",200);
    ptrFilm firstFilm = firstBase->createFilm("FIRST_FILM","vid.mp4",250,4,new int[4]);
    ptrGroup firstGroup = firstBase->createGroup("FIRST_GROUP");
    serverStart(firstBase);
    
    

    #endif
        
    return 0;
}
