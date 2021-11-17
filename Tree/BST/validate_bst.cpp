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
//--------------------------------Main Code---------------------------
bool chk_bst(Node *root, long long maxi_val, long long mini_val)
{
    if (root == NULL)
    {
        return 1;
    }

    if ((root->data < maxi_val) && (root->data > mini_val) && chk_bst(root->left, root->data, mini_val) && chk_bst(root->right, maxi_val, root->data))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
bool isValidBST(Node *root)
{
    return chk_bst(root, INT64_MAX, INT64_MIN);
}
//-----------------------------------------------------------------------
void print_tree(Node *root) //Inorder printing
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
    print_tree(root);
    cout << endl;
    if (isValidBST(root))
    {
        cout << "It is a bst";
    }
    else
    {
        cout << "It is not a bst";
    }
    return 0;
}
