
#include <bits/stdc++.h>
using namespace std;
#define int long long

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    int direction;

    Node(int data, int direction)
    {
        this->data = data;
        left = NULL;
        right = NULL;
        this->direction = direction;
    }
};

Node *insertionBst(Node *curr, int eleVal, int direction)
{
    if (curr == NULL)
    {
        return new Node(eleVal, direction);
    }

    if (curr->data > eleVal)
    {
        curr->left = insertionBst(curr->left, eleVal, 1);
    }
    else
    {
        curr->right = insertionBst(curr->right, eleVal, 2);
    }

    return curr;
}

void preorderChk(Node *currNode)
{
    if (currNode == NULL)
        return;

    cout << currNode->data << " ";
    preorderChk(currNode->left);
    preorderChk(currNode->right);
}
int32_t main()
{
    int n;
    cin >> n;

    if (n == 0)
        return 0;
    int r;
    cin >> r;
    Node *root = new Node(r, 0);

    for (int i = 1; i < n; i++)
    {
        int x;
        cin >> x;

        insertionBst(root, x, 0);
    }


    queue<Node *> qu;
    qu.push(root);
    bool chk = true;
    while (qu.size() > 0)
    {
        int size = qu.size();
        while (size--)
        {
            Node *curr = qu.front();
            qu.pop();
            if (curr->direction == 1 && chk == 1)
            {
                cout << curr->data << " ";
            }
            else if (curr->direction == 2 && chk == 0)
            {
                cout << curr->data << " ";
            }

            if (curr->left)
                qu.push(curr->left);
            if (curr->right)
                qu.push(curr->right);
        }
        chk = !chk;
    }

    return 0;
}