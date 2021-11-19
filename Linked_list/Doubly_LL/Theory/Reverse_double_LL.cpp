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
        next = NULL;
        prev = NULL;
    }
};
void traversal(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

Node *Reverse_LL1(Node *head) //Method 1
{
    Node *temp = head;
    Node *prev = NULL;
    Node *temp_new = NULL;
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    while (temp != NULL)
    {
        prev = temp->prev;
        temp->prev = temp->next;
        temp->next = prev;
        temp_new = temp;   //this is the last temp
        temp = temp->prev; //temp will be having address of last index
    }
    return temp_new;
}
Node *Reverse_LL2(Node *head) //Method 2
{
    Node *temp = head;
    Node *prev = NULL;
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    while (temp != NULL)
    {
        prev = temp->prev; //for last step prev will become 30
        temp->prev = temp->next;
        temp->next = prev;
        temp = temp->prev; //temp will be having address of last index
    }
    return prev->prev; //now this prev points to next that is 40
} //because pointers are reversed

int main()
{
    Node *head = new Node(10);
    Node *temp1 = new Node(20);
    Node *temp2 = new Node(30);
    Node *temp3 = new Node(40);

    head->next = temp1;

    temp1->next = temp2;
    temp1->prev = head;

    temp2->next = temp3;
    temp2->prev = temp1;

    temp3->prev = temp2;
    temp3->next = NULL;

    // Node *rev_tra = Reverse_LL1(head);
    Node *rev_tra = Reverse_LL2(head);
    traversal(rev_tra);
    return 0;
}
