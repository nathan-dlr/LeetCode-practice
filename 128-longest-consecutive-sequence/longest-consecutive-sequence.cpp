class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::unordered_set<int> set(nums.begin(), nums.end());
       

        int curr = 1;
        int max = 0;
        for (auto it = set.begin(); it != set.end();) {
            int next = *it + 1;
            while (set.contains(next)) {
                set.erase(next++);
                curr++;
            }
            next = *it - 1;
            while (set.contains(next)) {
                set.erase(next--);
                curr++;
            }
            max = std::max(max, curr);
            curr = 1;
            it = set.erase(it);
        }
        return max;
    }
};