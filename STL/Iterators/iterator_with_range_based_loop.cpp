#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> v = {1, 2, 3, 4};
    vector<int>::iterator it;
    for (it = v.begin(); it != v.end(); it++)
    {
        cout << (*it) << " ";
    }
    cout << endl;
    for (int val : v)
    {
        val++; //this will not be able to change the values in vector
    }
    for (int val : v)
    {
        cout << val << " ";
    }
    cout << endl;
    for (int &val : v)
    {
        val++;
    }
    for (int val : v)
    {
        cout << val << " ";
    }
    cout << endl;
    for (auto val : v)
    {
        cout << val << " ";
    }

    return 0;
}