class Solution {
    public int change(int amount, int[] coins) {
        int dp[][] = new int[coins.length + 1][amount + 1];
        dp[coins.length][0] = 1;
        for (int i = 0; i <= amount; i++) {
            for (int j = coins.length - 1; j >= 0; j--) {
                dp[j][i] = dp[j+1][i];
                if (coins[j] <= i) {
                    dp[j][i] += dp[j][i-coins[j]];
                }
            }
        }
        return dp[0][amount];
    }
}