class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int size = nums.size();
        int index = 0;
        for (int i = 0; i < size; i++) {
            if (nums[index] == 0) {
                nums.erase(nums.begin() + index);
                nums.push_back(0);
            }
            else {
                index++;
            }
        }
    }
};