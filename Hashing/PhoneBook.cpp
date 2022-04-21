#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int main()
{
    unordered_map<string, vector<string>> ump;
    ump["sahil"].push_back("126457345");
    ump["sahil"].push_back("126345");
    ump["sahil"].push_back("18826345");
    ump["rahil"].push_back("123242345");
    ump["raj"].push_back("12342345");
    ump["roak"].push_back("1232342345");

    // cout << ump["saihl"] << endl;
    for (unordered_map<string, vector<string>>::iterator it = ump.begin(); it != ump.end(); it++)
    {
        cout << it->first << " -> ";
        for (string itt : (*it).second)
        {
            cout << itt << " ";
        }
        cout << endl;
    }
}