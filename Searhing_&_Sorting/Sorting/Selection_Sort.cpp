#include <iostream>
using namespace std;
void Selection_sort(int arr[], int n)
{
    int min_Ind;
    for (int i = 0; i < n - 1; i++)
    {
        min_Ind = i;
        for (int j = i; j < n; j++)
        {
            if (arr[min_Ind] > arr[j]) //change this sign to less than for rev sorting
            {
                min_Ind = j;
            }
        }
        swap(arr[i], arr[min_Ind]);
        // for (int i = 0; i < n; i++)//for checking how it is working
        // {
        //     cout << arr[i] << " ";
        // }
        // cout << endl;
    }
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
    Selection_sort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}