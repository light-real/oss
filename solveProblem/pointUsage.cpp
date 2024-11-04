#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int arrayInt[] = {1,2,3,4,5,6};
    vector<string> arrayString = {"demo1","demo2","demo3"};
    int *p1 = arrayInt;
    cout<<*p1<<endl;
    system("pause");
    return 0;
}