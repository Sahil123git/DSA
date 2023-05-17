/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution
{
public:
    Node *connect(Node *root)
    {
        int i, j, k, c = 0;
        int d1, d2;
        queue<Node *> q;
        vector<int> ans;

        if (!root)
            return 0;
        q.push(root);

        while (!q.empty())
        {
            int n = q.size();

            for (i = 0; i < n; i++)
            {
                Node *curr = q.front();
                q.pop();
                if (i < n - 1)
                {
                    curr->next = q.front();
                }
                else
                {
                    curr->next = NULL;
                }
                if (curr->left)
                {
                    q.push(curr->left);
                }
                if (curr->right)
                {
                    q.push(curr->right);
                }
            }
        }
        return root;
    }
};