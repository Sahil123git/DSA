#include <iostream>
using namespace std;
int main()
{
    pair<int, string> p(10, "sahil"), p1(10, "roe");
    //if 1st pair is same then it will check 2nd pair (check all in lexographicallys)
    if (p == p1)
    {
        cout << "equal" << endl;
    }
    else if (p < p1)
    {
        cout << "not equal p is smaller" << endl;
    }
    else
    {
        cout << "not equal p1 is smaller" << endl;
    }
}