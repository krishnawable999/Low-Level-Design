#ifndef ORDER_FACTORY_H
#define ORDER_FACTORY_H

#include<iostream>
#include<vector>
#include<string>
#include "../model/Order.h"
#include "../model/Cart.h"
#include "../model/Restaurent.h"
#include "../strategeies/PaymentStrategy.h"
using namespace std;    

class OrderFactory{
    public:
    virtual Order* createOrder(User* user, Cart* cart, Restaurent* restaurent, const vector<MenuItem> &menuItems, PaymentStrategy* paymentStrategy, const string &orderType)=0;

    virtual ~OrderFactory(){}
};

#endif