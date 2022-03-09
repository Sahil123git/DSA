#include <iostream>
using namespace std;
class Node
{
public:
    string key; // we are using this to find ind
    int value;  // no use only for storing info
    Node *next;
    bool chkr;
    Node(string key, int val)
    {
        this->key = key;
        value = val;
        next = NULL;
        chkr = 1; // so tht it can work for both rehashing recursive deltn and for del of key
    }
    ~Node() // this will delete next ptng LL
    {
        if (next != NULL)
        {
            // cout << key << " " << value << " Deleting " << endl;
            if (chkr) // allowed to del recursively next node only while rehashing
            {
                delete next;
            }
            // means other will get deleted recursively
        }
    }
};
class Hashtable
{
    Node **table; // ptr to arr of ptrs
    // table data type is Node**
    int cur_size, table_size;
    int hash_func(string key) // this will make ind for key
    {
        int idx = 0;
        int p = 1;
        for (int i = 0; i < key.length(); i++)
        {
            idx = idx + (key[i] * p) % table_size;
            idx = idx % table_size;
            p = (p * 27) % table_size;
        }
        return idx;
    }
    void rehash() // rehashing inc size of table
    {
        Node **oldTable = table;
        int old_size = table_size;
        table_size = 2 * old_size;
        // cout << table_size << " " << old_size << endl;
        table = new Node *[table_size];
        for (int i = 0; i < table_size; i++)
        {
            table[i] = NULL;
        }
        cur_size = 0;
        for (int i = 0; i < old_size; i++)
        {
            Node *iter = oldTable[i]; // passing index of, head of LL
            while (iter != NULL)
            {
                insert(iter->key, iter->value);
                iter = iter->next;
            }
            if (oldTable[i] != NULL) // if the value at index is not NULL then only we can delete
            {
                // cout << "hcl" << oldTable[i] << endl;
                // cout << "h";
                delete oldTable[i]; // it is having head of LL
                // if there are more LL then that will also get deleted
            }
        }
        delete[] oldTable; // deleting whole arr of ptrs prev table
    }

public:
    Hashtable(int table_size = 7)
    {
        this->table_size = table_size;
        table = new Node *[table_size];

        /*this is like
        Node** table = new Node* [table_size];
        int* arr = new int[5]; (arr size = 5)
        ____________________________________________
        | table datatype : Node**                   |
        | every ele in the table data type : Node*  |
        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
        cur_size = 0;
        for (int i = 0; i < table_size; i++) // initially initializing all ele with NULL
        {
            table[i] = NULL;
        }
    }
    void insert(string key, int value) //
    {
        int ind = hash_func(key);
        Node *n = new Node(key, value);

        n->next = table[ind]; // inserting new ele at the head of LL
        table[ind] = n;
        cur_size++;

        // rehash.....
        float load_factor = cur_size / (1.0 * table_size);
        // cout << load_factor << "load " << cur_size << " " << table_size << endl;
        if (load_factor > 0.7)
        {
            // print();
            rehash();
        }
    }
    int *search(string key)
    {
        int idx = hash_func(key);
        Node *iter = table[idx];
        while (iter != NULL)
        {
            if (iter->key == key)
            {
                return &iter->value; // returning address
            }
            iter = iter->next;
        }
        return nullptr; // if not found then returning nullptr
    }
    void deletion(string key)
    {
        int idx = hash_func(key);
        Node *iter = table[idx]; // this will give head of the LL in the arr
        while (iter != NULL && iter->next != NULL)
        {
            if (iter->next->key == key)
            {
                // cout << "here";
                Node *nxt = iter->next->next;
                iter->next->chkr = 0;
                delete iter->next;
                iter->next = nxt; // for iteration
                return;           // becoz only have to del 1 ele at a time
            }
            iter = iter->next;
        }
        if (table[idx] != NULL && table[idx]->key == key)
        {
            table[idx]->chkr = 0;
            delete (table[idx]);
            table[idx] = NULL;
        }
    }
    
    // here in this overloaded operator we r returning by reference
    // so that changes will be visible
    int &operator[](string key) // operator overloading
    {
        int *ptr = search(key);
        if (ptr == NULL)
        {
            int garbage;
            insert(key, garbage);
            ptr = search(key);
        }
        return *ptr; //* so that it will return a value not addrs
    }
    void print() // To view how ele are present in the Arr of ptr
    {
        for (int i = 0; i < table_size; i++)
        {
            cout << "Bucket " << i << "-->";
            Node *iter = table[i];
            while (iter != NULL)
            {
                cout << iter->key << "--";
                iter = iter->next;
            }
            cout << endl;
        }
    }
};
