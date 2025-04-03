class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        if (n < 3)
            return 0;

        long long maxVal = 0;
        int max_i = nums[0];
        int max_ik = INT_MIN;

        for (int j = 1; j < n - 1; j++) {
            max_ik = max(max_ik, max_i - nums[j]);
            maxVal = max(maxVal, (long long)max_ik * nums[j + 1]);
            max_i = max(max_i, nums[j]);
        }

        return maxVal;
    }
};
