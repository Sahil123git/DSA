class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {

        int n = nums.size();
        k = k % n;
        int lft = n - k, end = n - 1;

        for (int i = lft; i <= end; i++, end--)
        {
            swap(nums[i], nums[end]);
        }

        end = lft - 1;
        for (int i = 0; i <= end; i++, end--)
        {
            swap(nums[i], nums[end]);
        }

        end = n - 1;
        for (int i = 0; i <= end; i++, end--)
        {
            swap(nums[i], nums[end]);
        }
    }
};