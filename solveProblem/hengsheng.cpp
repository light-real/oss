#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

// 连续区间和不大于k的情况下，该区间的最大公因数求和

int gcd(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int maxGcd(const std::vector<int> &nums, int k)
{
    int n = nums.size();
    int maxG = 0;
    for (int start = 0; start < n; start++)
    {
        int sum = 0;
        int sumOfG = 0;
        for (int end = start; end < n; ++end)
        {
            sum += nums[end];
            if (end > start)
            {
                sumOfG += gcd(nums[end - 1], nums[end]);
            }
            if (sum > k)
                break;
            maxG = max(maxG, sumOfG);
        }
    }
    return maxG;
}
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> vec;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        vec.push_back(temp);
    }
    int result = maxGcd(vec, k);
    result = result == 0 ? -1 : result;
    cout << result << endl;
    system("pause");
    return 0;
}
// 64 位输出请用 printf("%lld")