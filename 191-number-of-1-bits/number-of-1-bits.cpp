class Solution {
public:
    int hammingWeight(int n) {
        int count = 0;
        while (n) {
            count += n & 0x01;
            n = n >> 1;
        }
        return count;
    }
};