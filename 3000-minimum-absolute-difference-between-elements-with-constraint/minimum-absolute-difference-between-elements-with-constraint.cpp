class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
        set<int> set;
        int ret = INT_MAX;
        for (int i = x; i < nums.size(); i++) {
            set.insert(nums[i - x]);
            auto upperBound = set.upper_bound(nums[i]);

            if (upperBound != set.begin()) {
                ret = min(ret, abs(nums[i] - *prev(upperBound)));
            }
            if (upperBound != set.end()) {
                ret = min(ret, abs(nums[i] - *upperBound));
            }
        }
        return ret;
    }
};