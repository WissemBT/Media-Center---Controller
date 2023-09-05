/**
 * @file database.h
 * @author Wissem BEN BETTAIEB
 * @brief 
 * @version 0.1
 * @date 2022-11-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef DATABASE_H
#define DATABASE_H
#include <bits/stdc++.h>
#include "multimedia.h"
#include "photo.h"
#include "video.h"
#include "film.h"
#include "group.h"
#include "tcpserver.h"


using ptrPhoto = shared_ptr<Photo>;
using ptrVideo = shared_ptr<Video>;
using ptrFilm = shared_ptr<Film>;
using ptrGroup = shared_ptr<Group>;


/**
 * @brief the Database class
 * 
 */
class Database{
    private:
        map<string,ptrMultimedia> multimediaTable;
        map<string,ptrGroup> groupTable;
    public:

    Database(){}
    /**
     * @brief Create a Photo object
     * 
     * @param _objName 
     * @param _pathName 
     * @param _latitude 
     * @param _longitude 
     * @return ptrPhoto 
     */
    ptrPhoto createPhoto(string _objName,string _pathName,double _latitude,double _longitude){
        ptrPhoto _Ph(new Photo(_objName,_pathName,_latitude,_longitude));
        multimediaTable[_objName]=_Ph;
        return _Ph;
    }
    /**
     * @brief Create a Video object
     * 
     * @param _objName 
     * @param _pathName 
     * @param _duree 
     * @return ptrVideo 
     */
    ptrVideo createVideo(string _objName,string _pathName,int _duree){
        ptrVideo _Vi(new Video(_objName,_pathName,_duree));
        multimediaTable[_objName]=_Vi;
        return _Vi;
    }
    /**
     * @brief Create a Film object
     * 
     * @param _objName 
     * @param _pathName 
     * @param _duree 
     * @param _nOfChptrs 
     * @param _chptrs 
     * @return ptrFilm 
     */
    ptrFilm createFilm(string _objName,string _pathName,int _duree,int _nOfChptrs,int * _chptrs){
        ptrFilm _Fi(new Film(_objName,_pathName,_duree,_nOfChptrs,_chptrs));
        multimediaTable[_objName]=_Fi;
        return _Fi;
    }
    /**
     * @brief Create a Group object
     * 
     * @param _groupName 
     * @return ptrGroup 
     */
    ptrGroup createGroup(string _groupName){
        ptrGroup _Gr(new Group(_groupName));
        groupTable[_groupName]=_Gr;
        return _Gr;
    }
    /**
     * @brief Search for an object using its name
     * , if it exists it call the afficher method
     * else a message will be shown
     * 
     * @param _objName 
     * @param s 
     */
    void findANDShow(string _objName,ostream & s){
        auto elementMultimedia = multimediaTable.find(_objName);
        auto elementGroup = groupTable.find(_objName);

        if(elementMultimedia==multimediaTable.end() && elementGroup==groupTable.end()){
            s << "There's no element named " << _objName << " in the database." << endl;
        }
        else if(elementMultimedia!=multimediaTable.end()){
            s << "Multimedia object " << _objName << " exist." << endl;;
            elementMultimedia->second->afficher(s);
        }
        else if(elementGroup!=groupTable.end())
        {
            s << "Group " << _objName << " exist." << endl;;
            elementGroup->second->show(s);
        }
    }
    /**
     * @brief search for a certain object by its name,
     * if it exists it will be playen else a message
     * will be shown
     * 
     * @param _objName 
     * @return int 
     */
    int findANDPlay(string _objName){
        auto elementMultimedia = multimediaTable.find(_objName);
        if(elementMultimedia!=multimediaTable.end()){
            elementMultimedia->second->lire();
            return 1;
        }
        else{
            cout <<"Multimedia Object named " << _objName << " doesn't exist." <<endl;
            return 0;
        }
    }


    /**
     * @brief This method takes request and response
     * as arguments, the request should be either
     * find <filename> or play <filename>
     * 
     * 
     * @param request 
     * @param response 
     * @return true 
     * @return false 
     */
    bool processRequest(const string & request, string & response){
        stringstream ss(request);
        string operation , name, buffer;
        ss >> operation >> name;
        while(ss >> buffer){
            name = name + " " + buffer;
        }
        
        if(operation=="find")
        {
            stringstream s;
            findANDShow(name,s);
            response=s.str();
            replace(response.begin(),response.end(),'\n',';') ;     
        }
        else if (operation=="play"){
            if(findANDPlay(name))
            {
                response="File "+name+" is currently playing on the server";
            }
            else{
                response="File "+name+" Was NOT FOUND";
            }
        }
        else
        {
            response="Undefined command, use find <filename> or play <filename>";
        }
    return true;
    }

};

#endif
