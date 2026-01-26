#include<bits/stdc++.h>
using namespace std;

class Burger{
    public:
    virtual void prepare()=0;    // pure virtual function
    virtual ~Burger(){}   // virtual destructor
};

class basicBurger : public Burger{
    public:
    void prepare(){
        cout<<"Preparing Basic Burger"<<endl;
    }
};

class standardBurger : public Burger{
    public:
    void prepare(){
        cout<<"Preparing Standard Burger"<<endl;
    }
};

class premiumBurger : public Burger{
    public:
    void prepare(){
        cout<<"Preparing Premium Burger"<<endl;
    }
};

class basicWheatBurger : public Burger{
    public:
    void prepare(){
        cout<<"Preparing basic wheat Burger"<<endl;
    }
};


class standardWheatBurger : public Burger{
    public:
    void prepare(){
        cout<<"Preparing standard wheat Burger"<<endl;
    }
};
class premiumWheatBurger : public Burger{
    public:
    void prepare(){
        cout<<"Preparing premium wheat Burger"<<endl;
    }
};








// product 2

class GarlicBread{
    public:
    virtual void prepare()=0;
    virtual ~GarlicBread(){}
};

class basicGarlicBread : public GarlicBread{
    public:
    void prepare(){
        cout<<"Preparing Basic Garlic Bread"<<endl;
    }
};

class cheeseGarlicBread : public GarlicBread{
    public:
    void prepare(){
        cout<<"Preparing Chease Garlic Bread"<<endl;
    }
};

class basicWheatGarlicBread : public GarlicBread{
    public:
    void prepare(){
        cout<<"Preparing Basic Wheat Gerlic Bread"<<endl;
    }
}; 

class cheeseWheatGarlicBread : public GarlicBread{
    public:
    void prepare(){
        cout<<"preparing basic wheat garlic bread"<<endl;
    }
};


// factory and its concreations

class MealFactory{
    public:
    virtual Burger* createBurger(string &type)=0;
    virtual GarlicBread* crateGarlicBread(string &type)=0; 
};

class KingsBurger : public MealFactory{
    Burger* createBurger(string &type){
        if(type == "basic"){
            return new basicWheatBurger;
        }
        else if(type == "standard"){
            return new standardWheatBurger;

        }
        else if(type == "premium"){
            return new premiumWheatBurger;
        }else{
            cout<<"Enter Correct Choice"<<endl;
            return nullptr;
        }
    }

    GarlicBread* crateGarlicBread(string& type){
        if(type == "basic"){
            return new basicGarlicBread;
        }else if(type == "cheese"){
            return new cheeseGarlicBread;
        }else{
            return  nullptr;
        }
    }
};


class SinghBurger : public MealFactory{
    Burger* createBurger(string &type){
        if(type == "basic"){
            return new basicBurger;
        }
        else if(type == "standard"){
            return new standardBurger;

        }
        else if(type == "premium"){
            return new premiumBurger;
        }else{
            cout<<"Enter Correct Choice"<<endl;
            return nullptr;
        }
    }

    GarlicBread *crateGarlicBread(string &type){
        if(type == "basic"){
            return new basicWheatGarlicBread;
        }

        if(type == "cheese"){
            return new cheeseWheatGarlicBread;
        }else{
            return  nullptr;
        }
    }
};

int main(){
    string type = "standard";
    string garlicBreadTyoe = "cheese";
    MealFactory* mealFactory = new SinghBurger();
    Burger *burger = mealFactory->createBurger(type);
    GarlicBread* garlicbread = mealFactory->crateGarlicBread(garlicBreadTyoe);
    burger->prepare(); 
    garlicbread->prepare();
    return 0;

}