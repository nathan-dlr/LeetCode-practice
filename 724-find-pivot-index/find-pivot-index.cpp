class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        if (nums.size() == 1) {return 0;}
        int i = 1;
        int j = nums.size() - 2;
        int left_sum[nums.size()];
        int right_sum[nums.size()];
        left_sum[0] = nums[0];
        right_sum[nums.size() - 1] = nums.back();
        for (; i < nums.size(); i++) {
            left_sum[i] = nums[i] + left_sum[i - 1];
            right_sum[j] = nums[j] + right_sum[j + 1];
            j--;
        }
        i = -1;
        j = 1;
        for (int k = 0; k < nums.size(); k++) {
            if (k == 0) {
                if (!right_sum[j]) {
                    return 0;
                }
            }
            else if (k == nums.size() - 1) {
                if (!left_sum[i]) {
                    return nums.size() - 1;
                }
            }
            else {
                if (left_sum[i] == right_sum[j]) {
                    return k;
                }
            }
            i++;
            j++;
        }
        return -1;
    }
};