#include <iostream>
#include <map>
using namespace std;
class ds
{
public:
    map<int, string> m;

    void add_val(int val, string st)
    {
        m.insert({val, st});
    }

    void find(int price)
    {
        auto it = m.find(price);
        if (it == m.end())
        {
            cout << "not found" << endl;
        }
        else
        {
            cout << "found " << (*it).first << endl;
        }
    }

    void sorted()
    {
        for (auto i : m)
        {
            cout << i.first << " ";
        }
        cout << endl;
    }

    void greated_srtd(int price) //print all ele which are greater than this
    {
        auto it = m.upper_bound(price);
        while (it != m.end())
        {
            cout << it->first << " "; //using -> this sign because we are using iterator
            it++;
        }
        cout << endl;
    }

    void smallest_srtd(int price) //print all ele which are smaller than this
    {
        auto it = m.lower_bound(price);
        for (auto it_ = m.begin(); it_ != it; it_++)
        {
            cout << (*it_).first << " ";
        }
        cout << endl;
    }
};
int main()
{
    ds m;
    m.add_val(1, "sahil");
    m.add_val(2, "rahil");
    m.add_val(3, "john");
    m.add_val(4, "rc");

    m.sorted();
    m.find(2);
    m.greated_srtd(1);
    m.smallest_srtd(4);
    return 0;
}