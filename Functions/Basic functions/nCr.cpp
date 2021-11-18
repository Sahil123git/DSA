#include <iostream>
using namespace std;

int fact(int num);
int main()
{
    int n, r, nCr;
    cin >> n >> r;
    nCr = (fact(n)) / (fact(r) * fact(n - r));
    cout << nCr;
}
int fact(int num)
{
    int fact = 1;
    for (int i = 1; i <= num; i++)
    {
        fact = fact * i;
    }
    return fact;
}