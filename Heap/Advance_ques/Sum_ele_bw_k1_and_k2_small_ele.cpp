#include <iostream>
#include <queue>
using namespace std;
int sumBetweenTwoKth(int A[], int N, int K1, int K2)
{
    // Your code goes here
    priority_queue<int, vector<int>, greater<int>> M_heap;
    for (int i = 0; i < N; i++)
    {
        M_heap.push(A[i]);
    }

    int iter = 1, sum = 0;
    while (!(M_heap.empty())) //or can make func for both k which will give 1st smallest and
    {                         // which will give 2nd smallest in the arr
        if (iter > K1 && iter < K2)
        {
            sum += M_heap.top();
            //   cout<<M_heap.top()<<" "<<iter<<endl;
        }
        M_heap.pop();
        iter += 1;
    }
    return sum;
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int k1, k2;
    cin >> k1 >> k2;

    cout << sumBetweenTwoKth(arr, n, k1, k2);
}