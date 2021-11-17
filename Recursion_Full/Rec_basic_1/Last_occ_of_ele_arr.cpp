#include <iostream> //Bottom to top approach
using namespace std;
int last_occ(int arr[], int n, int key)
{
    if (n == 0)
    {
        return -1;
    }
    int ind = last_occ(arr + 1, n - 1, key);
    if (ind == -1)
    {
        if (arr[0] == key)
        {
            return 0;
        }
        else
        {
            return -1;
        }
    }
    return ind + 1;
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
    int key;
    cin >> key;
    cout << last_occ(arr, n, key);
    return 0;
}