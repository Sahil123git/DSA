#include <bits/stdc++.h>
using namespace std;

int fndFactors(int num) // TC:O(sqrt(N))
{
    int i = 1, cntFctr = 0;
    // cout << num << endl;
    vector<int> vc; // This vector is having all factors of num
    // in this vector we are adding divisor and quotient
    while (i * i <= num)
    {
        if (num % i == 0)
        {
            cntFctr++;
            vc.push_back(i);

            if (num / i != i) // if divisor is a factor then quotient will also be factor
            {                 // this if case when num is 16 divisor is 4, then quotient will also be 4
                cntFctr++;
                vc.push_back(num / i);
            }
        }
        i++;
    }

    for (int i = 0; i < vc.size(); i++)
    {
        cout << vc[i] << " ";
    }
    cout << endl;
    return cntFctr;
}

int main()
{
    int n;
    n = 100;
    cout << fndFactors(n);
    return 0;
}