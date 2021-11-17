#include <iostream>
#include <cstring>
using namespace std;
int str_to_int(char ch[], int n)
{
    if (n == 0)
    {
        return 0;
    }
    int output = str_to_int(ch, n - 1);
    // output *= 10;
    // cout << output << " "; //to chk how it is working
    int ele;
    ele = int(ch[n - 1] - '0');
    return ele + (output * 10);
}
int main()
{
    char ch[10];
    cin >> ch;
    int len = strlen(ch);
    // cosut << len << " ";
    cout << str_to_int(ch, len);
    return 0;
}