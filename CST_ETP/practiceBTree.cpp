#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val;
    Node *left, *right;
    Node(int d)
    {
        val = d;
        left = right = NULL;
    }
};
Node *addNode(Node *root, int val, queue<Node *> &qu)
{
    Node *node = new Node(val);

    if (root == NULL)
    {
        root = node;
        qu.push(node);
    }
    else if (qu.front()->left == NULL)
    {
        qu.front()->left = node;
        if (val != -1)
        {
            qu.push(node);
        }
    }
    else
    {
        if (val != -1)
        {
            qu.front()->right = node;
            qu.push(node);
        }
        qu.pop();
    }

    return root;
}
Node *MakeTree(vector<int> &vc, int n)
{
    queue<Node *> qu;
    Node *root = NULL;

    for (int i = 0; i < n; i++)
    {
        root = addNode(root, vc[i], qu);
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
            cout << qu.front()->val << " ";

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

    Node *root = MakeTree(vc, n);

    levelOrder(root);
}