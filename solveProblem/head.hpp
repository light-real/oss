#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>

template <typename T>
void printVec(const std::vector<T> &vec)
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
    for (auto &u : vec)
    {
        printVec(u);
    }
    std::cout << std::endl;
}

class Node // 双向链表
{
public:
    int key;
    int val;
    Node *prev;
    Node *next;
    Node(int k = 0, int v = 0) : key(k), val(v)
    {
    }
};
