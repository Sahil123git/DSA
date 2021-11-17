#include <iostream>  //time comp O[n]
using namespace std; //space comp O[n]
int fibo(int n)
{
    if (n == 0 || n == 1)
    {
        return n;
    }
    return fibo(n - 1) + fibo(n - 2);
}
int main()
{
    int n;
    cin >> n;
    cout << fibo(n);
    return 0;
}