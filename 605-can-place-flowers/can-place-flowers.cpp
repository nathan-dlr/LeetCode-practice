class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if (!n || (flowerbed.size() == 1 && flowerbed[0] == 0 && n == 1)) {
            return true;
        }
        if (flowerbed[0] == 0 && flowerbed.size() != 1 && flowerbed[1] == 0) {
            flowerbed[0] = 1;
            n--;
        }
        for (int i = 1; i < flowerbed.size() && n > 0; i++) {
            bool isZero = flowerbed[i] == 0;
            bool leftZero = flowerbed[i-1] == 0;
            bool rightZero = (flowerbed.size() != i + 1) && (flowerbed[i+1] == 0);
            if (isZero && leftZero && rightZero) {
                flowerbed[i] = 1;
                n--;
            }
        }
        bool isZero = flowerbed[flowerbed.size() - 1] == 0;
        bool leftZero = (flowerbed.size() > 1) && (flowerbed[flowerbed.size() - 2] == 0);
        if (isZero && leftZero) {
            flowerbed[flowerbed.size() - 1] = 1;
            n--;
        }
        return n <= 0;
    }
};