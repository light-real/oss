#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*

*/

int killWood(int n, int m, int a, int b)
{
    // 时间为n m个木头人 每个木头人血量为a 攻击范围为b
    //攻击范围为b,每次攻击最多能对b个存活的木头人造成1点伤害，每次攻击需要1秒，经过一次攻击后木头人的血量为0，表示木头人死亡
    //问时间结束后，最多能消灭多少木头人
    vector<int> wood(m, a);
    for (int t = 0; t < n; ++t)
    {
        
    }
}
int main()
{
    int T;
    cin >> T;
    vector<vector<int>> array(T, vector<int>(4));
    for (int i = 0; i < T; i++)
    {
        cin >> array[i][0] >> array[i][1] >> array[i][2] >> array[i][3];
    }

    system("pause");
    return 0;
}