#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> v{1, 2, 3, 4};
    cout << all_of(v.begin(), v.end(), [](int x)
                   { return x > 0; }) //all then only true
         << endl;

    cout << any_of(v.begin(), v.end(), [](int x)
                   { return x % 2 == 0; }) //correct if one wrong
         << endl;

    cout << none_of(v.begin(), v.end(), [](int x)
                    { return x > 5; }); // all correct means all wrong
}