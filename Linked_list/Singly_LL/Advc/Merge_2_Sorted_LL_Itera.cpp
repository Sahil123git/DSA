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

Node *insert_end(Node *head, int ele)
{
    if (head == NULL)
    {
        Node *temp = new Node(ele);
        head = temp;
        return head;
    }
    Node *temp1 = head;
    while (temp1->next != NULL)
    {
        temp1 = temp1->next;
    }
    temp1->next = new Node(ele);
    return head;
}
void print(Node *head)
{
    cout << endl;
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}
Node *merge_LL(Node *head1, Node *head2)
{
    Node *p1 = head1;
    Node *p2 = head2;
    Node *dummy_Node = new Node(-1);
    Node *p3 = dummy_Node;

    while (p1 != NULL && p2 != NULL) //All changes we can see on head1 and head2
    {                                //but not on p1 and p2 as we are incrementing them
        if (p1->data < p2->data)     //Debug for more clearity
        {
            p3->next = p1; //this will put value in next of p3
            p1 = p1->next; //Here p1 is updating so it will not change it's next (both p1
                           //and p3 are connected).The Same Address whose next's p3 will update is
                           //not present in p1 becasue we have incermented p1.So only p3's next will change.

            p3 = p3->next; //this will shift the pointer p3 to next
        }
        else
        {
            p3->next = p2; //This will change only p3's next but will not change p1's next
                           //as p1 is incremented.
            p2 = p2->next; //Here also the address which p3 will change is not present
            p3 = p3->next; //in p2 because of increment.So p3's next will only change
        }
    }
    while (p1 != NULL)
    {
        p3->next = p1;
        p1 = p1->next;
        p3 = p3->next;
    }
    while (p2 != NULL)
    {
        p3->next = p2;
        p2 = p2->next;
        p3 = p3->next;
    }
    // print(head1);
    return dummy_Node->next;
}

int main()
{
    // Node *head = NULL;
    // int n;
    // cin >> n;
    // while (n--)
    // {
    //     int ele;
    //     cin >> ele;
    //     head = insert_end(head, ele);
    // }
    // Node *head1 = NULL;
    // int n1;
    // cin >> n1;
    // while (n1--)
    // {
    //     int ele;
    //     cin >> ele;
    //     head1 = insert_end(head1, ele);
    // }
    Node *head = new Node(3);
    Node *head1 = new Node(4);
    Node *head2 = new Node(5);
    head->next = head1;
    head1->next = head2;

    Node *headb = new Node(1);
    Node *heada = new Node(3);
    headb->next = heada;

    Node *temp;
    temp = merge_LL(headb, head);
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    return 0;
}
