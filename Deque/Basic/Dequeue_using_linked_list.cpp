#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int data)
    {
        this->data = data;
        next = NULL;
        prev = NULL;
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
    int size_()
    {
        size++;
        return size;
    }
    bool isEmpty()
    {
        if (size == 0)
        {
            return 1;
        }
        return 0;
    }
    void insert_rear(int ele)
    {
        Node *temp = new Node(ele);
        if (add_front == NULL)
        {
            add_front = add_rear = temp;
            return;
        }
        add_rear->next = temp;
        temp->prev = add_rear;
        add_rear = temp;
        size++;
    }
    void insert_front(int ele)
    {
        Node *temp = new Node(ele);
        if (add_front == NULL)
        {
            add_front = add_rear = temp;
            return;
        }
        temp->next = add_front;
        add_front->prev = temp;
        add_front = temp;
        size++;
    }
    int delete_front()
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
            size--;
            return ele;
        }
        add_front->prev = NULL; // w/o this add_front->prev will remain prev front deleted ele
        size--;
        delete (temp);
        return ele;
    }
    int delete_rear()
    {
        if (add_front == NULL)
        {
            return -1;
        }
        Node *temp = add_rear->prev;
        // cout << temp->data << " prev" << endl;
        int ele = add_rear->data;
        if (temp == NULL)
        {
            add_front = NULL;
            size--;
            return ele;
        }
        add_rear = temp;
        Node *del = temp->next;
        add_rear->next = NULL;
        delete (del);
        size--;
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
    // q.insert_rear(2);
    // q.insert_rear(4);
    // cout << q.getRear() << " Rear " << endl;
    // cout << q.getfront() << " Front " << endl;
    // q.insert_rear(5);
    // q.insert_front(3);
    // q.insert_front(1);
    // cout << q.delete_front() << " ";
    // cout << q.delete_rear() << " " << endl;

    q.insert_front(80);
    q.insert_front(92);
    q.insert_front(96);
    cout << q.delete_front() << " ";
    q.insert_rear(54);
    cout << q.delete_rear() << " ";
    cout << q.getRear() << " " << q.getfront() << endl;
    cout << q.size_();
    return 0;
}