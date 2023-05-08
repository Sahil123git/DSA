int search(vector<int> &nums, int target)
{
    int fst = 0, lst = nums.size() - 1;

    while (fst <= lst)
    {
        int mid = fst - (fst - lst) / 2;
        // cout << mid <<endl;
        if (nums[mid] == target)
        {
            return mid;
        }

        else if (nums[fst] <= nums[mid])
        { // if ele which are left to mid r sorted
            if (nums[fst] <= target && nums[mid] > target)
            {
                lst = mid - 1;
            }
            else
            {
                fst = mid + 1;
                // cout << nums[fst] <<" "<< nums[mid] <<" "<< fst << endl;
            }
        }
        else
        { // if ele right to mid r sorted
            if (nums[mid] < target && target <= nums[lst])
            {
                // cout << nums[fst] <<" "<< nums[mid]<<endl;
                fst = mid + 1;
            }
            else
            {
                lst = mid - 1;
            }
        }
    }
    return -1;
}