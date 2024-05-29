class Solution {
public:
    int maxArea(vector<int>& height) {
        int x1 = 0;
        int x2 = height.size() - 1;
        int max = (height[x1] > height[x2]) ? ((x2-x1) * (height[x2])) : (((x2-x1) * (height[x1])));
        int current; 

        for (int i = 0; i < height.size(); i++) {
            if (height[x1] > height[x2]) {
                x2--;
            }
            else {
                x1++;
            }
            if (x1 == x2) {
                break;
            }

            current = (height[x1] > height[x2]) ? ((x2-x1) * (height[x2])) : (((x2-x1) * (height[x1])));
            max = (max >= current) ? max : current;
        }


        return max;
    }
};