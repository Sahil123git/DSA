#include <iostream>
#include <array>
// #include <bits/stdc++.h>
using namespace std;
int main()
{
    array<int, 5> ar1 = {1, 2, 3, 4};
    for (auto it = ar1.begin(); it != ar1.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    for (auto it = ar1.rbegin(); it != ar1.rend(); it++)
    {
        cout << *it << " "; //pointer so use *it to dereference
    }
    cout << endl;

    for (auto it : ar1)
    {
        cout << it << " "; //no pointer so not use *it
    }
    cout << endl;

    string str = "sahildussa";
    for (auto it : str)
    {
        cout << it << " ";
    }
    return 0;
}