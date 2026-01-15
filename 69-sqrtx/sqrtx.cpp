class Solution {
public:
    int mySqrt(int x) {
        for (int i = 0; i <= x; i++) {
            long product = (long) i * i;
            if (product > x) {
                return i - 1;
            }
            else if (product == x) {
                return i;
            }
        }
        return 0;
    }
};