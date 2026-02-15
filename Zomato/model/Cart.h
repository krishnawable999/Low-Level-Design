#ifndef CART_H
#define CART_H

#include<iostream>
#include<vector>
#include<string>
#include "../model/MenuItem.h"
#include "../model/Restaurent.h"
using namespace std;

class Cart{
    private:
    Restaurent *restaurent;
    vector<MenuItem> items;

    public:
    Cart(){
        restaurent = nullptr;
    }

    void addItem(const MenuItem &item){
        if(!restaurent){
            cout<<"Cart: set Restaurent before adding items"<<endl;
            return;
        }

        items.push_back(item);
    }

    double getTotalCost() const{
        double sum=0;
        for(auto &it:items){
            sum += it.getPrice();
        }
        return sum;
    }

    bool isEmpty(){
        return (!restaurent || items.empty());
    }

    void clear(){
        items.clear();
        restaurent = nullptr;
    }

    // Getters and Setters

    void setRestaurent(Restaurent *r){
        restaurent = r;
    }

    Restaurent * getRestaurent() const{
        return restaurent;
    }

    const vector<MenuItem>& getItems() const {
        return items;
    }

};


#endif