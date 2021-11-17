#include <iostream>
#include <set>
using namespace std;

set<int> s;
class sett
{
public:
    void insert(int ele)
    {
        s.insert(ele);
    }
    int search(int ele)
    {
        if (s.find(ele) == s.end())
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
    void delete_(int ele)
    {
        s.erase(ele);
    }

    int get_ceiling(int ele)
    {
        auto up = s.lower_bound(ele);
        if (up != s.end())
        {
            return *up;
        }
        else
        {
            return -1;
        }
    }
    int get_floor(int ele)
    {
        auto up = s.lower_bound(ele);
        if (up == s.begin())
        {
            if (*up == ele)
            {
                return *up;
            }
            else
            {
                return INT16_MAX;
            }
        }
        else
        {
            if (up != s.end() && *up == ele)
            {
                return ele;
            }
            up--;
            return *up;
        }
    }
};
int main()
{
    sett t;
    t.insert(2);
    t.insert(3);
    t.insert(5);
    t.insert(6);
    t.insert(9);
    t.insert(8);

    cout << t.get_ceiling(4) << " " << t.get_floor(1) << endl;
} //get_ceiling will give ele which is greater than or equal to that ele
  //get_floor will give ele which is smaller or equal to that given ele