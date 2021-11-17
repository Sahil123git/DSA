#include <iostream>
#include <map>
using namespace std;
int main()
{
    map<int, int> m;
    m.insert({2, 10});
    m[1] = 20;
    m.insert({3, 30});
    m.insert({5, 60});
    m.insert({4, 80});
    m.insert({6, 70});
    m.insert({2, 50}); //this can't be change by this
    m[1] = 50;         //but this can

    m.erase(2);
    m.erase(m.find(3));
    m.erase(m.find(4), m.end());
    for (auto &x : m)
    {
        cout << x.first << " " << x.second << endl;
    }
    return 0;
}