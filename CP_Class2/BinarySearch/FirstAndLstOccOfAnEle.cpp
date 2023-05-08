class Solution
{ // Binary Search Approach
public:
    int fnd1st(vector<int> &nums, int fst, int lst, int tg)
    { // fnding 1st occ of tg

        while (fst <= lst)
        {

            int mid = (fst + lst) / 2;
            if ((mid == 0 || nums[mid] != nums[mid - 1]) && (nums[mid] == tg))
            {
                return mid;
            }
            else if (nums[mid] >= tg)
            { // if nums[mid] is equals to tg but not fst occ of tg then chng lst to (mid-1)
                lst = mid - 1;
            }
            else
            { // if nums[mid] is smaller than then inc fst
                fst = mid + 1;
            }
        }
        return -1;
    }

    int fndlst(vector<int> &nums, int fst, int lst, int tg)
    { // fndng lst occ of tg

        while (fst <= lst)
        {

            int mid = (fst + lst) / 2;
            if ((mid == nums.size() - 1 || nums[mid] != nums[mid + 1]) && (nums[mid] == tg))
            {
                return mid;
            }
            else if (nums[mid] <= tg)
            { // if nums[mid] is equals to tg but not lst occ of tg then chng fst to (mid+1)
                fst = mid + 1;
            }
            else
            {
                lst = mid - 1;
            }
        }
        return -1;
    }

    vector<int> searchRange(vector<int> &nums, int tg)
    {

        int ind1, ind2;
        ind1 = fnd1st(nums, 0, nums.size() - 1, tg);
        ind2 = fndlst(nums, 0, nums.size() - 1, tg);

        return {ind1, ind2};
    }
};