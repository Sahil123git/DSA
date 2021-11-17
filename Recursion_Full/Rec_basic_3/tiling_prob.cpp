#include <iostream> //length or height of every tile is 4
using namespace std;
int tiling_pr(int n)
{
    if (n <= 3)
    {
        return 1;
    }
    return tiling_pr(n - 1) + tiling_pr(n - 4);
}
int main()
{
    int n;
    cin >> n;
    cout << tiling_pr(n);
    return 0;
}