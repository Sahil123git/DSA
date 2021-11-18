#include <iostream>
using namespace std;
int main()
{
    char arr[100][100];
    int n;
    cin >> n;
    cin.get(); //use this it will take the extra the enter after the n that we use to go to next line
    for (int i = 0; i < n; i++)
    {
        cin.getline(arr[i], 100);
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}