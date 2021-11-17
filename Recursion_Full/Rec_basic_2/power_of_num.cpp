#include <iostream> //bottom to top approach
using namespace std;
int fnd_pwr(int num, int pwr)
{
    if (pwr == 0)
    {
        return 1;
    }

    num = fnd_pwr(num, pwr - 1) * num;
    // cout << num << endl;
    return num;
}
int main()
{
    int num, pow;
    cin >> num >> pow;
    cout << fnd_pwr(num, pow);
    return 0;
}