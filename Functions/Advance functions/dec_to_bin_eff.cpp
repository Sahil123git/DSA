#include <iostream>
using namespace std;
int main()
{
    int num, rem, binary = 0;
    cin >> num;
    // num=12;
    int temp = 1;
    while (num != 0)
    {
        rem = num % 2;
        num = num / 2;
        binary = binary + (rem * temp);
        temp = temp * 10;
    }
    cout << binary;
    return 0;
}
