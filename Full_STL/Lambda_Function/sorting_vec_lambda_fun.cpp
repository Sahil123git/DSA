#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
    vector<int> v{10, 3, 1, 4, 2};

    sort(v.begin(), v.end(), [](int a, int b)
         { return a < b; }); //it will false when a is smaller than b

    for (int it : v)
    {
        cout << it << " ";
    }
}