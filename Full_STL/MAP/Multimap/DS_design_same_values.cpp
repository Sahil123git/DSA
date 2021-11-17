#include <iostream>
#include <map>
using namespace std;

class ds_des
{
public:
    multimap<int, string> mp;
    void add(int val, string str)
    {
        mp.insert({val, str});
    }

    void find_pr(int price)
    {
        auto it = mp.equal_range(price);
        for (auto it_ = it.first; it_ != it.second; it_++)
        {
            cout << it_->first << " " << (*it_).second << " |";
        }
        cout << endl;
    }

    void sorted()
    {
        for (auto it = mp.begin(); it != mp.end(); it++)
        {
            cout << (*it).first << " " << it->second << " |";
        }
        cout << endl;
    }

    void samller_sortd(int price)
    {
        auto it = mp.lower_bound(price);
        for (auto it_ = mp.begin(); it_ != it; it_++)
        {
            cout << it_->first << " " << it_->second << " |";
        }
        cout << endl;
    }

    void greater_sortd(int price)
    {
        auto it = mp.upper_bound(price);
        for (auto it_ = it; it_ != mp.end(); it_++)
        {
            cout << it_->first << " " << it_->second << " |";
        }
        cout << endl;
    }
};
int main()
{
    ds_des m;
    m.add(2, "sahil");
    m.add(2, "john");
    m.add(1, "ron");
    m.add(3, "jack");
    m.add(4, "joe");
    m.add(4, "jimmy");
    m.add(4, "josh");

    m.sorted();
    m.find_pr(4);
    m.samller_sortd(3);
    m.greater_sortd(2);
    return 0;
}