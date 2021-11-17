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

void print_postorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    print_postorder(root->left);
    print_postorder(root->right);
    cout << root->data << " ";
}
int main()
{
    Node *head = build_tree();
    print_postorder(head);
    return 0;
}