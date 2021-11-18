#include <bits/stdc++.h>
using namespace std;

#define maxx(a, b) (a > b ? a : b)
#define Fo1(num) for (int i = 0; i < num - 2; i++)
#define ct(num) cout << #num
#define ct_v1(num) cout << num
#define cn_1(num1) cin >> num1
#define ev_od(num1) (num1 % 2 == 0 ? 1 : 0)
#define cn_2(num1, num2) cin >> num1 >> num2
#define cn_3(num1, num2, num3) cin >> num1 >> num2 >> num3

int hex_to_dec(string str)
{
    int len = str.length();
    int x = 1, output = 0;
    for (int i = len - 1; i >= 0; i--)
    {
        if (str[i] >= '0' && str[i] <= '9') //subtraction or addition occur in ascii number or any number but not in character
        {
            output += x * (str[i] - '0'); //str[i] ascii number will get subtracted with  0(0 ASII is 48)
        }
        else if (str[i] >= 'A' && str[i] <= 'F')
        {
            output += x * (str[i] - 'A' + 10); //subtracting 'A'(ASII code) to get (1 or 2 or 3) and then adding 10 to that
        }
        else if (str[i] >= 'a' && str[i] <= 'f')
        {
            output += x * (str[i] - 'a' + 10); //adding 10 to character ascii value so that after subtracting it 
        }                                      //will return its original value a=10,b=11,c=12,d=13....
        x *= 16;
    }
    return output;
}
int main()
{
    string num;
    getline(cin, num);
    // num = "1AF";
    ct_v1(hex_to_dec(num)); //passing string num
    return 0;
}