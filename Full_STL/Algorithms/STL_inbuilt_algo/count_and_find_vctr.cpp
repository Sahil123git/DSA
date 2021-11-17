#include <iostream>
#include <numeric>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int ele;
        cin >> ele;
        v.push_back(ele);
    }
    int count_ele = count(v.begin(), v.end(), 2); //count the freq of 2
    cout << "freq of the ele is " << count_ele << endl;

    auto find_ele = find(v.begin(), v.end(), 2);
    if (find_ele != v.end()) //if ele is not in the vector then it will give index equal to end of vector
    {
        cout << "found at " << find_ele - v.begin(); //to find the index of that ele
    }
    else
    {
        cout << "Not found";
    }

    
    return 0;
}