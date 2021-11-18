#include <iostream> //Queue is FIFO
using namespace std;
class queue
{
public:
    int size, cap;
    int *arr;
    queue(int cap)
    {
        this->cap = cap;
        size = 0;
        arr = new int[cap];
    }
    bool isFull()
    {
        return (size == cap);
    }
    bool isEmpty()
    {
        return (size == 0);
    }
    void enqueue(int x) //enqueue means to put ele in the end
    {
        if (isFull())
        {
            return;
        }
        arr[size] = x;
        size++;
    }
    void deque() //deque means to remove ele from front
    {
        if (isEmpty())
        {
            return;
        }
        for (int i = 0; i < size - 1; i++) //only this is the extra thing we have to do if we will not use circular arr
        {
            arr[i] = arr[i + 1];
        }
        size--;
    }
    int getFront()
    {
        if (isEmpty())
        {
            return -1;
        }
        else
        {
            return arr[0];
        }
    }
    int getRear()
    {
        if (isEmpty())
        {
            return -1;
        }
        return arr[size - 1];
    }
};
int main()
{
    queue w(8);
    w.enqueue(1); //1
    w.enqueue(2); //1 2
    cout << w.getFront() << " ";
    cout << w.getRear() << " " << endl;

    w.deque();    //2
    w.enqueue(3); //2 3
    w.enqueue(4); //2 3 4
    cout << w.getFront() << " ";
    cout << w.getRear() << " ";

    return 0;
}
