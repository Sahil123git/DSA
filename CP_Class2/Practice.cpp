#include <iostream>
#include <vector>
using namespace std;

int fndRotatedSortedArr(vector<int> &vc, int key)
{
    int st = 0, end = vc.size() - 1;
    while (st <= end)
    {
        int mid = st + (end - st) / 2;

        if (vc[mid] == key)
        {
            return mid;
        }
        else if (vc[st] <= vc[mid])
        {
            if (key >= vc[st] && key < vc[mid])
            {
                end = mid - 1;
            }
            else
            {
                st = mid + 1;
            }
        }
        else
        {
            if (key > vc[mid] && key <= vc[end])
            {
                st = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
    }
    return -1;
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

    int fndEle;
    cin >> fndEle;

    cout << fndRotatedSortedArr(vc, fndEle);
}