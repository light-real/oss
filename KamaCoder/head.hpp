#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>

template <typename T>
void printVec(const std::vector<T> vec)
{
    for (auto &u : vec)
    {
        std::cout << u << " ";
    }
    std::cout << std::endl;
}

template <typename T>
void printTwoVec(const std::vector<std::vector<T>> &vec)
{
    for (auto &v : vec)
    {
        printVec(v);
    }
}