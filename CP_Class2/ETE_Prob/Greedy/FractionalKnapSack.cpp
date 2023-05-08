#include <bits/stdc++.h>

bool cmp(pair<int, int> p1, pair<int, int> p2)
{
    double val1 = (p1.first * 1.0) / p1.second; // val by weight
    double val2 = (p2.first * 1.0) / p2.second;

    if (val1 > val2)
    { // if val1 is greater
        return 1;
    }
    else
    {
        return 0;
    }
}

double maximumValue(vector<pair<int, int>> &arr, int n, int W)
{                              // gvn vctr is weight and val pair
    vector<pair<int, int>> vp; // val and weight arr

    for (int i = 0; i < n; i++)
    {
        vp.push_back({arr[i].second, arr[i].first});
    }

    sort(vp.begin(), vp.end(), cmp);

    double profit = 0;
    int i = 0;
    for (int i = 0; i < n; i++)
    {
        if (W <= 0)
        {
            break;
        }
        if (vp[i].second <= W)
        { // if cur ele weight <= W
            W -= vp[i].second;
            profit += vp[i].first;
        }
        else
        { // if cur ele weight is > W
            // cout <<"here";
            double remVal = (((double)vp[i].first) / vp[i].second) * W;
            profit += remVal;
            break;
        }
    }
    return profit;
}