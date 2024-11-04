#include <iostream>
#include <vector>
#include <string>

// 搜索矩阵元素 用于遍历某一个矩阵元素的周围
template <typename T>
void matrixElementTraversal(const std::vector<std::vector<T>> &matrix)
{
    std::vector<int> ner = {-1, 0, 1}; // 用于遍历周围元素
    int rows = matrix.size();          // 矩阵行
    int cols = matrix[0].size();       // 矩阵列

    //   * 当前节点是[ i , j ]
    //   * [i-1,j-1]    [i-1,j]    [i-1,j+1]
    //   * [ i ,j-1]    [ i ,j]    [ i ,j+1]
    //   * [i+1,j-1]    [i+1,j]    [i+1,j+1]
    //   * 那么以当前节点为中心，要求周围的节点，则最多是3*3形式
    //   * 并且所有的行和列都是用当前节点+1或者-1或者不变构成

    // 比如想遍历(1,1)周围的八个元素
    int row = 1;
    int col = 1;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            // 不遍历自己
            if (!(ner[i] == 0 && ner[j] == 0))
            {
                int r = row + ner[i];
                int c = col + ner[j];
                if ((r >= 0 && r < rows) && (c >= 0 && c < cols))
                {
                    std::cout << matrix[r][c] << " ";
                }
            }
        }
    }
}

int main()
{
    std::vector<std::vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    matrixElementTraversal(matrix);
    
    // std::cout << "hello" << std::endl;
    system("pause");
    return 0;
}