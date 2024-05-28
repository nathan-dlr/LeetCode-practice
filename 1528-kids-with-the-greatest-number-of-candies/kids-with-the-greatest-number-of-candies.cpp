class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> result;
        int max_candy = candies[0];
        for (int num_candies : candies) {
            max_candy = max(max_candy, num_candies);
        }

        for (int num_candies : candies) {
            result.push_back(num_candies + extraCandies >= max_candy);
        }
        return result;
    }
};