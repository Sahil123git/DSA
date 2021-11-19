#include <iostream>
#include <algorithm>
using namespace std;

bool comparator(int a, int b)
{
    int rem, count = 0;
    while (a != 0)
    {
        rem = a % 10;
        a = a / 10;
        count++;
    }
    int rem1, count1 = 0;
    while (b != 0)
    {
        rem1 = b % 10;
        b = b / 10;
        count1++;
    }
    // cout << a << " " << b << endl;
    return count < count1; //if this is true then only swap will occur
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
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
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
}