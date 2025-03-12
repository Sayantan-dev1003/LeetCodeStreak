class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n = nums.size();

        int posIndex = lower_bound(nums.begin(), nums.end(), 1) - nums.begin();

        int zeroIndex = lower_bound(nums.begin(), nums.end(), 0) - nums.begin();

        int negCount = zeroIndex;

        int posCount = n - posIndex;

        return max(posCount, negCount);
    }
};
