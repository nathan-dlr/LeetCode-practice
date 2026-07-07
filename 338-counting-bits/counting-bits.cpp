class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res;
        for (int i = 0; i <= n; i++) {
            int num = i;
            int bits = 0;
            while (num) {
                bits += num & 0x01;
                num = num >> 1;
            }
            res.push_back(bits);
        }
        return res;
    }
};