#include <bits/stdc++.h>
using namespace std;

vector<int> greater_height(vector<int> v)
{
    set<int> s;
    vector<int> vt;

    for (int i = 0; i < v.size(); i++)
    {
        auto it = s.upper_bound(v[i]);
        if (it == s.end())
        {
            vt.push_back(-1);
        }
        else
        {
            vt.push_back(*it);
        }
        s.insert(v[i]);
    }
    return vt;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v;
        for (int i = 0; i < n; i++)
        {
            int k;
            cin >> k;
            v.push_back(k);
        }
        vector<int> result = greater_height(v);
        for (auto i : result)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}