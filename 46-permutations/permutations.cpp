class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> permutations;
        
        if (nums.size() == 1) {
            vector<int> singlePerm = {nums[0]};
            permutations.push_back(singlePerm);
            return permutations;
        }

        vector<int> numsCopy = nums;
        for (int i = 0; i < nums.size(); i++) {
            int startNum = nums[i];
            numsCopy.erase(numsCopy.begin() + i);
            vector<vector<int>> newPerms = permute(numsCopy);
            numsCopy.insert(numsCopy.begin() + i, startNum);

            for (vector<int> perm : newPerms) {
                perm.insert(perm.begin(), startNum);
                permutations.push_back(perm);
            }
        }
        return permutations;
    }
};