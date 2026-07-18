class Solution {
public:
    int rob(vector<int>& nums) {
        int size = std::max((int)nums.size(), 3);
        int money[size];
        money[0] = nums[0];
        money[1] = nums.size() > 1 ? nums[1] : money[0];
        money[2] = nums.size() > 2 ? nums[2] + money[0] : std::max(money[0],money[1]);
        for (int i = 3; i < nums.size(); i++) {
            money[i] = std::max(money[i-2],money[i-3]) + nums[i];
        }
        return std::max(money[size - 1], money[size - 2]);
    }
};