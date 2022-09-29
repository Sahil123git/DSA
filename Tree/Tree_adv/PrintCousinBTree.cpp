// C++ program to print cousins of a node
#include <bits/stdc++.h>
using namespace std;

// A Binary Tree Node
struct Node
{
    int data;
    Node *left, *right;
};

// A utility function to create a new
// Binary Tree Node
Node *newNode(int item)
{
    Node *temp = new Node;
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}

/* It returns level of the node if it is
present in tree, otherwise returns 0.*/
int getLevel(Node *root, Node *node, int level) // here we r finding lvl of the node tht we have to find
{
    if (root == NULL) // if node not fnd return
    {
        return 0;
    }
    else if (root->data == node->data) // if node found return it's lvl
    {
        return level;
    }

    int leftLvl = getLevel(root->left, node, level + 1); // other wise incr lvl by 1
    if (leftLvl != 0)
    {
        return leftLvl; // if in node not found then only chk right side
    }
    return getLevel(root->right, node, level + 1);
}

/* Print nodes at a given level such that
sibling of node is not printed if it exists */
void printGivenLevel(Node *root, Node *key, int level)
{
    if (root == NULL || level < 2) // if lvl is less than 2 than no need to print any node
    {
        return;
    }

    if (level == 2) // if lvl == 2 then only we can chk it right and left so tht we can skip if matches
    {
        if (root->left == key || root->right == key)
        {
            return;
        }
        if (root->left)
        {
            cout << root->left->data << " ";
        }
        if (root->right)
        {
            cout << root->right->data << " ";
        }
    }

    if (level > 2)
    {
        printGivenLevel(root->right, key, level - 1);
        printGivenLevel(root->left, key, level - 1);
    }
}
// This function prints cousins of a given node
void printCousins(Node *root, Node *key)
{
    int lvl = getLevel(root, key, 1);
    printGivenLevel(root, key, lvl);
}

// Driver Code
int main()
{
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->left->right->right = newNode(15);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->right = newNode(8);

    printCousins(root, root->left->right);

    return 0;
}
