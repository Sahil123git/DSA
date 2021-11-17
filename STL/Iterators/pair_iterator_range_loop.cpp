#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<pair<int, int>> v = {{1, 2}, {3, 4}, {6, 7}};
    vector<pair<int, int>>::iterator it;

    for (pair<int, int> &val : v)
    {
        cout << val.first << " " << val.second;
    }
    cout << endl;
    for (auto &val : v) //Use this for shortcut
    {
        cout << val.first << " " << val.second;
    }
    
    return 0;
}