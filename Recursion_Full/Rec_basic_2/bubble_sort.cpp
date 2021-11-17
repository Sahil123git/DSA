#include <iostream>
using namespace std;
void bubble_srt(int arr[], int n, int j)
{
    if (n == 1)
    {
        return;
    }
    if (j == n - 1)
    {
        return bubble_srt(arr, n - 1, 0);
    }
    if (arr[j] > arr[j + 1])
    {
        swap(arr[j], arr[j + 1]);
    }
    bubble_srt(arr, n, j + 1);
    return;
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
    bubble_srt(arr, n, 0);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}