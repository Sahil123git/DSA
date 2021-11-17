#include <iostream>
#include <algorithm>
#include <ctime>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int arr[n];
    srand(time(NULL)); //this will not let the rand num to repeat
    for (int i = 0; i < n; i++)
    {
        arr[i] = (rand() % 10);
    }
    sort(arr, arr + n);
    int *ptr = lower_bound(arr, arr + n, 2);
    cout << *ptr << " lower bound" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}