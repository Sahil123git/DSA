#include <iostream>
#include <unordered_map>
using namespace std;
int main()
{
    int n;
    cin >> n;
    unordered_map<string, int> m;
    while (n--)
    {
        string str;
        cin >> str;

        m[str] += 1; //adding 1 to preinitialized m[str] = 0
    }
    int maxi = -1;
    string str_ans;
    for (auto it = m.begin(); it != m.end(); it++)
    {
        int ele = (*it).second;
        if (ele > maxi)
        {
            maxi = ele;
            str_ans = (*it).first;
        }
        else if (maxi == ele && (*it).first < str_ans)
        {
            str_ans = (*it).first;
            cout << str_ans;
        }
    }
    cout << str_ans;
    return 0;
}