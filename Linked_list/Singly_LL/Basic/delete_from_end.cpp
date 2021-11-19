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
Node *del_end(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    else if (head->next == NULL)
    {
        delete (head);
        return NULL;
    }
    Node *cur = head; //both address's is same so if we change cur that will effect head also

    while (cur->next->next != NULL) //Debug the code for more clearity
    {                               //if next->next is not used it will not delete correctly
        cur = cur->next;            //In this if we will use (head) instead of (cur) it will traverse
                                    //to last address So use cur so that it will not get deleted
    }

    delete (cur->next); //this step will delete head last ele also
    cur->next = NULL;   //this will remove the data also
    return head;
}
void traversal(Node *head)
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
    Node *temp1 = new Node(20);
    Node *temp2 = new Node(30);
    Node *temp3 = new Node(40);

    head->next = temp1;
    temp1->next = temp2;
    temp2->next = temp3;
    Node *temp4 = NULL;
    temp4 = del_end(head); //check for corner case temp3
    traversal(temp4);
}
