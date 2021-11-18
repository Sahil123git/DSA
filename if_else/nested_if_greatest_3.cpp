#include <iostream>
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int num_1, num_2, num_3;
    cin >> num_1 >> num_2 >> num_3;
    if (num_1 > num_2)
    {
        if (num_1 > num_2)
        {
            cout << "num_1 is greatest";
        }
    }
    else
    {
        if (num_2 > num_3)
        {
            cout << "num_2 is greatest";
        }
        else
        {
            cout << "num_3 is greatest";
        }
    }
    return 0;
}