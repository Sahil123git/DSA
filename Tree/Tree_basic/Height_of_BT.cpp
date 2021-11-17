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
    if (ele == -1)
    {
        return NULL;
    }
    Node *root = new Node(ele);
    root->left = build_tree();
    root->right = build_tree();
    return root;
}
int height_t(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int left_s = height_t(root->left);
    int right_s = height_t(root->right);

    return max(left_s, right_s) + 1;
}
int main()
{
    Node *temp = build_tree();
    cout << height_t(temp) << " ";
}