#include <iostream>
using namespace std;
class Trie
{
public:
    Trie *arr[26];
    // bool ended;
    Trie()
    {
        for (int i = 0; i < 26; i++)
        {
            arr[i] = NULL;
        }
        // ended = 0;
    }
};
void insert(string str, Trie *root)
{
    // cout << 'd';
    for (int i = 0; i < str.size(); i++)
    {
        if (root->arr[str[i] - 'a'] == NULL)
        {
            root->arr[str[i] - 'a'] = new Trie();
            root = root->arr[str[i] - 'a'];
        }
        else
        {
            root = root->arr[str[i] - 'a'];
        }
    }
    // root->ended = 1;
}
bool chk_sub(string str, Trie *root)
{

    for (int i = 0; i < str.size(); i++)
    {
        if (root->arr[str[i] - 'a'] == NULL)
        {
            return false;
        }
        else
        {
            root = root->arr[str[i] - 'a'];
        }
    }
    return 1;
}
int main()
{
    Trie *root = new Trie();
    Trie *cur1 = root;
    Trie *cur2 = root;

    string str, substr;
    cin >> str >> substr;
    for (int i = 0; i < str.size(); i++)
    {
        insert(str.substr(i, str.size()), cur1);
    }
    cout << chk_sub(substr, cur2);
}