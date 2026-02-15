#ifndef RESTAURENT_MANAGER_H
#define RESTAURENT_MANAGER_H

#include<iostream>
#include<string>
#include<algorithm>
#include "../model/Restaurent.h"
using namespace std;

class RestaurentManager{
    private:
    vector<Restaurent*> restaurents;
    static RestaurentManager* instance;

    RestaurentManager(){
        // private ctor
    }

    public:
    static RestaurentManager* getInstance(){
        if(!instance){
            instance = new RestaurentManager();
        }

        return instance;
    }

    void addRestaurent(Restaurent* r){
        restaurents.push_back(r);
    }

    vector<Restaurent*> searchByLocation(string loc){
        vector<Restaurent*>  result;
        transform(loc.begin(), loc.end(), loc.begin(), ::tolower);
        for(auto r : restaurents){
            string rl = r->getLocation();
            transform(rl.begin(), rl.end(), rl.begin(), ::tolower);
            if(rl == loc){
                result.push_back(r);
            }
        }
        return result;
    } 


};

RestaurentManager * RestaurentManager ::instance = nullptr;
#endif