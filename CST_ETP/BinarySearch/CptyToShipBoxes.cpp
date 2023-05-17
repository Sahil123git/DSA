class Solution
{
public:
    // Binary Search on Ans Concept

    bool chk(int cpty, vector<int> &wgt, int days)
    { // O(n)
        int tempCpty = cpty, tempDays = 1, n = wgt.size();

        for (int i = 0; i < n; i++)
        {
            if (tempCpty >= wgt[i])
            {
                tempCpty -= wgt[i];
            }
            else
            {
                tempCpty = cpty;
                tempDays++;
                tempCpty -= wgt[i];
            }
        }

        if (days >= tempDays)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    // fixing Low and high for BS
    // Here we r keeping Low of BS as max ele of weight array, this will take max num of days (size of weight arr days)
    // and High as sum of weight array, this will take min num of days (1 day)

    /* Binary Search Condns:

     * if we r getting ans in less days, so to increase days we can dec the
       cpty by shifting (High = mid - 1)

     * if we r getting ans in more days so decrease days we can inc the cpty of
       per day by shifting (Low = mid + 1)

    */

    int shipWithinDays(vector<int> &weights, int days)
    {
        int mini = 0, maxi = 0;
        mini = *max_element(weights.begin(), weights.end());
        maxi = accumulate(weights.begin(), weights.end(), 0);

        int low = mini, high = maxi, cpty = -1;
        cout << low << " " << high << endl;
        while (low <= high)
        { // O(log(n) * n)
            int mid = low + (high - low) / 2;

            if (chk(mid, weights, days))
            {
                cpty = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return cpty;
    }
};