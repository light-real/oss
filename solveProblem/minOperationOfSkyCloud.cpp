#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 目标是a数组中的最大值不大于b数组中的最小值
// 可以选择a或b数组中的某一项将其加1，求最少操作次数达成目标
int minOperation(vector<int> &a, vector<int> &b)
{
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    if (a.back() <= b[0])
    {
        return 0;
    }
    int result = 0;
    int index = 0;
    for (; index < b.size() && a.back() > b[index]; index++)
    {
    }
    cout << "index = " << index << endl;
    for (int j = 0; j < index; j++)
    {
        if (a.back() > b[j])
        {
            result += a.back() - b[j];
        }
    }
    cout << result << endl;
    return result;
}

int main()
{
    vector<int> a = {1, 2, 4};
    vector<int> b = {2, 3, 5, 10};
    minOperation(a, b);
    return 0;
}
