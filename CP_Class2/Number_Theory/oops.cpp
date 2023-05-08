#include <iostream>
using namespace std;

class Rational
{
    int real, img;

public:
    Rational()
    {
        cout << "You called me\n";
    }

    friend ostream &operator<<(ostream &out, Rational &r);
    friend istream &operator>>(istream &in, Rational &r);

    Rational operator+(Rational &r2)
    {
        Rational out;
        out.real = real + r2.real;
        out.img = img + r2.img;

        cout << real << " " << r2.real << endl;
        cout << out.real << " " << out.img << "\n";
        return out;
    }
};

ostream &operator<<(ostream &out, Rational &r)
{
    out << r.real << " " << r.img << endl;
    return out;
}

istream &operator>>(istream &in, Rational &r)
{
    in >> r.real >> r.img;
    return in;
}

int main()
{
    Rational r1, r2, totR;
    cin >> r1 >> r2;

    totR = r1 + r2;
    cout << totR;
}
