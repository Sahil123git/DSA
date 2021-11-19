// { Driver Code Starts
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

// } Driver Code Ends
/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/

Node *mid_ele(Node *head)
{
    Node *slow = head;
    Node *fast = head->next;
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}
Node *merge(Node *head_1, Node *head_2)
{
    if (head_1 == NULL)
    {
        return head_2;
    }
    if (head_2 == NULL)
    {
        return head_1;
    }
    Node *new_node;
    if (head_1->data < head_2->data)
    {
        new_node = head_1;
        new_node->next = merge(head_1->next, head_2);
    }
    else
    {
        new_node = head_2;
        new_node->next = merge(head_1, head_2->next);
    }
    return new_node;
}
class Solution
{
public:
    //Function to sort the given linked list using Merge Sort.
    Node *mergeSort(Node *head)
    {
        // your code here
        if (head == NULL || head->next == NULL)
        {
            return head;
        }
        Node *head_1 = head;
        Node *mid_LL = mid_ele(head);
        Node *head_2 = mid_LL->next;

        mid_LL->next = NULL;
        head_1 = mergeSort(head_1);
        head_2 = mergeSort(head_2);

        return merge(head_1, head_2);
    }
};

// { Driver Code Starts.

void printList(Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node **head_ref, int new_data)
{
    Node *new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main()
{
    long test;
    cin >> test;
    while (test--)
    {
        struct Node *a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> tmp;
            push(&a, tmp);
        }
        Solution obj;
        a = obj.mergeSort(a);
        printList(a);
    }
    return 0;
} // } Driver Code Ends