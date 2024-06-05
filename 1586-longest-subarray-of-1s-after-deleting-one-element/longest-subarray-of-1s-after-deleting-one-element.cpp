class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int i = 0;
        int max = 0;
        int curr = 0;
        int zeros = 0;
        for (int j = 0; j < nums.size(); j++) {
            if (nums[j] == 0) {
                if (zeros == 0) {
                    zeros++;
                }
                else {
                    if (nums[i] == 1) {
                        while(nums[i] == 1) {
                            i++;
                            curr--;
                        }
                        i++;
                    }
                    else {
                        while (!nums[i] && i < j) {
                            i++;
                        }
                    }
                }
            }
            else {curr++;} 
            if (curr - (zeros ^ 1) > max) {max = curr - (zeros ^ 1);}
        }
        return max;
    }
};