#include <iostream>
#include <iostream>
#include <algorithm>
using namespace std;
bool comp(int a, int b)
{
    if (a < b) //now the sorting is depended on this
    {
        return 1;
    }
    return 0;
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

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (comp(arr[i], arr[j]))
            {
                swap(arr[i], arr[j]);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}