class Solution {
public:
    long long sumAndMultiply(int n) {
        int sum = 0;
        int x = 0;
        int factor = 1;
        while (n) {
            int digit = n % 10;
            if (digit) {
                sum += digit;
                x += factor * digit;
                factor *= 10;
            }
            n /= 10;
        }
        return sum * (long long)x;
    }
};