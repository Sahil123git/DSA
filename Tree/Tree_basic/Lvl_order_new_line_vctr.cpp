#include <iostream>
#include <queue>
#include <vector>
using namespace std;
class Node
{
public:
    int data;
    Node *right, *left;
    Node(int data)
    {
        this->data = data;
        right = NULL;
        left = NULL;
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

vector<vector<int>> levelOrder(Node *root)
{
    //Your code here
    vector<vector<int>> vt;
    queue<Node *> qu;
    qu.push(root);
    qu.push(NULL);
    vector<int> vvt;
    while (!qu.empty())
    {
        if (qu.front() == NULL)
        {
            vt.emplace_back(vvt);
            vvt.clear();
            qu.pop();
            if (!qu.empty())
            {
                qu.push(NULL);
            }
        }
        else
        {
            Node *fn = qu.front();
            vvt.emplace_back(fn->data);
            // cout << fn->data << " ";
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
    return vt;
}

int main()
{
    Node *root = build_tree();
    vector<vector<int>> vt = levelOrder(root);

    for (vector<int> v : vt)
    {
        for (int value : v)
        {
            cout << value << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}