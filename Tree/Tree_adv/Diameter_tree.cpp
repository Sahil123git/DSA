#include <iostream>//O(n^2)
using namespace std;
class Node
{
public:
    int data;
    Node *left, *right;
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
int height_tree(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return max(height_tree(root->left), height_tree(root->right)) + 1;
}
int diameter_tree(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int l = height_tree(root->left);
    int r = height_tree(root->right);
    int sum_root = l + r; //this will calculate from middle for both ends

    int l_node = diameter_tree(root->left);  //to check if left node is having max diameter
    int r_node = diameter_tree(root->right); //to check if right node is having max diameter

    // cout << sum_root << " " << l_node << " " << r_node << endl;
    return max(sum_root, max(l_node, r_node));
}
int main()
{
    Node *root = build_tree();
    cout << diameter_tree(root);
}
//1 4 5 8 -1 -1 -1 6 7 -1 -1 -1 9 -1 -1