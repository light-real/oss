#include "head.hpp"

using namespace std;

int main()
{
    string s;
    getline(cin, s);
    stringstream ss(s);
    vector<int> v;
    int i = 0;
    while (ss >> i)
    {
        v.push_back(i);
    }
    printVec(v);
    return 0;
}