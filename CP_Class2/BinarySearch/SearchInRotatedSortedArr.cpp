class Solution
{
public:
    int search(vector<int> &Rarr, int key)
    {
        int start = 0, end = Rarr.size() - 1;

        while (start <= end)
        {
            int mid = start + (end - start) / 2;

            if (Rarr[mid] == key)
            {
                return mid;
            }
            else if (Rarr[start] <= Rarr[mid])
            { // if this side is not sorted then right side will be
                if (Rarr[start] <= key && Rarr[mid] > key)
                {                   // sorted  so move to tht side
                    end = mid - 1; // if this side is sorted but ele is not b/w this range
                }                   // then take start to mid+1
                else
                {
                    start = mid + 1;
                }
            }
            else
            { // if(Rarr[mid + 1] <= Rarr[end]){ (this will be sorted if lft side is not sorted)
                if (Rarr[mid] < key && Rarr[end] >= key)
                {
                    start = mid + 1;
                }
                else
                {
                    end = mid - 1;
                }
            }
            // cout << start <<" "<<mid<<" "<<end<<endl;
        }
        return -1;
    }
};