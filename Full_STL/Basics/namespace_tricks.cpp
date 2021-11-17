#include <bits/stdc++.h>
using namespace std;
namespace sahil
{
    int val = 20;
    int get_val()
    {
        return (val * 2);
    }
}

int main()
{
    double var = 10.0;
    
    cout << sahil::get_val() << " " << sahil::val << " " << var << endl;
    return 0;
}
