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
    int res = 0;
    void findSum(TreeNode *root, int sum)
    {
        if (root == NULL)
            return;
        if (root->left == NULL && root->right == NULL)
        {
            res += ((sum * 10) + root->val);
            return;
        }

        findSum(root->left, sum * 10 + root->val);
        findSum(root->right, sum * 10 + root->val);
    }

    int sumNumbers(TreeNode *root)
    {
        int sum = 0;
        findSum(root, sum);

        return res;
    }
};