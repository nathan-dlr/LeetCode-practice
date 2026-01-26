class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max = 0;
        int currLen = 0;
        std::set<char> currStr;
        for (int i = 0; i < s.size(); i++) {
            currStr.insert(s[i]);
            currLen = 1;
            for (int j = i + 1; j < s.size(); j++) {
                if (!currStr.contains(s[j])) {
                    currStr.insert(s[j]);
                    currLen++;
                }
                else {
                    if (currLen > max) {
                        max = currLen;
                    }
                    currStr.clear();
                    break;
                }
            }
            if (currLen > max) {
                max = currLen;
            }
        }
        return max;
    }
};