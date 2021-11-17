#include <iostream>
#include <map>
using namespace std;
int main()
{
    map<int, string> mp;
    mp.insert({1, "sahil"});
    mp.insert({3, "rahil"});
    mp.insert({3, "ram"});
    mp[2] = "ron";
    mp.at(1) = "josh";
    mp[6] = "john";
    mp[5];

    for (auto it = mp.rbegin(); it != mp.rend(); it++)
    {
        cout << (*it).first << " " << (*it).second << " | ";
    }
    cout << endl
         << "2nd method using find" << endl;
    for (auto it = mp.find(1); it != mp.end(); it++)
    {
        cout << (*it).first << " " << (*it).second << endl;
    }
    if (mp.count(3) == 0) //for counting the number of times 3 is present
    {
        cout << "not find " << endl;
    }
    else
    {
        cout << "found " << endl;
    }
    return 0;
}