#include <iostream>
using namespace std;
int main()
{
    int n, m; //n = row  ,   m=coloumn
    cin >> n >> m;
    int arr[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    int target;
    cin >> target;
    int i, j;
    i = 0;
    j = m - 1;
    while (i < n && j >= 0)
    {
        if (target == arr[i][j])
        {
            cout << "target found at -> " << i << "," << j;
            return 0;
        }
        else if (target < arr[i][j])
        {
            j--;
        }
        else if (target > arr[i][j])
        {
            i++;
        }
    }
    cout << "Not found ";
    return 0;
}