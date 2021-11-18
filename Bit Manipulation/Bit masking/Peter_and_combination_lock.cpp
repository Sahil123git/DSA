#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int ele1;
        cin >> ele1;
        v.push_back(ele1);
    }
    // cout << (1 << v.size());
    for (int i = 0; i < (1 << v.size()); i++)
    {
        int sum = 0, cntr = i; //so that real i will not change
        for (int j = 0; j < v.size(); j++)
        {
            // cout << cntr << " ";
            if (1 & cntr)
            {
                sum += v[j];
            }
            else
            {
                sum -= v[j];
            }
            cntr = cntr >> 1;
            // cout << sum << " ";
            if (sum % 360 == 0 && j == v.size() - 1)
            {
                // cout << sum << endl;
                cout << "YES";
                return 0;
            }
        }
    }
    cout << "NO";
    return 0;
}