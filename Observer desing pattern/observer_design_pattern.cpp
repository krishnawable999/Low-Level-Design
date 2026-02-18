#include<iostream>
#include<bits/stdc++.h>
using namespace std;


// Abstract observer interface

class ISubscriber{
    public:
    virtual void update()=0;
    virtual ~ISubscriber() {};  // virtual Destructor for interface
};

// Abstreact Obervable Interface: Youtube channel interface
class IChannel{
    public:
    virtual void subscribe(ISubscriber * subscribe)=0;
    virtual void unscbscribe(ISubscriber * subscribe)=0;
    virtual void notifyAll()=0; 
    virtual ~IChannel(){} ; // virtual Dtor for interface
};

// Concrete Subject : a observer can subscribe to 

class Channel : public IChannel{
    private:
    vector<ISubscriber*> subscribers; //List of subscribers
    string name;
    string latestVideo;
    public:

    Channel(const string &name){
        this->name = name;
    }

    // Add Subscriber
    void subscribe(ISubscriber * subscribe) override{
        if(find(subscribers.begin(), subscribers.end(), subscribe) == subscribers.end()){ 
            subscribers.push_back(subscribe);
        }
        
    }

    // Remove a subscriber if present
    void unscbscribe(ISubscriber * subscriber) override{
        auto it = find(subscribers.begin(), subscribers.end(), subscriber);
        if(it != subscribers.end()){
            subscribers.erase(it);
        }
    }

    // notify all subscribers of the new video
    void notifyAll() override{
        for(ISubscriber* subscriber : subscribers){
            subscriber->update();
        }
    }

    // Upload new video and notify all subscribers
    void uploadVideo(const string &title){
        latestVideo = title;
        cout<<"New video Uploaded: "<<latestVideo<<endl;
        notifyAll();
    }

    // Read video data
    string getVideoData(){
        return "\n Check out our new video: "+ latestVideo+"\n";
    }
};

// Concrete Observer : represents a subscriber to a channel
class Subscriber : public ISubscriber{
    private:
    string name;
    Channel* channel;

    public:
    Subscriber(const string &name, Channel* channel){
        this->name = name;
        this->channel = channel;
    }

    void update() override{
        cout<<"Hey"<<name<<" "<<this->channel->getVideoData();
    }
};




int main(){
//  create channel and subscribers
    Channel* channel = new Channel("Channel Army");

    Subscriber * sub1 = new Subscriber("krish", channel);
    Subscriber * sub2 = new Subscriber("pooja", channel);

    // krishna and pooja scbscribers krish and pooja
    channel->subscribe(sub1);
    channel->subscribe(sub2);

    // Upload video and both krish and pooja are nofitied
    channel->uploadVideo("LLD in C++");

    // krish unsubscribers channel
    channel->unscbscribe(sub1);

    // upload anothe video and puja is notified
    channel->uploadVideo("New DSA Playlist");

    return 0;

}