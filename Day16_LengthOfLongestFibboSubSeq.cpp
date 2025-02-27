class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> index;
        vector<vector<int>> dp(n, vector<int>(n, 2));
        int maxLen = 0;

        for (int i = 0; i < n; i++) {
            index[arr[i]] = i;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                int needed = arr[i] - arr[j];
                if (needed < arr[j] && index.count(needed)) {
                    int k = index[needed];
                    dp[j][i] = dp[k][j] + 1;
                    maxLen = max(maxLen, dp[j][i]);
                }
            }
        }

        return (maxLen >= 3) ? maxLen : 0;
    }
};
