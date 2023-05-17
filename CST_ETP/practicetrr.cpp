#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int node;
    Node *left, *right;
    Node(int data)
    {
        this->node = data;
        left = right = NULL;
    }
};
Node *addNodes(int val, Node *root, queue<Node *> &qu)
{
    if (root == NULL)
    {
        root = new Node(val);
        qu.push(root);
    }
    else if (qu.front()->left == NULL)
    {
        // cout << val << " add " << endl;
        qu.front()->left = new Node(val);
        if (val != -1)
        {
            qu.push(qu.front()->left);
        }
    }
    else
    {
        // cout << val << " right " << endl;
        if (val != -1)
        {
            qu.front()->right = new Node(val);
            qu.push(qu.front()->right);
        }
        qu.pop();
    }

    return root;
}
Node *MakeTree(vector<int> &vc)
{
    Node *root = NULL;
    queue<Node *> qu;
    for (int i = 0; i < vc.size(); i++)
    {
        // cout << vc[i] << " ";
        root = addNodes(vc[i], root, qu);
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
            if (qu.front()->left != NULL && qu.front()->left->node != -1)
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
    Node *root = MakeTree(vc);

    levelOrder(root);
}