#include <bits/stdc++.h>
using namespace std;

// Fuction to rotate array
void LrotateArr(int arr[], int d, int n) // L rotate
{
    // code here
    d = d % n;
    for (int i = 0; i < d / 2; i++)
    {
        swap(arr[i], arr[d - i - 1]);
    }

    int z = 0, rem = n - d;
    for (int i = d; z < rem / 2; i++)
    {
        swap(arr[i], arr[n - z - 1]);
        z++;
    }

    for (int i = 0; i < n / 2; i++)
    {
        swap(arr[i], arr[n - 1 - i]);
    }
}
void RrotateArr(int arr[], int d, int n) // L rotate
{
    // code here
    d = d % n;
    int z = 0, rem = (n - d) / 2;
    cout << rem << endl;
    for (int i = 0; i < rem; i++)
    {
        swap(arr[i], arr[(n - d) - i - 1]);
    }

    for (int i = (n - d); z < d / 2; i++)
    {
        swap(arr[i], arr[n - z - 1]);
        z++;
    }

    for (int i = 0; i < n / 2; i++)
    {
        swap(arr[i], arr[n - 1 - i]);
    }
}
// Function to print elements of array
void PrintTheArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

// Driver code
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int N = sizeof(arr) / sizeof(arr[0]);
    int d = 3;

    // Function calling
    // LrotateArr(arr, d, N);
    RrotateArr(arr, d, N);
    PrintTheArray(arr, N);

    return 0;
}
