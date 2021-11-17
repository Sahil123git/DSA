#include <iostream>
using namespace std;
void toh(int n, char A, char B, char C)
{
    if (n == 1)
    {
        cout << n << " " << A << " to " << C << endl;
        return;
    }
    toh(n - 1, A, C, B);
    cout << n << " " << A << " to " << C << endl;
    toh(n - 1, B, A, C);
}
int main()
{
    int n;
    cin >> n; //n is number of plates in the rod
    toh(n, 'A', 'B', 'C');
}