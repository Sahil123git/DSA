//

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data, height;
    Node *left, *right;
    Node(int x)
    {
        data = x;
        height = 1;
        left = right = NULL;
    }
};

int setHeights(Node *n)
{
    if (!n)
        return 0;
    n->height = 1 + max(setHeights(n->left), setHeights(n->right));
    return n->height;
}

Node *buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size())
    {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N")
        {

            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N")
        {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    setHeights(root);
    return root;
}

bool isBST(Node *n, int lower, int upper)
{
    if (!n)
        return 1;
    if (n->data <= lower || n->data >= upper)
        return 0;
    return isBST(n->left, lower, n->data) && isBST(n->right, n->data, upper);
}

pair<int, bool> isBalanced(Node *n)
{
    if (!n)
        return pair<int, bool>(0, 1);

    pair<int, bool> l = isBalanced(n->left);
    pair<int, bool> r = isBalanced(n->right);

    if (abs(l.first - r.first) > 1)
        return pair<int, bool>(0, 0);

    return pair<int, bool>(1 + max(l.first, r.first), l.second && r.second);
}

bool isBalancedBST(Node *root)
{
    if (!isBST(root, INT_MIN, INT_MAX))
        cout << "BST voilated, inorder traversal : ";

    else if (!isBalanced(root).second)
        cout << "Unbalanced BST, inorder traversal : ";

    else
        return 1;
    return 0;
}

void printInorder(Node *n)
{
    if (!n)
        return;
    printInorder(n->left);
    cout << n->data << " ";
    printInorder(n->right);
}

struct Node *deleteNode(struct Node *root, int data);

int main()
{
    int t;
    cin >> t;
    getchar();

    while (t--)
    {
        string s;
        getline(cin, s);
        Node *root = buildTree(s);

        int n;
        cin >> n;
        int ip[n];
        for (int i = 0; i < n; i++)
            cin >> ip[i];

        for (int i = 0; i < n; i++)
        {
            root = deleteNode(root, ip[i]);

            if (!isBalancedBST(root))
                break;
        }

        if (root == NULL)
            cout << "null";
        else
            printInorder(root);
        cout << endl;

        getline(cin, s); // to deal with newline char
    }
    return 1;
}
// } Driver Code Ends

/* Node is as follows:

struct Node
{
	int data, height;
	Node *left, *right;
	Node(int x)
	{
		data = x;
		height = 1;
		left = right = NULL;
	}
};

*/
int nodeheight(Node *root)
{
    if (root == NULL)
        return 0;

    return 1 + max(nodeheight(root->left), nodeheight(root->right));
}

Node *minNode(Node *root)
{
    if (root->left == NULL)
        return root;

    return minNode(root->left);
}

// when rr imbalence occour
Node *rrRotation(Node *x)
{
    Node *y = x->right;
    Node *temp = y->left;

    //rotation
    y->left = x;
    x->right = temp;

    return y;
}

//when ll imbalance occour
Node *llRotation(Node *y)
{
    Node *x = y->left;
    Node *temp = x->right;

    //rotate
    x->right = y;
    y->left = temp;

    return x;
}

Node *delet(Node *root, int x)
{
    if (root == NULL)
        return root;

    if (root->data < x)
        root->right = delet(root->right, x);

    else if (root->data > x)
        root->left = delet(root->left, x);

    else
    {

        if (root->left == NULL && root->right == NULL)
        {
            return root = NULL;
        }

        else if (root->left == NULL && root->right != NULL)
        {
            *root = *(root->right);
            free(root->right);
            return root;
        }

        else if (root->left != NULL && root->right == NULL)
        {
            *root = *(root->left);
            free(root->left);
            return root;
        }

        else if (root->left != NULL && root->right != NULL)
        {
            Node *temp = minNode(root->right);
            root->data = temp->data;
            root->right = delet(root->right, root->data);
            //return root;
        }
    }

    root->height = nodeheight(root);

    //printf("Entering balance check");

    // same as insertion

    int bf = nodeheight(root->left) - nodeheight(root->right);

    if (bf > 1)
    {                                                                      //Left heavy
        if (nodeheight(root->left->left) >= nodeheight(root->left->right)) //Left-Left
            return llRotation(root);

        else
        { //Left-right
            root->left = rrRotation(root->left);
            return llRotation(root);
        }
    }

    else if (bf < -1)
    { //Right heavy

        if (nodeheight(root->right->right) >= nodeheight(root->right->left))
        { //Right-Right
            return rrRotation(root);
        }
        else
        { //Right - left
            root->right = llRotation(root->right);
            return rrRotation(root);
        }
    }

    return root;
}

Node *deleteNode(Node *root, int data)
{
    return delet(root, data);
}