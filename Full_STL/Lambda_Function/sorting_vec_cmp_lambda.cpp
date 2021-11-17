#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
    vector<int> v{10, 3, 1, 4, 2};
    auto cmp = [](int x, int y)
    { return x < y; };
    sort(v.begin(), v.end(), cmp); //it will not when a is smaller than b

    for (int it : v)
    {
        cout << it << " ";
    }
}