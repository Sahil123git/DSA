#include <iostream>
#include <map>
using namespace std;
int main()
{
    multimap<int, int> mp; //it can have similar values
    mp.insert({2, 30});
    mp.insert({1, 10});
    mp.insert({1, 50});
    mp.insert({3, 20});
    mp.insert({3, 40});
    mp.insert({4, 40});
    mp.insert({4, 40});
    mp.insert({4, 40});

    cout << "no of times 1 is present" << mp.count(1) << endl;
    auto it = mp.find(1);
    mp.erase(it); //this will remove only 1 occurence of the ele
    mp.erase(3);  //this will remove all occurence of the ele

    for (auto it : mp)
    {
        cout << it.first << " " << it.second << endl;
    }
    return 0;
}