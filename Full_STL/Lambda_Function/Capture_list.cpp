#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int x = 10, y = 20; //&means they are passed by ref

    auto fun_name1 = [&](int a)
    {
        x += a;
        y += a;
    };
    fun_name1(100);
    cout << x << " " << y << endl;
    //-----------------------------------------------------------------------------

    int x1 = 10, y1 = 20; //because of mutable keyword we could access y1
    auto fun_name2 = [=, &x1](int a) mutable
    {
        x1 += a; //here only x1 is passed by ref
        y1 += a; //use this but can't modify these values
    };
    fun_name2(100);
    cout << x1 << " " << y1 << endl;
    //-----------------------------------------------------------------------------

    int x3 = 10, y3 = 20; //because of mutable keyword we could use
    auto fun_name4 = [&, x3](int a) mutable
    {
        x3 += a; //use this but can't modify this values
        y3 += a; //here only y3 is passed by ref
    };
    fun_name4(100);
    cout << x3 << " " << y3 << endl;
    //-----------------------------------------------------------------------------

    static int x2 = 10, y2 = 20;
    auto fun_name3 = [](int a)
    {
        x2 += a;
        y2 += a;
    };
    fun_name2(100);
    cout << x2 << " " << y2;

    return 0;
}