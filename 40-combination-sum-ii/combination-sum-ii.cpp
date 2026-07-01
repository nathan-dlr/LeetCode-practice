class Solution {
public:
    void backtrack(vector<int>& candidates, int remaining, int start, std::vector<std::vector<int>>& sums, std::vector<int>& path) {
        if (remaining == 0) {
            sums.push_back(path);
            return;
        }

        for (int i = start; i < candidates.size(); i++) {
            if (candidates[i] > remaining) break;
            if (i > start && candidates[i] == candidates[i-1]) continue;

            path.push_back(candidates[i]);
            backtrack(candidates, remaining - candidates[i], i + 1, sums, path);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        std::sort(candidates.begin(), candidates.end());
        std::vector<std::vector<int>> sums;
        std::vector<int> path;

        backtrack(candidates, target, 0, sums, path);
        return sums;
    }
};