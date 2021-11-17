#include <iostream>
#include <forward_list>
using namespace std;
int main()
{
    forward_list<int> l;
    cout << "1st method " << endl;
    l.assign({1, 2, 3, 1});
    l.remove(1);
    for (auto it = l.begin(); it != l.end(); it++)
    {
        cout << (*it) << " ";
    }
    //---------------------------------------------------------------------------------------------------
    cout << endl
         << "2nd method" << endl;
    forward_list<int> l2;
    l2.assign(l.begin(), l.end());
    l2.push_front(1);
    l2.push_front(2);
    l2.push_front(3);
    l2.remove(2);
    for (forward_list<int>::iterator it = l2.begin(); it != l2.end(); it++)
    {
        cout << (*it) << " ";
    }
    //---------------------------------------------------------------------------------------------------
    cout << endl
         << "3rd method " << endl;

    forward_list<int> l3(4, 5);
    for (auto it = l3.begin(); it != l3.end(); it++)
    {
        cout << (*it) << " ";
    }
    cout << endl;
}