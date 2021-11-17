#include <iostream>
#include <forward_list>
using namespace std;
int main()
{
    forward_list<int> l = {1, 2, 3};

    l.push_front(4);
    l.push_front(5);
    l.push_front(6);
    l.pop_front();
    for (int it : l)
    {
        cout << it << " ";
    }
}