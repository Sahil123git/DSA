/*We can find Pivot Ele ind by going to tht side which is not sorted*/

/*Now we can use Binary search on both sides because we know pivot ele ind. So chk in which side range, pivot ele can exist use Binary search in tht side to save memory*/

// This code can be used in Rotated Sorted arr or Mountain Arr

// Concept from Aditya Verma(video No: 7(Num of times array is sorted))

int search(vector<int> &nums, int target) // it return pivot ele index
{
    int low = 0, high = nums.size() - 1;
    int pivotInd, n = nums.size();

    // next ele : (mid + 1) % n
    // prev ele : (mid + n - 1) % n
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        // pivot ele is tht ele which is smaller than both of it's neighbor
        if (nums[mid] < nums[(mid + n - 1) % n] && nums[mid] < nums[(mid + 1) % n])
        {
            pivotInd = mid;
            break;
        }

        // smallest ele will be in unsorted side
        else if (nums[mid] < nums[nums.size() - 1])
        { // this means right side is sorted so take high to mid - 1
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return pivotInd;
}