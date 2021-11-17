#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};
Node *build_tree()
{
    int ele;
    cin >> ele;
    if (ele == -1) //-1 to stop particular side dirn node
    {
        return NULL;
    }
    Node *root = new Node(ele);
    root->left = build_tree();
    root->right = build_tree();
    return root;
}
void preord_print(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preord_print(root->left);
    preord_print(root->right);
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
    preord_print(head);
    cout << endl;
    print_inorder(head);
    cout << endl;
    print_postorder(head);
    return 0;
}
/*input
4 3 8 -1 -1 -1 2 1 -1 -1 -1
output
4 3 8 2 1
*/