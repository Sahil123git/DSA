#include <iostream>
#include <vector>
using namespace std;
bool min_heap = 1;
bool compare(int ele1, int ele2)
{
    if (min_heap)
    {
        return ele1 < ele2;
    }
    else
    {
        return ele1 > ele2;
    }
}

void heapify(vector<int> &vt, int Par_ind) //MIN_HEAP
{
    int L_chld_ind = Par_ind * 2;
    int R_chld_ind = L_chld_ind + 1;
    int min_ind = Par_ind, last_ind = vt.size() - 1;

    if ((L_chld_ind <= last_ind) && compare(vt[L_chld_ind], vt[Par_ind]))
    {
        min_ind = L_chld_ind;
    }

    if ((R_chld_ind <= last_ind) && compare(vt[R_chld_ind], vt[min_ind]))
    {
        min_ind = R_chld_ind;
    }

    if (min_ind != Par_ind)
    {
        swap(vt[min_ind], vt[Par_ind]);
        heapify(vt, min_ind); //after fixing this lvl, using recursion we will fix below lvls
    }
}
void build_heap_opt(vector<int> &vt) //in this we are comparing parent with its 2 children
{
    for (int i = ((vt.size()-1) / 2); i > 0; i--)
    {
        heapify(vt, i); //here we are going from down to up
    }
}
int main()
{
    int n;
    cin >> n;
    min_heap = 0;
    vector<int> vt;
    vt.push_back(-1);
    for (int i = 1; i <= n; i++)
    {
        int ele;
        cin >> ele;
        vt.push_back(ele);
    }

    build_heap_opt(vt); //O(n)
    for (int i = 1; i < vt.size(); i++)
    {
        cout << vt[i] << " ";
    }
}