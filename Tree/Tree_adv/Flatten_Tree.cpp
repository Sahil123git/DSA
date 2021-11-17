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
//------------------------------Code starts here------------------------
void flatten_Naive(Node *root) //Naive approach with TC:O(n) and SC:O(n)
{
    if (root == NULL)
    {
        return;
    }
    Node *temp_left = root->left;
    Node *temp_right = root->right;

    root->left = NULL;
    flatten_Naive(temp_left);
    flatten_Naive(temp_right);
    root->right = temp_left;

    Node *last_leftT = root;
    while (last_leftT->right != NULL) //we can do last_leftT->right because it will be having 1 ele in worst case also as we are having condn in starting for this
    {
        last_leftT = last_leftT->right;
    }
    last_leftT->right = temp_right;
}

void flatten_opt(Node *root) //Opt approach using Moris algo TC:O(n) and SC:O(1)
{
    if (root == NULL)
    {
        return;
    }

    while (root != NULL)
    {
        if (root->left != NULL)
        {
            Node *left_node = root->left;
            Node *current = left_node;
            while (current->right != NULL)
            {
                current = current->right;
            }
            current->right = root->right;
            root->left = NULL;
            root->right = left_node;
        }
        root = root->right;
    }
}
//---------------------Code ends here-----------------------------------------
void print(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    print(root->left);
    cout << root->data << " ";
    print(root->right);
}
int main()
{
    Node *root = build_tree();
    flatten_Naive(root);
    flatten_opt(root);
    print(root);
}

//8 10 1 -1 -1 6 9  -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1