class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int count = 0;
        int n = nums.size();
        
        for (int i = 0; i <= n - 3; ++i) {
            int first = nums[i];
            int middle = nums[i + 1];
            int third = nums[i + 2];
            
            if (first + third == middle / 2 && middle % 2 == 0) {
                count++;
            }
        }
        
        return count;
    }
};
