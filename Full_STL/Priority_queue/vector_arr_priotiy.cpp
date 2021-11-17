#include <iostream>
#include <queue>
using namespace std;
int main()
{
    vector<int> v = {1, 2, 3, 4, 5, 6};
    priority_queue<int> q{v.begin(), v.end()};
    while (q.empty() != true)
    {
        cout << q.top() << " ";
        q.pop();
    }
    cout << endl;
    int arr[] = {1, 2, 3, 4, 5, 6};
    priority_queue<int> q1{arr, arr + 6};
    while (q1.empty() != true)
    {
        cout << q1.top() << " ";
        q1.pop();
    }
    return 0;
}