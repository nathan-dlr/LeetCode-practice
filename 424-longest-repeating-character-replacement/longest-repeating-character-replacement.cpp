class Solution {
public:
    int characterReplacement(string s, int k) {
        int freq[26]{};
        int l = 0;
        int maxFreq = 0;
        int result = 0;

        for (int r = 0; r < s.size(); r++) {
            freq[s[r] - 'A']++;
            maxFreq = std::max(maxFreq, freq[s[r] - 'A']);

            if ((r - l + 1) - maxFreq > k) {
                freq[s[l++] - 'A']--;
            }

            result = std::max(result, r - l + 1);
        }
        return result;
    }
};