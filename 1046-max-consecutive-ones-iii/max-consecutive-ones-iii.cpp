class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i = 0;
        int max = k;
        int curr = 0;
        int zeros = 0;
        vector<int> zero_pos;
        for (int j = 0; j < nums.size(); j++) {
            if (nums[j] == 0) {
                zeros++;
                zero_pos.push_back(j);
            }
            if (zeros > k) {
                if (!nums[i]){
                    i++;
                }
                else {
                    while (nums[i]) {
                        i++;
                    }
                    i++;
                }
                zeros = k;
            }
            curr = j - i + 1;
            if (curr > max) {
                max = curr;
            }
        }
        return max;
    }
};