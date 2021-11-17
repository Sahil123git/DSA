#include <iostream> 
#include <queue>

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
int sum_replacement_tree(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    if ((root->right == NULL) && (root->left == NULL))
    {
        // cout << root->data << endl;
        return root->data;
    }
    int left = sum_replacement_tree(root->left);
    int right = sum_replacement_tree(root->right);

    int cur_data = root->data;
    int sum_l_r = left + right;
    root->data = sum_l_r;

    // cout << sum_l_r << endl;

    return (cur_data + sum_l_r);
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
void lvl_order_nline(Node *root)
{
    queue<Node *> qu;
    qu.push(root);
    qu.push(NULL);
    while (!qu.empty())
    {
        if (qu.front() == NULL)
        {
            cout << endl;
            qu.pop();

            if (!qu.empty())
            {
                qu.push(NULL);
            }
        }
        else
        {
            Node *fn = qu.front();
            cout << fn->data << " ";
            qu.pop();
            if (fn->left != NULL)
            {
                qu.push(fn->left);
            }
            if (fn->right != NULL)
            {
                qu.push(fn->right);
            }
        }
    }
}

int main()
{
    Node *root = build_tree();
    sum_replacement_tree(root);
    lvl_order_nline(root);
}
//1 4 5 8 -1 -1 -1 6 7 -1 -1 -1 9 -1 -1