#include <iostream>
#include <map>
using namespace std;
int main()
{
    multimap<int, int> mp; //it can have similar values
    mp.insert({2, 30});
    mp.insert({2, 10});
    mp.insert({2, 30});
    mp.insert({1, 50});
    mp.insert({5, 20});
    mp.insert({5, 40});

    auto it = mp.lower_bound(2);
    auto it_ = mp.upper_bound(2);

    cout << (*it).first << " " << (*it_).first;
    return 0;
}