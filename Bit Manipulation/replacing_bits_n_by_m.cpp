#include <iostream>
using namespace std;
int main()
{
    int ele, i, j, sub;
    cin >> ele >> i >> j >> sub;

    int chk_a = (ele & (-1 << j));
    int chk_b = (1 << (i - 1)) - 1;

    ele = chk_a | chk_b; //Unsetting the old bits where we will add new bits

    sub = (sub << (i - 1)); //left shifting the bits which we have to enter
    cout << (sub | ele);    //now doing or to replace new with old bits
    return 0;
}