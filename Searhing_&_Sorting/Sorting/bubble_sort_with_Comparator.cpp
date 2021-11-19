#include <iostream>
#include <algorithm>
using namespace std;

bool comparator(int a, int b)
{
    return a < b; //if this is true then only swap will occur
}
void sort(int arr[], int n, bool (&comp)(int a, int b))
{
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            if (comp(arr[j], arr[j + 1])) //this will 1st go to (&comp) then
            {                             //from there to comparator
                swap(arr[j], arr[j + 1]);
                cout << "swapped" << j << endl;
            }
        }
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
    sort(arr, n, comparator);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}