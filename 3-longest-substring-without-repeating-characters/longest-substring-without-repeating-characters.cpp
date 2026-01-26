class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> lastIdx(128, -1);
        int maxLen = 0;
        int left = 0;
        for (int right = 0; right < s.size(); right++) {
            char current = s[right];

            if (lastIdx[current] >= left) {
                left = lastIdx[current] + 1;
            }
            
            lastIdx[current] = right;
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};