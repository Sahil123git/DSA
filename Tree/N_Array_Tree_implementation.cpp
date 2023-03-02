#include <iostream>
#include <vector>

using namespace std;

class Node
{
public:
    int data;
    vector<Node *> children;

    Node(int val)
    {
        data = val;
    }
};

class NArrayTree
{
public:
    Node *root;

    NArrayTree(int rootVal)
    {
        root = new Node(rootVal); // fixing root value
    }

    void addChild(Node *parent, int childVal) // adding n child
    {
        Node *child = new Node(childVal);
        parent->children.push_back(child);
    }

    void printTree(Node *node, int depth = 0)
    {
        for (int i = 0; i < depth; i++)
        {
            cout << "-";
        }
        cout << node->data << endl;
        for (Node *child : node->children)
        {
            printTree(child, depth + 1);
        }
    }
};

int main()
{
    // NArrayTree tree(1);
    NArrayTree *tree = new NArrayTree(1); // creating root of tree
    Node *root = tree->root;              // taking root val from NArrayTree

    tree->addChild(root, 2);
    tree->addChild(root, 3);
    tree->addChild(root, 4);

    tree->addChild(root->children[0], 5);
    tree->addChild(root->children[0], 6);

    tree->addChild(root->children[1], 7);

    tree->printTree(root);

    return 0;
}
