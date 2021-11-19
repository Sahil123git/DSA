#include <iostream>  //best case TC is O(n)
using namespace std; //worst case TC is O(n^2)
void Bubble_sort(int arr[], int n)
{
    for (int i = 1; i < n; i++) //starting from so we can subract the last ele gradually
    {
        bool swapped;
        for (int j = 0; j < n - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (swapped == false) //now for best case it will become O(n)
        {
            cout << "already sorted" << endl;
            break;
        }
        for (int i = 0; i < n; i++) //for checking how it is working
        {
            cout << arr[i] << " ";
        }
        cout << endl;
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
    Bubble_sort(arr, n);
    cout << "After Sorting " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
//DRY RUN
/*5 4 3 2 1
  4 5 3 2 1
  4 3 5 2 1
  4 3 2 5 1
  4 3 2 1 5

  3 4 2 1 5
  3 2 4 1 5
  3 2 1 4 5

  2 3 1 4 5
  2 1 3 4 5
  
  1 2 3 4 5 */