class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string new_string = "";
        for (int i = 0; i < word1.length() || i < word2.length(); i++) {
            if (i < word1.length()) {
                new_string += word1[i];
            }
            if (i < word2.length()) {
                new_string += word2[i];
            }
        }
        return new_string;
    }
};