vector<int> twoSum(vector<int> &nums, int target)
{
    int ind1 = -1, ind2 = -1;
    unordered_map<int, int> ump;

    for (int i = 0; i < nums.size(); i++)
    {
        ump[nums[i]] = i + 1;
    }

    for (int i = 0; i < nums.size(); i++)
    {
        if (ump[target - nums[i]] > 0)
        {
            ind1 = ump[target - nums[i]] - 1;
            ind2 = i;

            if (ind1 == ind2)
            {
                continue;
            }
            else
            {
                break;
            }
        }
    }

    return {ind1, ind2};
}