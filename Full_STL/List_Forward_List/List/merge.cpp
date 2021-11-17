#include <iostream>
#include <list>
using namespace std;
int main()
{
    list<int> li{3, 4, 5, 6};
    list<int> li2{1, 2, 8};
    li.merge(li2);
    for (list<int>::iterator it = li.begin(); it != li.end(); it++)
    {
        cout << *it << " ";
    }
}