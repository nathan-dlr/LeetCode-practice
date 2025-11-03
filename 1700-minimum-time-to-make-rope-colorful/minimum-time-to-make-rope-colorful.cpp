class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int minTime = 0;
        int groupTime = neededTime[0];
        int maxInGroup = neededTime[0];
        for (int i = 1; i < colors.size(); i++) {
            if (colors[i] == colors[i - 1]) {
                groupTime += neededTime[i];
                maxInGroup = std::max(maxInGroup, neededTime[i]);
            }
            else {
                minTime += groupTime - maxInGroup;

                groupTime = neededTime[i];
                maxInGroup = neededTime[i];
            }
        }
        minTime += groupTime - maxInGroup;
        return minTime;
    }
};