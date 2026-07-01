class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // Sort in decending order to easiler iterate from largest to smallest 
        std::sort(candidates.begin(), candidates.end(), std::greater<>());
        // All possible sums that may add up to target
        std::queue<vector<int>> combinations;
        std::vector<vector<int>> sums;
        
        for (int i = 0; i < candidates.size(); i++) {
            if (candidates[i] == target) {
                sums.push_back({candidates[i]});
                continue;
            }
            else if (candidates[i] < target) {
                combinations.push({candidates[i]});
            }
            else {
                continue;
            }
            // start with our current possible subsets and try to build a sum to target with each of them
            // avoid iterating the same subsets by keeping the current candidate's possible subsets seperate from the list of all possible subsets
            std::queue<vector<int>> curSubsets = combinations;
            while (!curSubsets.empty()) {
                int size = curSubsets.size();
                for (int j = 0; j < size; j++) {
                    std::vector<int> subset = curSubsets.front();
                    curSubsets.pop();
        
                    int sum = std::accumulate(subset.begin(), subset.end(), candidates[i]);
                    if (sum == target) {
                        subset.push_back(candidates[i]);
                        sums.emplace_back(subset);
                    }
                    // this subset is possible for our current candidate and future candidates so add to both queues
                    else if (sum < target) {
                        subset.push_back(candidates[i]);
                        curSubsets.push(subset);
                        combinations.push(subset);
                    }
                }
            }
        }
        return sums;
    }
};