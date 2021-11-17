#include <iostream>
#include <list>
using namespace std;
int main()
{
    list<int> li{3, 4, 5, 6};
    li.push_front(1);
    li.push_front(2);
    li.push_back(7);
    li.push_back(8);

    li.pop_front();
    li.pop_back();
    for (auto it : li)
    {
        cout << it << " ";
    }
}