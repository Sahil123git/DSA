#include <iostream> //https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/
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
TreeNode *bstFromPreorder(vector<int> &preorder)
{
    TreeNode *Tree = new TreeNode(preorder[0]);
    int iter = 1;
    TreeNode *ptr = Tree;
    while (iter < preorder.size())
    {
        TreeNode *ele = new TreeNode(preorder[iter]);
        ptr = insert_ele(ptr, ele); //function call
        iter += 1;                  //this ptr which we will get from insert_ele fun will remain root node
    }
    return Tree;
}
TreeNode *insert_ele(TreeNode *root, TreeNode *ele)
{
    if (root == NULL)
    {
        return ele;
    }
    else if (ele->val > root->val)
    {
        root->right = insert_ele(root->right, ele);
    }
    else
    {
        root->left = insert_ele(root->left, ele);
    }
    return root;
}