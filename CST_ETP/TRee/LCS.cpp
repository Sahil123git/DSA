/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (p == root || q == root)
            return root;

        TreeNode *lft = NULL, *rght = NULL;
        if (root->left != NULL)
            lft = lowestCommonAncestor(root->left, p, q);
        if (root->right != NULL)
            rght = lowestCommonAncestor(root->right, p, q);

        if (lft != NULL && rght != NULL)
            return root; // if both are not NULL
        else if (lft != NULL)
            return lft; // if one of them is not NULL
        else if (rght != NULL)
            return rght; // same as above
        // if(lft == NULL && rght == NULL) return NULL;
        else
            return NULL; // if both are NULL
    }
};