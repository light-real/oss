#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <cctype>
using namespace std;

char gameJudge(string &s)
{
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    // 评分去除最高分和最低分
    sort(s.begin(), s.end());
    int result = 0;
    for (int i = 1; i < s.size() - 1; i++)
    {
        result += (s[i] - 'a');
    }
    result = result / (s.size() - 2);
    return result;
}
int main()
{
    // 第一行输入两个整数 n评委的数量 m选手的数量
    // 此后n行，第i行输入一个长度为m，且有大小写混合构成的字符串 表示第i个评委对第j个选手做出的评分
    // int n, m;
    // cin >> n >> m;
    // while (--n)
    // {
    //     string s;
    //     cin >> s;
    // }
    string s = "AaBbCc";
    cout << gameJudge(s) << endl;
    system("pause");
    return 0;
}