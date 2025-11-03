class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int size = colors.size();
        int minTime = 0;
        bool taken = false;
        int j;
        std::priority_queue<int, std::vector<int>, std::greater<int>> min;
        for (int i = 0; i < size; i++) {
            j = i + 1;
            while ((j < size) && (colors[i] == colors[j])) {
                if (j == i + 1) {
                    min.push(neededTime[i]);
                }
                min.push(neededTime[j]);
                j++;
                taken = true;
            }
            if (!taken) continue;
            while (!min.empty()) {
                if (i < j - 1) {
                    minTime += min.top();
                    i++;
                }
                min.pop();
            }
        }
        return minTime;
    }
};