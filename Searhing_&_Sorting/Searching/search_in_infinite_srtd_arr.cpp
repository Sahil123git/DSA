#include <iostream>
using namespace std;

int Inf_Bin_sea(int st, int en, int key, int arr[])
{
    int low, high;
    low = st;
    high = en;
    while (high >= low)
    {
        int mid = (low + (high - low) / 2);
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] < key)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
            // cout << arr[mid] << " ";
        }
    }
    return -1;
}
int fnd_st_en(int key, int arr[])//for finding the last ind
{
    int st = 0, en = 1;
    while (arr[en] < key)
    {
        int temp = en + 1;
        en = en + (en - st + 1) * 2;
        st = temp;
    }
    // cout << arr[en] << " " << en << endl;
    return Inf_Bin_sea(st, en, key, arr);
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
    int key;
    cin >> key;
    cout << fnd_st_en(key, arr);
}