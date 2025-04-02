class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        long long maxVal = 0;

        vector<int> maxSuffix(n);
        maxSuffix[n - 1] = nums[n - 1];
        for (int k = n - 2; k >= 0; --k) {
            maxSuffix[k] = max(maxSuffix[k + 1], nums[k]);
        }

        int maxI = nums[0];
        for (int j = 1; j < n - 1; ++j) {
            maxVal = max(maxVal, (long long)(maxI - nums[j]) * maxSuffix[j + 1]);
            maxI = max(maxI, nums[j]);
        }

        return maxVal;
    }
};
