#include <iostream>
#include <deque>
using namespace std;
void max_sub_arr(int arr[], int n, int k) //optimized approach
{
    deque<int> dq;
    for (int i = 0; i < k; i++) //this is for finding max in 1st k elements
    {
        while (!dq.empty() && arr[i] >= arr[dq.back()])
        {
            dq.pop_back();
        }
        dq.push_back(i);
    }

    for (int i = k; i < n; i++) //this is for rest k elements
    {                           //***here what we are doing is pop from last and printing front ele***
        cout << arr[dq.front()] << " ";
        while (!dq.empty() && dq.front() <= i - k) //this will remove extra ele which are not present
        {                                          //in the in k elements group
            dq.pop_front();
        }
        while (!dq.empty() && arr[i] > arr[dq.back()]) //this will remove small ele from the top of deque
        {
            dq.pop_back();
        }
        dq.push_back(i); //we are keeping last ele address so
    }                    //so that we can get when we want
    cout << arr[dq.front()];
}
void max_sub_naive(int arr[], int n, int k) //Naivae approach
{
    for (int i = 0; i <= n - k; i++)
    {
        int sum = 0;
        for (int j = 0; j < i + k; j++)
        {
            if (arr[j] > sum)
            {
                sum = arr[j];
            }
        }
        cout << sum << " ";
    }
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
    int k;
    cin >> k;
    // cout << "fd";
    max_sub_arr(arr, n, k);
    cout << " "
         << "opti approach " << endl;
    max_sub_naive(arr, n, k);
    cout << "naive approach " << endl;

    return 0;
}
/*9
1 2 4 3 2 8 6 10 7
3*/