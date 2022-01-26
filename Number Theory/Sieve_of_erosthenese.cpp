#include <iostream>
using namespace std;
int arr[100000];
void fnd_sieve(int n)
{
    for (int i = 3; i < n; i += 2) // marking all odds as 1, except 2 all even can't be prime number
    {
        arr[i] = 1;
    }

    for (int i = 3; i < n; i += 2) // marking all multiple of i as 0
    {
        if (arr[i] == 1)
        {
            // initailly j will be i*i because smaller ele will get marked by smaller value of i
            for (int j = i * i; j < n; j += i) // iterating with speed of i
            {
                arr[j] = 0;
            }
        }
    }
    arr[2] = 1;          // becoz 2 is prime
    arr[0] = arr[1] = 0; // because 0 and 1 is not prime
}

int main()
{
    int n;
    cin >> n;
    fnd_sieve(n);
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 1)
        {
            cout << i << " ";
        }
    }
    return 0;
}