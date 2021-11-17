#include <iostream> //TIME COMPLEXITY O[logN] of upper and lower bound
#include <algorithm>
#include <vector>
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
    auto it1 = lower_bound(v.begin(), v.end(), 2);
    auto it2 = upper_bound(v.begin(), v.end(), 2);
    cout << *it1 << " lower bound" << endl;
    cout << *it2 << " upper bound" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
}