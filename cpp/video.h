/**
 * @file video.h
 * @author Wissem BEN BETTAIEB
 * @brief 
 * @version 0.1
 * @date 2022-11-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef VIDEO_H
#define VIDEO_H
#include "multimedia.h"

/**
 * @brief a Video class that herit from Multimedia class
 * and will be herited by the Film class
 * 
 */
class Video : public Multimedia{
    protected:
        int duree{};
    public:
        Video(){}
        Video(string _objName,string _pathName,int _duree):Multimedia(_objName,_pathName),duree(_duree){}

        void setDuree(int _duree){
            duree=_duree;
        }
        
        int getDuree() const{
            return duree;
        }

        void afficher(ostream & s) const override{
            s << "object name is  : " << objName << endl;
            s << "the path is : " << pathName << endl;
            s << "Duration is  : " << duree << endl;
        }
        /**
         * @brief a method to play the video
         * 
         */
        void lire(){
            string path="mpv "+ pathName + " &";
            system(path.data());
        }

        ~Video() override{
         cout <<" a video named " << objName << " was deleted!" << endl;
           
        }

};
#endif