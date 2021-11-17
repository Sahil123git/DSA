#include <iostream>
#include <numeric>
#include <vector>
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
    int count_ele = count(arr, arr + n, 2); //count the freq of 2
    cout << "freq of the ele is " << count_ele << endl;

    int *find_ele = find(arr, arr + n, 2);
    if (find_ele != arr + n) //if ele is not in the array then it will give index equal arr+n
    {
        cout << "found at " << find_ele - arr; //to find the index of that ele
    }
    else
    {
        cout << "Not found";
    }
    return 0;
}