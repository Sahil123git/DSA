#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    sort(arr, arr + 4);
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    if (binary_search(arr, arr + 5, 5))
    {
        cout << "present";
    }
    else
    {
        cout << "not present";
    }
    return 0;
}