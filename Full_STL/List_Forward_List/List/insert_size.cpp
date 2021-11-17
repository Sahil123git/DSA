#include <iostream>
#include <list>
using namespace std;
int main()
{
    list<int> li{3, 4, 5, 6};
    auto it = li.begin();
    it++;
    it = li.insert(it, 20);    //return address of insreted ele
    it = li.insert(it, 2, 70); //return addresss of 1st 70 and inserted before 20
    for (list<int>::iterator it = li.begin(); it != li.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
    it = li.erase(it); ///will return address of next of it
    cout << *it << endl;
    li.remove(6);
    for (list<int>::iterator it = li.begin(); it != li.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl
         << "size: " << li.size();
}