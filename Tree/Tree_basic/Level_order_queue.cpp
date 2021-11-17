#include <iostream>
#include <queue>
using namespace std;
class Node
{
public:
    int data;
    Node *left, *right;
    Node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

Node *build_tr()
{
    int ele;
    cin >> ele;
    if (ele == -1)
    {
        return NULL;
    }
    Node *root = new Node(ele);
    root->left = build_tr();
    root->right = build_tr();
    return root;
}

void lvl_order_bfs(Node *root) //lvl order using queueu in O(n)
{
    queue<Node *> qu;
    qu.push(root);
    while (!qu.empty())
    {
        Node *fn = qu.front();
        qu.pop();
        cout << fn->data << " ";
        if (fn->left)
        {
            qu.push(fn->left);
        }
        if (fn->right)
        {
            qu.push(fn->right);
        }
    }
}
int main()
{
    Node *lvl_bu = build_tr();
    lvl_order_bfs(lvl_bu);
    return 0;
}//1 2 -1 7 -1 -1 3 5 -1 -1 -1