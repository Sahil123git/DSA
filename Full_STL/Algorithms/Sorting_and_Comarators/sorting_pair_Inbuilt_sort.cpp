#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
// bool comp(pair<int, int> a, pair<int, int> b)
// {
//     if (a.first != b.first) //now the sorting is depended on this
//     {
//         return (a.first > b.first); //this is for ascending order if u want
//     }
//     else
//     {
//         return (a.second > b.second);
//     }
// }
int main()
{
    int n;
    cin >> n;

    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first >> a[i].second;
    }

    sort(a.begin(), a.end());

    for (int i = 0; i < n; i++)
    {
        cout << a[i].first << " " << a[i].second << endl;
    }
    return 0;
}