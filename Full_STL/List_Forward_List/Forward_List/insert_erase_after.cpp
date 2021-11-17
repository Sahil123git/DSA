#include <iostream>
#include <forward_list>
using namespace std;
int main()
{
    forward_list<int> l;
    l.assign({1, 2, 3, 4});

    auto it = l.emplace_after(l.begin(), 7); //it will give the index of next to  inserted ele
    it = l.insert_after(it, {8, 9, 10});
    it = l.erase_after(it); //it will also return the index of next of deleted ele
    for (auto it : l)
    {
        cout << it << " ";
    }
}