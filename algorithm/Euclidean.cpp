#include <iostream>

int gcd(int a,int b)
{
    int t = 1;
    while(t != 0)
    {
        t = a % b;
        a = b;
        b = t;
    }
    return a;
}
int main()
{
    int a,b; //��ʾ�����������
    std::cin>>a>>b;
    int result = gcd(a,b);
    std::cout<<"result = "<<result<<std::endl;
    return 0;
}