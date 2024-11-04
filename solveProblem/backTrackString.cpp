#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

void backtrack(vector<string> &memory, string &s, int k)
{
    if (s.size() == k)
    {
        memory.push_back(s);
        return;
    }
    for (char c = '0'; c <= '1'; c++)
    {
        s += c;
        backtrack(memory, s, k);
        s.pop_back();
    }
}
int main()
{
    // vector<string> ans;
    // string s;
    // int k = 3;
    // unordered_map<string, int> umap;
    // umap.insert({"", 0});
    // backtrack(ans, s, k);
    string test = "absd";
    string s;
    s = test.substr(0, 2);
    cout << s << endl;
    return 0;
}