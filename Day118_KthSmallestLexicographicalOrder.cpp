class Solution {
private:
    long countSteps(long n, long prefix1, long prefix2) {
        long steps = 0;
        while (prefix1 <= n) {
            steps += min(n + 1, prefix2) - prefix1;
            prefix1 *= 10;
            prefix2 *= 10;
        }
        return steps;
    }

public:
    int findKthNumber(int n, int k) {
        long curr = 1;
        k--;

        while (k > 0) {
            long steps = countSteps(n, curr, curr + 1);
            if (steps <= k) {
                k -= steps;
                curr++;
            } else {
                curr *= 10;
                k--;
            }
        }

        return curr;
    }
};
