class Solution {
    const int MOD = 1e9 + 7;

public:
    int lengthAfterTransformations(string s, int t) {
        vector<long long> count(26, 0);

        for (char ch : s) {
            count[ch - 'a']++;
        }

        for (int i = 0; i < t; ++i) {
            vector<long long> nextCount(26, 0);
            for (int j = 0; j < 26; ++j) {
                if (j == 25) {
                    nextCount[0] = (nextCount[0] + count[j]) % MOD;
                    nextCount[1] = (nextCount[1] + count[j]) % MOD;
                } else {
                    nextCount[j + 1] = (nextCount[j + 1] + count[j]) % MOD;
                }
            }
            count = nextCount;
        }

        long long result = 0;
        for (int i = 0; i < 26; ++i) {
            result = (result + count[i]) % MOD;
        }

        return result;
    }
};
