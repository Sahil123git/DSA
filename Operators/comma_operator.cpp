#include <stdio.h>
int main()
{
    int a = 5;
    a = 1, 2, 3;
    printf("%d ", a);

    int b = 3;
    b = (1, 2, 3);
    printf(" %d", b);
    return 0;
}