#include<iostream>
#include "Zomato.h"
using namespace std;

int main(){
    Zomato *zomato = new Zomato();

    // Create user
    User* user = new User(101, "Krishna", "kasarvadavali naka");
    cout<<"User"<<user->getName()<<"is Active"<<endl;


    // User searches restaurent by location
    vector<Restaurent*> restaurentList = zomato->searchRestaurents("Thane");

    if(restaurentList.empty()){
        cout<<"No Restaurent Found"<<endl;
    }

    cout<<"Restaurents Found"<<endl;
    for(auto it : restaurentList){
        cout<<"Name"<<it->getName()<<endl;
    }

    // User selects the restaurent
    zomato->selectRestaurent(user, restaurentList[0]);

    cout<<"Selected Restaurent: "<<restaurentList[0]->getName()<<endl;

    // Add items to cart
    zomato->addToCart(user,"V1");
    zomato->addToCart(user, "V2");

    zomato->printUserCart(user);


    // User checkout the order
    Order *order = zomato->checkOutNow(user, "Delivery", new UpiPaymentStrategy("1234567890"));

    // user pays for the cart if success, notification sent
    zomato->payForOrder(user, order);

    // clean memory
    delete zomato;
    delete user;
    
}