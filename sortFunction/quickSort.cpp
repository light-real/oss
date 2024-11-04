#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int> &vec, int low, int high)
{
    int c = vec[low];
    while (low < high)
    {
        while (low < high && vec[high] >= c)
        {
            high--;
        }
        vec[low] = vec[high];
        while (low < high && vec[low] <= c)
        {
            low++;
        }
        vec[high] = vec[low];
    }
    vec[low] = c;
    return low;
}

void quickSort(vector<int> &vec, int low, int high)
{
    if (low >= high)
    {
        return;
    }
    int pivot = partition(vec, low, high);
    quickSort(vec, low, pivot - 1);
    quickSort(vec, pivot + 1, high);
}
int main()
{
    vector<int> vec = {3, 2, 9, 8, 1, 0};
    quickSort(vec, 0, vec.size() - 1);
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;
    return 0;
}
