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
    int low = 10, high = 100;
    int range = high - low + 1; //now it will give ele till (0-91) as last ele is 91
                                //so thatswhy have added 1 to it as 91 will not get added

    srand(time(NULL)); //this will not let the rand num to repeat
    for (int i = 0; i < n; i++)
    {
        int ele = rand() % range; //it is already dec by 1 so no need to dec it by 1
        ele += low;
        v.push_back(ele);
    }
    for (auto it : v)
    {
        cout << it << " ";
    }
}
