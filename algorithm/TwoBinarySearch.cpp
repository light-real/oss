#include <iostream>
#include <vector>

int TwoBinarySearchWithTwoClose(const std::vector<int> &nums, int target)
{
    // nums = {1};
    // ????
    int mid;
    int left = 0, right = nums.size() - 1; // ????????
    while (left <= right)                  // left == right
    {
        mid = left + (right - left) / 2; // mid = (left+right)/2; ????
        if (nums[mid] > target)
        {
            right = mid - 1;
        }
        else if (nums[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            return mid;
        }
    }
    return -1; // ???
}

int TwoBinarySearchWithLeftCloseRightOpen(const std::vector<int> &nums, int target)
{
    // ????
    //  nums = {1};
    int mid;
    int left = 0, right = nums.size(); // ??????????????
    while (left < right)
    {
        mid = left + (right - left) / 2;
        if (nums[mid] > target) // right??
        {
            right = mid; //
        }
        else if (nums[mid] < target)
        {
            left = mid + 1; // ??
            // ???? left = mid
        }
        else
        {
            return mid;
        }
    }
    return -1;
}
int main()
{
    std::vector<int> nums = {1, 2, 3, 4, 5, 6};
    // int result = TwoBinarySearchWithTwoClose(nums, 9); // result = 1
    int result = TwoBinarySearchWithLeftCloseRightOpen(nums, 9);
    std::cout << "result = " << result << std::endl;
    return 0;
}