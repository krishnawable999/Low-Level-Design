#include<bits/stdc++.h>
using namespace std;

class httpreq{
    private:
    string url;             // required
    string method;
    map<string, string> header;
    map<string, string> queryparams;
    string body;            
    int timeout;           // required

    //  private ctor only be accessed by httpreq object
    httpreq(){}
    public:
    friend class httpreqBuilder;

    // execute class
    void execute(){
        cout<<"Executing "<<method<<" request to "<< url <<endl;

        if(!queryparams.empty()){
            for(auto &it : queryparams){
                cout<<"key-> "<<it.first<<" value-> "<<it.second<<endl;
            }
        }

        cout<<"Headers"<<endl;
        for(auto &it:queryparams){
            cout<<"Key-> "<<it.first<<" value-> "<<it.second<<endl;
        }

        if(!body.empty()){
            cout<<body<<endl;
        }

        cout<<timeout<<endl;
    }
};

class httpreqBuilder{
    private:
    httpreq req;

    public:
    // method chaining

    httpreqBuilder& withurl(const string &u){
        req.url = u;
        return *this;
    }

    httpreqBuilder& withMethod(string m){
        req.method = m;
        return *this;
    }

    httpreqBuilder& withHeader(const string &key, const string& value){
        req.header[key] = value;
        return *this;
    }

    httpreqBuilder& withqueryParam(const string &key, const string& value){
        req.queryparams[key] = value;
        return *this;
    }

    httpreqBuilder& withBody(string b){
        req.body = b;
        return *this;
    }

    httpreqBuilder& withtimeOut(int t){
        req.timeout = t;
        return *this;
    }

    // build method to create the immutable Httprequest object
    httpreq build(){
        if(req.url.empty()){
            throw runtime_error("URL cannot be empty");
        }

        return req;
    }
};

int main(){
    // using builder patern

    httpreq req = httpreqBuilder()
    .withurl("http://localhost:8080/api/login")
    .withMethod("POST")
    .withHeader("content-type","application-json")
    .withqueryParam("key","2134")
    .withBody("This is sample")
    .withtimeOut(1800).build();

    
    req.execute();
}