#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int node;
    Node *right;
    Node *left;

    Node(int node)
    {
        left = NULL;
        right = NULL;

        this->node = node;
    }
};
Node *addNode(int val, Node *root)
{
    if (root == NULL)
    {
        return new Node(val);
    }
    else if (val >= root->node)
    {
        root->right = addNode(val, root->right);
    }
    else
    {
        root->left = addNode(val, root->left);
    }

    return root;
}
Node *buildBST(vector<int> &vc)
{
    Node *root = NULL;
    for (int i = 0; i < vc.size(); i++)
    {
        root = addNode(vc[i], root);
    }

    return root;
}

void levelOrder(Node *root)
{
    queue<Node *> qu;
    qu.push(root);

    while (!qu.empty())
    {
        int sz = qu.size();
        for (int i = 0; i < sz; i++)
        {
            cout << qu.front()->node << " ";

            if (qu.front()->left != NULL)
            {
                qu.push(qu.front()->left);
            }
            if (qu.front()->right != NULL)
            {
                qu.push(qu.front()->right);
            }
            qu.pop();
        }
        cout << endl;
    }
}
int main()
{
    int n;
    cin >> n;

    vector<int> vc(n);
    for (int i = 0; i < n; i++)
    {
        cin >> vc[i];
    }

    Node *root = buildBST(vc);
    levelOrder(root);
}