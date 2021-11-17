#include <iostream>
#include <forward_list>
using namespace std;
int main()
{
    forward_list<int> l;
    l.assign(5, 10); //five 10s

    for (int it : l)
    {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}