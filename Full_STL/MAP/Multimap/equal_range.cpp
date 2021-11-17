#include <iostream>
#include <map>
using namespace std;
int main()
{
    multimap<int, int> mp;
    mp.insert({1, 45});
    mp.insert({1, 35});
    mp.insert({2, 25});
    mp.insert({2, 75});
    mp.insert({2, 85});
    mp.insert({4, 65});

    // auto it = mp.equal_range(2);
    // cout << (*it.first) << " " << it.second << endl;

    auto it = mp.equal_range(2); //this is also same as lower bound and upper bound
    cout << (it.first)->first << " " << (*it.second).first << endl;
    for (auto it_ = it.first; it_ != it.second; it_++)
    {
        cout << (*it_).first << " " << it_->second << " |";
    }
    return 0;
}
