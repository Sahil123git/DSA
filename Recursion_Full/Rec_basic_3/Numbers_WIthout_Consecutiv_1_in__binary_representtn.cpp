#include <iostream>
using namespace std;
int count_conseq(int n)
{
    if (n == 1)
    {
        return 2;
    }
    else if (n == 2)
    {
        return 3;
    }
    return count_conseq(n - 1) + count_conseq(n - 2);
}
int main()
{
    int n;
    cin >> n;
    cout << count_conseq(n);
    return 0;
}