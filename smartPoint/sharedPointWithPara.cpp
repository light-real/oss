#include <iostream>
#include <memory>
#include <vector>
// shared_ptr作为参数传递时，是否会增加引用计数

using namespace std;

void func(vector<shared_ptr<int>> &vec, shared_ptr<int> sp)
{
    vec.push_back(sp);
}

int main()
{
    shared_ptr<int> sp = make_shared<int>(10);
    vector<shared_ptr<int>> vec;
    cout << sp.use_count() << endl;
    func(vec, sp);
    cout << sp.use_count() << endl;
    return 0;
}