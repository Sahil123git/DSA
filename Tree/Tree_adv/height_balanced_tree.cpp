#include <iostream>
#include <cmath>
using namespace std;
class node
{
public:
    int data;
    node *right, *left;
    node(int d)
    {
        data = d;
        right = NULL;
        left = NULL;
    }
};

node *build_tree()
{
    int ele;
    cin >> ele;
    if (ele == -1)
    {
        return NULL;
    }
    node *new_node = new node(ele);

    new_node->left = build_tree();
    new_node->right = build_tree();

    return new_node;
}
class chk_bal
{
public:
    int height;
    bool balance;
};

chk_bal chk_balnced_tree(node *tree)
{
    chk_bal ob;
    if (tree == NULL)
    {
        ob.height = 0;
        ob.balance = 1;
        return ob;
    }

    chk_bal chk_left = chk_balnced_tree(tree->left);
    chk_bal chk_right = chk_balnced_tree(tree->right);

    if (abs(chk_left.height - chk_right.height) <= 1 && (chk_left.balance != 0) && (chk_right.balance == 1))
    {
        ob.balance = 1;
    }
    else
    {
        ob.balance = 0;
    }

    ob.height = max(chk_left.height, chk_right.height) + 1;
    return ob;
}
int main()
{
    node *tree = build_tree();
    chk_bal ob;

    ob = chk_balnced_tree(tree);
    if (ob.balance)
    {
        cout << "tree nodes are balanced";
    }
    else
    {
        cout << "tree nodes are not balance";
    }
}