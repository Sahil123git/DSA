#include <bits/stdc++.h>
using namespace std;

void primeFctrFnd(int num) // sqrt(n)
{
    vector<int> pr;
    int fst = -1, end = -1;
    for (int st = 2; st * st <= num; st++) // TC: Sqrt(n)
    {
        bool condition = 1;
        while ((num % st) == 0)
        {
            if (condition == 1)
            {
                (fst == -1) ? fst = st : fst;
                end = st;
                pr.push_back(st);
                condition = 0;
            }
            num /= st;
        }
    }
    if (num >= 2) // left out prime num
    {
        // cout << n << endl;
        end = num;
        fst == -1 ? fst = num : fst;
        pr.push_back(num);
    }

    // if (num == 1)
    // {
    //     fst = 1;
    //     end = 1;
    // }
    // for (auto it : pr)
    // {
    //     cout << it << " ";
    // }

    cout << fst << " " << end << endl;
}
int main()
{
    int n;
    cin >> n;
    primeFctrFnd(n);
}