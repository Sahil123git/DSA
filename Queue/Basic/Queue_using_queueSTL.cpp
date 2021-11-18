#include <iostream>
#include <queue>
using namespace std;
int main()
{
    queue<int> q;
    for (int i = 0; i < 5; i++)
    {
        q.push(i);
    }
    cout << q.size() << " " << q.back() << endl;
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}