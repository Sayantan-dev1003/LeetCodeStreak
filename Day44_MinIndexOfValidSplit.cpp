class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> freq;

        for (int num : nums) {
            freq[num]++;
        }

        int dominant = -1, maxFreq = 0;
        for (auto& [num, count] : freq) {
            if (count * 2 > n) {
                dominant = num;
                maxFreq = count;
                break;
            }
        }

        if (dominant == -1)
            return -1;

        int leftCount = 0;
        for (int i = 0; i < n - 1; ++i) {
            if (nums[i] == dominant)
                leftCount++;
            int rightCount = maxFreq - leftCount;

            if (leftCount * 2 > (i + 1) && rightCount * 2 > (n - i - 1)) {
                return i;
            }
        }

        return -1;
    }
};
