class Solution {
public:
    int numSub(string s) {
        bool isSubStr = false;
        int onesInSubStr = 0;
        int total = 0;
        for (char c : s) {
            if (c == '0' && !isSubStr) {
                continue;
            }
            else if (c == '0' && isSubStr) {
                onesInSubStr = 0;
                isSubStr = false;
            }
            else if (c == '1' && isSubStr) {
                onesInSubStr++;
                total = (total + onesInSubStr) % 1000000007;
            }
            else if (c == '1' && !isSubStr) {
                total += ++onesInSubStr;
                isSubStr = true;
            }
        }
        return total;
    }
};