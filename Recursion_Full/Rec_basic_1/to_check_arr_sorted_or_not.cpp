#include <iostream>
using namespace std;
bool check_sort(int n, int arr[])
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    return ((arr[0] < arr[1]) && check_sort(n - 1, arr + 1));
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
    cout << check_sort(n, arr);
    return 0;
}