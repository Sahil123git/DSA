#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> p = {1, 2, 3, 4, 5, 6};
    vector<int>::iterator it = p.begin();
    for (it = p.begin(); it != p.end(); it++)
    {
        cout << (*it) << " ";
    }
    return 0;
}