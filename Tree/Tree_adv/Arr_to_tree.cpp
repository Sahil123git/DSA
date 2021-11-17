#include <iostream>
#include <vector>
using namespace std;
class TreeNode
{
public:
    int data;
    TreeNode *left, *right;
    TreeNode(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};
TreeNode *make_bst(vector<int> vt, int st, int en)
{
    if (st > en)
    {
        return NULL;
    }
    int mid = (st + en) / 2;
    TreeNode *root = new TreeNode(vt[mid]);

    root->left = make_bst(vt, st, mid - 1);
    root->right = make_bst(vt, mid + 1, en);
    return root;
}
TreeNode *sortedArrayToBST(vector<int> &nums)
{
    TreeNode *root = make_bst(nums, 0, nums.size() - 1);
    return root;
}
void print_preorder(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    print_preorder(root->left);
    print_preorder(root->right);
}
int main()
{
    int n;
    cin >> n;
    vector<int> vt;
    for (int i = 0; i < n; i++)
    {
        int ele;
        cin >> ele;
        vt.push_back(ele);
    }
    TreeNode *root = sortedArrayToBST(vt);
    print_preorder(root);
    return 0;
}