#ifndef SCHEDULE_ORDER_FACTORY_H
#define SCHEDULE_ORDER_FACTORY_H

#include "OrderFactory.h"
#include "../model/DeliveryOrder.h"
#include "../model/PickupOrder.h"
#include "../utils/TimeUtils.h"
using namespace std;

class ScheduleOrderFactory{
    private:
    string scheduleTime;
    public:
    ScheduleOrderFactory(string scheduleTime){
        this->scheduleTime = scheduleTime;
    }

    Order *createOrder(User *user, Cart* cart, Restaurent *restaurent, const vector<MenuItem> &menuItems, PaymentStrategy* paymentStrategy, const string &orderType){
        Order *order = nullptr;
        if(orderType == "Delivery"){
            auto deliveryOrder = new DeliveryOrder();
            deliveryOrder->setUserAddress(user->getAddress());
            order = deliveryOrder;
        }else{
            auto pickupOrder = new PickupOrder();
            pickupOrder->setRestaurentAddress(restaurent->getLocation());
            order = pickupOrder;
        }

        order->setUser(user);
        order->setRestaurent(restaurent);
        order->setItems(menuItems);
        order->setPaymentStretegy(paymentStrategy);
        order->setSchedule(TimeUtils::getCurrentTime());
        order->setTotal(cart->getTotalCost());
        return order;
    }
};


#endif