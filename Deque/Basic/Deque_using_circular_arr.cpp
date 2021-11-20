#include <iostream>
using namespace std;
class Deq
{
    int size, cap;
    int *arr, front;

public:
    Deq(int c)
    {
        cap = c;
        size = 0;
        front = 0;
        arr = new int[c];
    }
    bool isFull()
    {
        return (size == cap);
    }
    bool isEmpty()
    {
        return (size == 0);
    }
    void insert_rear(int ele)
    {
        if (isFull())
        {
            return;
        }
        int new_rear = (front + size) % cap;
        arr[new_rear] = ele;
        size++;
    }
    void delete_rear()
    {
        if (isEmpty())
        {
            return;
        }
        size--;
    }
    int getRear()
    {
        if (isEmpty())
        {
            return -1;
        }
        return arr[(front + size - 1) % cap];
    }
    void insert_front(int ele)
    {
        if (isFull())
        {
            return;
        }
        front = (front + cap - 1) % cap; //when dequeue is empty will get added to last block of arr
        arr[front] = ele;
        size++;
    }
    void delete_front()
    {
        if (isEmpty())
        {
            return;
        }
        front = (front + 1) % cap;
        size--;
    }
    int getfront()
    {
        if (isEmpty())
        {
            return -1;
        }
        return arr[front];
    }
};
int main()
{
    Deq d(4);
    d.insert_front(10);
    // d.insert_front(30);
    d.insert_rear(40);
    d.delete_rear();
    d.delete_front();
    d.insert_rear(50);
    cout << d.getfront() << " ";
    cout << d.getRear();
}