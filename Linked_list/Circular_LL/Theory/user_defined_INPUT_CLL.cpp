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

void traversal(Node *head)
{
    Node *temp = head;
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

Node *insert_end(Node *head, int ele)
{
    if (head == NULL)
    {
        Node *temp = new Node(ele);
        temp->next = temp;
        return temp;
    }
    Node *temp = head;
    Node *new_val = new Node(ele);

    new_val->next = head->next; //inserting extra node
    head->next = new_val;

    int data;
    data = temp->data; //now swapping that node data with prev one
    temp->data = new_val->data;
    new_val->data = data;
    // cout << new_val->data;
    head = new_val;
    return head;
}
int main()
{
    Node *head = NULL;
    int n;
    cin >> n;
    while (n--)
    {
        int ele;
        cin >> ele;
        head = insert_end(head, ele);
    }
    traversal(head);
    return 0;
}