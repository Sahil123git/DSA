#include <iostream>
#include <numeric>
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
    int maxi, mini;
    maxi = *max_element(arr, arr + n);     //it will start from 0
    mini = *min_element(arr + 2, arr + n); //here it will start from index 2
    cout << maxi << " " << mini << endl;

    int sum1 = accumulate(arr, arr + n, 0);     //here it will get the initial val as 0
    int sum2 = accumulate(arr + 2, arr + n, 4); //now it will add 4 also to the total sum
    cout << sum1 << " " << sum2 << endl;
    return 0;
}