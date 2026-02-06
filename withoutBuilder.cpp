#include<bits/stdc++.h>
using namespace std;

class httpreq{
    private:
    string url;
    string method;
    map<string, string> header;
    map<string, string> queryparams;
    string body;
    int timeout;

    public:
    // parameterized ctor1
    httpreq(string url, string method){
        this->url = url;
        this->method = method;
    }

    httpreq(const string &url){
        this->url = url;
        this->method = "GET";
        this->timeout = 30;
    }
    httpreq(const string &url, string method, map<string, string> header, map<string, string> queryparams, string body, int timeout){
        this->url = url;
        this->method = method;
        this->header = header;
        this->queryparams = queryparams;
        this->body = body;
        this->timeout = timeout;
    }

    // ctor->2;
    httpreq(const string &url, string method, int timeout){
        this->url = url;
        this->method = method;
        this->timeout = timeout;
    }

    // default ctor
    httpreq(){}

     // Getter and Setter for url
    string getUrl() const {
        return url;
    }

    void setUrl(const string& url) {
        this->url = url;
    }

    // Getter and Setter for method
    string getMethod() const {
        return method;
    }

    void setMethod(const string& method) {
        this->method = method;
    }

    // Getter and Setter for header
    map<string, string> getHeader() const {
        return header;
    }

    void setHeader(const map<string, string>& header) {
        this->header = header;
    }

    // Getter and Setter for queryparams
    map<string, string> getQueryParams() const {
        return queryparams;
    }

    void setQueryParams(const map<string, string>& queryparams) {
        this->queryparams = queryparams;
    }

    // Getter and Setter for body
    string getBody() const {
        return body;
    }

    void setBody(const string& body) {
        this->body = body;
    }

    // Getter and Setter for timeout
    int getTimeout() const {
        return timeout;
    }

    void setTimeout(int timeout) {
        this->timeout = timeout;
    }
    


};

int main(){

}