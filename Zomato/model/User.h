#ifndef USER_H
#define USER_H

#include<iostream>
#include "Cart.h"
using namespace std;

class User{
    private:
    int userId;
    string name;
    string address;
    Cart* cart;

    public:
    User(int userId, string name, string address){
        this->userId = userId;
        this->name = name;
        this->address = address;
    }

    ~User(){
        delete cart;
    }

    int getUserId() const{
        return userId;
    }

    void setUserId(const int &u){
        userId = u;
    }

    string getName() const{
        return name;
    }

    void setName(const string &n){
        name = n;
    }

    string getAddress() const{
        return address;
    }

    void setAddress(const string &a){
        address = a;
    }

    Cart * getCart() const{
        return cart;
    }
    


};



#endif