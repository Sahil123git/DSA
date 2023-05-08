#include <iostream>
#include <vector>
using namespace std;

int findFstOcc(vector<int> &vc, int fndEle)
{
    int end = vc.size() - 1, st = 0;
    while (st <= end)
    {
        int mid = st + (end - st) / 2;
        // cout << st << " " << end << " " << mid << " " << (st + end) / 2 << endl;

        if (mid == 0 && vc[mid] == fndEle || vc[mid] == fndEle && vc[mid] != vc[mid - 1])
        {
            return mid;
        }

        if (fndEle <= vc[mid])
        {
            end = mid - 1;
        }
        else
        {
            st = mid + 1;
        }
    }
    return -1;
}

int findLstOcc(vector<int> &vc, int fndEle)
{
    int end = vc.size() - 1, st = 0;
    while (st <= end)
    {
        int mid = st + (end - st) / 2;
        // cout << st << " " << end << " " << mid << " " << (st + end) / 2 << endl;

        if (mid == vc.size() - 1 && vc[mid] == fndEle || vc[mid] == fndEle && vc[mid] != vc[mid + 1])
        {
            return mid;
        }

        if (fndEle >= vc[mid])
        {
            st = mid + 1;
        }
        else
        {
            end = mid - 1;
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

    int fstOccInd = findFstOcc(vc, fndEle), lstOccInd = findLstOcc(vc, fndEle);

    cout << findFstOcc << " fst occ" << endl;
    cout << lstOccInd << " lst occ" << endl;
    cout << (lstOccInd - fstOccInd) + 1 << " is the freq of " << fndEle;
}