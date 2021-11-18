#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int arr[n], res_xor = 0;
    for (int i = 0; i < n; i++)
    {
        int ele;
        cin >> ele;
        arr[i] = ele;
        res_xor = res_xor ^ ele; //this will give xor of 2 unique numbers
    }
    int temp = res_xor, pos = 0;
    while ((temp & 1) == 0) //finding for 1st set bit posn
    {
        pos++;
        temp = temp >> 1;
    }
    int num = (1 << pos); //now fixing num acc to first set bit
    int x = 0, y = 0;
    for (int i = 0; i < n; i++)
    {
        if ((num & arr[i]) > 0)
        {
            x = x ^ arr[i];
        }
    }
    y = x ^ res_xor; //to get the second unique number

    cout << x << " " << y;
    return 0;
}