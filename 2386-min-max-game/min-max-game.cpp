class Solution {
public:
    int minMaxGame(vector<int>& nums) {
        while (nums.size() != 1) {
            int newSize = nums.size() / 2;
            nums.resize(newSize);
            for (int i = 0; i < newSize; i++) {
                if (i % 2) {
                    nums[i] = max(nums[2 * i], nums[2 * i + 1]);
                }
                else {
                    nums[i] = min(nums[2 * i], nums[2 * i + 1]);
                }
            }
        }
        return nums.back();

    }
};