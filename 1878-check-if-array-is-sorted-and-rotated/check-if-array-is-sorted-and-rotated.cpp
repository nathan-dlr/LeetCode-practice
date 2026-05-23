class Solution {
public:
    bool check(vector<int>& nums) {
        if (nums.size() == 1) {
            return true;
        }
        int decrease = 0;
        if (nums[nums.size() - 1] > nums[0]) {
                decrease++;
        }
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i-1] > nums[i]) {
                decrease++;
                if (decrease > 1) {
                    return false;
                }
            }
        }
        return (decrease <= 1);
    }
};