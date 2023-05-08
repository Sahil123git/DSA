#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int inpt1, inpt2;
    cin >> inpt1 >> inpt2;

    vector<int> tree(1);
    tree[0] = 2;
    // int totTree = 0;

    for (int i = 0; i < inpt1; i++)
    {
        int val = tree[i];
        int nTree = (val + 1) % inpt2;

        
        tree.erase(tree.begin());
        // cout << nTree << " val" << endl;
        for (int j = 0; j < nTree; j++)
        {
            tree.push_back(j);
        }

        // totTree += nTree;
        // tree[i] = nTree;
    }
    cout << tree.size();
}