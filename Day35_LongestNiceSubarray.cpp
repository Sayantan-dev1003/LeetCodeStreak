class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();
        int maxLength = 0, left = 0, bitwiseAnd = 0;

        for (int right = 0; right < n; ++right) {
            while ((bitwiseAnd & nums[right]) != 0) {
                bitwiseAnd ^= nums[left];
                ++left;
            }

            bitwiseAnd |= nums[right];
            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};
