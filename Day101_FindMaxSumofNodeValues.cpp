class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k,
                              vector<vector<int>>& edges) {
        long long total = accumulate(nums.begin(), nums.end(), 0ll);

        long long total_diff = 0;
        long long diff;
        int positive_count = 0;
        long long min_abs_diff = numeric_limits<int>::max();
        for (auto p : nums) {
            diff = (p ^ k) - p;

            if (diff > 0) {
                total_diff += diff;
                positive_count++;
            }
            min_abs_diff = min(min_abs_diff, abs(diff));
        }
        if (positive_count % 2 == 1) {
            total_diff = total_diff - min_abs_diff;
        }
        return total + total_diff;
    }
};
