#include <list>
#include <iostream>
using namespace std;
int main()
{
    list<int> l = {2, 2, 3, 3, 5, 6};
    l.unique();
    l.sort();
    l.reverse();
    for (int it : l)
    {
        cout << it << " ";
    }
}