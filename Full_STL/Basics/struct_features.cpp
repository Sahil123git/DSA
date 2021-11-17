#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    string str;
    char ch;
    node()
    {
        data = 0;
        str = "nothing";
        ch = 's';
    }
    node(int data_, string str_, char ch_ = ' ')
    {
        data = data_;
        str = str_;
        ch = ch_;
    }
};
int main()
{
    node *one = new node(10, "sahil", 's'); //this is efficient and better app so use this
    cout << one->ch << " " << one->data << " " << one->str << endl;

    node one_1;
    one_1.ch = 'A';
    one_1.str = "RAM";
    one_1.data = 18;
    cout << one_1.ch << " " << one_1.str << " " << one_1.data;

    return 0;
}