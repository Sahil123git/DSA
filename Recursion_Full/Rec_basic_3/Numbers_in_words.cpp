#include <iostream>
using namespace std;
char arr[][10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten"};
void print_in_word(int n)
{
    if (n == 0)
    {
        return;
    }
    print_in_word(n / 10);
    int ele = n % 10;
    cout << arr[ele] << " ";
}
int main()
{
    int n;
    cin >> n;
    print_in_word(n);
    return 0;
}