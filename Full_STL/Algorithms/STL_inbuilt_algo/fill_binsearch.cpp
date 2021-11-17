#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
    //------------------------------------------fill
    vector<int> v = {1, 2, 3, 4, 5};
    fill(v.begin(), v.end(), 3);
    for (auto it : v) //time comp--O[n]
    {
        cout << it << " ";
    }
    cout << endl;

    string str = "sahil dussa";
    fill(str.begin(), str.end(), 'a');
    for (auto it : str)
    {
        cout << it << " ";
    }
    cout << endl;
    //----------------------------------------------Binary Searach
    vector<int> v1 = {1, 2, 3, 4, 5};                   //Time comp O[logN]
    auto it = (binary_search(v1.begin(), v1.end(), 7)); //return only 1 or 0
    cout << it << endl;                                 //found or not found
}