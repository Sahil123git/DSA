#include <iostream>
#include <vector>
using namespace std;

double median_arr(vector<int> arr1, vector<int> arr2)
{
    if (arr2.size() < arr1.size())
    {
        return median_arr(arr2, arr1);
    }
    int n1 = arr1.size(), n2 = arr2.size();
    int low = 0, high = n1;
    while (low <= high)
    {
        int cut1 = (low + high) >> 1;
        int cut2 = ((n1 + n2 + 1) >> 1) - cut1;

        int left1 = (cut1 == 0 ? INT32_MIN : arr1[cut1 - 1]);
        int left2 = (cut2 == 0 ? INT32_MIN : arr2[cut2 - 1]);

        int right1 = (cut1 == n1 ? INT32_MAX : arr1[cut1]);
        int right2 = (cut2 == n2 ? INT32_MAX : arr2[cut2]);
        // cout << left1 << " " << left2 << " " << right1 << " " << right2 << endl;
        if (left1 <= right2 && left2 <= right1)
        {
            if (((n1 + n2) & 1) == 0) //for even no's of ele
            {
                return ((max(left1, left2) + min(right1, right2)) / 2.0); //dividing with 2.0 to chng the data type to double
            }
            else //for odd no's of ele
            {
                return max(left1, left2);
            }
        }
        else if (left1 > right2)
        {
            high = cut1 - 1;
        }
        else
        {
            low = cut1 + 1;
        }
    }
    return 0.0;
}

int main()
{
    int n1;
    cin >> n1;
    vector<int> arr1;
    for (int i = 0; i < n1; i++)
    {
        int ele;
        cin >> ele;
        arr1.push_back(ele);
    }
    int n2;
    cin >> n2;
    vector<int> arr2;

    for (int i = 0; i < n2; i++)
    {
        int ele;
        cin >> ele;
        arr2.push_back(ele);
    }

    cout << median_arr(arr1, arr2);
    return 0;
}