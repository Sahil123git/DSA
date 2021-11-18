#include <iostream>
using namespace std;
int count_set(int n)
{
    int count = 0;
    while (n > 0)
    {
        int chk_l;
        auto chk = [](int &chk_l, int &n)
        { return (n & 1); }; //lambda function

        bool chkng = chk(chk_l, n); //calling lambda function
        if (chkng)
        {
            count += 1;
        }
        n = n >> 1; //removing the first bit
    }
    return count;
}

int count_set_fast(int n)
{
    int count = 0;
    while (n > 0)
    {
        n = n & (n - 1);
        count++;
    }
    return count;
}
int main()
{
    int n;
    cin >> n;
    cout << count_set(n) << " ";
    cout << count_set_fast(n) << " ";
    cout << __builtin_popcount(n);
    return 0;
}