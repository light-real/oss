#include <iostream>
#include <condition_variable>
#include <deque>
#include <queue>
#include <mutex>
#include <cassert>
using namespace std;

mutex mutex_;
condition_variable cond;
queue<int> q;
int dequeue()
{
    
    while(q.empty())
    {
        // cond.wait(lock(mutex_));
    }
    assert(!q.empty());
    int top = q.front();
    q.pop();
    return top;
}