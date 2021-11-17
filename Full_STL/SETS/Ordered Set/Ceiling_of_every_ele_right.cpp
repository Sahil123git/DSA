#include <iostream>
#include <vector>
#include <set>
using namespace std;
void check_ceil(vector<int> v) //this vector is for getting values
{
    set<int> s;        //this is for keeping track
    int arr[v.size()]; //we will return this
    int n = v.size();
    for (int i = n - 1; i >= 0; i--)
    {
        auto it = s.lower_bound(v[i]);
        if (it == s.end())
        {
            arr[i] = -1;
        }
        else
        {
            arr[i] = *it;
        }
        s.insert(v[i]);
    }
    // for (auto it : s)
    // {
    //     cout << it << " ";// In stack ele are stored in order wise and uniquely
    // }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
int main()
{
    int n;
    cin >> n;
    vector<int> v;
    while (n--)
    {
        int ele;
        cin >> ele;
        v.push_back(ele);
    }
    check_ceil(v);
    return 0;
}