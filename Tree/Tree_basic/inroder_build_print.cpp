#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
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
    Node *head = new Node(ele);
    head->left = build_tree();
    head->right = build_tree();
    return head;
}

void print_inorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    print_inorder(root->left);
    cout << root->data << " ";
    print_inorder(root->right);
}
int main()
{
    Node *head = build_tree();
    print_inorder(head);
    return 0;
}