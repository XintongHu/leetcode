class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int k = coins.size(), i, j, m;
        if (amount == 0) return 0;
        vector<int> dp(amount + 1, amount);
        for (i = 0; i < k; ++i) if (coins[i] <= amount) dp[coins[i]] = 0;
        for (i = 0; i <= amount; ++i) {
            m = dp[i];
            for (j = 0; j < k; ++j) {
                if (i - coins[j] >= 0 && dp[i - coins[j]] != 0 && dp[i - coins[j]] < m)
                    m = dp[i - coins[j]];
            }
            dp[i] = m + 1;
        }
        return dp[amount] == amount + 1 ? -1 : dp[amount];
    }
};