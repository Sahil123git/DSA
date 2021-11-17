#include <iostream>
#include <queue>
using namespace std;
int main()
{
    priority_queue<int, vector<int>, greater<int>> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);

    while (q.empty() != true)
    {
        cout << q.top() << " ";
        q.pop();
    }
    return 0;
}