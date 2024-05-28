class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> output;
        vector<int> forward;
        vector<int> backward;
        forward.push_back(nums[0]);
        backward.push_back(nums.back());
        int length = nums.size() - 1;

        for (int i = 1; i < nums.size(); i++) {
            forward.push_back(nums[i] * forward[i-1]);
        }

        for (int j = 1; j < nums.size(); j++) {
            backward.push_back(nums[length - j] * backward[j-1]);
        }

        int i = 0;
        for (int k = 1; k <= nums.size(); k++) {
            if (k == 1) {
                output.push_back(backward[length - k]);
            }
            else if (k < nums.size()) {
                output.push_back(backward[length - k] * forward[i]);
                i++;
            }
            else {
                output.push_back(forward[i]);
            }
        }
        
        return output;
    }
};