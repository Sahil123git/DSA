#include <iostream>
#include <queue>
using namespace std;
int main()
{
    queue<char> q;
    char ch;
    int freq[40] = {0};

    cin >> ch;
    while (ch != '.')
    {
        q.push(ch);
        freq[ch - 'a']++;
        while (!q.empty())
        {
            int ele = q.front() - 'a';
            if (freq[ele] == 1)
            {
                cout << q.front() << " ";
                break;
            }
            else
            {
                q.pop();
            }
        }
        if (q.empty())
        {
            cout << "-1 ";
        }
        cin >> ch;
    }
    return 0;
}