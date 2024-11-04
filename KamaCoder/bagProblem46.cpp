#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int M, N; // M 代表研究材料的种类 N代表小明的行李空间
    cin >> M >> N;
    vector<int> weights(M, 0);
    vector<int> values(M, 0);
    for (int i = 0; i < M; i++)
    {
        cin >> weights[i];
    }
    for (int i = 0; i < M; i++)
    {
        cin >> values[i];
    }
    // dp[i][j] 表示截止物品i 容量为j 能获得的最大价值
    vector<vector<int>> dp(M, vector<int>(N + 1, 0)); // 如果背包数量为5 那么dp数组就是 0 1 2 3 4 5 即N+1
    for (int i = 0; i < M; i++)
    {
        dp[i][0] = 0; // 容量为0 最大价值为0
    }
    for (int i = weights[0]; i <= N; i++) // 从容量大于weight[0]的地方开始 和顺序无关 因为从物品0开始遍历
    {
        dp[0][i] = values[0];
    }
    for (int i = 1; i < M; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (j < weights[i])
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weights[i]] + values[i]);
        }
    }
    cout << dp[M - 1][N] << endl;
    return 0;
}