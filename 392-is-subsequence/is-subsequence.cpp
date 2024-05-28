class Solution {
public:
    bool isSubsequence(string s, string t) {
        int j = 0;
        int s_size = s.size(); 

        if (!s_size) {return true;}

        for (int i = 0; i < t.size(); i++) {
            if (s[j] == t[i]) {
                j++;
            }
            if (j == s_size) {
                return true;
            }
        }
        return false; 
    }
};