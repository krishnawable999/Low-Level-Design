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

// factory and its concreations

class burgerFactory{
    public:
    virtual Burger* createBurger(string &type)=0; 
};


class SinghBurger : public burgerFactory{
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
};

class KingsBurger : public burgerFactory{
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
};



int main(){
    string type = "standard";
    burgerFactory* myFactory = new SinghBurger();
    Burger *burger = myFactory->createBurger(type);
    burger->prepare(); 
    return 0;

}