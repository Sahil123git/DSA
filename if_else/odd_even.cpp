#include <iostream>
using namespace std;
int main()
{
    int num;
    scanf("%d", &num);
    if (num % 2 == 0)
    {
        cout << "Even";
    }
    else
    {
        cout << "Odd";
    }
    return 0;
}