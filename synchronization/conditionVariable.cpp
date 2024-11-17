#include <iostream>
#include <condition_variable>
#include <deque>
#include <queue>
#include <mutex>
#include <cassert>
#include <thread>
using namespace std;

/*
利用线程间共享的全局变量进行同步的一种机制
两个动作：
    1、一个线程因等待条件变量的条件成立而挂起
    2、另一个线程使条件成立，给出信号，从而唤醒被等待的线程
*/

mutex mtx;
condition_variable cond;
queue<int> q;
int preducerCount = 2;
bool finished = false;
// 生产消费者模型

void producer(int id)
{
    for (int i = 0; i < 5; i++)
    {
        std::unique_lock<mutex> lock(mtx);
        cond.wait(lock, []()
                  { return q.size() < 3; });
        q.push(i);
        std::cout << "Producer " << id << " produced " << i << endl;
        lock.unlock();
        cond.notify_one();
        std::this_thread::sleep_for(chrono::microseconds(100));
    }
    unique_lock<mutex> lock(mtx);
    preducerCount--;
    if (preducerCount == 0)
        finished = true;
    lock.unlock();
    cond.notify_all();
}

void consumer(int id)
{
    while (true)
    {
        std::unique_lock<mutex> lock(mtx);
        cond.wait(lock, []
                  { return !q.empty() || finished; });
        if (!q.empty())
        {
            int data = q.front();
            q.pop();
            cout << "consumer " << id << " consumed " << data << endl;
            cond.notify_one();
        }
        else if (finished)
        {
            break;
        }
    }
}

int main()
{
    std::thread producer1(producer, 1);
    std::thread producer2(producer, 2);
    std::thread consumer1(consumer, 1);
    producer1.join();
    producer2.join();
    consumer1.join();
    return 0;
}