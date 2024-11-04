#include <iostream>

using namespace std;

// 通过函数指针实现回调函数
void result(int a)
{
    cout << "result = " << a << endl;
}

/*
函数指针可以将一个函数的地址作为参数传入给另一个函数，并在需要时调用这个函数，从而实现回调
*/
void processData(int a, void (*callback)(int))  //这里的参数和返回类型必须和调用的回调函数相匹配
{
    a *= 2;
    result(a);
}

int main()
{
    processData(5, result);
    return 0;
}