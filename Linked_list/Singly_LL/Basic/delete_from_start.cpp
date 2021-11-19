#include <bits/stdc++.h>
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
// Node *del(Node *head)   //We can do like this also
// {
//     Node *temp = new Node(1);
//     temp->next = head->next->next;
//     temp->data = head->next->data;
//     delete (head);
//     return temp;
// }
Node *del(Node *head) //pointer so that it will return pointer
{
    if (head == NULL)
    {
        return NULL;
    }
    Node *temp = head->next; //giving address of (next of head)
    delete (head);
    head = NULL; //our choice to write or not
    return temp;
}
void print(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}
int main()
{
    Node *head = new Node(10);
    Node *temp = new Node(20);
    Node *temp1 = new Node(30);
    head->next = temp;
    temp->next = temp1;
    Node *temp2 = NULL;
    temp2 = del(head);
    print(temp2);
    return 0;
}