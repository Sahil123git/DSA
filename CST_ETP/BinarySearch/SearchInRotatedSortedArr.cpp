class Solution
{
public:
    bool search(vector<int> &nums, int target)
    {
        int low = 0, high = nums.size() - 1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            cout << mid << endl;
            if (target == nums[mid])
            {
                return 1;
            }

            if (nums[low] == nums[mid] && nums[mid] == nums[high])
            { // so that we can get rid of duplicates
                low++;
                high--;
            }
            else if (nums[mid] <= nums[high])
            {
                if (target > nums[mid] && target <= nums[high])
                {
                    low = mid + 1;
                }
                else
                {
                    high = mid - 1;
                }
            }
            else
            {
                if (target >= nums[low] && target < nums[mid])
                {
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                }
            }
        }

        return 0;
    }
};