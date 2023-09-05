/**
 * @file photo.h
 * @author Wissem BEN BETTAIEB
 * @brief 
 * @version 0.1
 * @date 2022-11-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef PHOTO_H
#define PHOTO_H
#include "multimedia.h"
/**
 * @brief a class that herit from Multimedia class
 * 
 */
class Photo: public Multimedia{
    private:
        double latitude{},longitude{};
    public:
        Photo(){}
        Photo(string _objName,string _pathName,double _latitude,double _longitude):
        Multimedia(_objName,_pathName),latitude(_latitude),longitude(_longitude){}

        void setLatitude(double _latitude){
            latitude=_latitude;
        }
        void setLongitude(int _longitude){
            longitude=_longitude;
        }

        double getLatitude() const{
            return latitude;
        }
        double getLongitude() const{
            return longitude;
        }
        /**
         * @brief a method to output the attributes of the photo instance
         * 
         * @param s 
         */
        void afficher(ostream & s) const override{
            s << "object name is  : " << objName << endl;
            s << "the path is : " << pathName << endl;
            s << "Latitude is  : " << latitude << endl;
            s << "Longitude is : " << longitude << endl;
        }
        /**
         * @brief a method to play the Image
         * 
         */
        void lire(){
            string path="imagej " + pathName +" &";
            system(path.data());
        }

        ~Photo() override{
            cout << "Photo named " << objName << " was deleted!" << endl;
        }


};
#endif