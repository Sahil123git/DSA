#include <iostream>
#include <vector>
using namespace std; //acc to MAX_HEAP

void heapify(vector<int> &vt, int i, int sz)
{
    int l_chld_ind = i * 2;
    int r_chld_ind = l_chld_ind + 1;
    int min_ind = i, last = sz;

    if (l_chld_ind <= last && vt[l_chld_ind] > vt[i]) //acc to max heap condition
    {
        min_ind = l_chld_ind;
    }
    if (r_chld_ind <= last && vt[r_chld_ind] > vt[min_ind])
    {
        min_ind = r_chld_ind;
    }
    if (min_ind != i)
    {
        swap(vt[min_ind], vt[i]);
        heapify(vt, min_ind, sz);
    }
}
void implace_sort(vector<int> &vt)
{
    for (int i = (vt.size() - 1) / 2; i >= 1; i--)
    {
        heapify(vt, i, (vt.size() - 1));
    }
    int n = vt.size() - 1;
    while (n > 1)
    {
        swap(vt[1], vt[n]);
        n--;
        heapify(vt, 1, n);

        // cout << endl;
        // for (int i = 1; i < vt.size(); i++)
        // {
        //     cout << vt[i] << " ";
        // }
        // cout << endl;
    }
}
int main()
{
    int n;
    cin >> n;

    vector<int> vt;
    vt.push_back(-1);
    for (int i = 0; i < n; i++)
    {
        int ele;
        cin >> ele;
        vt.push_back(ele);
    }
    implace_sort(vt);
    for (int i = 1; i < vt.size(); i++)
    {
        cout << vt[i] << " ";
    }
    cout << endl;
}