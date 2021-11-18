#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int arr[66] = {0};

    for (int i = 0; i < n; i++)
    {
        int ele;
        cin >> ele;
        int ind = 0;
        while (ele > 0)
        {
            arr[ind] = arr[ind] + (ele & 1);
            ele = ele >> 1;
            ind++;
        }
    }
    int mul = 1, ans = 0;
    for (int i = 0; i < 64; i++)//for converting the arr into number
    {
        arr[i] = arr[i] % 3;
        ans += (mul * arr[i]);
        mul = mul << 1;
    }
    cout << ans;
}