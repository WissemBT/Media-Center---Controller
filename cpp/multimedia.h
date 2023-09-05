/**
 * @file multimedia.h
 * @author Wissem BEN BETTAIEB
 * @brief 
 * @version 0.1
 * @date 2022-11-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef MULTIMEDIA_H
#define MULTIMEDIA_H
#include <bits/stdc++.h>


using namespace std;
/**
 * @brief an abstract class which will be herited by Photo and Video classes
 * 
 */
class Multimedia{
    protected:
        string objName{};
        string pathName{};
    public:
        Multimedia();
        Multimedia(string _objName,string _pathName);

        string getObjName() const;
        string getPathName() const;

        void setObjName(string _objName);
        void setPathName(string _pathName);

        virtual void afficher(ostream & s) const;
        virtual void lire() = 0;
        virtual ~Multimedia();
};
#endif