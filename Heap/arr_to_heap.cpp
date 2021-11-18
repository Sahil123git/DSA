#include <iostream>
#include <vector>
using namespace std;
void build_heap(vector<int> &vt) //max heap O(N logN)
{
    for (int i = 2; i < vt.size(); i++) //in this we are comparing childrens with their parent
    {
        int chld = i, parent = chld / 2;
        while (chld > 2 && vt[chld] > vt[parent]) //if found any wrongly placed ele in heap then have to go all the way to up.
        {
            swap(vt[chld], vt[parent]);
            chld = parent;
            parent = parent / 2;
        }
    }
}
int main()
{
    vector<int> vt;
    int n;
    cin >> n;
    vt.push_back(-1);
    for (int i = 1; i <= n; i++)
    {
        int ele;
        cin >> ele;
        vt.push_back(ele);
    }
    build_heap(vt);
    for (int i = 1; i < vt.size(); i++)
    {
        cout << vt[i] << " ";
    }
}