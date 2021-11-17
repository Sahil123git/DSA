#include <iostream>
#include <forward_list>
using namespace std;
int main()
{
    forward_list<int> l;
    l.assign({4, 2, 3, 4});
    l.remove(4);
    for (int it : l)
    {
        cout << it << " ";
    }
    cout << endl;
    forward_list<int> l2;
    l2.assign(l.begin(), l.end());
    for (int it : l)
    {
        cout << it << " ";
    }
    return 0;
}