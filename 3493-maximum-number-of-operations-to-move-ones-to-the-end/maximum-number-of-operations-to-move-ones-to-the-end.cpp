class Solution {
public:
    int maxOperations(string s) {
        int numOnes = 0;
        int ret = 0;
        for (int i = 0; i < s.size(); i ++) {
            if (s[i] == '0') {
                while ((i + 1) < s.size() && s[i+1] == '0') {
                    i++;
                }
                ret += numOnes;
            }
            else {
                numOnes++;
            }
        }
        return ret;
    }
};