#include <bits/stdc++.h>
using namespace std;
void dec_to_hex(int num);
int main()
{
    int num;
    cin >> num;
    // num = 2545;
    // string str;
    dec_to_hex(num);
    return 0;
}
void dec_to_hex(int num)
{
    int rem, i;
    string str[12];
    for (i = 0; num != 0; i++)
    {
        rem = num % 16;
        if (rem < 10)
        {
            str[i] = rem + 48; //for (rem = 1) first add (48 + 1) that is 49. 49 corresponds to 2
        }                      //it is string array so it will correseponds to the ascii value(take character value only)
        else
        {
            str[i] = rem + 55; //if we will add no' greater than 9 with 55 it will give correspoding ascii value. String take these as ascii number and will write that's number ascii value.
        }
        num = num / 16;
    }
    for (int j = i - 1; j >= 0; j--)
    {
        cout << str[j];
    }
}