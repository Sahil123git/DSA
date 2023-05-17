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
    bool isCousins(TreeNode *root, int x, int y)
    {
        TreeNode *par1 = NULL, *par2 = NULL;
        bool found1 = 0, found2 = 0;
        queue<pair<TreeNode *, TreeNode *>> qu;

        qu.push({root, NULL});

        while (!qu.empty())
        {
            int sz = qu.size();

            for (int i = 0; i < sz; i++)
            {
                TreeNode *node = qu.front().first;

                if (node->val == x)
                {
                    found1 = 1;
                    par1 = qu.front().second;
                }
                if (node->val == y)
                {
                    found2 = 1;
                    par2 = qu.front().second;
                }

                if (node->left != NULL)
                {
                    qu.push({node->left, node});
                }
                if (node->right != NULL)
                {
                    qu.push({node->right, node});
                }

                qu.pop();
            }

            if (found1 == 1 && found2 == 1)
            {
                if (par1 != par2)
                {
                    return 1;
                }
            }
            found1 = 0;
            found2 = 0;
            par1 = par2 = NULL;
        }

        return 0;
    }
};