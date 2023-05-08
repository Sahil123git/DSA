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

void addAtFront(Node **Rhead, Node *head, int data)
{
    if (Rhead == NULL)
    {
        head = new Node(data);
        (*Rhead) = head;
        return;
    }
    Node *frnt = new Node(data);
    frnt->next = head;

    (*Rhead) = frnt;
    // cout << (*Rhead)->data;
}

Node *addAtEnd(Node *head, int data)
{
    if (head == NULL)
    {
        head = new Node(data);
        return head;
    }

    // while (head != NULL && head->next != NULL)
    // {
    //     head = head->next;
    // }
    head->next = new Node(data); // here we r chngng head->next (next) which is a global var of class changes done on (next var)  and data var will be visible across the program
    return head->next;
}

void printLL(Node *head) // and this is call by val
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next; // these changes are temporary as head is call by val
    }
}
void refPrintLL(Node **head)      // nwo this is call by ref
{                                 // this Node **head is (Pointer of node)
    while ((*head)->next != NULL) //(*head) is used to dereference head to node
    {
        cout << (*head)->data << " ";
        (*head) = (*head)->next; // these chngs are permanent as head is call by ref
    }
}
int main()
{
    Node *head, *temp;
    temp = head = NULL;

    addAtFront(&head, temp, 2);
    temp = head;
    addAtFront(&head, temp, 1);
    // head = temp; // chng this head whenever inserting at front

    // cout << head->next->data << "data" << endl;
    temp = addAtEnd(temp, 3);
    temp = addAtEnd(temp, 4);
    temp = addAtEnd(temp, 5);

    // cout << head->data << endl;
    printLL(head); // here we r passing head pass by value
    cout << endl;
    refPrintLL(&head); // here we r passing head call by ref

    cout << endl
         << head->data;
}