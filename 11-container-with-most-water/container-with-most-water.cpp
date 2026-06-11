class Solution {
public:
    int maxArea(vector<int>& height) {
        int x1 = 0;
        int x2 = height.size() - 1;
        int max = 0;

        for (int i = 0; i < height.size(); i++) {
            int curr = std::min(height[x1], height[x2]) * (x2-x1);
            max = std::max(curr, max);
        
            if (height[x1] > height[x2]) {
                x2--;
            }
            else {
                x1++;
            }
        }


        return max;
    }
};