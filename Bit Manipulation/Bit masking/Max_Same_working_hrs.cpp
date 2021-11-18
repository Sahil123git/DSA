//You are given with n Workers and their days of working.Find those workers who works on the maximum same days
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> masks(n, 0);

    for (int i = 0; i < n; i++)
    {
        int ele;
        cin >> ele;
        int mask = 0;
        for (int j = 0; j < ele; j++)
        {
            int day;
            cin >> day;
            mask = (mask | (1 << day));
        }
        masks[i] = mask;
    }
    // for (auto it : masks)
    // {
    //     cout << it << " ";
    // }
    int maxi = 0, person1 = -1, person2 = -1;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int intersection = (masks[i] & masks[j]);
            int common_days = __builtin_popcount(intersection);
            // maxi = max(maxi, common_days);
            if (common_days > maxi)
            {
                person1 = i;
                person2 = j;
                maxi = common_days;
            }
        }
    }
    cout << maxi << " " << person1 << " " << person2;
}
//https://codeforces.com/blog/entry/73558