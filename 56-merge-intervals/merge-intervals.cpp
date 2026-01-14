class Solution {
public:
    void merge(vector<vector<int>>& intervals, int left, int right, int mid) {
        int leftSize = mid - left + 1;
        int rightSize = right - mid;
        auto n1 = intervals.begin() + leftSize;
        auto n2 = n1 + rightSize;
        vector<vector<int>> leftArr(intervals.begin() + left, intervals.begin() + mid + 1);
        vector<vector<int>> rightArr(intervals.begin() + mid + 1, intervals.begin() + right + 1);
    
        int i = 0;
        int j = 0;
        int k = left;

        while (i < leftSize && j < rightSize) {
            if (leftArr[i][0] <= rightArr[j][0]) {
                intervals[k] = leftArr[i];
                i++;
            }
            else {
                intervals[k] = rightArr[j];
                j++;
            }
            k++;
        }

        while (i < leftSize) {
            intervals[k] = leftArr[i];
            i++;
            k++;
        }
        while (j < rightSize) {
            intervals[k] = rightArr[j];
            j++;
            k++;
        }
    }
    void mergeSort(vector<vector<int>>& intervals, int left, int right) {
        if (left >= right) {
            return;
        }
        int mid = left + (right - left) / 2;
        mergeSort(intervals, left, mid);
        mergeSort(intervals, mid + 1, right);
        merge(intervals, left, right, mid);
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        mergeSort(intervals, 0, intervals.size() - 1);
        vector<vector<int>> ret = {intervals[0]};

        for (int i = 0, k = 0; i < intervals.size(); i++) {
            if (intervals[i][0] <= ret[k][1]) {
                if (ret[k][1] < intervals[i][1]) {
                    ret[k][1] = intervals[i][1];
                }
            }
            else {
                k++;
                ret.emplace_back(intervals[i]);
            }
        }
        return ret;
    }
};