#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int arr[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0, k = n - 1; j < k; j++, k--)
        {
            swap(arr[i][j], arr[i][k]);
        }
    }
    int p_counter = n, q_counter = 0;
    for (int i = 0, j = 0; i < n; i++, j++)
    {
        for (int p = n - 1, q = n - 1; q >= q_counter; p--, q--) //p < p_counter,
        {
            swap(arr[i][p], arr[q][j]);
        }
        p_counter--;
        q_counter++;
    }
    // cout << i << " " << j << " " << p << " " << q
    //  << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}