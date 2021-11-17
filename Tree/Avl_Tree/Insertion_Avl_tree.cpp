#include <bits/stdc++.h> //https://practice.geeksforgeeks.org/problems/avl-tree-insertion/1#
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    int height;
    Node(int data)
    {
        left = right = NULL;
        this->data = data;
    }
};
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
class Solution
{
public:
    int height(Node *root)
    {
        if (root == NULL)
            return 0;
        return max(height(root->left), height(root->right)) + 1;
    }

    int getbf(Node *root) //for checking whether it is correctly balanced tree or not conditions(-1,0,1)
    {
        if (root == NULL)
            return -1;
        else
            return (height(root->left) - height(root->right));
    }

    Node *rightRotate(Node *y)
    {
        Node *x = y->left;
        Node *temp = x->right;

        //rotate
        x->right = y;
        y->left = temp;

        return x;
    }
    Node *leftRotate(Node *x)
    {
        Node *y = x->right;
        Node *temp = y->left;

        //rotation
        y->left = x;
        x->right = temp;

        return y;
    }

    Node *insertToAVL(Node *root, int x)
    {
        //Your code here
        if (root == NULL)
        {
            return new Node(x);
        }

        if (root->data < x)                            //for bst insertion
            root->right = insertToAVL(root->right, x); //here we are not returning becoz we are checking from bottom whether that lvl is AVL or not
        else if (root->data > x)
            root->left = insertToAVL(root->left, x);
        else
            return root;

        int bf = getbf(root); //we will chk each lvl from bottom
        // left left ->rightRotate
        if (bf > 1 and x < root->left->data) // "and can be used in place of &&"
            return rightRotate(root);

        //right right ->leftRotate
        if (bf < -1 and x > root->right->data)
            return leftRotate(root);

        //left right ->leftRotate and then rightRotate
        if (bf > 1 and x > root->left->data)
        {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }

        //right left ->rightRotate and then leftrotate
        if (bf < -1 and x < root->right->data)
        {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }

        return root;
    }
};

int main()
{
    Node *root = NULL;
    Solution obj;

    root = obj.insertToAVL(root, 811);
    root = obj.insertToAVL(root, 488);
    root = obj.insertToAVL(root, 679);
    root = obj.insertToAVL(root, 600);

    print_inorder(root);
    return 0;
} //811 488 679 600