#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *right, *left;
    Node(int d)
    {
        data = d;
        right = left = NULL;
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
int count_nodes(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return 1 + count_nodes(root->left) + count_nodes(root->right);
}

int sum_all_nodes(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    return root->data + sum_all_nodes(root->left) + sum_all_nodes(root->right);
}
int main()
{
    Node *root = build_tree();

    cout << count_nodes(root) << " ";
    cout << sum_all_nodes(root);
}