#include <iostream>
using namespace std;
int main()
{
    int saving;
    cin >> saving;
    if (saving > 5000)
    {
        cout << "Best friends";
    }
    else if (saving > 2000)
    {
        cout << "friends";
    }
    else
    {
        cout << "solo";
    }
    return 0;
}