#include <iostream>
#include <queue>
using namespace std;
int main()
{
    priority_queue<int, vector<int>, greater<int>> que_max_heap;//MIN HEAP
    // priority_queue<int> que_max_heap; //MAX HEAP
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int ele;
        cin >> ele;
        que_max_heap.push(ele);
    }

    for (int i = 0; i < n; i++)
    {
        cout << que_max_heap.top() << " ";
        que_max_heap.pop();
    }
    return 0;
}
