#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int data)
    {
        this->data = data;
        next = prev = NULL;
    }
};
Node *insert_end(Node *head, int ele)
{
    Node *new_data = new Node(ele);
    if (head == NULL)
    {
        return new_data;
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new_data;
    new_data->prev = temp;
    return head;
}
void traversal(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
int main()
{
    Node *new_1st_ele = NULL;
    new_1st_ele = insert_end(new_1st_ele, 5); //Insert when there is no ele in the LL
    Node *head = new Node(10);
    Node *temp1 = new Node(20);
    Node *temp2 = new Node(30);
    Node *temp3 = new Node(40);

    new_1st_ele->next = head;
    head->prev = new_1st_ele;
    head->next = temp1;
    temp1->next = temp2;
    temp1->prev = head;
    temp2->next = temp3;
    temp2->prev = temp1;

    int data;
    cin >> data;
    Node *new_data = insert_end(head, data);
    Node *new_head = new_data->prev;
    traversal(new_head);
    return 0;
}
