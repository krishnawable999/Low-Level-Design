#ifndef ORDER_MANAGER_H
#define ORDER_MANAGER_H

#include<iostream>
#include <vector>
#include "../model/Order.h"
using namespace std;


class OrderManager{
    private:
    vector<Order*> orders;
    static OrderManager *instance;

    OrderManager(){
        // private ctor
    }

    public:
    static OrderManager * getInstance(){
        if(!instance){
            instance = new OrderManager();
        }
        return instance;
    }

    void addOrder(Order* order){
        orders.push_back(order);
    }

    void listOrders(){
        cout<<"-----All Orders------"<<endl;
        for(auto order: orders){
            cout<<order->getType()<<" order for "<<order->getUser()->getName()
            <<" | Total Rs. "<<order->getTotal()
            <<" | At: "<<order->getSchedule()<<endl;
        }
    }
};

OrderManager * OrderManager::instance=0;

#endif