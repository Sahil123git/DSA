#include <iostream>  //Queue is FIFO
using namespace std; //gfg another o[1] deque code
class queue          //https://practice.geeksforgeeks.org/problems/implement-queue-using-array/1/?track=DSA-Foundation-Queue&batchId=238#
{
public:
    int front, rear, cap;
    int *arr, cursize, maxis;
    queue(int cap)
    {
        this->cap = cap;
        maxis = cap;
        front = 0;
        rear = maxis - 1;
        cursize = 0;
        arr = new int[cap]; //dynamic size arr
    }
    bool isFull()
    {
        return (cursize == cap);
    }
    bool isEmpty()
    {
        return (cursize == 0);
    }
    void enqueue(int x) //enqueue means to push ele in the end
    {
        if (isFull())
        {
            return;
        }
        rear = (rear + 1) % maxis; //here we are using mode so that it will not overload
        arr[rear] = x;             //and changing rear and cursize
        cursize++;
    }
    void deque() //deque means to remove ele from front
    {
        if (isEmpty()) //we are not changing the size of rear because we are dec
        {              //the size of cursize which will let ele to push
            return;
        }
        front = (front + 1) % maxis; //using this we are inc the front and dec the cursize
        cursize--;                   // so that nxt time the ele will occupy this index space
    }
    int getFront()
    {
        if (isEmpty())
        {
            return -1;
        }
        return arr[front];
    }
    int getRear()
    {
        if (isEmpty())
        {
            return -1;
        }
        // int size = (cursize + 1) % maxis;
        // cout << cursize << " R " << endl;
        return arr[front + cursize - 1]; //this formula to find the rear ele Index
        // return arr[rear]; //or u can use directly this also
    }
};
int main()
{
    queue w(8);
    w.enqueue(1); //1
    w.enqueue(2); //1 2
    w.enqueue(5); //1 2 5
    w.enqueue(6); //1 2 5 6
    cout << w.getFront() << " ";
    cout << w.getRear() << " " << endl;

    w.deque();    //2 5 6
    w.deque();    //5 6
    w.deque();    //6
    w.enqueue(3); //6 3
    w.enqueue(4); //6 3 4
    cout << w.getFront() << " ";
    cout << w.getRear() << " ";

    return 0;
}
