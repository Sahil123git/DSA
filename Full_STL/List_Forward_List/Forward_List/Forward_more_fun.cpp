#include <iostream>
#include <forward_list>
using namespace std;
int main()
{
    forward_list<int> l = {1, 3, 8};
    if (l.empty())
    {
        cout << "it is empty" << endl;
    }
    l.reverse();
    for (int it : l)
    {
        cout << it << " ";
    }
    cout << endl;
    l.sort();

    forward_list<int> l2;
    l2.assign({2, 4, 5});
    l.merge(l2);

    for (int it : l)
    {
        cout << it << " ";
    }
    cout<<endl;
}