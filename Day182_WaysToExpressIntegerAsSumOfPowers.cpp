class Solution {
public:
    int numberOfWays(int n, int x) {
        const int MOD = 1e9 + 7;

        int max_num = 0;
        while (pow(max_num + 1, x) <= n) {
            max_num++;
        }

        vector<vector<long long>> dp(max_num + 1, vector<long long>(n + 1, 0));
        dp[0][0] = 1;

        std::vector<long long> powers(max_num + 1);
        for (int i = 1; i <= max_num; i++) {
            powers[i] = pow(i, x);
        }

        for (int i = 1; i <= max_num; i++) {
            for (int sum = 0; sum <= n; sum++) {
                dp[i][sum] = dp[i - 1][sum];

                if (sum >= powers[i]) {
                    dp[i][sum] =
                        (dp[i][sum] + dp[i - 1][sum - powers[i]]) % MOD;
                }
            }
        }

        return dp[max_num][n];
    }
};
