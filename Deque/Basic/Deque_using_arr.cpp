#include <iostream>
using namespace std;
class Deq
{
    int size, cap;
    int *arr;

public:
    Deq(int c)
    {
        cap = c;
        size = 0;
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
        arr[size] = ele;
        size++; //we inc this size by 1, thatswhy we dec size by 1 at rest places
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
        return arr[size - 1];
    }
    void insert_front(int ele)
    {
        if (isFull())
        {
            return;
        }
        for (int i = size - 1; i >= 0; i--) //inc size because it is increased
        {
            arr[i + 1] = arr[i];
        }
        arr[0] = ele;
        size++;
    }
    void delete_front()
    {
        if (isEmpty())
        {
            return;
        }
        for (int i = 0; i < size - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        size--;
    }
    int getfront()
    {
        if (isEmpty())
        {
            return -1;
        }
        return arr[0];
    }
};
int main()
{
    Deq d(4);
    d.insert_front(10);
    d.insert_front(30);
    d.insert_rear(40);
    d.delete_rear();
    d.insert_rear(50);
    d.delete_front();
    cout << d.getfront() << " ";
    cout << d.getRear();
}