class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int maxDiff = 0;
        int n = nums.size();

        for (int i = 0; i < n; ++i) {
            int next = (i + 1) % n;
            int diff = abs(nums[i] - nums[next]);
            maxDiff = max(maxDiff, diff);
        }

        return maxDiff;
    }
};
