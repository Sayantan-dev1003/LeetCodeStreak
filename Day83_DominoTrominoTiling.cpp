class Solution {
const int MOD = 1e9 + 7;
public:
    int numTilings(int n) {
        vector<long long> dp(n + 1), preSum(n + 1);
        dp[0] = 1;
        if (n >= 1)
            dp[1] = 1;
        if (n >= 2)
            dp[2] = 2;

        for (int i = 3; i <= n; ++i) {
            preSum[i - 3] = (preSum[i - 4 >= 0 ? i - 4 : 0] + dp[i - 3]) % MOD;
            dp[i] = (dp[i - 1] + dp[i - 2] + 2 * preSum[i - 3]) % MOD;
        }

        return dp[n];
    }
};
