#include <iostream>
#include <map>
using namespace std;
int main()
{
    map<int, int> m;
    m.insert({2, 10});
    m[1] = 20;
    m.insert({3, 30});
    m.insert({2, 50}); //this can't be change by this
    m[1] = 50;         //but this can

    for (auto &x : m)
    {
        cout << x.first << " " << x.second << endl;
    }
    cout << m[40] << endl; //no key 40 so 0 will be the value
    cout << m.size() << " size of the map" << endl;

    m.at(1) = 60;
    // m.at(9) = 60; this will not work as there is  no key with 9
    cout << m[1] << endl;

    for (auto it = m.begin(); it != m.end(); it++)
    {
        cout << (*it).first << " " << (*it).second << endl;
    }
    return 0;
}