#include <iostream>
using namespace std;
int merge_sort(int arr[], int s, int e)
{
    int mid = (s + e) / 2;
    int i = s;
    int j = (mid + 1);
    int k = s;
    int temp[10000], cnt = 0;

    while (i <= mid && j <= e) //this is for both sorting and counting inversions
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++]; //we inc j because we are checking for arr[i]
            cnt += (mid - i + 1); //this is the main step which will find the inversions
        }
    }
    while (i <= mid) //this is for remaining ele which left of index i
    {
        temp[k++] = arr[i++];
    }
    while (j <= e) //this is for remaining ele which left of index j
    {
        temp[k++] = arr[j++];
    }
    for (int i = s; i <= e; i++)
    {
        arr[i] = temp[i];
    }
    return cnt;
}
int inversion_ct(int arr[], int st, int end)
{
    if (st >= end)
    {
        return 0;
    }
    int mid = (st + end) / 2;
    int x = inversion_ct(arr, st, mid);
    int y = inversion_ct(arr, mid + 1, end);

    int z = merge_sort(arr, st, end);
    // cout << x << " " << y << " " << z << endl;
    return x + y + z;
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
    cout << inversion_ct(arr, 0, n - 1) << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}