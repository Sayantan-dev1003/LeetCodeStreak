class Solution {
public:
    static const long long MOD = 1e9 + 7;

    long long modPow(long long base, long long exp) {
        long long res = 1;
        while (exp > 0) {
            if (exp & 1) res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp >>= 1;
        }
        return res;
    }

    long long modInv(long long x) {
        return modPow(x, MOD - 2);
    }

    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<long long> powers;
        
        for (int i = 0; i < 31; i++) {
            if (n & (1 << i)) {
                powers.push_back(1LL << i);
            }
        }

        int m = powers.size();
        vector<long long> prefix(m);
        prefix[0] = powers[0] % MOD;
        for (int i = 1; i < m; i++) {
            prefix[i] = (prefix[i - 1] * (powers[i] % MOD)) % MOD;
        }

        vector<int> ans;
        ans.reserve(queries.size());

        for (auto &q : queries) {
            int l = q[0], r = q[1];
            long long product;
            if (l == 0) {
                product = prefix[r];
            } else {
                product = (prefix[r] * modInv(prefix[l - 1])) % MOD;
            }
            ans.push_back((int)product);
        }

        return ans;
    }
};
