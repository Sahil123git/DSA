#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> v;
    srand(time(NULL)); //this will not let the rand num to repeat
    for (int i = 0; i < n; i++)
    {
        int ele = rand() % n; //it is already dec by 1 so no need to dec it by 1
        v.push_back(ele);
    }
    for (auto it : v)
    {
        cout << it << " ";
    }
}
