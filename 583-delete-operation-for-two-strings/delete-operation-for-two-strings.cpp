class Solution {
public:
    int minDistance(string word1, string word2) {
        // if (word1.empty()) {
        //     return  word2.size();
        // } 
        // else if (word2.empty()) {
        //     return word1.size();
        // }
        // else if (word1[0] == word2[0]) {
        //     return minDistance(word1.substr(1), word2.substr(1));
        // }
        // int delLeft = 1 + minDistance(word1.substr(1), word2);
        // int delRight = 1 + minDistance(word1, word2.substr(1));
        // return min(delLeft, delRight);
        const int word1Size = word1.size();
        const int word2Size = word2.size();
        std::vector<std::vector<int>> dp(word1Size + 1, std::vector<int>(word2Size + 1, 0));

        for (int i = 0; i <= word1Size; i++) {
            dp[i][word2Size] = word1Size - i;
        }
        for (int j = 0; j <= word2Size; j++) {
            dp[word1Size][j] = word2Size - j;
        }

        for (int i = word1Size - 1; i >= 0; i--) {
            for (int j = word2Size - 1; j >= 0; j--) {

                if (word1[i] == word2[j]) {
                    dp[i][j] = dp[i+1][j+1];
                    continue;
                }

                dp[i][j] = 1 + std::min(dp[i+1][j],dp[i][j+1]);
            }
        }
        return dp[0][0];
    }
};