#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}
// https://www.hackerrank.com/contests/cse329-ca-3/challenges/andrew-and-smooth-numbers-1
int main()
{
    int n;
    cin >> n;
    vector<int> start;
    vector<int> end;

    for (int i = 0; i < n; i++)
    {
        int ele;
        cin >> ele;
        start.push_back(ele);
    }
    for (int i = 0; i < n; i++)
    {
        int ele;
        cin >> ele;
        end.push_back(ele);
    }

    vector<pair<int, int>> pair;

    for (int i = 0; i < n; i++)
    {
        pair.push_back({start[i], end[i]});
    }

    sort(pair.begin(), pair.end(), cmp);

    int endTime = 0, cnt = 0;

    for (int i = 0; i < n; i++)
    {
        if (pair[i].first >= endTime)
        {
            cnt++;
            endTime = pair[i].second;
        }
    }

    cout << cnt << endl;
}