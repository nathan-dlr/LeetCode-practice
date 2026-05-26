class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int high = n;
        int low = 0;
        while (low <= high) {
            int mid = (high + low) / 2;
            int peak = -1;
            int peakVal = -1;
            for (int y = 0; y < m; y++) {
                if (mat[y][mid] > peakVal) {
                    peak = y;
                    peakVal = mat[peak][mid];
                }
            }

            int LVal = mid == 0 ? -1 : mat[peak][mid-1];
            int RVal = mid == n-1 ? -1 : mat[peak][mid+1];
            if (peakVal > LVal && peakVal > RVal) {
                return vector<int>{peak,mid};
            }
            if (RVal > LVal) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return {0,0};
    }
};