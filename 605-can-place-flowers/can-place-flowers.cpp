class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if (n == 0) {
            return true;
        }
        for (int i = 0; i < flowerbed.size(); i++) {
            int flower = flowerbed.at(i);
            if (flower) {
                i++;
            }
            else {
                if (i == flowerbed.size() - 1) {
                    n--;
                    i++;
                }
                else if (!flowerbed[i+1]) {
                    n--;
                    i++;
                }
            }
            if (!n) {
                return true;
            }
        }
        return false;
    }
};