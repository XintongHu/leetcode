class Solution {
public:
    int numTrees(int n) {
        vector<int> dp;
        int val, i, j;
        dp.push_back(1);
        dp.push_back(1);
        for(i = 2; i <= n; ++i) {
            val = 0;
            for (j = 1; j <= i/2; ++j) {
                val += (dp[j - 1] * dp[i - j]);
            }
            if (i % 2 == 0) val *= 2;
            else val = val*2 + dp[j - 1] * dp[i - j];
            dp.push_back(val);
        }
        return dp[n];
    }
};