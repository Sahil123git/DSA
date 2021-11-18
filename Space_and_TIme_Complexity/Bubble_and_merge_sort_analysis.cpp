#include <iostream>
#include <algorithm>
#include <ctime>
using namespace std;
void bubble_sort(int n, int arr[])
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < (n - i - 1); j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = n - 1; i >= 0; i--)
    {
        arr[i] = i;
    }

    time_t start = clock();
    bubble_sort(n, arr);
    time_t end = clock();
    cout << (end - start) << endl;

    reverse(arr, arr + n);

    start = clock();
    sort(arr, arr + n); //for merge sort inbuilt sort is similar to merge sort
    end = clock();
    cout << (end - start);

    return 0;
}