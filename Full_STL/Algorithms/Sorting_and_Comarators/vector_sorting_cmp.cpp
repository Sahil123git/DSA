#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool comp(int a, int b)
{
    return (a > b); //here inbuilt function says that if u want to swap
                    //then return false and if not then return true
}
//here we are not swapping if a is greater than b so it will sort in descending order

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

    sort(v.begin(), v.end(), comp);

    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
}