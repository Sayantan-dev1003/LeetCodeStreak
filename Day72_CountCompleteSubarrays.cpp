class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, int> totalFreq;
        for (int num : nums)
            totalFreq[num]++;
        int totalDistinct = totalFreq.size();

        int result = 0;
        unordered_map<int, int> windowFreq;
        int left = 0;

        for (int right = 0; right < n; ++right) {
            windowFreq[nums[right]]++;

            while (windowFreq.size() == totalDistinct) {
                result += (n - right);
                windowFreq[nums[left]]--;
                if (windowFreq[nums[left]] == 0)
                    windowFreq.erase(nums[left]);
                left++;
            }
        }

        return result;
    }
};
