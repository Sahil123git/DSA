#include <iostream>
#include <queue>
using namespace std;
class Node
{
public:
    int data;
    Node *right, *left;
    Node(int data)
    {
        this->data = data;
        right = NULL;
        left = NULL;
    }
};
Node *build_tree()
{
    int ele;
    cin >> ele;
    if (ele == -1)
    {
        return NULL;
    }
    Node *root = new Node(ele);
    root->left = build_tree();
    root->right = build_tree();

    return root;
}

void lvl_order_nline(Node *root)
{
    queue<Node *> qu;
    qu.push(root);
    qu.push(NULL);
    while (!qu.empty())
    {
        if (qu.front() == NULL)
        {
            cout << endl;
            qu.pop();

            if (!qu.empty())
            {
                qu.push(NULL);
            }
        }
        else
        {
            Node *fn = qu.front();
            cout << fn->data << " ";
            qu.pop();
            if (fn->left != NULL)
            {
                qu.push(fn->left);
            }
            if (fn->right != NULL)
            {
                qu.push(fn->right);
            }
        }
    }
}

int main()
{
    Node *root = build_tree();
    lvl_order_nline(root);

    return 0;
}