#include <iostream>
#include <vector>
using namespace std;
vector<int> extendedGCD(int a, int b)
{
    if (b == 0)
    {
        // returning x and y
        return {1, 0, a};
    }
    vector<int> result = extendedGCD(b, a % b);

    // bottom up way it will work when recursive call is over
    int smallx = result[0];
    int smally = result[1];
    int gcd = result[2];

    int x = smally;
    int y = smallx - (a / b) * smally;

    return {x, y, gcd};
}
int main()
{
    int a, b;
    cin >> a >> b;

    int x, y;
    // int *p = new int(2);
    // int *p = new int[3]{1, 2, 3};
    vector<int> result = extendedGCD(a, b);
    cout << result[0] << " and " << result[1] << " gcd is " << result[2] << endl;
    return 0;
}
