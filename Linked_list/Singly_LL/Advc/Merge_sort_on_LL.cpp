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
Node *find_mid(Node *head)
{
    Node *slow = head;
    Node *fast = head->next; //starting it from 1 next so that we can get the pointer of  correct middle
                             //which handle the case of even numbers of ele
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}
Node *merge(Node *head1, Node *head2)
{
    if (head1 == NULL)
    {
        return head2;
    }
    if (head2 == NULL)
    {
        return head1;
    }
    Node *new_list;
    if (head1->data < head2->data)
    {
        new_list = head1;
        new_list->next = merge(head1->next, head2);
    }
    else
    {
        new_list = head2;
        new_list->next = merge(head1, head2->next);
    }
    // Node *sorted_head1 = new_list;
    // while (sorted_head1 != NULL)
    // {
    //     cout << sorted_head1->data << " ";
    //     sorted_head1 = sorted_head1->next;
    // }
    // cout << endl;
    return new_list;
}
Node *merge_sort(Node *head)
{
    if (head == NULL || head->next == NULL)//don't forget this condition this is imip
    {//
        return head;
    }
    Node *head_1 = head;
    Node *mid = find_mid(head);
    Node *head_2 = mid->next;

    mid->next = NULL; //this step will divide the head_1 into two parts

    head_1 = merge_sort(head_1);
    head_2 = merge_sort(head_2);

    return merge(head_1, head_2);
}
int main()
{
    Node *head = new Node(20);
    Node *temp1 = new Node(5);
    Node *temp2 = new Node(10);
    Node *temp3 = new Node(7);

    head->next = temp1;
    temp1->next = temp2;
    temp2->next = temp3;

    Node *sorted_head = merge_sort(head);
    while (sorted_head != NULL)
    {
        cout << sorted_head->data << " ";
        sorted_head = sorted_head->next;
    }
    return 0;
}