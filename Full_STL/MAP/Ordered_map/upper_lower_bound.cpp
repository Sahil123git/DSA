#include <iostream>
#include <map>
using namespace std;
int main()
{
    map<int, string> mp;
    mp.insert({5, "sahil"});
    mp.insert({6, "tina"});
    mp.insert({1, "rock"});
    mp[2] = "john";

    auto it = mp.lower_bound(5);
    if (it == mp.end())
    {
        cout << "not found" << endl;
    }
    else
    {
        cout << "found " << (*it).first << endl;
    }

    auto it_ = mp.upper_bound(6);
    if (it_ == mp.end())
    {
        cout << "not found" << endl;
    }
    else
    {
        cout << "found " << (*it_).first << endl;
    }
    return 0;
}