#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *Next; //Self Refrential
    Node(int data)
    {
        cout << "Data recieved by constructor " << data << endl;
        this->data = data;
        Next = NULL;
    }
};
int main()
{
    Node *head = new Node(10);
    Node *temp1 = new Node(20);
    Node *temp2 = new Node(30);
    head->Next = temp1;
    temp1 = head;
    
    cout << head->data << " " << temp1->data << " " << temp2->data;
    return 0;
}