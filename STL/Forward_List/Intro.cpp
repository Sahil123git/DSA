#include <iostream>
#include <forward_list>
using namespace std;
int main()
{
    forward_list<int> l = {1, 2, 3};
    l.push_front(2);
    l.push_front(7);
    l.pop_front();
    for (int x : l)
    {
        cout << x << " ";
    }
    return 0;
}
