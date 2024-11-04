#include "head.hpp"

using namespace std;

// 生成一个螺旋矩阵
/*
n = 3:
1 2 3
8 9 4
7 6 5
*/
vector<vector<int>> generateMatrix(int n)
{
    vector<vector<int>> result(n, vector<int>(n, 0));
    int startx = 0, starty = 0;
    int loop = n / 2;
    int mid = n / 2;
    int count = 1; // 用于赋值
    int offset = 1;
    int i, j;
    while (loop--) // 循环遍历的次数 如果n == 3,那么只需要循环遍历一次
    {
        i = startx;
        j = starty;

        for (; j < n - offset; j++)
        {
            result[i][j] = count++;
        }

        for (; i < n - offset; i++)
        {
            result[i][j] = count++;
        }

        for (; j > starty; j--)
        {
            result[i][j] = count++;
        }

        for (; i > startx; i--)
        {
            result[i][j] = count++;
        }

        offset++;
        startx++;
        starty++;
    }
    if (n % 2 == 1)
    {
        result[mid][mid] = count;
    }
    printTwoVec(result);
    return result;
}
int main()
{
    int n = 3;
    generateMatrix(n);
    return 0;
}