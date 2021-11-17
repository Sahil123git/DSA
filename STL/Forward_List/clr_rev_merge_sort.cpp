#include <iostream>
#include <forward_list>
using namespace std;
int main()
{
    forward_list<int> l = {10, 20, 30};
    l.reverse();
    for (int x : l)
    {
        cout << x << " ";
    }
    cout << endl;
    l.sort();
    forward_list<int> li = {1, 50, 40};
    li.merge(l);
    for (int x : li)
    {
        cout << x << " ";
    }
}
