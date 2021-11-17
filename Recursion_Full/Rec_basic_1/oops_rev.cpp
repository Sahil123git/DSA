#include <iostream>
using namespace std;
class st
{
private:
    int real, img;

public:
    friend ostream &operator<<(ostream &out, st &c);
    friend istream &operator>>(istream &in, st &c);
    friend st operator+(st c, st c1);
};

int main()
{
    st c1, c2, c3;
    cin >> c1;
    cin >> c2;
    c3 = c1 + c2;
    cout << c3;
}
ostream &operator<<(ostream &ot, st &c)
{
    ot << c.real << "+i" << c.img;
    return ot;
}
st operator+(st c, st c1)
{
    st temp;
    temp.real = c.real + c1.real;
    temp.img = c.img + c1.img;
    return temp;
}
istream &operator>>(istream &ot, st &c)
{
    ot >> c.real >> c.img;
    return ot;
}