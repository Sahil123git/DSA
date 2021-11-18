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
class Queue
{
public:
    Node *add_front;
    Node *add_rear;
    Queue()
    {
        add_front = NULL;
        add_rear = NULL;
    }

    int size = 0;
    // void size_()
    // {
    //     size++;
    // }
    bool isEmpty()
    {
        if (size == 0)
        {
            return 1;
        }
        return 0;
    }
    void enque(int ele)
    {
        Node *temp = new Node(ele);
        if (add_front == NULL)
        {
            add_front = add_rear = temp;
            return;
        }
        add_rear->next = temp;
        add_rear = temp;
        size++;
    }
    int deque()
    {
        if (add_front == NULL)
        {
            return -1;
        }
        Node *temp = add_front;
        int ele = add_front->data;
        add_front = add_front->next;
        if (add_front == NULL)
        {
            add_rear = NULL;
        }
        size--;
        delete (temp);
        return ele;
    }
    int getfront()
    {
        return add_front->data;
    }
    int getRear()
    {
        return add_rear->data;
    }
};
int main()
{
    Queue q;
    // q.enque(2);
    // q.enque(3);
    // cout << q.deque() << " ";
    // q.enque(4);
    // cout << q.deque() << " ";
    q.enque(10);
    cout << q.deque() << " " << endl;
    q.enque(20);
    q.enque(30);
    q.enque(40);
    q.enque(50);
    cout << q.getfront() << " " << q.getRear() << " Front and Rear" << endl;
    cout << q.deque() << " ";
    cout << q.deque() << " " << endl;
    q.enque(60);
    q.enque(70);
    q.enque(80);
    cout << q.getfront() << " " << q.getRear() << " Front and Rear" << endl;
    cout << q.size;

    return 0;
}