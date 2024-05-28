class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int size = nums.size();
        int min1 = pow(2,31) - 1;
        int min2 = min1;
        for (int i = 0; i < size; i++) {

            if (nums[i] < min1) {
                min1 = nums[i];
            }
            else if (nums[i] < min2 && nums[i] > min1) {
                min2 = nums[i];
            }
            else if (min1 < min2 && nums[i] > min2) {
                return true;
            }
        }
        return false;
    }
};