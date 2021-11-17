#include <iostream>
#include <unordered_map>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
bool comp(pair<int, int> p1, pair<int, int> p2)
{
    if (p1.second == p2.second)
    {
        return p1.first < p2.first; //this is like permission will say to do sorting or not
    }
    return p1.second > p2.second; //this is like permission will say to do sorting or not
}
void find_freq(int arr[], int n, int k)
{
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        m[arr[i]]++;
    }
    vector<pair<int, int>> v{m.begin(), m.end()};
    sort(v.begin(), v.end(), comp);
    for (int i = 0; i < k; i++)
    {
        cout << v[i].first << " ";
    }
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int k;
    cin >> k;
    find_freq(arr, n, k);
}
