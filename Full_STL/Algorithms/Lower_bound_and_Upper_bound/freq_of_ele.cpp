#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    cin >> n;

    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int ele;
        cin >> ele;
        v.push_back(ele);
    }
    sort(v.begin(), v.end());
    auto it1 = lower_bound(v.begin(), v.end(), 3);
    auto it2 = upper_bound(v.begin(), v.end(), 3);

    cout << "Their indexes" << endl;
    cout << it1 - v.begin() << " " << it2 - v.begin() << endl;
    int first_occ = it1 - v.begin();
    int last_occ = it2 - v.begin();
    // cout << *it1 << " " << *it2 << endl;
    cout << last_occ - first_occ << endl;
}