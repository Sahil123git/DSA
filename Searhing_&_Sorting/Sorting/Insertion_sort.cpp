#include <iostream>
using namespace std;
void Insert(int arr[], int n)
{
    int ele;
    for (int i = 1; i < n; i++)
    {
        ele = arr[i]; //saving in ele so that we can use it
        int j = i - 1;
        while (j >= 0 && arr[j] > ele) //change the greater than sign to less than for Rev sorting
        {
            arr[j + 1] = arr[j];
            j = j - 1; //so that it will  check all last ele
        }
        arr[j + 1] = ele; //Increasing it because it will get dec from while loop
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
    Insert(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}