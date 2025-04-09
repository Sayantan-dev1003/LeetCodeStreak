class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        for (int num : nums) {
            if (num < k) return -1;
        }

        vector<int> freq(101, 0);
        for (int num : nums) {
            freq[num]++;
        }

        int operations = 0;
        int seen = 0;

        for (int val = 100; val > k; --val) {
            if (freq[val] > 0) {
                seen += freq[val];
                operations++;
            }

            if (seen == nums.size()) break;
        }

        return operations;
    }
};
