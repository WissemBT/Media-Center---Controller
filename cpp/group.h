/**
 * @file group.h
 * @author Wissem BEN BETTAIEB
 * @brief 
 * @version 0.1
 * @date 2022-11-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef GROUP_H
#define GROUP_H
#include <list>
#include <memory>
#include "multimedia.h"

using ptrMultimedia = shared_ptr<Multimedia>;

/**a Group class that herit from a list of shared_ptr<Multimedia>
 * each object of this class contain a specific multimedias
*/
class Group: public list<ptrMultimedia>{
    private:
        string groupName{};
    public:
        Group();
        Group(string _groupName):list<ptrMultimedia>(),groupName(_groupName){};
        string getGroupName() const {return groupName;}
        void setGroupName(string _name) {groupName=_name;}
        void show(ostream &s) const{
            cout << "For group : " << groupName << " : " << endl;
            for (auto item : *this){
                item->afficher(s);
                cout << "*******************************************************" << endl;;
            }
            
        }



};
#endif