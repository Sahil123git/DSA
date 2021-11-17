#include <iostream>
#include <queue>
using namespace std;
int main()
{
    priority_queue<int> pq;
    pq.push(10);
    pq.push(20);
    pq.push(30);
    pq.push(40);

    cout << pq.size() << " " << pq.top() << endl;
    while (pq.empty() != true)
    {
        cout << pq.top() << " ";
        pq.pop();
    }
    return 0;
}