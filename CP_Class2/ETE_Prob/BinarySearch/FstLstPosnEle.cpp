int fndFirstPosn(vector<int> &nums, int tg)
{
    int st = 0, end = nums.size() - 1;
    while (st <= end)
    {
        int mid = st - (st - end) / 2;

        if (nums[mid] == tg && (mid == 0 || nums[mid - 1] != tg))
        {
            return mid;
        }
        else if (nums[mid] >= tg)
        {
            end = mid - 1;
        }
        else
        {
            st = mid + 1;
        }
    }
    return -1;
}

int fndLstPosn(vector<int> &nums, int tg)
{
    int st = 0, lst = nums.size() - 1;
    while (st <= lst)
    {
        int mid = st - (st - lst) / 2;

        if (nums[mid] == tg && (mid == nums.size() - 1 || nums[mid + 1] != tg))
        {
            return mid;
        }
        else if (nums[mid] > tg)
        { // becoz we want lst posn not first so we'll move st not lst when same is found
            lst = mid - 1;
        }
        else
        {
            st = mid + 1;
        }
    }
    return -1;
}

vector<int> searchRange(vector<int> &nums, int target)
{
    int fst = fndFirstPosn(nums, target);
    int lst = fndLstPosn(nums, target);

    return {fst, lst};
}