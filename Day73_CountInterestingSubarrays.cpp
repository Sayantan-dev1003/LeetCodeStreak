class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        unordered_map<int, long long> prefixCount;
        prefixCount[0] = 1;
        long long count = 0;
        int prefix = 0;

        for (int num : nums) {
            if (num % modulo == k) {
                prefix++;
            }
            int target = (prefix - k + modulo) % modulo;
            count += prefixCount[target];
            prefixCount[prefix % modulo]++;
        }

        return count;
    }
};
