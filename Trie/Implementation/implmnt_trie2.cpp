#include <iostream>
using namespace std;
class Trie
{
public:
    Trie *nxt[26]; // it is arr of Trie ptr
    bool ended;
    Trie()
    {
        for (int i = 0; i < 26; i++)
        {
            nxt[i] = NULL;
        }
        ended = 0;
    }
};
void insert(Trie *root, string s) // arguments passing class ptr and string s
{
    for (int i = 0; i < s.size(); i++)
    {
        if (root->nxt[s[i] - 'a'] == NULL)
        {
            root->nxt[s[i] - 'a'] = new Trie(); // if char is not prsnt create new class
            root = root->nxt[s[i] - 'a'];
        }
        else
        {
            root = root->nxt[s[i] - 'a'];
        }
    }
    root->ended = 1;
}
bool inTrie(Trie *root, string s)
{
    for (int i = 0; i < s.size(); i++)
    {
        if (root->nxt[s[i] - 'a'] == NULL) // if char is not prsnt
        {
            return 0;
        }
        else
        {
            root = root->nxt[s[i] - 'a'];
        }
    }
    return root->ended;
}
int main()
{
    Trie *root = new Trie();
    Trie *cur1 = root;
    Trie *cur2 = root;
    int n;
    cin >> n;
    string arr[10];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        insert(cur1, arr[i]);
    }
    cout << inTrie(cur2, "aaj");
}