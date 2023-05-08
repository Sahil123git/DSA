#include <bits/stdc++.h>
using namespace std;
#define ll long long

int reverseNum(int n)
{
    int num = n, rev = 0, rem;
    while (num > 0)
    {
        rem = num % 10;
        num = num / 10;
        rev = rev * 10 + rem;
    }
    return rev;
}
bool isPalindrome(int num)
{
    ll num1 = num;
    ll num2 = reverseNum(num);
    if (num1 == num2)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void preArr(vector<int> &vec, vector<int> &vc)
{
    if (isPalindrome(vec[0]))
    {
        // cout << vc[0] << endl;
        vc[0] = 1;
        // cout << "ehr";
    }
    for (int i = 1; i < vc.size(); i++)
    {
        int sum = vc[i - 1];
        if (isPalindrome(vec[i]))
        {
            sum++;
        }
        vc[i] = sum;
    }
}
int main()
{
    int n;
    cin >> n;
    vector<int> vc(n);
    for (int i = 0; i < n; i++)
    {
        int ele;
        cin >> ele;
        vc[i] = ele;
    }
    vector<int> pr(n);
    preArr(vc, pr);

    // for (auto it : pr)
    // {
    //     cout << it << " ";
    // }
    // cout << endl;
    int t;
    cin >> t;
    while (t--)
    {
        int fst, scnd;
        cin >> fst >> scnd;

        fst -= 1;
        scnd -= 1;

        if (fst == 0)
        {
            cout << pr[scnd] << endl;
            continue;
        }
        cout << pr[scnd] - pr[fst - 1] << endl;
    }
}