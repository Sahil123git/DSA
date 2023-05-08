int maxProduct(vector<int> &nums)
{
    int prod1 = 1, prod2 = 1;
    int n = nums.size();

    int maxVal1 = INT_MIN, maxVal2 = INT_MIN;

    for (int i = 0; i < n; i++)
    { // chk from left side
        prod1 *= nums[i];
        maxVal1 = max(prod1, maxVal1);
        if (prod1 == 0)
        {
            prod1 = 1;
        }
    }

    for (int i = n - 1; i >= 0; i--)
    { // chk from right side
        prod2 *= nums[i];
        cout << prod2 << endl;
        maxVal2 = max(prod2, maxVal2);
        if (prod2 == 0)
        {
            prod2 = 1;
        }
    }

    // cout << prod1 <<" "<<prod2<<endl;
    // cout << maxVal1<<" "<<maxVa
    return max(maxVal1, maxVal2);
}
// https://leetcode.com/problems/maximum-product-subarray/description/