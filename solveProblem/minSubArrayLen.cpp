#include "head.hpp"

using namespace std;

int minSubArrayLen(int s, vector<int> &nums)
{
    int result = INT_MAX;
    int sum = 0;
    int fast = 0;
    int slow = 0;
    int n = nums.size();
    while (fast < n)
    {
        sum += nums[fast];
        while (sum >= s)
        {
            result = min(result, fast - slow + 1);
            sum -= nums[slow];
            ++slow;
        }
        ++fast;
    }
    cout << "result = " << result << endl;
    return slow == 0 ? 0 : result;
}
int main()
{
    vector<int> vec = {2, 3, 1, 2, 4, 3};
    printVec(vec);
    minSubArrayLen(7, vec);
    return 0;
}