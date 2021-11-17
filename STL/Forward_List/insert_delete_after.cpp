#include <iostream>
#include <forward_list>
using namespace std;
int main()
{
    forward_list<int> l = {1, 2, 3, 4, 5, 6, 7, 8};
    auto it = l.insert_after(l.begin(), 19);
    it = l.insert_after(++it, {30, 40});
    it = l.emplace_after(++it, 50);
    it = l.erase_after(it);
    for (int x : l)
    {
        cout << x << " ";
    }
    cout << endl;
    cout << "Using 2nd method of erase after " << endl;
    it = l.erase_after(it, l.end());
    for (int x : l)
    {
        cout << x << " ";
    }
}