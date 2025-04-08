class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int operations = 0;
        unordered_map<int, int> freq;
        int n = nums.size();
        int startIdx = 0;

        for (int i = 0; i < n; ++i)
            freq[nums[i]]++;

        auto hasDuplicates = [&]() {
            for (auto& entry : freq) {
                if (entry.second > 1)
                    return true;
            }
            return false;
        };

        while (hasDuplicates()) {
            operations++;
            int removeCount = min(3, n - startIdx);

            for (int i = 0; i < removeCount; ++i) {
                int val = nums[startIdx + i];
                freq[val]--;
                if (freq[val] == 0)
                    freq.erase(val);
            }

            startIdx += removeCount;
        }

        return operations;
    }
};
