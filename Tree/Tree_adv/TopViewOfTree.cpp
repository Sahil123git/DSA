class Solution
{
public:
    // Concpt striver video
    // can be done using queue also to fill map both can be used (queue cncpt is used by striver)
    void fillUmp(TreeNode *root, map<int, int> &ump, int x)
    { // this will make map acc to coordinates
        if (root == NULL)
        { // base case
            return;
        }
        if (ump.find(x) == ump.end())
        {
            ump[x] = (root->val); // at this coordinate insert this val
        }

        fillUmp(root->left, ump, x - 1);  // going left side
        fillUmp(root->right, ump, x + 1); // goidng right side
    }

    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        map<int, int> ump; // using multiset becoz at ump[0][2] can have more than one value so in this case we need sorted val so use set but there can be duplicates also so use multiset
        vector<int> res;
        fillUmp(root, ump, 0); // strtng from (0,0) node

        for (auto it : ump)
        {
            res.push_back(it.second);
        }
        return {res, {0}};
    }
};