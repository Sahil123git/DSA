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
    Node *root = new Node(ele);
    root->left = build_tree();
    root->right = build_tree();
    return root;
}
void print_kth(Node *root, int k)//Lvl order in O(n^2)
{
    if (root == NULL)
    {
        return;
    }
    if (k == 1)
    {
        cout << root->data << " ";
        return;
    }
    print_kth(root->left, k - 1);
    print_kth(root->right, k - 1);
    return;
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
void print_lvl_order(Node *root)
{
    int hei = height_t(root);

    for (int i = 1; i <= hei; i++)
    {
        print_kth(root, i);
        cout << endl;
    }
}
int main()
{
    Node *temp = build_tree();
    print_lvl_order(temp);
    return 0;
}