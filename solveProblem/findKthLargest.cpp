#include "head.hpp"

using namespace std;

int partition(vector<int> &nums, int low, int high)
{
    int cc = nums[low];
    while (low < high)
    {
        while (low < high && nums[high] > cc)
        {
            high--;
        }
        nums[low] = nums[high];
        while (low < high && nums[low] < cc)
        {
            low++;
        }
        nums[high] = nums[low];
    }
    nums[low] = cc;
    return low;
}
void quickSort(vector<int> &nums, int low, int high)
{
    if (low < high)
    {
        int pivot = partition(nums, low, high);
        partition(nums, low, pivot - 1);
        partition(nums, pivot + 1, high);
    }
}

int findKthLargest(vector<int> &nums, int k)
{
    int n = nums.size();
    quickSort(nums, 0, n - 1);
    for (int i = n - 1; i >= 0; i--)
    {
        if (n - i == k)
        {
            return nums[i];
        }
    }
    return 0;
}
int main()
{
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    int k = 2;
    cout << "quickSort before: ";
    printVec(nums);
    // quickSort(nums, 0, nums.size() - 1);
    cout << "findKthLargest = " << findKthLargest(nums, k) << endl;
    cout << "quickSort after: ";
    printVec(nums);
    return 0;
}