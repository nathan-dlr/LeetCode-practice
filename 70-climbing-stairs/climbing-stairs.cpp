class Solution {
public:
    int climbStairs(int n) {
        // At any given n, you either came from n - 1 steps or n - 2 step
        vector<int> steps;
        steps.push_back(1); // amount of distinct steps when n = 1
        steps.push_back(2); // amount of distinct steps when n = 2
        for (int i = 2; i < n; i++) {
            steps.push_back(steps[i-1] + steps[i-2]);
        }
        return steps[n-1];
    }
};