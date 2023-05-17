class Solution {
public:
// TC: O log(m * n) not (m + n) because we are traversing whole matarix 

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        int low = 0, high = (n * m) - 1;

        while(low <= high) {
            int mid = low + (high - low) / 2;
            // cout << low << " " << high << " - ";
            int y = mid / m, x = mid % m; //to extract locn from mid and num of columns
            // cout << y << " " << x << " " << mid << " " << m << " " << mid/m << " " << mid%m << endl;
            if(matrix[y][x] == target) {
                return 1;
            }
            else if(matrix[y][x] < target) {
                low = mid + 1;
            }
            else {
                high = mid -1;
            }
        }

        return 0;
    }
};