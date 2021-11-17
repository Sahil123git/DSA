#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
    vector<int> v = {1, 2, 3, 4, 5};
    vector<int> v1 = {2, 3, 1, 4, 5};

    if (is_permutation(v.begin(), v.end(), v1.begin()))
    {
        cout << "both vectors are same" << endl;
    }
    else
    {
        cout << "No " << endl;
    }

    string v11 = "sahil";
    string v12 = "lihas";

    if (is_permutation(v11.begin(), v11.end(), v12.begin()))
    {
        cout << "both strings are same ";
    }
    else
    {
        cout << "No ";
    }

    return 0;
}