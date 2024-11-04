#include <iostream>
#include <functional>
#include <string>

using namespace std;

// 通过std::function和std::bind实现回调函数

class Server
{
private:
    std::function<void(const string &s)> callback;

public:
    void setCallback(std::function<void(const string &s)> fn)
    {
        callback = fn;
    }

    void triggerEvent(const string &s)
    {
        if (callback)
        {
            callback(s);
        }
    }
};

class EchoServer
{
public:
    Server server;

public:
    EchoServer()
    {
        server.setCallback(std::bind(&EchoServer::handleEvent, this, std::placeholders::_1));
    }

/*
如果有handleEvent事件发生了，那么将会回调Server对象的triggleEvent方法，在triggleEvent方法中，如果Server的callback对象存在的话
那么调用callback(argv)。在EchoServer的构造函数中，已经调用了Server的setcallback方法，将handleEvent绑定给了callback对象
*/
    void handleEvent(const std::string &s) 
    {
        cout << "s = " << s << endl;
    }
};

int main()
{
    EchoServer s;
    s.server.triggerEvent("I am happy!");
    return 0;
}