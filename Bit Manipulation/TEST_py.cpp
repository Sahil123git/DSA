#include <iostream> //Time taken: 6min for writing and thinking
#include <algorithm>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    reverse(arr, arr + n);
    int x = 0, y = 0;

    for (int i = 1; i < n; i = i + 2)//doing the operation on the even index numbers
    {
        arr[i] *= 2;
        if (arr[i] > 9)
        {
            arr[i] -= 9;
        }
        x += arr[i];
    }
    for (int i = 0; i < n; i += 2)//collecting sum of all odd index ele
    {
        y += arr[i];
    }
    if (((x + y) % 10) == 0)
    {
        cout << "Card is valid";
    }
    else
    {
        cout << "card is not valid";
    }
    return 0;
}