#include <iostream>
using namespace std;
class Functor
{
public:
    void operator()(string str) //overloading parenthesis
    {
        cout << "This operator is called " << str;
    }
};
int main()
{
    Functor ft;

    string str;
    cin >> str;

    ft(str);
}