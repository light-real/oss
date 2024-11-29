#include "head.hpp"

using namespace std;
/*
����Ŀ������
����һ���� n ���ڵ�������޻�ͼ���ڵ��Ŵ� 1 �� n�����дһ���������ҳ����������дӽڵ� 1 ���ڵ� n ��·����
ÿ��·��Ӧ�Խڵ��ŵ��б���ʽ��ʾ��

������������
��һ�а����������� N��M����ʾͼ��ӵ�� N ���ڵ㣬M ����
���� M �У�ÿ�а����������� s �� t����ʾͼ�е� s �ڵ��� t �ڵ�����һ��·��

�����������
������еĿɴ�·����·�������нڵ�ĺ����һ���ո�ÿ��·����ռһ�У����ڶ���·����·�������˳������⡣
����������κ�һ��·��������� -1��
*/

vector<vector<int>> result; // ���ڼ�¼���
vector<int> path;           // ���ڼ�¼��ǰ·��

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
    cin >> N >> M;                                           // ����ڵ�ͱ�
    int s, t;                                                // ����ı�
    vector<vector<int>> graph(N + 1, vector<int>(N + 1, 0)); // ����һ��(N+1)*(N+1)��С��ͼ�����ڽڵ��ά��һһ��Ӧ
    for (int i = 0; i < M; i++)
    {
        cin >> s >> t;
        graph[s][t] = 1;
    }
    // ���Ͼ͹�������һ��ʹ���ڽӾ��󹹽��õ�ͼ
    path.push_back(1); //����ڵ��1��ʼ graph[1][1] = 0 ����������ȥ
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