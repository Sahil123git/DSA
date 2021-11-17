#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    vector<int> v{1, 2, 3, 4, 5};

    for_each(v.begin(), v.end(), [](int &x)
             { x = x * 10; }); //we used ampersand so that we can modify value of x

    for_each(v.begin(), v.end(), [](int x)
             { cout << x << " "; });
}