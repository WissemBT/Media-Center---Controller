/**
 * @file film.h
 * @author Wissem BEN BETTAIEB
 * @brief 
 * @version 0.1
 * @date 2022-11-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef FILM_H
#define FILM_H
#include "video.h"

/**
 * @brief a Film class which herit from the Video class
 * 
 */
class Film: public Video{
    private:
    int* chapters = nullptr;
    int nbrOfChapters = 0;
    public:
    Film(){};
    Film(string _objName,string _pathName,int _duree,int _nbrOfChapters=0,int *_chapters=nullptr):Video(_objName,_pathName,_duree)
    {
        if(_nbrOfChapters && _chapters){
        nbrOfChapters=_nbrOfChapters;
        chapters= new int[nbrOfChapters];
        for (int i=0;i<nbrOfChapters;i++)
            chapters[i]=_chapters[i];
        }
    }
    /**
     * @brief Set the Chapters object
     * destroying the old chapters before seting the new ones
     * @param _chapters 
     * @param _nbrOfChapters 
     */
    void setChapters(int *_chapters=nullptr,int _nbrOfChapters=0)
    {
        if (_chapters && _nbrOfChapters){
            if(chapters) delete[] chapters;
        }
        nbrOfChapters = _nbrOfChapters;
        chapters = new int[nbrOfChapters];
        for (int i=0;i<nbrOfChapters;i++)
        {
            chapters[i]=_chapters[i];
        }
    }

    int getNbrOfChapters() const { return nbrOfChapters;}

    const int* getChapters() const { return chapters;}

    void afficher(ostream & s) const override{
        s << "Film name " << objName << endl;
        s << "Film path " << pathName << endl;
        s << "Duration " << duree << endl;
        if (nbrOfChapters && chapters){
            s << "nbrOf Chapters is : " << nbrOfChapters << endl;
            for (int i=0;i<nbrOfChapters;i++){
                s << chapters[i] << " | ";
            
            }
            s << endl;
            }
            else{
                s << "There's no chapters" << endl;
            }
        }
    /**
     * @brief Construct a new Film object using another object
     * 
     * @param from 
     */
    Film(const Film & from):Video(from.objName,from.pathName,from.duree){
        int _nbrOfChapters=from.getNbrOfChapters();
        const int *_chapters=from.getChapters();
        if(_nbrOfChapters && _chapters){
            nbrOfChapters = _nbrOfChapters;
            chapters=new int[nbrOfChapters];
            for(int i=0;i<nbrOfChapters;i++)
                chapters[i]=_chapters[i];
        } 
        
    }
    /**
     * @brief The = operator for the film class as it contains pointers
     * 
     * @param from 
     * @return Film& 
     */
    Film & operator= (const Film & from){
        Video::operator=(from);
        int _nbrOfChapters=from.getNbrOfChapters();
        const int * _chapters=from.getChapters();
        if(_nbrOfChapters && _chapters){
            if(chapters){
                delete[] chapters;
            }
            nbrOfChapters = _nbrOfChapters;
            chapters = new int[nbrOfChapters];
            for(int i=0;i<nbrOfChapters;i++)
                chapters[i]=_chapters[i];       
        }
        return *this;
    }
    /**
     * @brief Destroy the Film object and the chapters
     * 
     */
    virtual ~Film(){
        if(chapters) delete[] chapters;
        cout <<" a film named " << objName << " was deleted!" << endl;
    }
    
};
#endif