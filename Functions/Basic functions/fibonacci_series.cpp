#include <iostream>
using namespace std;
void fib(int);

int main()
{
    int n;
    cin >> n;
    fib(n);
    return 0;
}
void fib(int num)
{
    int term_1 = 0, term_2 = 1, sum;
    cout << term_1 << " " << term_2 << " ";
    for (int i = 0; i < num; i++)
    {
        sum = (term_1 + term_2);
        cout << (sum) << " ";
        term_1 = term_2;
        term_2 = sum;
    }
    // return;
}