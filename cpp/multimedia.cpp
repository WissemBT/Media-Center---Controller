/**
 * @file multimedia.cpp
 * @author Wissem BEN BETTAIEB
 * @brief 
 * @version 0.1
 * @date 2022-11-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "multimedia.h"

Multimedia::Multimedia(){}
Multimedia::Multimedia(string _objName,string _pathName){
    objName = _objName;
    pathName= _pathName;
}

string Multimedia::getObjName() const {
    return objName;
}
string Multimedia::getPathName() const{
    return pathName;
}

void Multimedia::setObjName(string _objName){
    objName=_objName;
}
void Multimedia::setPathName(string _pathName){
    pathName=_pathName;
}

void Multimedia::afficher(ostream & s) const{
    s << "object name is  : " << objName << endl;
    s << "the path is : " << pathName << endl;
}

Multimedia::~Multimedia(){
    cout << "Multimedia object named " << objName << " was deleted!" << endl;
}