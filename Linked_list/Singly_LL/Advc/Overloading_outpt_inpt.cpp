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
istream &operator>>(istream &is, Node *&head)
{
    int n; //to use cin>>head1>>head2 use &is like this
    cin >> n;
    while (n--)
    {
        int ele;
        cin >> ele;
        head = insert_end(head, ele);
    }
    return is;
}

ostream &operator<<(ostream &os, Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;

    return os;
}
int main()
{
    Node *head1 = NULL;
    Node *head2 = NULL;

    cin >> head1 >> head2;
    cout << head1 << head2;
    return 0;
}