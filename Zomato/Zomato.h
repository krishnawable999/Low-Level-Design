#ifndef ZOMATO_H
#define ZOMATO_H

#include<vector>
#include<string>
#include "model/User.h"
#include "model/Restaurent.h"
#include "model/Cart.h"
#include "managers/OrderManager.h"
#include "managers/RestaurentManager.h"
#include "strategeies/PaymentStrategy.h"
#include "strategeies/UpiPaymentStrategy.h"
#include "factories/NowOrderFactory.h"
#include "factories/ScheduleOrderFactory.h"
#include "services/NotificationService.h"
#include "utils/TimeUtils.h"
using namespace std;

class Zomato{
    public:
    Zomato(){
        initializeRestaurants();
    }

    void initializeRestaurants(){
        Restaurent *restaurent1 = new Restaurent("Shivraj dhaba", "Nitin Company");
        restaurent1->addMenuItem(MenuItem("P1", "Akkaha Masura", 190));
        restaurent1->addMenuItem(MenuItem("P2", "Kaju Masala", 220));

        Restaurent *restaurent2 = new Restaurent("Veggies", "Kasarvadavali");
        restaurent2->addMenuItem(MenuItem("V1", "Paneer Handi", 190));
        restaurent2->addMenuItem(MenuItem("V2", "Dal Fry", 220));
        restaurent2->addMenuItem(MenuItem("P3", "Kaju Kari", 180));

        Restaurent *restaurent3 = new Restaurent("Ratna Sagar", "Kasarvadavali naka");
        restaurent3->addMenuItem(MenuItem("R1", "Shahi Paneer", 280));
        restaurent3->addMenuItem(MenuItem("R2", "Special Thali", 350));
        restaurent3->addMenuItem(MenuItem("R3", "Butter Paneer", 380));


        RestaurentManager* restaurentManager = RestaurentManager::getInstance();
        restaurentManager->addRestaurent(restaurent1);
        restaurentManager->addRestaurent(restaurent3);
        restaurentManager->addRestaurent(restaurent3);

        // add more
    }

    vector<Restaurent*> searchRestaurents(const string & location){
            return RestaurentManager::getInstance()->searchByLocation(location);
        }

        void selectRestaurent(User* user, Restaurent *restaurent){
            Cart *cart = user->getCart();
            cart->setRestaurent(restaurent);
        }

        void addToCart(User* user, const string& itemCode){
            Restaurent* restaurent = user->getCart()->getRestaurent();

            if(!restaurent){
                cout<<"Please select restaurent first"<<endl;
                return;
            }
            for(const auto &item:restaurent->getMenu()){
                if(item.getCode() == itemCode){
                    user->getCart()->addItem(item);
                    break;
                }
            }
        }

        Order* checkOutNow(User *user, const string &orderType, PaymentStrategy *paymentStrategy){
            return checkout(user, orderType, paymentStrategy, new NowOrderFactory());
        }

        Order * checkoutSchedule(User *user, const string& orderType, PaymentStrategy* paymentStrategy, const string &scheduleTime){
            return checkout(user, orderType, paymentStrategy, new ScheduleOrderFactory(scheduleTime));
        }

        Order* checkout(User* user, const string &orderType, PaymentStrategy* paymentStrategy, OrderFactory *orderFactory){
            if(user->getCart()->isEmpty()){
                return nullptr;
            }

            Cart *usercart = user->getCart();
            Restaurent *orderedRestaurent = usercart->getRestaurent();
            vector<MenuItem> itemsOrdered = usercart->getItems();
            double totalCost = usercart->getTotalCost();

            Order *order = orderFactory->createOrder(user, usercart, orderedRestaurent, itemsOrdered, paymentStrategy, orderType);
            OrderManager ::getInstance()->addOrder(order);
            return order;
        }

        void payForOrder(User* user, Order* order){
            bool paymentSucces = order->processPayment();

            // clear cart if pasyment is successful
            if(paymentSucces){
                NotificationService* notification = new NotificationService();
                notification->notify(order);
                user->getCart()->clear();
            }
        }

        void printUserCart(User* user){
            cout<<"Items in cart"<<endl;
            cout<<"------------------------"<<endl;
            for(const auto &item : user->getCart()->getItems()){
                cout<<item.getCode() << " "<<item.getName() <<" Rs: "<<item.getPrice()<<endl;

            }
            cout<<"--------------------------"<<endl;
            cout<<"Total: "<<user->getCart()->getTotalCost()<<endl;
        }
};

#endif