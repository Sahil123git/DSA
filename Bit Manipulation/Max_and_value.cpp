#include <iostream>
using namespace std;
int chk_bit(int mask, int arr[], int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if ((mask & arr[i]) == mask)
        {
            count++;
        }
        // cout<<arr[i]<<" "<<mask<<endl;
    }
    return count;
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
    int ans_max = 0;
    for (int bit = 16; bit >= 0; bit--)
    {
        int count = chk_bit(ans_max | (1 << bit), arr, n);
        if (count >= 2)
        {
            ans_max = (ans_max | (1 << bit));
        }
    }
    cout << ans_max;
    return 0;
}