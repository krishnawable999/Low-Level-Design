#ifndef PICKUP_ORDER_H
#define PICKUP_ORDER_H

#include "Order.h"
using namespace std;

class PickupOrder : public Order
{
private:
    string restaurentAddress;

public:
    PickupOrder()
    {
        restaurentAddress = "";
    }

    string getType() const override
    {
        return "Pickup";
    }

    // Getters and Setters
    void setRestaurentAddress(const string &addr)
    {
        restaurentAddress = addr;
    }

    string getRestaurentAddress() const
    {
        return restaurentAddress;
    }
};

#endif