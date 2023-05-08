#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<int, int> p1, pair<int, int> p2)
{
    if (p1.second < p2.second) // if first activity end time is less then no swap
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    int n;
    cin >> n;

    vector<int> stTime, endTime;

    for (int i = 0; i < n; i++)
    {
        int ele;
        cin >> ele;

        stTime.push_back(ele);
    }

    for (int i = 0; i < n; i++)
    {
        int ele;
        cin >> ele;

        endTime.push_back(ele);
    }

    vector<pair<int, int>> vp;
    for (int i = 0; i < n; i++)
    {
        vp.push_back({stTime[i], endTime[i]});
    }

    sort(vp.begin(), vp.end(), cmp); // sorting acc to end time

    // for (auto it : vp)
    // {
    //     cout << it.first << " " << it.second << endl;
    // }
    int fnshTime = 0, cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (vp[i].first >= fnshTime)
        {
            cnt++;
            fnshTime = vp[i].second;
        }
    }
    cout << cnt;
}