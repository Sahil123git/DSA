#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> v{1, 2, 3, 4, 5, 6};

    int res = count_if(v.begin(), v.end(), [](int x)
                       { return x >= 3; });
    cout << res << " " << endl;

    auto it = find_if(v.begin(), v.end(), [](int x)
                      { return x >= 5; });
    cout << "Number:" << *it << "  Address:" << it - v.begin() << endl;

    int res1 = accumulate(v.begin(), v.end(), 1, [](int x, int y)
                          { return x * y; });
    cout << res1 << endl;
}