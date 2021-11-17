#include <iostream>
using namespace std;
class TreeNode
{
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int data)
    {
        this->val = data;
    }
};
TreeNode *build_tree()
{
    int ele;
    cin >> ele;
    if (ele == -1)
    {
        return NULL;
    }
    TreeNode *temp = new TreeNode(ele);
    temp->left = build_tree();
    temp->right = build_tree();

    return temp;
}
void right_view_tree(TreeNode *root, int lvl, int &max_lvl)
{
    if (root == NULL)
    {
        return;
    }
    if (max_lvl < lvl)
    {
        // cout << root->val << " " << max_lvl << " " << lvl << endl;
        cout << root->val << " ";
        max_lvl = lvl;
    }
    right_view_tree(root->right, lvl + 1, max_lvl);
    right_view_tree(root->left, lvl + 1, max_lvl);
}

int main()
{
    TreeNode *node = build_tree();
    int max_lvl = -1;
    right_view_tree(node, 0, max_lvl);
    return 0;
}