/*Find missing in a array where there are num (<= N)

BruteForce:
  run O(n^2) to chck every num is present or not

Opt (sorting)
  after sorting chk

Mathematical Formula Approach  O(N)
Sum of 1st n natural nums subtract from sum of gvn arr sum

XOR
 First take XOR of 1st n num then take XOR of gvn arr
 then take XOR of both gvn Arr XOR and n natural num XOR


*/
int app(vector<int> vc, int n)
{
    int tot = 1;
    for (int i = 2; i <= n + 1; i++)
    {
        tot = tot + i;
        tot = tot - a[i - 2];
    }

    return tot;
}
int main()
{
    vector<int> vc{3, 1, 2, 6, 4};
    int n = vc.size();

    cout << app(vc, n);
}