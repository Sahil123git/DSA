/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    // Just keep this thing in mind You have to do INORDER Traversal

    void findError(TreeNode *root, TreeNode *&prev, TreeNode *&fst, TreeNode *&scnd)
    {
        if (root == NULL)
        {
            return;
        }
        findError(root->left, prev, fst, scnd);

        if (prev->val != INT_MIN && fst == NULL && prev->val > root->val)
        {
            // cout << "here  " << root->val << endl;
            fst = prev;
            scnd = root;
            // cout << prev->val << " " << root->val << " " << fst->val << endl;
        }
        else if (prev->val != -1 && root->val < prev->val)
        {
            // cout << "then here" << " " << root->val << endl;
            scnd = root;
        }
        prev = root;

        findError(root->right, prev, fst, scnd);
    }

    void recoverTree(TreeNode *root)
    {
        TreeNode *fst = NULL, *scnd = NULL;
        TreeNode *prev = new TreeNode(INT_MIN);

        findError(root, prev, fst, scnd);
        cout << fst->val << " " << scnd->val << endl;
        swap(fst->val, scnd->val);
    }
};