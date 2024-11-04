#include "head.hpp"

using namespace std;

// 求给定数据的区间和
int main()
{
    int n; // 表示输入的数据个数
    cin >> n;
    vector<int> PrefixSum(n + 1, 0); // 直接计算前缀和，不管元素
    for (int i = 1; i <= n; i++)
    {
        int temp;
        cin >> temp;
        PrefixSum[i] = PrefixSum[i - 1] + temp;
    }
    printVec(PrefixSum);

    // 随后输入需要计算的总和的区间 直至文件结束
    int a, b;
    while (cin >> a >> b)
    {
        cout << PrefixSum[b + 1] - PrefixSum[a]<<endl;
    }
    return 0;
}