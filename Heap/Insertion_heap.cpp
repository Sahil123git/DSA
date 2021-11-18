#include <iostream>
#include <vector>
using namespace std;
class heap
{
    vector<int> vt;
    bool min_heap;
    bool compare(int ch_ele, int par_ele)
    {
        if (min_heap)
        {
            return ch_ele < par_ele; //If parent ele is greater, then we'll swap becoz in min heap top ele must be smaller
        }
        else
        {
            return ch_ele > par_ele; //If parent ele is smaller, then we'll swap becoz in max heap top ele must be greater
        }
    }
    void heapify(int ind)
    {
        int left = ind * 2;
        int right = left + 1;

        int min_ind = ind;
        int last_ind = vt.size() - 1;
        if (left <= last_ind && compare(vt[left], vt[ind]))
        {
            min_ind = left; //checking top and left ind ele
        }
        if (right <= last_ind && compare(vt[right], vt[min_ind]))
        {
            min_ind = right; //checking min_ind ele and right ind ele
        }

        if (min_ind != ind) //this will also act as base case becoz this is only calling again
        {
            swap(vt[min_ind], vt[ind]);
            heapify(min_ind); //using  this we are going deeper in tree
        }
    }

public:
    heap(bool type = true, int default_size = 10) //CONSTRUCTOR
    {
        vt.reserve(default_size);
        vt.push_back(-1);
        min_heap = type; //bydefault minheap
    }
    void push(int ele) //O(log N)
    {
        vt.push_back(ele);
        int ind = vt.size() - 1;
        int parent_ind = ind / 2;

        while (ind > 1 && compare(vt[ind], vt[parent_ind]))
        {
            swap(vt[ind], vt[parent_ind]);
            ind = parent_ind;
            parent_ind = parent_ind / 2; //the last index which will become parent is 1 index becoz child ind can't be equal to 1 the last index for child is 2.
        }
    }
    int top()
    {
        return vt[1];
    }

    void pop() //O(log N)
    {
        int last = vt.size() - 1;
        swap(vt[last], vt[1]); //swap 1st and lst ele of heap
        vt.pop_back();

        heapify(1);
    }
    bool empty()
    {
        return vt.size() == 1;
    }
};
int main()
{
    heap h(0, 6); //1 for min heap
    int n;
    //if we'll start vector from index 0 it's children will become 1 and 0
    //as 2*0 is 0 and 2*0+1 is 1 so we are having 1 less children node
    //so start vector from 1 so that it will become
    //2*1=2(left node) and 2*1+1=3(right node)
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int ele;
        cin >> ele;
        h.push(ele);
    }

    while (!h.empty())
    {
        cout << h.top() << " ";
        h.pop();
    }
}