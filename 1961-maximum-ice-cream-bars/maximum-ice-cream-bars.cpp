class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int res = 0;
        int spent = 0;
        std::sort(costs.begin(), costs.end());
        for (int i = 0; i < costs.size(); i++) {
            if (costs[i] + spent > coins) {
                return res;
            }
            res++;
            spent += costs[i];
        }
        return res;
    }
};