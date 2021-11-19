#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};
int search(Node *head, int key)
{
    int count = 1;
    while (head != NULL)
    {
        if (head->data == key)
        {
            return count;
        }
        head = head->next;
        count++;
    }
    return 0;
}
int main()
{
    Node *head = new Node(10);
    Node *temp1 = new Node(20);
    Node *temp2 = new Node(30);
    int key;
    cin >> key;
    head->next = temp1;
    temp1->next = temp2;
    int res = search(head, key);
    if (res)
    {
        cout << res;
    }
    else
    {
        cout << "not found";
    }
    return 0;
}