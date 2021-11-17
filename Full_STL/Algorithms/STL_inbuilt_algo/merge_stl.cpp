#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> v1;
    vector<int> v2;
    vector<int> v3(2 * n);

    for (int i = 0; i < n; i++)
    {
        int ele;
        cin >> ele;
        v1.push_back(ele);
    }
    for (int i = 0; i < n; i++)
    {
        int ele;
        cin >> ele;
        v2.push_back(ele);
    }

    merge(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
    for (auto it : v3)
    {
        cout << it << " ";
    }

    return 0;
}
