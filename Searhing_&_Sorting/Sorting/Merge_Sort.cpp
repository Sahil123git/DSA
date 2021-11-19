#include <iostream>
using namespace std;

void merge_sort(int arr[], int s, int e) //this is for sorting the arr that we got
{
    int mid = (s + e) / 2;
    int i = s, j = mid + 1, t = s;

    int temp[100];
    while (i <= mid && j <= e)
    {
        if (arr[i] < arr[j])
        {
            temp[t++] = arr[i++];
        }
        else
        {
            temp[t++] = arr[j++];
        }
    }
    while (i <= mid) //now adding the rest of the ele
    {
        temp[t++] = arr[i++];
    }
    while (j <= e) //now adding the rest of the ele
    {
        temp[t++] = arr[j++];
    }
    for (int i = s; i <= e; i++) //don't use (i<e) because then it will not include last ele
    {                            //as we already sending exact size ele so use (i<=e)
        arr[i] = temp[i];
    }
}

void merge(int arr[], int s, int e)
{
    if (s == e)
    {
        return;
    }
    int mid = (s + e) / 2;

    merge(arr, s, mid);     //for  1st half array
    merge(arr, mid + 1, e); //for 2nd half array

    merge_sort(arr, s, e); //this will send 2 half sorted array in one array
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
    merge(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}