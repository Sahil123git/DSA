#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    unordered_map<string, int> m;

    m["sahil"] = 1;
    m["sa"] = 2;
    m["sahi"] = 3;
    m.insert({"rock", 5});
    m.at("sahil") = 7;

    auto it = m.find("sahil");
    if (it != m.end())
    {
        cout << it->second << " " << endl;
    }

    for (auto it : m)
    {
        cout << it.first << " " << it.second << endl;
    }
    cout << "size is " << m.size();
    return 0;
}
