#include<bits/stdc++.h>
using namespace std;

class Singleton{
    static Singleton * instance;
    static mutex mtx;

    private:
    Singleton(){
        cout<<"Ctor has been called"<<endl;
    }

    public:
    //  there is bug in this code, when the multiple threads trying to access the same instance then it will fail at that moment to avoid that condition we use the mutex and locking

    static Singleton* getInstance(){
        if(instance == nullptr){
            lock_guard<mutex> lock(mtx);
            if(instance == nullptr){
                instance = new Singleton();
            }
            
        }
        return instance;
    }
};

Singleton *Singleton ::instance = nullptr;  
mutex Singleton :: mtx;
int main(){
    Singleton * s1 = Singleton::getInstance();
    Singleton * s2 = Singleton::getInstance();

    cout<<(s1 == s2)<<endl;
    
}