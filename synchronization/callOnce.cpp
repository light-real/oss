#include <iostream>
#include <mutex>
#include <thread>

std::once_flag flag;

void initialize()
{
    std::cout << "initialize function." << std::endl;
}

void thread_func()
{
    std::call_once(flag, initialize);
    std::cout << "thread_func execute." << std::endl;
}

int main()
{
    std::thread t1(thread_func);
    std::thread t2(thread_func);
    std::thread t3(thread_func);
    t1.join();
    t2.join();
    t3.join();
    return 0;
}