class Solution {
public:
    int longestSubsequence(string s, int k) {
        int n = s.size();
        int count = 0;
        int zeros = 0;
        long long value = 0;
        int power = 0;

        for (char c : s) {
            if (c == '0')
                zeros++;
        }

        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == '1') {
                if (power < 32) {
                    if (value + (1LL << power) <= k) {
                        value += (1LL << power);
                        count++;
                    }
                }
                power++;
            } else {
                count++;
                power++;
            }
        }

        return count;
    }
};
