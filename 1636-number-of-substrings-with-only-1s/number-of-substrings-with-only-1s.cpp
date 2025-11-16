class Solution {
public:
    int numSub(string s) {
        int onesInSubStr = 0;
        int total = 0;
        int mod = 1000000007;
        for (char c : s) {
            if (c == '0') {
                onesInSubStr = 0;
            }
            if (c == '1') {
                onesInSubStr++;
                total += onesInSubStr;
                if (total > mod) {
                    total %= mod;
                }
            }
        }
        return total;
    }
};