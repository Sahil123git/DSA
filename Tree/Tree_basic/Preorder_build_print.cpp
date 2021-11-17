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
void print(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    print(root->left);
    print(root->right);
}
int main()
{
    Node *head = build_tree();
    print(head);
    return 0;
}
/*input
4 3 8 -1 -1 -1 2 1 -1 -1 -1
output
4 3 8 2 1
*/