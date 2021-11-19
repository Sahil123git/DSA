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

Node *del_knode(Node *head, int k)
{
    Node *temp = head;
    if (k == 1)
    {
        head->data = head->next->data;
        Node *temp1 = head->next;
        head->next = head->next->next;
        delete (temp1);
        return temp;
    }
    int count = 1;
    while (count < k - 1)
    {
        temp = temp->next;
        count++;
    }
    Node *temp1 = temp->next;
    temp->next = temp->next->next;
    delete (temp1);
    return head;
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

    new_val->next = head->next; //for putting this node b/w the CLL
    head->next = new_val;

    int data;
    data = temp->data;          //swapping the both LL data
    temp->data = new_val->data; //now this new_val is the new head
    new_val->data = data;

    head = new_val;
    return head;
}
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
    int k;
    cin >> k;
    Node *new_head = del_knode(head, k);
    traversal(new_head);
}