int missingNumber(vector<int> &nums)
{
    int sum = 0, n = nums.size();

    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
    }

    int orgSum = (n * (n + 1)) / 2; // sum of fst n natural Nums

    return orgSum - sum;
}