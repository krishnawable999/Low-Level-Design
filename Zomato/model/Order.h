#ifndef ORDER_H
#define ORDER_H

#include<iostream>
#include<vector>
#include<string>
#include "User.h"
#include "MenuItem.h"
#include "Restaurent.h"
#include "PaymentStrategy.h"
#include "TimeUtils.h"
using namespace std;

class Order{
    protected:
    static int nextOrderId;
    int orderId;
    User* user;
    Restaurent* restaurent;
    vector<MenuItem> items;
    PaymentStrategy *paymentStrategy;
    double total;
    string schedule;


    public:
    Order(){
        user = nullptr;
        restaurent = nullptr;
        paymentStrategy = nullptr;
        total = 0.0;
        schedule = "";
        orderId = ++nextOrderId;
    }

    virtual ~Order(){
        delete paymentStrategy;
    }

    bool processPayment(){
        if(paymentStrategy){
            paymentStrategy->pay(total);
            return true;
        }else{
            cout<<"Please choose payment mode first"<<endl;
            return false;
        }
    }

    virtual string getType() const =0;

    // Getters and setters
    int getOrderId() const{
        return orderId;
    }

    void setOrderId(const int &id){
        orderId = id;
    }

    void setUser(User* u){
        user = u;
    }

    User* getUser() const{
        return user;
    }

    void setRestaurent(Restaurent* r){
        restaurent = r;
    }

    Restaurent* getRestaurent() const{
        return restaurent;
    }

    void setItems(const vector<MenuItem> &its){
        items = its;
        total=0;
        
        for(auto it:items){
            total += it.getPrice();
        }
    }

    vector<MenuItem> getItems() const{
        return items;
    }

    void setPaymentStretegy(PaymentStrategy* p){
        paymentStrategy = p;
    }

    void setSchedule(string s){
        schedule = s;
    }
    string getSchedule() const {
        return schedule;
    }

    double getTotal() const{
        return total;
    }

    void setTotal(int total){
        this->total = total;
    }

};

int Order::nextOrderId=0;




#endif