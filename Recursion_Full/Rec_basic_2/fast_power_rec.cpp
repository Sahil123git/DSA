#include <iostream> //Time Complexity ---> O[log n]
using namespace std;
int fst_pwr(int n, int pow)
{
    if (pow == 0)
    {
        return 1;
    }

    int prd_val = fst_pwr(n, pow / 2);
    prd_val = prd_val * prd_val;
    if (pow % 2 != 0)
    {
        return (prd_val * n);
    }
    return prd_val;
}
int main()
{
    int n, pow;
    cin >> n >> pow;
    cout << fst_pwr(n, pow);
    return 0;
}