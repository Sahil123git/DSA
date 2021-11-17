#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *right, *left;
    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};
Node *build_bst(Node *root, int data)
{
    if (root == NULL) //this is when we are adding ele first time
    {
        return new Node(data);
    }
    else if (data <= root->data)
    {
        root->left = build_bst(root->left, data); //this root->left will become NULL when it will go to build_bst
    }
    else
    {
        root->right = build_bst(root->right, data); //this root->right will become NULL when it will go to build_bst
    }
    return root;
}
Node *build_t()
{
    int data;
    cin >> data;
    Node *node = NULL;
    while (data != -1) //to stop inserting in BST we will use this
    {
        node = build_bst(node, data);
        cin >> data;
    }
    return node;
}
bool search_bst(Node *root, int data)
{
    if (root == NULL)
    {
        return 0;
    }
    if (root->data == data)
    {
        return 1;
    }
    if (data <= root->data)
    {
        return search_bst(root->left, data);
    }
    else
    {
        return search_bst(root->right, data);
    }
}
void print_tree(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    print_tree(root->left);
    cout << root->data << " ";
    print_tree(root->right);
}
int main()
{
    Node *root;
    root = build_t();
    if (search_bst(root, 4))
    {
        cout << "found" << endl;
    }
    else
    {
        cout << "not found" << endl;
    }
    return 0;
}
