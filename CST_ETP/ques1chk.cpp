
#include <bits/stdc++.h>
using namespace std;
#define int long long

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    int dir;

    Node(int data, int dir)
    {
        this->data = data;
        left = NULL;
        right = NULL;
        this->dir = dir;
    }
};

Node *insertion(Node *curr, int val, int dir)
{
    if (curr == NULL)
    {
        return new Node(val, dir);
    }

    if (curr->data > val)
    {
        curr->left = insertion(curr->left, val, 1);
    }
    else
    {
        curr->right = insertion(curr->right, val, 2);
    }

    return curr;
}

void preOrder(Node *curr)
{
    if (curr == NULL)
        return;

    cout << curr->data << " ";
    preOrder(curr->left);
    preOrder(curr->right);
}
void solution()
{
    int n;
    cin >> n;

    if (n == 0)
        return;
    int rd;
    cin >> rd;
    Node *root = new Node(rd, 0);

    for (int i = 1; i < n; i++)
    {
        int x;
        cin >> x;

        insertion(root, x, 0);
    }

    // preOrder(root);

    queue<Node *> que;
    que.push(root);
    bool ct = true;
    while (que.size() > 0)
    {
        int size = que.size();
        while (size--)
        {
            Node *curr = que.front();
            que.pop();
            if (curr->dir == 1 && ct)
            {
                cout << curr->data << " ";
            }
            else if (curr->dir == 2 && !ct)
            {
                cout << curr->data << " ";
            }

            if (curr->left)
                que.push(curr->left);
            if (curr->right)
                que.push(curr->right);
        }
        ct = !ct;
    }
}

signed main()
{
    solution();

    return 0;
}