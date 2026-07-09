class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> minCost;
        minCost.push_back(cost[0]);
        minCost.push_back(cost[1]);
        for (int i = 2; i < cost.size(); i++) {
            minCost.push_back(std::min(minCost[i-1], minCost[i-2]) + cost[i]);
        }
        return std::min(minCost[minCost.size() - 1], minCost[minCost.size() - 2]);
        
    }
};