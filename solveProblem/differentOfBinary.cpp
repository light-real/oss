#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string toBinary(int n)
{
    string s;
    while (n)
    {
        s += to_string(n % 2);
        n /= 2;
    }
    reverse(s.begin(), s.end());
    return s;
}

int minChanges(int n, int k)
{
    int count = 0;
    string sn = toBinary(n);
    string sk = toBinary(k);
    cout << "sn = " << sn << endl;
    cout << "sk = " << sk << endl;
    int sizen = sn.size();
    int sizek = sk.size();
    // 如果k的长度更大，说明在n的前sizek-sizen位需要补0，那么如果sk的前sizek-sizen有1的话，直接返回-1
    int in = sizen - 1;
    int ik = sizek - 1;
    while (in >= 0 && ik >= 0)
    {
        if (sk[ik] ^ sn[in])
        {
            if (sk[ik] == '1')
            {
                return -1;
            }
            else
            {
                ++count;
            }
        }
        --in;
        --ik;
    }
    while (ik >= 0)
    {
        if (sk[ik] == '1')
        {
            return -1;
        }
        --ik;
    }
    while (in >= 0)
    {
        if (sn[in] == '1')
        {
            ++count;
        }
        --in;
    }
    return count;
}

int main()
{
    int n = 54;
    int k = 4;
    int result = minChanges(n, k);
    cout << "result = " << result << endl;
    return 0;
}