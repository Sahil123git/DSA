#include <iostream>
#include <unordered_map>
using namespace std;
class money
{
public:
    unordered_map<int, int> m;
    void set(int id, int bal)
    {
        // m.insert({id, bal}); or
        m[id] = bal;
    }

    int get(int val)
    {
        return m[val];
    }
};
int main()
{
    money m;
    m.set(1, 10101);
    m.set(2, 20101);
    m.set(1, 101);

    cout << m.get(1) << " " << m.get(2);
    return 0;
}