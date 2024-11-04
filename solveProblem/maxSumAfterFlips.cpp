#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long maxSum(const vector<int> &a)
{
    // int n = a.size();
    long long totalSum = 0;
    for (auto num : a)
    {
        totalSum += abs(num);
    }

    int minAbs = *min_element(a.begin(), a.end(), [](int x, int y)
                              { return abs(x) < abs(y); });

    int negativeCount = count_if(a.begin(), a.end(), [](int x)
                                 { return x < 0; });
    if (negativeCount % 2 != 0)
    {
        totalSum -= 2 * abs(minAbs);
    }
    return totalSum;
}

int main()
{
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
    }
    cout << maxSum(a) << endl;
    return 0;
}