#include <iostream>
#include <vector>

using namespace std;

void bubbleSort(vector<int> &vec)
{
    int n = vec.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (vec[i] > vec[j])
            {
                swap(vec[i], vec[j]);
            }
        }
        for (int i = 0; i < vec.size(); i++)
        {
            cout << vec[i] << " ";
        }
        cout << endl;
    }
}
int main()
{
    vector<int> vec = {3, 2, 9, 8, 1, 0};
    bubbleSort(vec);
    return 0;
}