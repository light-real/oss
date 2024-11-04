#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>

using namespace std;

int stringToInt(const string &str)
{
    int locateN = str.size();
    int locateI = locateN - 1;
    int locateSum = 0;
    while (locateI >= 0)
    {
        int x = (str[locateI] == '1' ? 1 : 0);
        if (x == 1)
        {
            int currentPow = pow(2, locateN - locateI - 1);
            cout<<"currentPow = "<<currentPow<<endl;
            locateSum += currentPow;
        }
        locateI--;
    }
    cout << "locateSum = " << locateSum << endl;
    return locateSum;
}

int compute(const vector<string> &vec)
{
    int n = vec.size();
    if (n == 0)
    {
        return 0;
    }
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        int currentSum = stringToInt(vec[i]);
        
        sum += currentSum;
    }
    return sum;
}

int main()
{
    vector<string> question = {"100","101"};
    cout << compute(question) << endl;
    system("pause");
    return 0;
}