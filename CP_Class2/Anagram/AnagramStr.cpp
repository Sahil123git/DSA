#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

bool chkrAnagram(string str1, string str2)
{
    if (str1.size() != str2.size())
    {
        return 0;
    }

    unordered_map<int, int> ump;
    for (int i = 0; i < str1.size(); i++)
    {
        ump[str1[i]]++;
    }
    for (int i = 0; i < str2.size(); i++)
    {
        ump[str2[i]]--;
    }

    for (auto it : ump)
    {
        if (it.second != 0)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    string str1, str2;
    cin >> str1 >> str2;

    cout << chkrAnagram(str1, str2);
}