#include <iostream>  //https://www.youtube.com/watch?v=FbGG2qpNp4U&list=PL_z_8CaSLPWdeOezg68SKkeLN4-T_jNHd&index=10
using namespace std; //don't have to find nearest greatest
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int arr_l[n];
    arr_l[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        arr_l[i] = max(arr_l[i - 1], arr[i]);
    }

    int arr_r[n];
    arr_r[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        arr_r[i] = max(arr_r[i + 1], arr[i]);
    }

    // for (int i = 0; i < n; i++)  //see this for more clearification
    // {
    //     cout << arr_l[i] << " ";
    // }
    // cout << endl;
    // for (int i = 0; i < n; i++)
    // {
    //     cout << arr_r[i] << " ";
    // }
    // cout << endl;

    int water[n];
    for (int i = 0; i < n; i++)
    {
        water[i] = min(arr_r[i], arr_l[i]) - arr[i];
    }
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        // cout << water[i] << " ";
        sum += water[i];
    }
    cout << sum;
    return 0;
}