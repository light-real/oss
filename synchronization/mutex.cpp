#include <iostream>
#include <mutex>
#include <memory>

using namespace std;

class Request
{
public:
    void printAll() __attribute__((noinline))
    {
        lock_guard<mutex> lock(mutex_);
        print();
    }

    void print() __attribute__((noinline))
    {
        // lock_guard<mutex> lock(mutex_);
    }

private:
    mutable std::mutex mutex_;
};

int main()
{
    Request *request = new Request();
    request->printAll();
    return 0;
}