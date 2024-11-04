#include <iostream>
#include <list>
#include <unordered_map>

using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;
    list<int> necklace;
    unordered_map<int, list<int>::iterator> pos;

    for (int i = 1; i <= n; i++)
    {
        necklace.push_back(i);
        pos[i] = --necklace.end();
    }
    for (int i = 0; i < q; ++i)
    {
        int a, b, op;
        cin >> a >> b >> op;
        auto itA = pos[a];
        necklace.erase(itA);
        auto itB = pos[b];
        if (op == 0)
        {
            pos[a] = necklace.insert(itB, a);
        }
        else
        {
            pos[a] = necklace.insert(++itB, a);
        }
    }
    for (auto it : necklace)
    {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}