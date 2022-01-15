#include <stdio.h>
int main()
{
    int a = 3;
    // cout << (++a + a++ + --a) << endl;
    int b = ++a + a++ + ++a; // 4 + 3 + 4
    printf("%d", b);
    a = 3;
    // cout << b;
}