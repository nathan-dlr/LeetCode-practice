class Solution {
public:
    string smallestString(string s) {
        int i = 0;
        while (s[i] == 'a' && i < s.size() - 1) {
            i++;
        }
        if (i == s.size() - 1) {
            s[i] = s[i] == 'a' ? 'z' : s[i] - 1;
            return s;
        }
        for (; i < s.size() && s[i] != 'a'; i++) {
            s[i] = s[i] - 1;
        }
        return s;
    }
};