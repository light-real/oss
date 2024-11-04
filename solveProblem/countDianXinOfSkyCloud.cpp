#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <map>
using namespace std;

int countDianXinOfSkyCloud(string str)
{
    vector<int> umap(26, 0);
    // 字符串不区分大小写
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            umap[str[i] - 'A']++;
        }
        else
        {
            umap[str[i] - 'a']++;
        }
    }
    cout << umap[0] << endl;
}
int main()
{
    string str = "Abca";
    // cin >> str;
    // countDianXinOfSkyCloud(str);
    cout<<'x'-'a'<<endl;

    return 0;
}