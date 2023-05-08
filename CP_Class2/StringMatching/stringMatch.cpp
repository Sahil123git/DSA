/*s = "working hard is better than working smart"
 p = "hard"*/
#include <iostream>
#include <string>
using namespace std;

int naiveApp(string &s, string &p)
{
    if (p.size() > s.size())
    {
        return -1;
    }

    int i = 0; // index of s
    while (i < s.size())
    {
        int j = 0, k = i; // index of p
        while (k < s.size() && j < p.size() && s[k] == p[j])
        {
            k++;
            j++;
        }
        if (j == p.size())
        {
            return i;
        }
        i++;
    }
    return -1;
}
int main()
{
    string s = "working hard is better hard than working smart";
    string p = "art";

    cout << naiveApp(s, p) << endl;
    return 0;
}
