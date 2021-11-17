#include <iostream> //O(n)
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
class pair_//using this pair because we cannot return two values w/o this
{
public:
    int height;
    int diameter;
};

pair_ diameter_tree_opt(Node *root)
{
    pair_ p;
    if (root == NULL)
    {
        p.height = p.diameter = 0;
        return p;
    }
    pair_ left = diameter_tree_opt(root->left);
    pair_ right = diameter_tree_opt(root->right);

    p.height = max(left.height, right.height) + 1;
    p.diameter = max((left.height + right.height), max(left.diameter, right.diameter));
    // cout << p.diameter << endl;
    return p;
}
int main()
{
    Node *root = build_tree();
    pair_ p;
    p = diameter_tree_opt(root);
    cout << p.height << " " << p.diameter;
}
//8 10 1 -1 -1 6 9  -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1