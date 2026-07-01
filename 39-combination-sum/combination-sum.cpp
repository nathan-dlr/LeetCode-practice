class Solution {
public:
    void backtrack(vector<int>& candidates, int remaining, int start, vector<vector<int>>& sums, vector<int>& path) {
        if (remaining == 0) {
            sums.push_back(path);
            return;
        }
        for (int i = start; i < candidates.size(); i++) {
            if (candidates[i] > remaining) break;
            path.push_back(candidates[i]);
            backtrack(candidates, remaining - candidates[i], i, sums, path);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        std::sort(candidates.begin(), candidates.end());
        std::vector<vector<int>> sums;
        std::vector<int> path;

        backtrack(candidates, target, 0, sums, path);
        return sums;
    }
};