#include <iostream> //link: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
#include <vector>
#include <unordered_map>
using namespace std;
class TreeNode
{
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int d)
    {
        val = d;
        right = left = NULL;
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
    TreeNode *root = new TreeNode(ele);
    root->left = build_tree();
    root->right = build_tree();

    return root;
}

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    unordered_map<int, int> mp;

    for (int i = 0; i < preorder.size(); i++)
    {
        mp[inorder[i]] = i;
    }
    TreeNode *root = bt(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, mp);
    return root;
}

TreeNode *bt(vector<int> &pre, int p_st, int p_end, vector<int> &inor, int in_st, int in_end, unordered_map<int, int> &ump)
{
    if (p_st > p_end || in_st > in_end)
    {
        return NULL;
    }
    TreeNode *root = new TreeNode(pre[p_st]);
    int in_root = ump[root->val]; //saving address of inorder ele
    int left_ele = in_root - in_st;

    root->left = bt(pre, p_st + 1, p_st + left_ele, inor, in_st, in_st + in_root - 1, ump);
    root->right = bt(pre, p_st + left_ele + 1, p_end, inor, in_root + 1, in_end, ump);

    return root;
}