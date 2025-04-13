class Solution {
#define MOD 1000000007
public:
    long long modPow(long long base, long long exp, long long mod) {
        long long result = 1;
        base %= mod;
        while (exp > 0) {
            if (exp % 2 == 1) {
                result = (result * base) % mod;
            }
            base = (base * base) % mod;
            exp /= 2;
        }
        return result;
    }

    int countGoodNumbers(long long n) {
        long long even_count = (n + 1) / 2;
        long long odd_count = n / 2;

        long long even_part = modPow(5, even_count, MOD);
        long long odd_part = modPow(4, odd_count, MOD);

        return (even_part * odd_part) % MOD;
    }
};
