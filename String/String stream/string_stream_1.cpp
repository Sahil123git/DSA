#include <iostream>
#include <sstream>
using namespace std;
int main()
{
    stringstream ss;
    ss << 87 << " sdd " << 89 << " sd " << oct << 87;
    cout << "This is printed using ss.str() -> " << ss.str() << endl;

    string stri = "my name is sahil dussa id \0 gg";
    stringstream ssd(stri);
    cout << ssd.str() << endl; // ssd.str -> .str() we have to write this every time

    int count = 0;
    while (ssd >> stri) //this will see null charater and stops after finding null character
    {
        cout << stri << endl;
        count++;
    }
    cout << count;
    return 0;
}