#ifndef RESTAURENT_H
#define RESTAURENT_H

#include<iostream>
#include<string>
#include<vector>
#include"MenuItem.h"

using namespace std;

class Restaurent{
    private:
    static int nextRestaurentId;
    int restaurentId;
    string name;
    string location;
    vector<MenuItem> menu;


    public:
    Restaurent(const string& name, const string &location){
        this->name = name;
        this->location = location;
        this->restaurentId = ++nextRestaurentId;
    }

    ~Restaurent(){
        cout<<"Destroying the restaurent: "<<name<<" and cleariing its menu"<<endl;
        menu.clear();
    }

    int getNextRestaurentId(){
        return nextRestaurentId;
    }
    void setNextRestaurentId(int& value){
        this->nextRestaurentId = value;
    }
    int getRestaurentId(){
        return restaurentId;
    }
    void setRestaurentId(int& value){
        restaurentId = value;
    }
    string getName(){
        return name;
    }
    void setName(string& value){
        name = value;
    }
    string getLocation(){
        return location;
    }
    void setLocation(string& value){
        location = value;
    }

    void setMenu(vector<MenuItem> &menu){
        this->menu = menu;
    }

    void addMenuItem(const MenuItem &item) {
        menu.push_back(item);
    }

    const vector<MenuItem>& getMenu() const {
        return menu;
    }

    
};

int Restaurent :: nextRestaurentId=0;

    
#endif