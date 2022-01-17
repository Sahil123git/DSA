#include <iostream>
#include <unordered_map>
using namespace std; // https://practice.geeksforgeeks.org/problems/shortest-unique-prefix-for-every-word/1/#
class Node
{
public:
    char data;
    int freq;
    unordered_map<char, Node *> chldrn; // This Node* is a pointer which can have addrss of another Node class
    bool terminal;
    Node(char data) // parametrized constructor
    {
        this->data = data;
        terminal = false;
        freq = 0;
    }
};
class Trie
{
    Node *root; // root is Node* class pointer whch can have ptr of some othr class
    int cnt;

public:
    Trie()
    {
        root = new Node('\0'); // root is pntnt to obj('\0') whch is in heap
        cnt = 0;
    }

    void insert(char *arr)
    {
        Node *temp = root; // giving adder of '\0' to temp Node* pointer
        // cout << arr << endl;
        for (int i = 0; arr[i] != '\0'; i++) // iteratng all chars of char arr
        {
            char ch = arr[i];
            if (temp->chldrn.count(ch)) // this will chk whether ch is prsent in trie
            {
                temp = temp->chldrn[ch]; // if prsnt then cpy its ptr.
                temp->freq += 1;
            }
            else
            {
                Node *n = new Node(ch); // making ch a new class in heap
                temp->chldrn[ch] = n;   // addng this new ch char to pre temp
                temp = n;               // now nxt time chk in temp as it is n
                temp->freq += 1;
            }
        }
        temp->terminal = true; // making true last char of char arr as terminal
    }
    string find(char *arr)
    {
        Node *temp = root;
        temp = temp->chldrn[arr[0]]; // gvng temp addr of arr[0] class
        // cout << temp->data << endl;
        string ans;
        for (int i = 1; arr[i] != '\0'; i++)
        {
            char ch = arr[i]; // ch is 1 ptr forward to temp->data
            if (temp->freq == 1)
            {
                // cout << temp->data << "><";
                ans.push_back(temp->data);
                return ans;
            }
            else
            {
                ans.push_back(temp->data);
                temp = temp->chldrn[ch];
            }
        }
        if (temp->freq == 1) // chkng freq of last char
        {
            // cout << temp->data << "><";
            ans.push_back(temp->data);
            return ans;
        }
        return " "; // if 2 string are totaly same then return " ";
    }
};
int main()
{
    Trie t;
    char wrds[][17] = {"zebra", "dog", "duck", "dove"};
    char word[10];
    // cin >> word;
    for (int i = 0; i < 4; i++)
    {
        t.insert(wrds[i]);
    }

    for (int i = 0; i < 4; i++)
    {
        cout << t.find(wrds[i]) << endl;
    }
}
