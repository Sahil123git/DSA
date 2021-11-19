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
Node *Insert_beg(Node *head, int ele)
{
    Node *temp = head;
    Node *temp_ele = new Node(ele);
    if (head == NULL)
    {
        head = temp_ele;
        temp_ele->next = temp_ele;
        return head;
    }
    temp_ele->next = temp->next;
    temp->next = temp_ele;

    int temp_;
    temp_ = temp->data;
    temp->data = temp_ele->data;
    temp_ele->data = temp_;
    return temp;
}
void traversal3(Node *head)
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
    Node *head = new Node(10);
    Node *temp = new Node(20);
    Node *temp1 = new Node(30);

    head->next = temp;
    temp->next = temp1;
    temp1->next = head;
    int ele;
    cin >> ele;
    Node *temp_tra;
    temp_tra = Insert_beg(head, ele);
    traversal3(temp_tra);
    return 0;
}