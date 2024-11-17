#include "head.hpp"

using namespace std;

class HashNode
{
public:
    int val;
    int key;
    HashNode *prev;
    HashNode *next;

public:
    HashNode(int ckey = 0, int cval = 0) : key(ckey), val(cval), prev(nullptr), next(nullptr)
    {
    }
};

class MyListNode
{
private:
    HashNode *dummy;
    unordered_map<int, HashNode *> umap;

public:
    MyListNode() : dummy(new HashNode())
    {
        dummy->prev = dummy;
        dummy->next = dummy;
    }

    // 头插
    void insertFront(HashNode *node)
    {
        node->next = dummy->next;
        dummy->next->prev = node;
        dummy->next = node;
        node->prev = dummy;
        umap[node->key] = node;
    }

    // 尾插
    void insertTail(HashNode *node)
    {
        node->next = dummy;
        node->prev = dummy->prev;
        dummy->prev->next = node;
        dummy->prev = node;
        umap[node->key] = node;
    }

    void deleteWithKey(int key)
    {
        auto it = umap.find(key);
        if (it != umap.end()) // 说明存在
        {
            HashNode *node = it->second;
            node->prev->next = node->next;
            node->next->prev = node->prev;
            delete node;
        }
    }
    void showAllNode()
    {
        HashNode *node = dummy->next;
        while (node != dummy)
        {
            cout << "key = " << node->key << "----->" << "val = " << node->val << endl;
            node = node->next;
        }
    }
};
int main()
{
    MyListNode *ml = new MyListNode();
    HashNode *head = new HashNode(1, 5);
    HashNode *node1 = new HashNode(2, 10);
    HashNode *node2 = new HashNode(3, 15);
    HashNode *node3 = new HashNode(4, 20);
    ml->insertFront(head); // dummp ->3 -> 1 -> 2 -> 4
    ml->insertTail(node1);
    ml->insertFront(node2);
    ml->insertTail(node3);
    ml->showAllNode();
    cout << "-------------我是分割线---------" << endl;
    ml->deleteWithKey(1);
    ml->showAllNode();
    return 0;
}