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
Node *insert_at(Node *head, int pos, int ele)
{

    if (pos == 1)
    {
        Node *temp2 = new Node(ele);
        temp2->next = head;
        return temp2;
    }
    int count = 1;
    Node *temp = new Node(ele);
    Node *temp1 = head; // cout << head->data << endl;
                        //so that we can do changes on temp1 that we can see on head
    while (temp1 != NULL)
    {
        if (count == (pos - 1))
        {
            temp->next = temp1->next;
            temp1->next = temp;
            break;
        }
        else
        {
            temp1 = temp1->next;
        }
        count++;
        // cout << count << " ";
    }
    return head; //we are doing changes on temp1 and we can see on head
}
void traversal(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " | ";
        head = head->next;
    }
}
int main()
{
    Node *head = new Node(10);
    Node *temp1 = new Node(20);
    Node *temp2 = new Node(30);

    head->next = temp1;
    temp1->next = temp2;
    int pos=2, ele=20;
    // cin >> pos >> ele;
    Node *temp3 = NULL;

    temp3 = insert_at(head, pos, ele);
    while (temp3 != NULL)
    {
        cout << temp3->data << " | ";
        temp3 = temp3->next;
    }
    // traversal(temp3);
    return 0;
}