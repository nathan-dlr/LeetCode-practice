class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        // Start with the empty set
        // For each number in nums, we can either included it or not include it in all our current subsets
        vector<vector<int>> subsetVec;
        subsetVec.push_back({});
        for (int i = 0; i < nums.size(); i++) {
            int size = subsetVec.size();
            for (int j = 0; j < size; j++) {
                vector<int> subset = subsetVec[j];
                subset.push_back(nums[i]);
                subsetVec.emplace_back(std::move(subset));
            }
        }
        return subsetVec;
    }
};