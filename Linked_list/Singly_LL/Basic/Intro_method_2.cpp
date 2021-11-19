#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *Next;
    Node(int ele)
    {
        data = ele;
        cout << "data " << data << endl;
        Next = NULL;
    }
};

int main()
{
    Node *head = new Node(10);
    head->Next = new Node(20);
    head->Next->Next = new Node(30);
    cout << head->data << " " << head->Next->data << " " << head->Next->Next->data;
}
