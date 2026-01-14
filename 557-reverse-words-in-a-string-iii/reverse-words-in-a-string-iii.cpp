class Solution {
public:
    string reverseWords(string s) {
        char temp;
        for (int i = 0, j = 0; j < s.length(); j++) {
            if ((j + 1) == s.length() || s[j + 1] == ' ') {
                int k = i;
                int l = j;
                while (k != l && k < l) {
                    temp = s[k];
                    s[k] = s[l];
                    s[l] = temp;
                    k++;
                    l--;
                }
                j += 1;
                i = j + 1;
            }
        }
        return s;
    }
};