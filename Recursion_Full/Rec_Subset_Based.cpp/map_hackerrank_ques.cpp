#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<string> cust;
    for (int i = 0; i < n; i++)
    {
        string ele;
        cin >> ele;
        cust.push_back(ele);
    }
    map<string, float> m;
    for (int i = 0; i < n; i++)
    {
        m[cust[i]] += 1;
    }
    vector<string> ss;
    for (auto it : m)
    {
        it.second = it.second / n;
        it.second *= 100.0f;     //it will not change the value at this key
        m[it.first] = it.second; //this will change
        // cout << it.second << " " << it.first << endl;
    }

    for (auto it : m)
    {
        if (it.second >= 5.0f)
        {
            ss.push_back(it.first);
        }
    }
    for (auto it : ss)
    {
        cout << it << " ";
    }

    return 0;
}