class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // Start by searching for the row the target is in
        // Binary search to compare target to find which row the target is in by comparing the first and last element
        int n = matrix.size();
        int m = matrix[0].size();
        int low = 0;
        int high = n - 1;
        int mid = high / 2;

        if (target < matrix[0][0] || matrix[n-1][m-1] < target) {
            return false;
        }

        while (low <= high) {
            if (matrix[mid][0] <= target && target <= matrix[mid][m-1]) {
                break;
            }
            else if (matrix[mid][0] >= target) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
            mid = (high + low) / 2;
        }

        // Once the row is round, binary search the column to find the specific number, if it exists
        int row = mid;
        low = 0;
        high = m - 1;
        mid = high / 2;
        while (low <= high) {
            if (matrix[row][mid] == target) {
                return true;
            }
            else if (matrix[row][mid] < target) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
            mid = (high + low) / 2;
        }
        return false;
    }
};