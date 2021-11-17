#include <iostream> //https://www.geeksforgeeks.org/huffman-coding-greedy-algo-3/
#include <queue>
using namespace std;
class MinHeap_node
{
public:
    char data;
    int freq;
    MinHeap_node *left, *right; //these left and right are of MinHeap_node* data type
    //*MinHeap_node::left like this
    MinHeap_node(char data, int freq)
    {
        left = right = NULL;
        this->data = data;
        this->freq = freq;
    }
};
class cmp
{
public:
    bool operator()(MinHeap_node *left, MinHeap_node *right)
    {
        return (left->freq > right->freq);
    }
};
void print_codes(MinHeap_node *root, string str)
{
    if (!root)
    {
        return;
    }
    if (root->data != '#')
    {
        cout << root->data << " " << str << "\n";
    }
    print_codes(root->left, str + "0");
    print_codes(root->right, str + "1");
}
void Huffman_codes(char data[], int freq[], int size)
{
    MinHeap_node *top, *right, *left; //these pointers(*) are with MinHeap_node
    //these top, right, left all are of type of MinHeap_node
    priority_queue<MinHeap_node *, vector<MinHeap_node *>, cmp> pq; //min heap
    for (int i = 0; i < size; i++)
    {
        pq.push(new MinHeap_node(data[i], freq[i])); //new because we are pushing new class every time
    }
    while (pq.size() > 1)
    {
        left = pq.top();
        pq.pop();

        right = pq.top();
        pq.pop();

        top = new MinHeap_node('#', left->freq + right->freq);
        top->left = left;
        top->right = right;
        pq.push(top);
    }
    print_codes(pq.top(), "");
}
int main()
{

    char arr[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};
    //In the end there will be 1 node which will be having all nodes to their left and right
    int size = sizeof(arr) / sizeof(arr[0]);

    Huffman_codes(arr, freq, size);

    return 0;
}
