class Solution {
public:
    int maxOperations(string s) {
        int numOnes = 0;
        int ret = 0;
        bool prevZero = false;
        for (int i = 0; i < s.size(); i ++) {
            if (s[i] == '0') {
                prevZero = true;
                continue;
            }
            if (prevZero) {
                ret += numOnes;
            }
            numOnes++;
            prevZero = false;
        }
        if (prevZero) {
            ret += numOnes;
        }
        return ret;
    }
};