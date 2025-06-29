class Solution {
    const int MOD = 1e9 + 7;

public:
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<int> power(n, 1);
        for (int i = 1; i < n; ++i) {
            power[i] = (power[i - 1] * 2LL) % MOD;
        }

        int left = 0, right = n - 1, result = 0;
        while (left <= right) {
            if (nums[left] + nums[right] <= target) {
                result = (result + power[right - left]) % MOD;
                ++left;
            } else {
                --right;
            }
        }
        return result;
    }
};
