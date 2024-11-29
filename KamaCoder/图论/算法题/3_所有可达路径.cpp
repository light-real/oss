#include "head.hpp"

using namespace std;
/*
【题目描述】
给定一个有 n 个节点的有向无环图，节点编号从 1 到 n。请编写一个函数，找出并返回所有从节点 1 到节点 n 的路径。
每条路径应以节点编号的列表形式表示。

【输入描述】
第一行包含两个整数 N，M，表示图中拥有 N 个节点，M 条边
后续 M 行，每行包含两个整数 s 和 t，表示图中的 s 节点与 t 节点中有一条路径

【输出描述】
输出所有的可达路径，路径中所有节点的后面跟一个空格，每条路径独占一行，存在多条路径，路径输出的顺序可任意。
如果不存在任何一条路径，则输出 -1。
*/

vector<vector<int>> result; // 用于记录结果
vector<int> path;           // 用于记录当前路径

void dfs(const vector<vector<int>> &graph, int x, int n)
{
    if (x == n)
    {
        result.push_back(path);
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (graph[x][i] == 1)
        {
            path.push_back(i);
            dfs(graph, i, n);
            path.pop_back();
        }
    }
}
int main()
{
    int N, M;
    cin >> N >> M;                                           // 输入节点和边
    int s, t;                                                // 输入的边
    vector<vector<int>> graph(N + 1, vector<int>(N + 1, 0)); // 创建一个(N+1)*(N+1)大小的图，用于节点和维度一一对应
    for (int i = 0; i < M; i++)
    {
        cin >> s >> t;
        graph[s][t] = 1;
    }
    // 以上就构建好了一个使用邻接矩阵构建好的图
    path.push_back(1); //任意节点从1开始 graph[1][1] = 0 并不会计算进去
    dfs(graph, 1, N);

    if (result.size() == 0)
        cout << -1 << endl;
    for (auto &u : result)
    {
        for (int i = 0; i < u.size() - 1; i++)
        {
            cout << u[i] << " ";
        }
        cout << u[u.size() - 1] << endl;
    }
    return 0;
}