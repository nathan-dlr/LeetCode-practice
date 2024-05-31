class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int i = 0;
        double max_avg;
        double curr_avg;
        int denominator;
        for (int j = 0; j < nums.size(); j++) {
            denominator = (j - i) + 1;
            if (denominator > k) {
                curr_avg = ((curr_avg * k) + (nums[j] - nums[i])) / k;
                i++;

                if (curr_avg > max_avg) {
                    max_avg = curr_avg;
                }
            }
            else if (denominator > 1) {
                max_avg = ((max_avg * (denominator - 1)) + nums[j]) / denominator;
                curr_avg = max_avg;
            }
            else {
                max_avg = nums[j];
                curr_avg = max_avg;
            }
        }
        return max_avg;
    }
};