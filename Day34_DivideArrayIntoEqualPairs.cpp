class Solution {
public:
    bool divideArray(vector<int>& nums) {
        if (nums.size() % 2 != 0)
            return false;

        unordered_map<int, int> freq;

        for (int num : nums) {
            freq[num]++;
        }

        for (const auto& entry : freq) {
            if (entry.second % 2 != 0) {
                return false;
            }
        }

        return true;
    }
};
