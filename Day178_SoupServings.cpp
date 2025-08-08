class Solution {
public:
    double dfs(int a, int b, vector<vector<double>>& memo) {
        if (a <= 0 && b <= 0)
            return 0.5;
        if (a <= 0)
            return 1.0;
        if (b <= 0)
            return 0.0;

        if (memo[a][b] >= 0)
            return memo[a][b];

        double res = 0.25 * (dfs(a - 4, b, memo) + dfs(a - 3, b - 1, memo) +
                             dfs(a - 2, b - 2, memo) + dfs(a - 1, b - 3, memo));

        return memo[a][b] = res;
    }
    double soupServings(int n) {
        if (n > 5000)
            return 1.0;

        int N = (n + 24) / 25;
        vector<vector<double>> memo(N + 1, vector<double>(N + 1, -1.0));
        return dfs(N, N, memo);
    }
};
