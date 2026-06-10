class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefix;
        vector<int> suffix(nums.size());
        vector<int> result(nums.size());
        prefix.reserve(nums.size());
        prefix.push_back(1);
        suffix[nums.size() - 1] = 1;

        for (int i = 1, j = nums.size()-2; i < nums.size(); i++, j--) {
            prefix.push_back(prefix[i-1] * nums[i - 1]);
            suffix[j] = suffix[j+1] * nums[j + 1];
        }

        result[0] = suffix[0];
        result[nums.size() - 1] = prefix[nums.size() - 1];
        for (int i = 1; i < nums.size() - 1; i++) {
            result[i] = prefix[i] * suffix[i];
        }
        return result;
    }
};