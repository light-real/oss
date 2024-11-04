#include "head.hpp"

using namespace std;
// 设计一个满足LRU(最近最少使用)缓存约束的数据结构
/*
实现 LRUCache 类：
LRUCache(int capacity) 以 正整数 作为容量 capacity 初始化 LRU 缓存
int get(int key) 如果关键字 key 存在于缓存中，则返回关键字的值，否则返回 -1 。
void put(int key, int value) 如果关键字 key 已经存在，则变更其数据值 value ；如果不存在，则向缓存中插入该组 key-value
                             如果插入操作导致关键字数量超过 capacity ，则应该 逐出 最久未使用的关键字。
函数 get 和 put 必须以 O(1) 的平均时间复杂度运行。
*/

class LRUCache
{
private:
    int capacity;
    Node *dummy; // 哨兵节点 头节点->尾部节点指向它 不存储数据
    unordered_map<int, Node *> key_to_node;

    // 删除一个节点
    void remove(Node *node)
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    // 在链表头添加一个节点
    void push_front(Node *node)
    {
        node->prev = dummy;
        node->next = dummy->next;
        node->prev->next = node;
        node->next->prev = node;
    }

    // 获取key对应的节点，同时将该节点移到链表头部
    Node *get_node(int key)
    {
        auto it = key_to_node.find(key);
        if (it == key_to_node.end()) // 如果没有找到
        {
            return nullptr;
        }
        Node *node = it->second;
        remove(node);     // 在原来的地方删除
        push_front(node); // 在头部进行添加
        return node;
    }

public:
    LRUCache(int capacity) : capacity(capacity), dummy(new Node())
    {
        dummy->prev = dummy;
        dummy->next = dummy;
    }

    int get(int key)
    {
        Node *node = get_node(key);
        return node ? node->val : -1;
    }

    void put(int key, int value)
    {
        Node *node = get_node(key);
        if (node) // 节点存在，那么更新节点的值并且将其移动到最前面
        {
            node->val = value;
            return;
        }
        // 如果没有这个节点，那么创建节点，移动到最前面
        node = new Node(key, value);
        key_to_node[key] = node;
        push_front(node);
        // 如果节点太多了
        if (key_to_node.size() > capacity)
        {
            Node *back_node = dummy->prev;     // 拿到最后节点
            key_to_node.erase(back_node->key); // 在哈希表里删除节点
            remove(back_node);                 // 在双向链表中也需要删除节点
            delete back_node;                  // 释放内存
        }
    }
};

int main()
{
    LRUCache *lc = new LRUCache(3);
    lc->put(1, 5);
    lc->put(2, 10);
    lc->put(3, 15);
    cout << "get() = " << lc->get(1) << endl;
    lc->put(4, 20);
    cout << "get() = " << lc->get(2) << endl;
    return 0;
}