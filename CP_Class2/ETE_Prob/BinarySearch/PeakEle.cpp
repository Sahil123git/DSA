int findPeakElement(vector<int> &nums)
{
    int low = 0, high = nums.size() - 1;

    if (nums.size() == 1)
    {
        return 0;
    }
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (mid > 0 && mid < nums.size() - 1)
        {
            if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
            { // if curr ele is greater than left and right ele
                //  cout <<"here";
                return mid;
            }
            else if (nums[mid] < nums[mid - 1])
            { // if curr ele is smaller than left ele then chk there
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        else if (mid == 0)
        {
            if (nums[mid] > nums[mid + 1])
            {
                return mid;
            }
            else
            {
                return mid + 1; // when you will reach at lst ind? when you have checked all other indexies.
            }
        }

        else if (mid == nums.size() - 1)
        {
            if (nums[mid] > nums[mid - 1])
            {
                return mid;
            }
            else
            {
                return mid - 1; // when you will reach at fst ind? when you have checked all other indexies.
            }
        }
    }
    return -1;
}