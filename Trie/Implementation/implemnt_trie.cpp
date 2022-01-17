#include <iostream>
#include <unordered_map>
using namespace std;
class Node
{
public:
    char data;
    unordered_map<char, Node *> chldrn; // This Node* is a pointer which can have addrss of another Node class
    bool terminal;
    Node(char data) // parametrized constructor
    {
        this->data = data;
        terminal = false;
    }
};
class Trie
{
    Node *root; // root is Node* class pointer whch can have ptr of some othr class
    int cnt;

public:
    Trie()
    {
        root = new Node('\0'); // root is pntng to obj('\0') whch is in heap
        cnt = 0;
    }

    void insert(char *arr)
    {
        Node *temp = root; // creatng temp ptr ptng to root
        // cout << arr << endl;
        for (int i = 0; arr[i] != '\0'; i++) // iteratng all chars of character arr
        {
            char ch = arr[i];
            if (temp->chldrn.count(ch)) // this will chk whether ch is prsent in trie
            {
                temp = temp->chldrn[ch]; // if prsnt then cpy its ptr.
            }
            else
            {
                Node *n = new Node(ch); // making ch a new obj in heap
                temp->chldrn[ch] = n;   // addng this new ch char to prev temp
                temp = n;               // now nxt time chk in temp as it is n
            }
        }
        temp->terminal = true; // making true last char of char arr as terminal
    }
    bool find(char *arr)
    {
        Node *temp = root;
        for (int i = 0; arr[i] != '\0'; i++)
        {
            char ch = arr[i];
            if (temp->chldrn.count(ch) == 0)
            {
                return false;
            }
            else // 1st class char is '\0' whch is pntng to some more char lets say 's' in '\0' in hashmap we r havng node* which is havng ptr of obj 's'
            {
                temp = temp->chldrn[ch];
                // for (auto it : temp->chldrn[ch]->chldrn)
                // {
                //     cout << it.first << " |";
                // }
                // cout << root->data << endl;
            }
        }
        return temp->terminal; // if this is terminal char then return 1;
    }
};
int main()
{
    Trie t;
    char wrds[][6] = {"SaHil",
                      "apple",
                      "not",
                      "new"};
    char word[10];
    cin >> word;
    for (int i = 0; i < 4; i++)
    {
        t.insert(wrds[i]);
    }

    if (t.find(word))
    {
        cout << "present" << endl;
    }
    else
    {
        cout << "not present" << endl;
    }
}
