class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int max = 0;
        int i = 0;
        int j = nums.size() - 1;
        int result;
        while (i < j) {
            result = nums[i] + nums[j];
            if (result == k) {
                i++;
                j--;
                max++;
            }
            else if (result > k) {
                j--;
            }
            else if (result < k) {
                i++;
            }
        }
        return max;
    }
};